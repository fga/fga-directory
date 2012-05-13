<?php
/**
 * @file
 * occupations_administration.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function occupations_administration_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "features_plumber" && $api == "features_plumber_records") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function occupations_administration_views_api() {
  return array("version" => "3.0");
}
