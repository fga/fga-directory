<?php
/**
 * @file
 * occupations.features_plumber_records.inc
 */

/**
 * Implements hook_features_plumber_defaults().
 */
function occupations_features_plumber_defaults() {
  $export = array();

  $features_plumber_record = new stdClass();
  $features_plumber_record->disabled = FALSE; /* Edit this to true to make a default features_plumber_record disabled initially */
  $features_plumber_record->api_version = 1;
  $features_plumber_record->name = 'occupations__dependencies__geofield_map';
  $features_plumber_record->feature = 'occupations';
  $features_plumber_record->component = 'dependencies';
  $features_plumber_record->component_val = 'geofield_map';
  $export['occupations__dependencies__geofield_map'] = $features_plumber_record;

  return $export;
}
