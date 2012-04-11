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

  // Exported permission: enter occupation revision log entry
  $permissions['enter occupation revision log entry'] = array(
    'name' => 'enter occupation revision log entry',
    'roles' => array(
      0 => 'occupation curator',
      1 => 'site administrator',
      2 => 'site developer',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: override occupation authored by option
  $permissions['override occupation authored by option'] = array(
    'name' => 'override occupation authored by option',
    'roles' => array(
      0 => 'occupation curator',
      1 => 'site administrator',
      2 => 'site developer',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: override occupation authored on option
  $permissions['override occupation authored on option'] = array(
    'name' => 'override occupation authored on option',
    'roles' => array(
      0 => 'site administrator',
      1 => 'site developer',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: override occupation promote to front page option
  $permissions['override occupation promote to front page option'] = array(
    'name' => 'override occupation promote to front page option',
    'roles' => array(
      0 => 'site developer',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: override occupation published option
  $permissions['override occupation published option'] = array(
    'name' => 'override occupation published option',
    'roles' => array(
      0 => 'occupation curator',
      1 => 'site administrator',
      2 => 'site developer',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: override occupation revision option
  $permissions['override occupation revision option'] = array(
    'name' => 'override occupation revision option',
    'roles' => array(
      0 => 'site administrator',
      1 => 'site developer',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: override occupation sticky option
  $permissions['override occupation sticky option'] = array(
    'name' => 'override occupation sticky option',
    'roles' => array(
      0 => 'site developer',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: view any unpublished occupation content
  $permissions['view any unpublished occupation content'] = array(
    'name' => 'view any unpublished occupation content',
    'roles' => array(
      0 => 'occupation curator',
      1 => 'site administrator',
      2 => 'site developer',
    ),
    'module' => 'view_unpublished',
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
