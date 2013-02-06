<?php
/**
 * @file
 * occupy_directory_util.features_plumber_records.inc
 */

/**
 * Implements hook_features_plumber_defaults().
 */
function occupy_directory_util_features_plumber_defaults() {
  $export = array();

  $features_plumber_record = new stdClass();
  $features_plumber_record->disabled = FALSE; /* Edit this to true to make a default features_plumber_record disabled initially */
  $features_plumber_record->api_version = 1;
  $features_plumber_record->name = 'occupy_directory_util__dependencies__context_ui';
  $features_plumber_record->feature = 'occupy_directory_util';
  $features_plumber_record->component = 'dependencies';
  $features_plumber_record->component_val = 'context_ui';
  $export['occupy_directory_util__dependencies__context_ui'] = $features_plumber_record;

  return $export;
}
