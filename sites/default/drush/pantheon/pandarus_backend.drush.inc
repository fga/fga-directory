<?php
/**
 * @file
 *
 * Back-end for Pantheon Drush Extensions.  This file must be present
 * and discoverable by Drush in any target Pantheon environment ("dev",
 * "test" or "live").
 */

/*
 * Implements hook_drush_command().
 */
function pandarus_backend_drush_command() {
  $items['pan-backend'] = array(
    'arguments' => array(
      'command' => 'Command',
    ),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
    'hidden' => TRUE,
  );
  return $items;
}

/**
 * Command callback for pan-backend.
 *
 * Intended as a back-end for Pandarus.  May be removed when/if Pantheon
 * upgrades to Drush 5.x
 *
 * @param $command
 *   The command to execute
 */
function drush_pandarus_backend_pan_backend($command) {
  $rc = drush_op_system($command);
  if ($rc !== 0) {
    return drush_set_error('PANDARUS_ERROR', dt('Error code @code executing command.', array('@code' => $rc)));
  }
}
