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

  // Exported permission: view any unpublished article content
  $permissions['view any unpublished article content'] = array(
    'name' => 'view any unpublished article content',
    'roles' => array(
      0 => 'site developer',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: view any unpublished content
  $permissions['view any unpublished content'] = array(
    'name' => 'view any unpublished content',
    'roles' => array(
      0 => 'site developer',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: view any unpublished occupation content
  $permissions['view any unpublished occupation content'] = array(
    'name' => 'view any unpublished occupation content',
    'roles' => array(
      0 => 'occupation curator',
      1 => 'site developer',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: view any unpublished page content
  $permissions['view any unpublished page content'] = array(
    'name' => 'view any unpublished page content',
    'roles' => array(
      0 => 'site developer',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: view any unpublished webform content
  $permissions['view any unpublished webform content'] = array(
    'name' => 'view any unpublished webform content',
    'roles' => array(
      0 => 'site developer',
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
