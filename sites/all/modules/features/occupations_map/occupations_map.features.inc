<?php
/**
 * @file
 * occupations_map.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function occupations_map_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "delta" && $api == "delta") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "openlayers" && $api == "openlayers_layers") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "openlayers" && $api == "openlayers_maps") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function occupations_map_views_api() {
  return array("version" => "3.0");
}
