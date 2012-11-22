<?php
/**
 * @file
 * directory_solr.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function directory_solr_user_default_permissions() {
  $permissions = array();

  // Exported permission: access resource search_api_index.
  $permissions['access resource search_api_index'] = array(
    'name' => 'access resource search_api_index',
    'roles' => array(),
    'module' => 'restws',
  );

  // Exported permission: access resource search_api_server.
  $permissions['access resource search_api_server'] = array(
    'name' => 'access resource search_api_server',
    'roles' => array(),
    'module' => 'restws',
  );

  // Exported permission: administer search_api.
  $permissions['administer search_api'] = array(
    'name' => 'administer search_api',
    'roles' => array(
      0 => 'site developer',
    ),
    'module' => 'search_api',
  );

  return $permissions;
}
