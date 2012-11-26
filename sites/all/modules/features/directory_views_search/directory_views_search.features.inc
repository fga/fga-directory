<?php
/**
 * @file
 * directory_views_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function directory_views_search_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
