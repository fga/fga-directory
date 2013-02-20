<?php
/**
 * @file
 * occupation_directory_structure.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function occupation_directory_structure_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'comment|comment_node_occupation|default';
  $ds_layout->entity_type = 'comment';
  $ds_layout->bundle = 'comment_node_occupation';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'links',
        1 => 'post_date',
        2 => 'author',
        3 => 'comment_body',
        4 => 'field_comment_state',
      ),
    ),
    'fields' => array(
      'links' => 'ds_content',
      'post_date' => 'ds_content',
      'author' => 'ds_content',
      'comment_body' => 'ds_content',
      'field_comment_state' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'section',
    'layout_attributes' => '',
    'layout_attributes_merge' => 0,
  );
  $export['comment|comment_node_occupation|default'] = $ds_layout;

  return $export;
}
