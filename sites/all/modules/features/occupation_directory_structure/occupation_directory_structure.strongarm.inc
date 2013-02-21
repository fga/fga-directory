<?php
/**
 * @file
 * occupation_directory_structure.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function occupation_directory_structure_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ajax_register_enabled_links';
  $strongarm->value = array(
    'login' => 'login',
    'register' => 'register',
  );
  $export['ajax_register_enabled_links'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ajax_register_form_enable_modal_links';
  $strongarm->value = 0;
  $export['ajax_register_form_enable_modal_links'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ajax_register_hide_captcha';
  $strongarm->value = FALSE;
  $export['ajax_register_hide_captcha'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ajax_register_login_redirect_behavior';
  $strongarm->value = 'refresh';
  $export['ajax_register_login_redirect_behavior'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ajax_register_modal_background_color';
  $strongarm->value = '000000';
  $export['ajax_register_modal_background_color'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ajax_register_modal_background_opacity';
  $strongarm->value = '0.7';
  $export['ajax_register_modal_background_opacity'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ajax_register_modal_width';
  $strongarm->value = '550';
  $export['ajax_register_modal_width'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ajax_register_password_redirect_behavior';
  $strongarm->value = 'refresh';
  $export['ajax_register_password_redirect_behavior'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ajax_register_register_redirect_behavior';
  $strongarm->value = 'refresh';
  $export['ajax_register_register_redirect_behavior'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ajax_register_show_links_inline';
  $strongarm->value = 1;
  $export['ajax_register_show_links_inline'] = $strongarm;

  return $export;
}
