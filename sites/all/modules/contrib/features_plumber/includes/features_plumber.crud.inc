<?php

/**
 * @file
 * CRUD functions for Features Plumber.
 */

/**
 * Load all records.
 *
 * @param $reset
 *   Whether to clear the static cache for these records.
 */
function features_plumber_records_load_all($reset = FALSE) {
  ctools_include('export');
  return ctools_export_crud_load_all('features_plumber', $reset);
}

/**
 * Load all records by feature name.
 *
 * @param $feature
 *   The machine name of the feature module.
 * @param $wildcard
 *   Whether to return any wildcard entries as well.
 */
function features_plumber_records_load_by_feature($feature, $wildcard = TRUE) {
  ctools_include('export');
  $return = ctools_export_load_object('features_plumber', 'conditions', array('feature' => $feature));
  if ($wildcard && $feature != FEATURES_PLUMBER_WILDCARD) {
    $return += ctools_export_load_object('features_plumber', 'conditions', array('feature' => FEATURES_PLUMBER_WILDCARD));
  }
  return $return;
}

/**
 * Create and save a new record.
 *
 * @param $feature
 *   The machine name of the feature module.
 * @param $component
 *   The machine name of the component, e.g. 'views'.
 * @param $component_val
 *   The component value, for instance 'frontpage'.
 * @return
 *   The saved record.
 */
function features_plumber_record_create($feature, $component, $component_val) {
  if (features_plumber_record_exists($feature, $component, $component_val)) {
    return FALSE;
  }
  $record = new stdClass();
  $record->name = features_plumber_generate_name($feature, $component, $component_val);
  $record->feature = $feature;
  $record->component = $component;
  $record->component_val = $component_val;

  return features_plumber_record_save($record);
}

/**
 * Write a record.
 *
 * @param stdClass $record
 *   A Features Plumber object record.
 */
function features_plumber_record_save(&$record) {
  $update = (isset($record->record_id) && is_numeric($record->record_id)) ? array('record_id') : array();
  if ($return = drupal_write_record('features_plumber', $record, $update)) {
    ctools_export_load_object_reset('features_plumber');
  }
  return $return;
}

/**
 * Delete a record from the database.
 *
 * @param $feature
 *   The machine name of the feature module.
 * @param $component
 *   The machine name of the component, e.g. 'views'.
 * @param $component_val
 *   The component value, for instance 'frontpage'.
 */
function features_plumber_record_delete($feature, $component, $component_val) {
  db_delete('features_plumber')
  ->condition('feature', $feature)
  ->condition('component', $component)
  ->condition('component_val', $component_val)
  ->execute();
}

/**
 * Generate a name.
 *
 * @param $feature
 *   The machine name of the feature module.
 * @param $component
 *   The machine name of the component, e.g. 'views'.
 * @param $component_val
 *   The component value, for instance 'frontpage'.
 * @return string
 *   The machine name for a record, based on the above arguments.
 */
function features_plumber_generate_name($feature, $component, $component_val) {
  return implode('__', compact('feature', 'component', 'component_val'));
}

/**
 * Determine if a record already exists.
 *
 * @param $feature
 *   The machine name of the feature module.
 * @param $component
 *   The machine name of the component, e.g. 'views'.
 * @param $component_val
 *   The component value, for instance 'frontpage'.
 * @return boolean
 *   TRUE or FALSE depending on if the record exists.
 */
function features_plumber_record_exists($feature, $component, $component_val) {
  $name = features_plumber_generate_name($feature, $component, $component_val);
  $records = features_plumber_records_load_by_feature($feature, FALSE);
  return isset($records[$name]);
}
