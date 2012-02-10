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
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
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
 * Implements hook_image_default_styles().
 */
function occupations_image_default_styles() {
  $styles = array();

  // Exported image style: occupation_thumb_sm
  $styles['occupation_thumb_sm'] = array(
    'name' => 'occupation_thumb_sm',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '50',
          'height' => '50',
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function occupations_node_info() {
  $items = array(
    'occupation' => array(
      'name' => t('Occupation'),
      'base' => 'node_content',
      'description' => t('An occupation is a multi-field, geo-coded entity, with taxonomies and publishing workflows.'),
      'has_title' => '1',
      'title_label' => t('Name of Occupation'),
      'help' => t('<p><strong>Occupations</strong> in this context are defined as geographically based. Organizations that don\'t hold physical space, like <em>Occupy the Environment</em>, or organizations in solidarity to the movement, like <em>Occupy Air Force</em>, will be considered in their own right after the initial directory is up and running. We will also soon be adding listings for broader geographies, like state and country-wide "occupations."</p>

<p>Further down the line, we will be incorporating <em>groups</em> also. That\'s big. That\'s awesome. BUT –– that\'s the future (not the present; please don\'t submit your group yet)!</p>'),
    ),
  );
  return $items;
}
