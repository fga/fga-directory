<?php
/**
 * @file
 * occupy_directory_util.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function occupy_directory_util_user_default_permissions() {
  $permissions = array();

  // Exported permission: access mollom statistics.
  $permissions['access mollom statistics'] = array(
    'name' => 'access mollom statistics',
    'roles' => array(
      0 => 'occupation curator',
      1 => 'site administrator',
      2 => 'site developer',
    ),
    'module' => 'mollom',
  );

  // Exported permission: administer mollom.
  $permissions['administer mollom'] = array(
    'name' => 'administer mollom',
    'roles' => array(
      0 => 'site developer',
    ),
    'module' => 'mollom',
  );

  // Exported permission: bypass mollom protection.
  $permissions['bypass mollom protection'] = array(
    'name' => 'bypass mollom protection',
    'roles' => array(
      0 => 'occupation curator',
      1 => 'occupation registrant',
      2 => 'site administrator',
      3 => 'site developer',
    ),
    'module' => 'mollom',
  );

  return $permissions;
}
