<?php
/**
 * @file
 * occupations_administration.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function occupations_administration_user_default_permissions() {
  $permissions = array();

  // Exported permission: create field_term_geographic_area
  $permissions['create field_term_geographic_area'] = array(
    'name' => 'create field_term_geographic_area',
    'roles' => array(
      0 => 'occupation curator',
      1 => 'site administrator',
      2 => 'site developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: delete terms in 4
  $permissions['delete terms in 4'] = array(
    'name' => 'delete terms in 4',
    'roles' => array(),
  );

  // Exported permission: edit field_term_geographic_area
  $permissions['edit field_term_geographic_area'] = array(
    'name' => 'edit field_term_geographic_area',
    'roles' => array(
      0 => 'occupation curator',
      1 => 'site administrator',
      2 => 'site developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_term_geographic_area
  $permissions['edit own field_term_geographic_area'] = array(
    'name' => 'edit own field_term_geographic_area',
    'roles' => array(
      0 => 'occupation curator',
      1 => 'site administrator',
      2 => 'site developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit terms in 4
  $permissions['edit terms in 4'] = array(
    'name' => 'edit terms in 4',
    'roles' => array(),
  );

  // Exported permission: view field_term_geographic_area
  $permissions['view field_term_geographic_area'] = array(
    'name' => 'view field_term_geographic_area',
    'roles' => array(
      0 => 'occupation curator',
      1 => 'site administrator',
      2 => 'site developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_term_geographic_area
  $permissions['view own field_term_geographic_area'] = array(
    'name' => 'view own field_term_geographic_area',
    'roles' => array(
      0 => 'occupation curator',
      1 => 'site administrator',
      2 => 'site developer',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
