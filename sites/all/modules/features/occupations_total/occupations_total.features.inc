<?php
/**
 * @file
 * occupations_total.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function occupations_total_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function occupations_total_views_api() {
  return array("version" => "3.0");
}
