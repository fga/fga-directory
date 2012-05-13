<?php
/**
 * @file
 * occupations_import_export.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function occupations_import_export_user_default_permissions() {
  $permissions = array();

  // Exported permission: clear occupation_csv feeds.
  $permissions['clear occupation_csv feeds'] = array(
    'name' => 'clear occupation_csv feeds',
    'roles' => array(
      0 => 'site developer',
    ),
    'module' => 'feeds',
  );

  // Exported permission: import occupation_csv feeds.
  $permissions['import occupation_csv feeds'] = array(
    'name' => 'import occupation_csv feeds',
    'roles' => array(
      0 => 'site developer',
    ),
    'module' => 'feeds',
  );

  // Exported permission: tamper occupation_csv.
  $permissions['tamper occupation_csv'] = array(
    'name' => 'tamper occupation_csv',
    'roles' => array(
      0 => 'site developer',
    ),
    'module' => 'feeds_tamper',
  );

  return $permissions;
}
