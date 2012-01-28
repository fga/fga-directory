<?php

/**
 * @file
 * API documentation file for Workbench Moderation.
 */

/**
 * Allows modules to alter moderation access.
 *
 * @param &$access
 *   A boolean access declaration. Passed by reference.
 * @param $op
 *   The operation being performed. May be 'view', 'update', 'delete',
 *   'view revisions' or 'moderate'.
 * @param $node
 *   The node being acted upon.
 */
function hook_workbench_moderation_access_alter(&$access, $op, $node) {
  global $user;
  // If the node is marked private, only let its owner moderate it.
  if (empty($node->private) || $op != 'moderate') {
    return;
  }
  if ($user->uid != $node->uid) {
    $access = FALSE;
  }
}
