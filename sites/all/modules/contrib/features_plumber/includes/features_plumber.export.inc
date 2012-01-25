<?php

/**
 * @file
 * Features Plumber features export functions.
 */

/**
 * Helper to features_plumber_features_export_alter().
 */
function _features_plumber_features_export_alter(&$export, $module_name) {
  $cleanup = array();
  features_plumber_include('crud');
  foreach (features_plumber_records_load_by_feature($module_name) as $record) {
    // If this is a depencency, we need a different part of the $export array.
    if ($record->component == 'dependencies') {
      $array = &$export['dependencies'];
    }
    elseif (isset($export['features'][$record->component])) {
      $array = &$export['features'][$record->component];
    }
    else {
      continue;
    }

    if (isset($array[$record->component_val])) {
      unset($array[$record->component_val]);
      $cleanup[$record->component] = TRUE;
      if (variable_get('features_plumber_export_records', TRUE)) {
        $export['features']['features_plumber'][$record->name] = $record->name;
      }
    }
  }

  if (!isset($export['features']['features_plumber'])) {
    $cleanup['features_plumber'] = TRUE;
  }
  // Make sure these guys are here.
  else {
    $export['dependencies']['features_plumber'] = 'features_plumber';
    ctools_features_export(array('features_plumber'), $export, $module_name);
  }

  foreach (array_keys($cleanup) as $component) {
    $function = "features_plumber_export_{$component}_cleanup";
    if (function_exists($function)) {
      $function($export, $module_name);
    }
  }
}

/**
 * Cleanup after Views removals.
 */
function features_plumber_export_views_cleanup(&$export) {
  if (empty($export['features']['views'])) {
    // @TODO: Clean up other detected dependencies.
    unset($export['features']['views'], $export['features']['views_api'], $export['dependencies']['views']);
  }
}

/**
 * Cleanup after Features Plumber removal.
 */
function features_plumber_export_context_cleanup(&$export) {
  _features_plumber_export_ctools_cleanup('context', $export);
}

/**
 * Cleanup after Features Plumber removal.
 */
function features_plumber_export_variable_cleanup(&$export) {
  _features_plumber_export_ctools_cleanup('variable', $export);
}

/**
 * Cleanup after Features Plumber removal.
 */
function features_plumber_export_box_cleanup(&$export) {
  _features_plumber_export_ctools_cleanup('box', $export);
}

/**
 * Cleanup after Features Plumber removal.
 */
function features_plumber_export_features_plumber_cleanup(&$export) {
  _features_plumber_export_ctools_cleanup('features_plumber', $export);
}

/**
 * Helper to clean up after all CTools implementing modules.
 */
function _features_plumber_export_ctools_cleanup($component, &$export) {
  if (empty($export['features'][$component])) {
    $info = _ctools_features_get_info($component);
    $identifier = "{$info['module']}:{$info['api']}:{$info['current_version']}";
    unset($export['dependencies'][$info['module']],
      $export['features']['ctools'][$identifier]);
  }
}
