<?php
/**
 * @file
 * directory_solr.features_plumber_records.inc
 */

/**
 * Implements hook_features_plumber_defaults().
 */
function directory_solr_features_plumber_defaults() {
  $export = array();

  $features_plumber_record = new stdClass();
  $features_plumber_record->disabled = FALSE; /* Edit this to true to make a default features_plumber_record disabled initially */
  $features_plumber_record->api_version = 1;
  $features_plumber_record->name = 'directory_solr__dependencies__pantheon_apachesolr';
  $features_plumber_record->feature = 'directory_solr';
  $features_plumber_record->component = 'dependencies';
  $features_plumber_record->component_val = 'pantheon_apachesolr';
  $export['directory_solr__dependencies__pantheon_apachesolr'] = $features_plumber_record;

  return $export;
}
