<?php
/**
 * @file
 *
 * Provides drush extensions for use with the Pantheon platform.
 */

/**
 * Implements hook_drush_command().
 */
function pandarus_drush_command() {
  $items = array();

  $items['pan-deploy'] = array(
    'description' => 'Deploy the current git commit to the test or live environment',
    'arguments' => array(
      'environment' => 'The environment (test or live) to which to deploy',
    ),
    'options' => array(
      'git-path' => 'The full path to your git executable.  Defaults to "git".',
      'show-tag' => 'If specified, does nothing but print the currently deployed tag.',
      'show-log' => 'Like "show-tag" but prints the log for the currently deployed tag. Optionally specify the number of log entries to print (default is 1)',
      'origin' => 'The name of the git remote that refers to the Pantheon repository.  Defaults to "origin"',
    ),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_ROOT,
    'topics' => array('pandarus'),
    'examples' => array(
      'drush pan-deploy test' => 'Deploy the current commit to the test environment.',
      'drush pan-deploy live --show-log=5' => 'Print the log entries for the last 5 commits deployed to the live environment.',
    ),
    );

  $items['pan-sftp'] = array(
    'description' => 'Connect to a Drupal site\'s server via SFTP for an interactive session or to run an FTP command',
    'arguments' => array(
      'cmd' => 'FTP command to execute on target(s). Optional, except when site-alias is a list.',
    ),
    'options' => array(
      'ssh-config' => 'A comma separated list of ssh-config options of the form name=value, (e.g. "Port=2222").  Will be passed via the "-o" sftp option.'
    ),
    'handle-remote-commands' => TRUE,
    'strict-option-handling' => TRUE,
    'examples' => array(
      'drush @mysite sftp' => 'Open an interactive SFTP session on @mysite\'s server.',
      'drush @prod sftp \'ls /tmp\'' => 'Run the FTP command "ls /tmp" on @prod site. If @prod is a site list, then the command will be executed on each site.',
    ),
    'aliases' => array('sftp'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
    'topics' => array('pandarus', 'docs-aliases'),
  );

  $items['pan-sql-cli'] = array(
    'description' => 'Open a SQL command-line interface to a Pantheon database (Pantheon-safe version of sql-cli).',
    'arguments' => array(
      'site-alias' => 'A remote site alias. Can be an alias list.',
    ),
    'options' => array(
      //'ssh-config' => 'A comma separated list of ssh-config options of the form name=value, (e.g. "Port=2222").  Will be passed via the "-o" sftp option.'
    ),
    'handle-remote-commands' => TRUE,
    'strict-option-handling' => TRUE,
    'examples' => array(
      'drush @mysite pan-sql-cli' => 'Open an interactive mysql session on @mysite\'s server.',
    ),
    'aliases' => array('psqlc'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
    'topics' => array('pandarus', 'docs-aliases'),
  );

  $commands = sql_drush_command();
  $items['pan-sql-sync'] = array(
    'description' => 'Syncs the Drupal DB between environments (Pantheon-safe version of sql-sync).',
    'examples' => array(
      'drush pan-sql-sync @pantheon.mysite.live @self' => 'Copy the live DB to the local environment.',
    ),
  ) + $commands['sql-sync'];
  $items['pan-sql-sync']['topics'][] ='pandarus';

  $items['pandarus'] = array(
    'description' => 'Pandarus: Drush extensions for the Pantheon Platform',
    'hidden' => TRUE,  
    'topic' => TRUE,
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
    'callback' => 'drush_print_file',
    'callback arguments' => array(dirname(__FILE__) . '/README.txt'),
  );
  return $items;
}

/**
 * Implements hook_drush_init().
 */
function pandarus_drush_init() {
  // Check to see if we're running a Pandarus command.
  $command = drush_get_command();
  switch ($command['command-hook']) {
    //case 'pan-deploy':
    case 'pan-sftp':
    case 'pan-sql-sync':
      if (DRUSH_VERSION < 5) {
        return drush_set_error(dt('This command requires drush 5.0+ on your local system.'));
      }
      break;
  }
}

/**
 * Drush command callback for pan-deploy.
 *
 * Pushes a deployment tag to the specified environment.
 *
 * @param $target
 *   The target environment (must be either "test" or "live").
 */
function drush_pandarus_pan_deploy($target) {
  $origin = drush_get_option('origin', 'origin');
  $target = strtolower(trim($target));
  if (!in_array($target, array('test', 'live'))) {
    return drush_set_error('PANDARUS_ERROR', dt('You must specify a valid target environment (either "test" or "live"'));
  }

  if (($n = drush_get_option('show-log', FALSE)) || drush_get_option('show-tag', FALSE)) {
    if (($index = _pandarus_get_deployed_tag_index($target, $origin)) === FALSE) return FALSE;
    if ($index == 0) {
      drush_print(dt('No code deployed on @tgt.', array('@tgt' => $target)));
    }
    else {
      $tag = "pantheon_{$target}_{$index}";
      drush_print($tag);
      if ($n) {
        _pandarus_git_invoke("log -n$n $tag", $commit, TRUE);
        drush_print(implode("\n", $commit));
      }
    }
    return;
  }

  // Get the current git branch (so we know what to push).
  if (_pandarus_git_invoke('symbolic-ref HEAD', $output, TRUE) || empty($output)) {
   return drush_set_error('PANDARUS_ERROR', dt('Unable to determine the current git branch.  You cannot run pan-deploy from a headless state.'));
  }
  list(, $branch) = explode('refs/heads/', $output[0]);
  $branch = trim($branch);

  if (($index = _pandarus_get_deployed_tag_index($target)) === FALSE) return FALSE;
  $index++;
  $tag = "pantheon_{$target}_{$index}";

  // Show a detailed warning message.
  drush_print();
  drush_print(dt('WARNING: You are about to deploy the following commit to the @env environment.', array('@env' => $target)));
  drush_print(dt('This will create a new tag "@tag" and push both it and the current branch (@b).', array('@tag' => $tag, '@b' => $branch)));
  _pandarus_git_invoke("log -n1", $commit, TRUE);
  drush_print(implode("\n", $commit));
  if (!drush_confirm(dt('Are you sure you want to continue?'))) {
    return drush_user_abort();
  }

  // First try to push the current branch.
  if (_pandarus_git_invoke("push $origin $branch", $output)) {
    return drush_set_error('PANDARUS_ERROR', dt('Unable to push @branch to @remote', array('@branch' => $branch, '@remote' => $origin)));
  }

  // Now tag and push tags.
  if (_pandarus_git_invoke("tag $tag", $output)) {
    drush_set_error('PANDARUS_ERROR', dt('Unable to write tag.'));
    if (drush_get_context('DRUSH_DEBUG')) {
      drush_print(implode("\n", $output));
    }
    return FALSE;
  }
  if (_pandarus_git_invoke("push $origin --tags", $output)) {
    drush_set_error('PANDARUS_ERROR', dt('Unable to push @branch to @remote', array('@branch' => $branch, '@remote' => $origin)));
    if (drush_get_context('DRUSH_DEBUG')) {
      drush_print(implode("\n", $output));
    }
    return FALSE;
  }
}

/**
 * Drush command callback for pan-sftp.
 *
 * Perform sftp commands or open an sftp shell on a remote site.
 *
 * @param $command
 *   The ftp command to execute.  If omitted, will open a shell.
 */
function drush_pandarus_pan_sftp($command = NULL) {
  if (!$alias = drush_get_context('DRUSH_TARGET_SITE_ALIAS')) {
    return drush_set_error('DRUSH_MISSING_TARGET_ALIAS', 'A remote site alias is required.');
  }
  $site = drush_sitealias_get_record($alias);
  // We only accept remote aliases.
  if (empty($site['remote-host'])) {
    drush_set_error('DRUSH_SITE_SSH_REMOTE_ALIAS_REQUIRED', dt('@alias does not specify a remote-host.', array('@alias' => $alias)));
    return;
  }

  if (isset($site['site-list'])) {
    if (empty($command)) {
      drush_set_error('DRUSH_SITE_SSH_COMMAND_REQUIRED', dt('A command is required when multiple site aliases are specified.'));
      return;
    }
    foreach ($site['site-list'] as $alias_single) {
      $site_single = drush_sitealias_get_record($alias_single);
      $status = mypantheon_sftp($site_single, $command);
      if ($status != 0) break;
    }
  }
  else {
    $status = _pandarus_sftp($site, $command);
  }
  if ($status != 0) {
    return drush_set_error('DRUSH_SITE_SSH_ERROR', dt('An error @code occurred while running the command `@command`', array('@command' => $cmd, '@code' => $status)));
  }
}

/**
 * Drush command callback for pan-sql-cli.
 */
function drush_pandarus_pan_sql_cli() {
  if (!$alias = drush_get_context('DRUSH_TARGET_SITE_ALIAS')) {
    return drush_set_error('DRUSH_MISSING_TARGET_ALIAS', 'A remote site alias is required.');
  }
  $site_record = drush_sitealias_get_record($alias);
  // We only accept remote aliases.
  if (empty($site_record['remote-host'])) {
    drush_set_error('DRUSH_SITE_SSH_REMOTE_ALIAS_REQUIRED', dt('@alias does not specify a remote-host.', array('@alias' => $alias)));
    return;
  }
  $result = drush_invoke_process($site_record, 'sql-conf');
  if (!$result || empty($result['object'])) {
    return drush_set_error('PANDARUS_ERROR', dt('Unable to retrieve remote database connection information.'));
  }
  drush_shell_proc_open(_drush_sql_connect($result['object']));
}

///////////////////////////////////////////////////////////////////////////////
// Helpers.

/**
 * Execute an sftp operation or open an sftp shell on a remote site.
 *
 * @param $site_record
 *   The array describing the remote site.
 * @param $command
 *   The command to execute.  If omitted, an interactive sftp shell will be opened.
 *
 * @return
 *   The return code from the sftp command.
 */
function _pandarus_sftp($site_record, $command = NULL) {
  $hostname = drush_remote_host($site_record);
  // Default options are appropriate for a Pantheon site.
  $config = explode(',', drush_get_option('ssh-config', 'Port=2222,AddressFamily=inet'));
  foreach ($config as $key => $pair) {
    $config[$key] = '-o ' . $pair;
  }
  $options = implode(' ', $config);
  $cmd = 'sftp';
  if (!empty($command)) {
    $temp = drush_save_data_to_temp_file($command);
    $cmd .= " -b '$temp'";
  }
  $cmd .= ' ' . $options . ' ' . $hostname;
  return drush_shell_proc_open($cmd);
}

/**
 * Execute a system command on a remote system using drush_invoke_process() and the pan-backend command.
 *
 * @param $site
 *   The site-alias record describing the site on which the command should be executed.
 * @param $command
 *   The complete command string.
 *
 * @return
 *   The output of the command if successful, FALSE otherwise.
 *
 */
function _pandarus_backend_invoke($site, $command) {
  $options = array();
  $options['yes'] = TRUE;
  // Mimic Drush 5 behavior - automatically include commandfiles located at sites/all/drush
  $options['include'] = 'sites/all/drush';
  $r = drush_invoke_process($site, 'pan-backend', array($command), $options);
  if (drush_get_context('DRUSH_DEBUG') && !empty($r['log'])) {
    drush_print(dt('Remote command log:'));
    foreach ($r['log'] as $key => $entry) {
      drush_log($entry['message'], $entry['type']);
    }
  }
  if (drush_get_context('DRUSH_VERBOSE') && !empty($r['output'])) {
    drush_print(dt("Remote command output:"));
    drush_print($r['output']);
  }
  if (!$r || $r['error_status'] !== 0) {
    return FALSE;
  }
  else {
    return $r['output'];
  }
}

/**
 * Determine whether a given site record refers to a remote pantheon site.
 *
 * @param $site_record
 *   The site record to check.
 * @return
 *   TRUE if the record describes a pantheon site, FALSE otherwise.
 */
function _pandarus_is_pantheon($site_record) {
  if (isset($site_record['remote-host'])) {
    // Does the remote host match the pantheon pattern?
    if (preg_match('/^appserver\.(dev|test|live)\.(.+)\.drush\.in$/', $site_record['remote-host'], $matches)) {
      // If so, is the user name correct?
      if (count($matches) > 2 && "{$matches[1]}.{$matches[2]}" == $site_record['remote-user']) {
        return TRUE;
      }
    }
  }
  return FALSE;
}

/**
 * Modified version of drush_sql_dump_file().
 *
 * Determine where to store an sql dump file.  This
 * function is called by sql-sync.
 *
 * This version uses Pantheon specific logic for a Pantheon remote site to
 * locate the tmp directory which belongs to this user.
 *
 * @param $site_record
 *   The array describing the site on which a temp file is to be found.
 *
 * @return
 *   The full path to a temp file, if one can be created.
 *
 * @see drush_sql_dump_file()
 */
function _pandarus_sql_dump_file(&$site_record) {
  $site_record['dump-is-temp'] = FALSE;
  // If the user has set the --{prefix}-dump option, then
  // use the exact name provided.
  $dump_file = drush_sitealias_get_path_option($site_record, 'dump');
  if (!isset($dump_file)) {
    $databases = sitealias_get_databases_from_record($site_record);
    if (isset($databases)) {
      $db_spec = $databases['default']['default'];
      // Make a base filename pattern to use to name the dump file
      $filename_pattern = $db_spec['database'];
      if (isset($db_spec['remote-host'])) {
        $filename_pattern = $db_spec['remote-host'] . '_' . $filename_pattern;
      }
    }
    // If the user has set the --dump-dir option, then
    // store persistant sql dump files there.
    $dump_dir = drush_sitealias_get_path_option($site_record, 'dump-dir');
    if (!isset($dump_dir)) {
      // If this is a remote site, try to find a writable tmpdir.
      if (isset($site_record['remote-host'])) {
        // For a Pantheon site, we will use ~/tmp.  This will prevent the possible
        // contention if multiple users tried to access the global /tmp dir.
        if (_pandarus_is_pantheon($site_record)) {
          // We invoke an empty command and use the 'context' key in the result to locate
          // drushrc.php (which is in the home directory).
          // This is preferable to using the output of a command like 'pwd' because that will be hard to
          // parse if --debug or --verbose have been specified.
          if (drush_get_context('DRUSH_DEBUG')) {
            drush_log(dt('Searching for temp directory on @alias', array('@alias' => '@' . $site_record['#name'])), 'notice');
          }
          $result = drush_invoke_process($site_record, '');
          if (array_key_exists('context', $result) && !empty($result['context']['config-file'])) {
            $dump_dir = dirname(trim($result['context']['config-file'])) . '/tmp';
          }
          // If we got no good result, then use /tmp and hope for the best.
          else {
            $dump_dir = '/tmp';
          }
        }
        else {
          $result = drush_invoke_process($site_record, 'ev', array('drush_print(drush_find_tmp())'));
          // If the call to invoke process does not work for some reason (e.g. drush not
          // installed on the target machine), then we will just presume that the tmp dir is '/tmp'.
          if (!array_key_exists('output', $result) || empty($result['output'])) {
            $dump_dir = '/tmp';
          }
          else {
            $dump_dir = trim($result['output']);
          }
        }
        $dump_file = $dump_dir . '/' . $filename_pattern . '.sql';
      }
      else {
        $dump_file = drush_tempnam($filename_pattern . '.sql.');
      }
      $site_record['dump-is-temp'] = TRUE;
    }
    else {
      $dump_file = $dump_dir . '/' . $filename_pattern . '.sql';
    }
  }

  return $dump_file;
}

/**
 * Executes a git command from the drupal root.
 *
 * Freely adapted from http://drupal.org/projects/dog
 *
 * @param $command
 *   The git command to execute.
 * @param $output
 *   Will be filled with the output of the command as an array of lines.
 * @param $force
 *   When TRUE, executes the command even in simulation mode.  Useful for
 *   non-destructive commands.
 *
 * @return
 *   The exit code from git.
 */
function _pandarus_git_invoke($command, &$output = NULL, $force = FALSE) {
  static $git_path;
  if (!isset($git_path)) {
    $git_path = drush_get_option('git-path', 'git');
  }

  // Inherit env using the sanest possible settings
  $vo = ini_get('variables_order');
  if (strpos($vo, 'E') !== FALSE) {
    $env =& $_ENV;
  }
  else if (strpos($vo, 'S') !== FALSE) {
    $env =& $_SERVER;
  }
  else {
    $env = FALSE;
  }
  if ($env === FALSE) {
    return drush_set_error('PANDARUS_ERROR', dt('Neither $_ENV nor $_SERVER are available to set up proper environment inheritance; ensure E and/or S is set in your php.ini\'s "variables_order" setting.'));
  }
  elseif (isset($env['argv'])) {
    // At least clean out argv/argc from this proc if we must rely on $_SERVER
    unset($env['argv'], $env['argc']);
  }

  $descriptor_spec = array(
    1 => array('pipe', 'w'),
    2 => array('pipe', 'w'),
  );

  // proc_open() and $pipes var preclude using drush_op() so we simulate it.
  if (drush_get_context('DRUSH_VERBOSE') || drush_get_context('DRUSH_SIMULATE')) {
     drush_print("Calling proc_open($git_path $command)");
  }

  if (!drush_get_context('DRUSH_SIMULATE') || $force) {
    $process = proc_open("$git_path $command", $descriptor_spec, $pipes, DRUPAL_ROOT, $env);
    if (is_resource($process)) {
      $stdout = stream_get_contents($pipes[1]);
      fclose($pipes[1]);
      $stderr = stream_get_contents($pipes[2]);
      fclose($pipes[2]);
    }

    $return_code = proc_close($process);
    $output = explode("\n", $stdout);
    return $return_code;
  }
  else {
    return 0;
  }
}

/**
 * Gets the tag index for the currently deployed code on the specified target.
 *
 * @param $target
 *   Either "test" or "live".
 * @param $origin
 *   The name of the git remote corresponding to the Pantheon repository.  Defaults to "origin".
 *
 * @return
 *   The index of the currently deployed tag (eg if the tag is "pantheon_test_12", will return 12).
 */
function _pandarus_get_deployed_tag_index($target, $origin = 'origin') {
  // Make sure our tags are up to date.
  if (_pandarus_git_invoke("fetch $origin --tags")) {
    //return drush_set_error('PANDARUS_ERROR', dt('Unable to fetch remote tags.'));
  }

  $list = array();
  if (_pandarus_git_invoke('tag -l', $list)) {
    return drush_set_error('PANDARUS_ERROR', dt('Unable to list tags.'));
  }
  $list = preg_grep('/^pantheon_' . $target . '_[0123456789]+$/', $list);
  //print_r($list);
  $max = 0;
  foreach ($list as $tag) {
    list(, , $number) = explode('_', $tag);
    $max = $number > $max ? $number : $max;
  }
  return $max;
}