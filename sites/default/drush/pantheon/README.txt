==============================================================
PANDARUS - Drush command extensions for the Pantheon Platform.
==============================================================

This extension provides the following Drush commands:

pan-sql-sync, pan-sql-cli
  Drop in replacements for the corresponding drush sql commands (which are
  currently unsupported on Pantheon).
pan-sftp
  Executes an sftp command or opens an sftp shell on a remote Pantheon site via
  a Pantheon site alias.
pan-deploy
  Tags the current git commit in the local repository and deploys to the "test" or
  "live" environment.


REQUIREMENTS
============
Drush 5.x (on the local machine).
NOTE: Not tested/supported for Windows.


INSTALLATION
============
Pandarus consists of three files:

- pandarus.drush.inc
- sync.sql.pan.inc
- pandarus_backend.drush.inc

You must place the first two files on your local system in one of the locations
which Drush normally searches for command files (type "drush topic docs-commands"
for more information).

The third file must be present and discoverable by Drush in any remote Pantheon
environment (dev, test or live) on which you wish to operate.

The easiest way to accomplish this is to create a sites/all/drush directory and
put it there. Like Drush 5.x, Pandarus automatically includes this directory in
the search path when invoking remote commands. However, you can place this file
elsewhere as long as you add to each site alias an 'include' key pointing to the
containing folder.  For example, if you place it in sites/default/drush/pantheon,
just add the following to the relevant entries in pantheon.aliases.drushrc.php:

  'include' => 'sites/default/drush/pantheon',

You will probably have to clear the Drush cache on the remote environment in order
for the command to be found, e.g.

  drush @site.dev cache-clear drush

NOTE: All three files may reside in the same directory and be present on the
remote environments, but most of the commands will only work if executed from
a local system with Drush 5.x installed.



USAGE NOTES
===========
- When using pan-sql-sync, if you specify the dump file locations on the remote
  systems, be sure they are in a writable directory. In particular, the drupal
  tree (except for sites/default/files) is *not* writable unless you have enabled
  "On Server Development" from the Pantheon control panel. Temporary dumps will
  be placed in the ~/tmp folder for the specified environment.

- The --create-db option of sql-sync won't work as advertised on a remote system.
  Instead it will drop all tables in the remote DB before performing the sql
  import.

- When using pan-deploy, if you are on the "master" branch, the commit will also
  be automatically deployed to the "dev" environment (just as if you had issued
  "git push origin master".  If you want to push a commit to "test" or "live"
  while bypassing the "dev" environment (e.g. a maintenance update), you can
  create a new branch from the last deployment tag, and then commit and deploy
  your changes from the new branch.  For example:
  
    git checkout -b test $(drush pan-deploy test --show-tag)
    ...
    (make and stage your changes)
    ...
    git commit -m "Maintenance fixes"
    drush pan-deploy test
  
  Ths will push the newly created "test" branch to the Pantheon repository
  (creating a new remote branch if it doesn't already exist), and tag the tip
  of that branch for deployment to the test environment. The dev environment
  (and your master branch) will remain unchanged.

  Note that you will probably want to merge those changes back into master, or
  they will be lost the next time you deploy from master or push code from dev.

  