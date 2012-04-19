<?php
/**
 * @file
 * fga_users.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function fga_users_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_admin_role';
  $strongarm->value = '5';
  $export['user_admin_role'] = $strongarm;

  return $export;
}
