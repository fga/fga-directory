<?php
/**
 * @file
 * fga_users.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function fga_users_user_default_roles() {
  $roles = array();

  // Exported role: site administrator
  $roles['site administrator'] = array(
    'name' => 'site administrator',
    'weight' => '3',
  );

  // Exported role: site developer
  $roles['site developer'] = array(
    'name' => 'site developer',
    'weight' => '2',
  );

  // Exported role: unconfirmed
  $roles['unconfirmed'] = array(
    'name' => 'unconfirmed',
    'weight' => '6',
  );

  return $roles;
}
