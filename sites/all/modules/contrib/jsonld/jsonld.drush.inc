<?php

/**
 * @file
 *   Drush integration for jsonld.
 */

/**
 * Implements hook_drush_command().
 */
function jsonld_drush_command() {
  $items = array();

  $items['jsonld-download'] = array(
    'callback' => 'jsonld_drush_download',
    'description' => dt('Downloads the PHP JSON-LD library from https://github.com/digitalbazaar/php-json-ld'),
    'arguments' => array(
      'path' => dt('Optional. A path to the download folder. If omitted Drush will use the default location (sites/all/libraries/php-json-ld).'),
    ),
  );
  return $items;
}

/**
 * Download command callback.
 */
function jsonld_drush_download() {
  $args = func_get_args();
  if ($args[0]) {
    $path = $args[0];
  }
  else {
    $path = drush_get_context('DRUSH_DRUPAL_ROOT') . '/sites/all/libraries/php-json-ld';
  }


  // Create the path if it does not exist yet.
  if (!is_dir($path)) {
    drush_mkdir($path);
  }

  if (is_dir($path . '/php-json-ld')) {
    drush_log('php-json-ld already present. No download required.', 'ok');
  }
  elseif (drush_op('chdir', $path) &&
      drush_shell_exec('wget -O php-json-ld.tar.gz http://github.com/digitalbazaar/php-json-ld/tarball/master') &&
      drush_shell_exec('tar zxvf php-json-ld.tar.gz') &&
      drush_shell_exec('mv digitalbazaar-php-json-ld-* php-json-ld') &&
      drush_shell_exec('rm php-json-ld.tar.gz')) {
    drush_log(dt('The latest php-json-ld library has been downloaded to @path', array('@path' => $path)), 'success');
  }
  else {
    drush_log(dt('Drush was unable to download the php-json-ld library to @path', array('@path' => $path)), 'error');
  }
}

/**
 * Implements drush_MODULE_post_COMMAND().
 */
function drush_jsonld_post_pm_enable() {
  $extensions = func_get_args();
  // Deal with comma delimited extension list.
  if (strpos($extensions[0], ',') !== FALSE) {
    $extensions = explode(',', $extensions[0]);
  }

  if (in_array('jsonld', $extensions) && !drush_get_option('skip')) {
    jsonld_drush_download();
  }
}
