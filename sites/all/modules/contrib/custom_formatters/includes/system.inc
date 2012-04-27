<?php
/**
 * @file
 * System module integration.
 */

/**
 * Implements hook_init().
 */
function custom_formatters_init() {
  module_invoke_all('custom_formatters_init');
}

/**
 * Implements hook_theme().
 */
function custom_formatters_theme() {
  $theme = array();
  drupal_alter('custom_formatters_theme', $theme);
  return $theme;
}

/**
 * Implements hook_form_alter().
 */
function custom_formatters_form_alter(&$form, &$form_state, $form_id) {
  drupal_alter('custom_formatters_form_alter', $form, $form_state, $form_id);
}
