<?php
/**
 * @file
 * occupations.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function occupations_user_default_permissions() {
  $permissions = array();

  // Exported permission: create field_occupation_needs_fixing
  $permissions['create field_occupation_needs_fixing'] = array(
    'name' => 'create field_occupation_needs_fixing',
    'roles' => array(
      0 => 'occupation curator',
      1 => 'site developer',
      2 => 'unconfirmed',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_occupation_notes
  $permissions['create field_occupation_notes'] = array(
    'name' => 'create field_occupation_notes',
    'roles' => array(
      0 => 'occupation curator',
      1 => 'occupation registrant',
      2 => 'site administrator',
      3 => 'site developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_occupation_notes_legacy
  $permissions['create field_occupation_notes_legacy'] = array(
    'name' => 'create field_occupation_notes_legacy',
    'roles' => array(
      0 => 'site developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_occupation_needs_fixing
  $permissions['edit field_occupation_needs_fixing'] = array(
    'name' => 'edit field_occupation_needs_fixing',
    'roles' => array(
      0 => 'occupation curator',
      1 => 'site developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_occupation_notes
  $permissions['edit field_occupation_notes'] = array(
    'name' => 'edit field_occupation_notes',
    'roles' => array(
      0 => 'occupation curator',
      1 => 'site administrator',
      2 => 'site developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_occupation_notes_legacy
  $permissions['edit field_occupation_notes_legacy'] = array(
    'name' => 'edit field_occupation_notes_legacy',
    'roles' => array(
      0 => 'occupation curator',
      1 => 'site administrator',
      2 => 'site developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_occupation_needs_fixing
  $permissions['edit own field_occupation_needs_fixing'] = array(
    'name' => 'edit own field_occupation_needs_fixing',
    'roles' => array(
      0 => 'occupation curator',
      1 => 'occupation registrant',
      2 => 'site developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_occupation_notes
  $permissions['edit own field_occupation_notes'] = array(
    'name' => 'edit own field_occupation_notes',
    'roles' => array(
      0 => 'occupation curator',
      1 => 'site administrator',
      2 => 'site developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_occupation_notes_legacy
  $permissions['edit own field_occupation_notes_legacy'] = array(
    'name' => 'edit own field_occupation_notes_legacy',
    'roles' => array(
      0 => 'occupation registrant',
      1 => 'site developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_occupation_needs_fixing
  $permissions['view field_occupation_needs_fixing'] = array(
    'name' => 'view field_occupation_needs_fixing',
    'roles' => array(
      0 => 'occupation curator',
      1 => 'site developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_occupation_notes
  $permissions['view field_occupation_notes'] = array(
    'name' => 'view field_occupation_notes',
    'roles' => array(
      0 => 'occupation curator',
      1 => 'site administrator',
      2 => 'site developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_occupation_notes_legacy
  $permissions['view field_occupation_notes_legacy'] = array(
    'name' => 'view field_occupation_notes_legacy',
    'roles' => array(
      0 => 'occupation curator',
      1 => 'site administrator',
      2 => 'site developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_occupation_needs_fixing
  $permissions['view own field_occupation_needs_fixing'] = array(
    'name' => 'view own field_occupation_needs_fixing',
    'roles' => array(
      0 => 'occupation curator',
      1 => 'occupation registrant',
      2 => 'site developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_occupation_notes
  $permissions['view own field_occupation_notes'] = array(
    'name' => 'view own field_occupation_notes',
    'roles' => array(
      0 => 'occupation curator',
      1 => 'occupation registrant',
      2 => 'site administrator',
      3 => 'site developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_occupation_notes_legacy
  $permissions['view own field_occupation_notes_legacy'] = array(
    'name' => 'view own field_occupation_notes_legacy',
    'roles' => array(
      0 => 'occupation registrant',
      1 => 'site developer',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
