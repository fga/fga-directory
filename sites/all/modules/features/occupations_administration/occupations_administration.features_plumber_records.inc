<?php
/**
 * @file
 * occupations_administration.features_plumber_records.inc
 */

/**
 * Implements hook_features_plumber_defaults().
 */
function occupations_administration_features_plumber_defaults() {
  $export = array();

  $features_plumber_record = new stdClass;
  $features_plumber_record->disabled = FALSE; /* Edit this to true to make a default features_plumber_record disabled initially */
  $features_plumber_record->api_version = 1;
  $features_plumber_record->name = 'occupations_administration__dependencies__comment';
  $features_plumber_record->feature = 'occupations_administration';
  $features_plumber_record->component = 'dependencies';
  $features_plumber_record->component_val = 'comment';
  $export['occupations_administration__dependencies__comment'] = $features_plumber_record;

  return $export;
}
