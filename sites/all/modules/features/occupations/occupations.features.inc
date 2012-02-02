<?php
/**
 * @file
 * occupations.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function occupations_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function occupations_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implements hook_node_info().
 */
function occupations_node_info() {
  $items = array(
    'occupation' => array(
      'name' => t('Occupation'),
      'base' => 'node_content',
      'description' => t('Occupation. This content type is very much a work in progress. The current fields are 100% proof of concept.'),
      'has_title' => '1',
      'title_label' => t('Name of Occupation'),
      'help' => '',
    ),
  );
  return $items;
}
