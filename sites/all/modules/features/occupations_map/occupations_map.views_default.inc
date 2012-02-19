<?php
/**
 * @file
 * occupations_map.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function occupations_map_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'map_displays';
  $view->description = 'Map views of occupations';
  $view->tag = 'FGA';
  $view->base_table = 'node';
  $view->human_name = 'Map Displays';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '1800';
  $handler->display->display_options['cache']['output_lifespan'] = '1800';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'openlayers_map';
  $handler->display->display_options['style_options']['map'] = 'occupation_map';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Occupation Map Page */
  $handler = $view->new_display('page', 'Occupation Map Page', 'page');
  $handler->display->display_options['path'] = 'map';
  $export['map_displays'] = $view;

  $view = new view;
  $view->name = 'occupation_map_data';
  $view->description = 'Map data of occuptations.';
  $view->tag = 'FGA';
  $view->base_table = 'node';
  $view->human_name = 'Occupation Map Data';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Occupations';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'openlayers_data';
  $handler->display->display_options['style_options']['data_source'] = array(
    'value' => 'wkt',
    'other_lat' => 'title',
    'other_lon' => 'title',
    'wkt' => 'field_occupation_geo',
    'other_top' => 'title',
    'other_right' => 'title',
    'other_bottom' => 'title',
    'other_left' => 'title',
    'name_field' => 'title',
    'description_field' => 'body',
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '300',
  );
  $handler->display->display_options['fields']['body']['field_api_classes'] = 0;
  /* Field: Content: Geofield */
  $handler->display->display_options['fields']['field_occupation_geo']['id'] = 'field_occupation_geo';
  $handler->display->display_options['fields']['field_occupation_geo']['table'] = 'field_data_field_occupation_geo';
  $handler->display->display_options['fields']['field_occupation_geo']['field'] = 'field_occupation_geo';
  $handler->display->display_options['fields']['field_occupation_geo']['label'] = '';
  $handler->display->display_options['fields']['field_occupation_geo']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_occupation_geo']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_occupation_geo']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_occupation_geo']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_occupation_geo']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_occupation_geo']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_occupation_geo']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_occupation_geo']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_occupation_geo']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_occupation_geo']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_occupation_geo']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_occupation_geo']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_occupation_geo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_occupation_geo']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_occupation_geo']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_occupation_geo']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_occupation_geo']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_occupation_geo']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_occupation_geo']['settings'] = array(
    'data' => 'full',
  );
  $handler->display->display_options['fields']['field_occupation_geo']['field_api_classes'] = 0;
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'occupation' => 'occupation',
  );
  /* Filter criterion: Content: Geofield (field_occupation_geo:wkt) */
  $handler->display->display_options['filters']['field_occupation_geo_wkt']['id'] = 'field_occupation_geo_wkt';
  $handler->display->display_options['filters']['field_occupation_geo_wkt']['table'] = 'field_data_field_occupation_geo';
  $handler->display->display_options['filters']['field_occupation_geo_wkt']['field'] = 'field_occupation_geo_wkt';
  $handler->display->display_options['filters']['field_occupation_geo_wkt']['operator'] = 'not empty';

  /* Display: Occupation OpenLayers Data Overlay */
  $handler = $view->new_display('openlayers', 'Occupation OpenLayers Data Overlay', 'openlayers_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $export['occupation_map_data'] = $view;

  return $export;
}
