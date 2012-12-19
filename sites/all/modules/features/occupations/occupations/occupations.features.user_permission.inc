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

  // Exported permission: create field_occupation_needs_fixing.
  $permissions['create field_occupation_needs_fixing'] = array(
    'name' => 'create field_occupation_needs_fixing',
    'roles' => array(
      0 => 'occupation curator',
      1 => 'site developer',
      2 => 'unconfirmed',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_occupation_notes.
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

  // Exported permission: create field_occupation_notes_legacy.
  $permissions['create field_occupation_notes_legacy'] = array(
    'name' => 'create field_occupation_notes_legacy',
    'roles' => array(
      0 => 'site developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_occupation_type.
  $permissions['create field_occupation_type'] = array(
    'name' => 'create field_occupation_type',
    'roles' => array(
      0 => 'site administrator',
      1 => 'site developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: delete terms in 2.
  $permissions['delete terms in 2'] = array(
    'name' => 'delete terms in 2',
    'roles' => array(
      0 => 'occupation curator',
      1 => 'site administrator',
      2 => 'site developer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 3.
  $permissions['delete terms in 3'] = array(
    'name' => 'delete terms in 3',
    'roles' => array(
      0 => 'site administrator',
      1 => 'site developer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit field_occupation_needs_fixing.
  $permissions['edit field_occupation_needs_fixing'] = array(
    'name' => 'edit field_occupation_needs_fixing',
    'roles' => array(
      0 => 'occupation curator',
      1 => 'site developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_occupation_notes.
  $permissions['edit field_occupation_notes'] = array(
    'name' => 'edit field_occupation_notes',
    'roles' => array(
      0 => 'occupation curator',
      1 => 'site administrator',
      2 => 'site developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_occupation_notes_legacy.
  $permissions['edit field_occupation_notes_legacy'] = array(
    'name' => 'edit field_occupation_notes_legacy',
    'roles' => array(
      0 => 'occupation curator',
      1 => 'site administrator',
      2 => 'site developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_occupation_type.
  $permissions['edit field_occupation_type'] = array(
    'name' => 'edit field_occupation_type',
    'roles' => array(
      0 => 'site administrator',
      1 => 'site developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_occupation_needs_fixing.
  $permissions['edit own field_occupation_needs_fixing'] = array(
    'name' => 'edit own field_occupation_needs_fixing',
    'roles' => array(
      0 => 'occupation curator',
      1 => 'occupation registrant',
      2 => 'site developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_occupation_notes.
  $permissions['edit own field_occupation_notes'] = array(
    'name' => 'edit own field_occupation_notes',
    'roles' => array(
      0 => 'occupation curator',
      1 => 'site administrator',
      2 => 'site developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_occupation_notes_legacy.
  $permissions['edit own field_occupation_notes_legacy'] = array(
    'name' => 'edit own field_occupation_notes_legacy',
    'roles' => array(
      0 => 'occupation registrant',
      1 => 'site developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_occupation_type.
  $permissions['edit own field_occupation_type'] = array(
    'name' => 'edit own field_occupation_type',
    'roles' => array(
      0 => 'site administrator',
      1 => 'site developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit terms in 2.
  $permissions['edit terms in 2'] = array(
    'name' => 'edit terms in 2',
    'roles' => array(
      0 => 'occupation curator',
      1 => 'site administrator',
      2 => 'site developer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 3.
  $permissions['edit terms in 3'] = array(
    'name' => 'edit terms in 3',
    'roles' => array(
      0 => 'site administrator',
      1 => 'site developer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: view field_occupation_needs_fixing.
  $permissions['view field_occupation_needs_fixing'] = array(
    'name' => 'view field_occupation_needs_fixing',
    'roles' => array(
      0 => 'occupation curator',
      1 => 'site developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_occupation_notes.
  $permissions['view field_occupation_notes'] = array(
    'name' => 'view field_occupation_notes',
    'roles' => array(
      0 => 'occupation curator',
      1 => 'site administrator',
      2 => 'site developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_occupation_notes_legacy.
  $permissions['view field_occupation_notes_legacy'] = array(
    'name' => 'view field_occupation_notes_legacy',
    'roles' => array(
      0 => 'occupation curator',
      1 => 'site administrator',
      2 => 'site developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_occupation_type.
  $permissions['view field_occupation_type'] = array(
    'name' => 'view field_occupation_type',
    'roles' => array(
      0 => 'site administrator',
      1 => 'site developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_occupation_needs_fixing.
  $permissions['view own field_occupation_needs_fixing'] = array(
    'name' => 'view own field_occupation_needs_fixing',
    'roles' => array(
      0 => 'occupation curator',
      1 => 'occupation registrant',
      2 => 'site developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_occupation_notes.
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

  // Exported permission: view own field_occupation_notes_legacy.
  $permissions['view own field_occupation_notes_legacy'] = array(
    'name' => 'view own field_occupation_notes_legacy',
    'roles' => array(
      0 => 'occupation registrant',
      1 => 'site developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_occupation_type.
  $permissions['view own field_occupation_type'] = array(
    'name' => 'view own field_occupation_type',
    'roles' => array(
      0 => 'site administrator',
      1 => 'site developer',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
