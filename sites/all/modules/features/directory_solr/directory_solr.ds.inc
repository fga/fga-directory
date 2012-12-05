<?php
/**
 * @file
 * directory_solr.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function directory_solr_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'ds_views|directory_global_search-search_page|default';
  $ds_fieldsetting->entity_type = 'ds_views';
  $ds_fieldsetting->bundle = 'directory_global_search-search_page';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'header' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'exposed' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'attachment_before' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'rows' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'empty' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'pager' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'attachment_after' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'footer' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['ds_views|directory_global_search-search_page|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function directory_solr_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'ds_views|directory_global_search-search_page|default';
  $ds_layout->entity_type = 'ds_views';
  $ds_layout->bundle = 'directory_global_search-search_page';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'attachment_before',
        1 => 'exposed',
        2 => 'header',
        3 => 'empty',
        4 => 'rows',
        5 => 'pager',
        6 => 'footer',
        7 => 'attachment_after',
      ),
    ),
    'fields' => array(
      'attachment_before' => 'ds_content',
      'exposed' => 'ds_content',
      'header' => 'ds_content',
      'empty' => 'ds_content',
      'rows' => 'ds_content',
      'pager' => 'ds_content',
      'footer' => 'ds_content',
      'attachment_after' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 0,
    'hide_page_title' => '0',
    'page_option_title' => '',
  );
  $export['ds_views|directory_global_search-search_page|default'] = $ds_layout;

  return $export;
}
