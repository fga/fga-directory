<?php
/**
 * @file
 * occupy_directory_util.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function occupy_directory_util_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "features_plumber" && $api == "features_plumber_records") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
