<?php
/**
 * @file
 * occupations.delta.inc
 */

/**
 * Implements hook_delta_default_templates().
 */
function occupations_delta_default_templates() {
  $export = array();

  $delta = new stdClass();
  $delta->disabled = FALSE; /* Edit this to true to make a default delta disabled initially */
  $delta->api_version = 3;
  $delta->machine_name = 'occupation_directory_default';
  $delta->name = 'default';
  $delta->description = 'default delta template';
  $delta->theme = 'occupy_directory';
  $delta->mode = 'preserve';
  $delta->parent = '';
  $delta->settings = array();
  $export['occupation_directory_default'] = $delta;

  return $export;
}
