<?php
/**
 * @file
 * Features module integration.
 */

/**
 * Implements hook_features_api().
 *
 * Main info hook that features uses to determine what components are provided
 *
 * The 'component' for this module is named 'filefield_paths' not just
 * 'filefield_paths' to follow recommended practice documented in features.api
 *
 * We export individual filefield_paths instances, although seldom on their
 * own, usually as part of a bigger package. When a content type or field is
 * being exported, these settings come along for the ride.
 */
function filefield_paths_features_api() {
  return array(
    'filefield_paths' => array(
      'name' => t('FileField Paths'),
      'default_hook' => 'default_filefield_paths',
      'feature_source' => TRUE,
      'default_file' => FEATURES_DEFAULTS_INCLUDED_COMMON,
    ),
  );
}

/**
 * Implements hook_features_export_options().
 *
 * List all FileField Paths config settings currently available for export. This
 * adds each of the configurations to the features UI where they can be chosen
 * for bundling.
 *
 * This UI may be entirely unneccessary if we only ever export as a part of
 * something else (individual fields settings), but it's here for completeness.
 *
 * @return array A keyed array of items, suitable for use with a FormAPI select
 * or checkboxes element.
 */
function filefield_paths_features_export_options() {
  $options = array();
  $results = db_select('filefield_paths', 'f')
    ->fields('f', array('type', 'field'))
    ->execute();
  foreach ($results as $row) {
    // Generate the unique keys that can identify the row
    // "{entity_type}::{bundle}::{field_name}" eg "node::story::field_illustration"
    $key = "{$row->type}::{$row->field}";
    $options[$key] = $key;
  }
  return $options;
}

/**
 * Implements hook_features_export().
 *
 * Process the export array for a given component.
 *
 * Normally, we will be adding this as a child in the pipe of
 * field_features_export, so that when a filefield instance is exported, this
 * setting was published along with it.
 */
function filefield_paths_features_export($data, &$export, $module_name = '') {
  $export['dependencies']['filefield_paths'] = 'filefield_paths';

  $pipe = array();
  foreach ($data as $identifier) {
    if ($wrapper = filefield_paths_load($identifier)) {
      $export['features']['filefield_paths'][$identifier] = $identifier;
      if ($wrapper['filename']['transliterate'] || $wrapper['filepath']['transliterate']) {
        $export['dependencies']['transliteration'] = 'transliteration';
      }
      if ($wrapper['filename']['pathauto'] || $wrapper['filepath']['pathauto']) {
        $export['dependencies']['pathauto'] = 'pathauto';
      }
      if (module_exists('strongarm')) {
        $variable_map = features_get_default_map('variable');
        $pipe['variable'][] = "ffp_{$wrapper['type']}_{$wrapper['field']}";
      }
    }
  }
  return $pipe;
}

/**
 * Attach our own export routine as a piped export that happens below any
 * filefield path that is getting exported.
 *
 * The component name for fields is 'field'.
 *
 * HOOK_features_pipe_COMPONENT_alter()
 *
 * This captures each field export, and adds ourself to the dependencies and
 * exports when that field is exported.
 */
function filefield_paths_features_pipe_field_alter(&$pipe, $data, $export) {
  foreach ($data as $field_identifier) {

    // Convert field identifier to FileField Paths format.
    $field_identifier = str_replace('-', '::', $field_identifier);

    // Field export is exporting a field named $field_identifier.
    // If that is a filefield, we should attach ourselves as a subprocess (pipe).
    // .. actually, don't need to check the field type,
    // just see if we have some filefield_path
    // settings that use the same $field_identifier key!

    if (filefield_paths_load($field_identifier)) {
      // So add this setting as a piped child of the filed when it gets exported.
      $pipe['filefield_paths'][$field_identifier] = $field_identifier;
    }
  }
}

/**
 * Return the required path settings for the named filefield instance.
 *
 * A CRUD utility for filefield_paths
 *
 * @param a unique identifier for the given field instance -
 * {$entity_type::$bundle::$field}.
 *
 * @return a row array from the filefield_paths DB table - with the 'serialized'
 * blobs unpacked.
 */
function filefield_paths_load($identifier) {
  list($entity_type, $bundle, $field_name) = explode('::', $identifier);
  $result = db_select('filefield_paths', 'f')
    ->fields('f')
    ->condition('type', "{$entity_type}::{$bundle}")
    ->condition('field', $field_name)
    ->execute();
  if ($row = $result->fetchAssoc()) {
    $ffp = array();
    // Each cell in the row gets exposed, retrieve the schema to figure this out.
    $schema = drupal_get_schema('filefield_paths');
    foreach ($schema['fields'] as $field => $field_def) {
      $ffp[$field] = empty($field_def['serialize']) ? $row[$field] : unserialize($row[$field]);
    }
    return $ffp;
  }
  return NULL;
}

/**
 * Delete the identified row
 *
 * A CRUD utility for filefield_paths
 */
function filefield_paths_delete($identifier) {
  list($entity_type, $bundle, $field_name) = explode('::', $identifier);
  db_delete('filefield_paths')
    ->condition('type', "{$entity_type}::{$bundle}")
    ->condition('field', $field_name)
    ->execute();
}

/**
 * Implements hook_features_export_render()
 *
 * Return the PHP code that represents a dump of the settings listed as $data
 */
function filefield_paths_features_export_render($module, $data) {
  $code = array();
  $code[] = '  $settings = array();';
  $code[] = '';

  $translatables = array();
  foreach ($data as $item_id) {
    $item = filefield_paths_load($item_id);
    if (empty($item)) {
      watchdog('filefield_paths', "Failed to retrieve the filefield path settings '%item_id' while preparing the feature export code.", array('%item_id' => $item_id), WATCHDOG_WARNING);
      continue;
    }
    $code[] = "  // Exported {$item_id}";
    $export = features_var_export($item, '  ');
    $code[] = "  \$settings['{$item_id}'] = {$export};";
  }

  $code[] = '';
  $code[] = '  return $settings;';
  $code = implode("\n", $code);
  return array('default_filefield_paths' => $code);
}

/**
 * Implements hook_features_export_revert().
 */
function filefield_paths_features_revert($module) {
  filefield_paths_features_rebuild($module);
}

/**
 * Create/recreate the items based on the data array. Data should contain a
 * number of filefield_paths definitions.
 *
 * Implements hook_features_export_rebuild().
 *
 * Data just need to be put straight into the database as rows.
 */
function filefield_paths_features_rebuild($module) {
  if ($defaults = features_get_default('filefield_paths', $module)) {
    foreach ($defaults as $filefield_paths_id => $filefield_paths) {
      // Delete any previous settings for this item.
      if (filefield_paths_load($filefield_paths_id)) {
        filefield_paths_delete($filefield_paths_id);
      }
      drupal_write_record('filefield_paths', $filefield_paths);
    }
  }
}
