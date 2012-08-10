<?php
/**
 * @file
 * occupations_map.delta.inc
 */

/**
 * Implements hook_delta_default_templates().
 */
function occupations_map_delta_default_templates() {
  $export = array();

  $delta = new stdClass();
  $delta->disabled = FALSE; /* Edit this to true to make a default delta disabled initially */
  $delta->api_version = 3;
  $delta->machine_name = 'directory_fullmap';
  $delta->name = 'Full Map homepage';
  $delta->description = 'a full width map for the homepage';
  $delta->theme = 'occupy_directory';
  $delta->mode = 'preserve';
  $delta->parent = '';
  $delta->settings = array(
    'theme_occupy_directory_settings' => array(
      'alpha_grid' => 'alpha_fluid',
      'alpha_debug_block_toggle' => 0,
      'alpha_debug_grid_toggle' => 0,
      'alpha_hidden_title' => 1,
    ),
  );
  $export['directory_fullmap'] = $delta;

  return $export;
}
