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
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
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

  /* Display: Occupations Mapbox Page */
  $handler = $view->new_display('page', 'Occupations Mapbox Page', 'page_mapbox');
  $handler->display->display_options['display_description'] = 'map of the world leveraging mapbox';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'openlayers_map';
  $handler->display->display_options['style_options']['map'] = 'occupations_mapbox';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['path'] = 'mapbox';
  $export['map_displays'] = $view;

  $view = new view;
  $view->name = 'occupation_map_data';
  $view->description = 'Map data of occuptations';
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
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
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
  /* Relationship: File Usage: File */
  $handler->display->display_options['relationships']['node_to_file']['id'] = 'node_to_file';
  $handler->display->display_options['relationships']['node_to_file']['table'] = 'file_usage';
  $handler->display->display_options['relationships']['node_to_file']['field'] = 'node_to_file';
  $handler->display->display_options['relationships']['node_to_file']['required'] = 0;
  /* Field: Content: Occupation Image or Icon */
  $handler->display->display_options['fields']['field_occupation_image']['id'] = 'field_occupation_image';
  $handler->display->display_options['fields']['field_occupation_image']['table'] = 'field_data_field_occupation_image';
  $handler->display->display_options['fields']['field_occupation_image']['field'] = 'field_occupation_image';
  $handler->display->display_options['fields']['field_occupation_image']['label'] = '';
  $handler->display->display_options['fields']['field_occupation_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_occupation_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_occupation_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_occupation_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_occupation_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_occupation_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_occupation_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_occupation_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_occupation_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_occupation_image']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_occupation_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_occupation_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_occupation_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_occupation_image']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_occupation_image']['element_class'] = 'o-image, clearfix';
  $handler->display->display_options['fields']['field_occupation_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_occupation_image']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_occupation_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_occupation_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_occupation_image']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_occupation_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_occupation_image']['settings'] = array(
    'image_style' => 'occupation_thumb_sm',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_occupation_image']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_class'] = 'o-name';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
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
  /* Field: Content: Founded */
  $handler->display->display_options['fields']['field_occupation_origin_date']['id'] = 'field_occupation_origin_date';
  $handler->display->display_options['fields']['field_occupation_origin_date']['table'] = 'field_data_field_occupation_origin_date';
  $handler->display->display_options['fields']['field_occupation_origin_date']['field'] = 'field_occupation_origin_date';
  $handler->display->display_options['fields']['field_occupation_origin_date']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_occupation_origin_date']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_occupation_origin_date']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_occupation_origin_date']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_occupation_origin_date']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_occupation_origin_date']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_occupation_origin_date']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_occupation_origin_date']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_occupation_origin_date']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_occupation_origin_date']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_occupation_origin_date']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_occupation_origin_date']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_occupation_origin_date']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_occupation_origin_date']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_occupation_origin_date']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_occupation_origin_date']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_occupation_origin_date']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_occupation_origin_date']['settings'] = array(
    'format_type' => 'date_short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_occupation_origin_date']['field_api_classes'] = 0;
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

  /* Display: Occupations OpenLayers Data Overlay */
  $handler = $view->new_display('openlayers', 'Occupations OpenLayers Data Overlay', 'openlayers_1');
  $handler->display->display_options['display_description'] = 'Occupations generated in OL Data format';
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';

  /* Display: geojson data overlay */
  $handler = $view->new_display('page', 'geojson data overlay', 'occupations_geojson');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Occupations geojson data';
  $handler->display->display_options['display_description'] = 'views_geojson generated json of occupation for OL';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_geojson';
  $handler->display->display_options['style_options']['data_source']['value'] = 'geofield';
  $handler->display->display_options['style_options']['data_source']['latitude'] = 'field_occupation_geo';
  $handler->display->display_options['style_options']['data_source']['longitude'] = 'field_occupation_geo';
  $handler->display->display_options['style_options']['data_source']['bbox_top'] = 'field_occupation_image';
  $handler->display->display_options['style_options']['data_source']['bbox_right'] = 'field_occupation_image';
  $handler->display->display_options['style_options']['data_source']['bbox_bottom'] = 'field_occupation_image';
  $handler->display->display_options['style_options']['data_source']['bbox_left'] = 'field_occupation_image';
  $handler->display->display_options['style_options']['data_source']['name_field'] = 'nothing';
  $handler->display->display_options['style_options']['data_source']['description_field'] = '';
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Occupation Image or Icon */
  $handler->display->display_options['fields']['field_occupation_image']['id'] = 'field_occupation_image';
  $handler->display->display_options['fields']['field_occupation_image']['table'] = 'field_data_field_occupation_image';
  $handler->display->display_options['fields']['field_occupation_image']['field'] = 'field_occupation_image';
  $handler->display->display_options['fields']['field_occupation_image']['label'] = '';
  $handler->display->display_options['fields']['field_occupation_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_occupation_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_occupation_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_occupation_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_occupation_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_occupation_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_occupation_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_occupation_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_occupation_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_occupation_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_occupation_image']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_occupation_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_occupation_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_occupation_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_occupation_image']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_occupation_image']['element_class'] = 'o-image, clearfix';
  $handler->display->display_options['fields']['field_occupation_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_occupation_image']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_occupation_image']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_occupation_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_occupation_image']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_occupation_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_occupation_image']['settings'] = array(
    'image_style' => 'occupation_thumb_sm',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_occupation_image']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<h3 class="o-image">[title]</h3>';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_class'] = 'o-name';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Founded */
  $handler->display->display_options['fields']['field_occupation_origin_date']['id'] = 'field_occupation_origin_date';
  $handler->display->display_options['fields']['field_occupation_origin_date']['table'] = 'field_data_field_occupation_origin_date';
  $handler->display->display_options['fields']['field_occupation_origin_date']['field'] = 'field_occupation_origin_date';
  $handler->display->display_options['fields']['field_occupation_origin_date']['label'] = '';
  $handler->display->display_options['fields']['field_occupation_origin_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_occupation_origin_date']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_occupation_origin_date']['alter']['text'] = '<span class="bday"><span class="label">founded:</span>&nbsp;[field_occupation_origin_date]</span>';
  $handler->display->display_options['fields']['field_occupation_origin_date']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_occupation_origin_date']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_occupation_origin_date']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_occupation_origin_date']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_occupation_origin_date']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_occupation_origin_date']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_occupation_origin_date']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_occupation_origin_date']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_occupation_origin_date']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_occupation_origin_date']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_occupation_origin_date']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_occupation_origin_date']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_occupation_origin_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_occupation_origin_date']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_occupation_origin_date']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_occupation_origin_date']['empty'] = '&nbsp;';
  $handler->display->display_options['fields']['field_occupation_origin_date']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_occupation_origin_date']['empty_zero'] = 1;
  $handler->display->display_options['fields']['field_occupation_origin_date']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_occupation_origin_date']['type'] = 'date_plain';
  $handler->display->display_options['fields']['field_occupation_origin_date']['settings'] = array(
    'format_type' => 'date_short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_occupation_origin_date']['field_api_classes'] = 0;
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
  $handler->display->display_options['fields']['field_occupation_geo']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_occupation_geo']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_occupation_geo']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_occupation_geo']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_occupation_geo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_occupation_geo']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_occupation_geo']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_occupation_geo']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_occupation_geo']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_occupation_geo']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_occupation_geo']['type'] = 'geofield_geojson';
  $handler->display->display_options['fields']['field_occupation_geo']['settings'] = array(
    'data' => 'full',
  );
  $handler->display->display_options['fields']['field_occupation_geo']['field_api_classes'] = 0;
  /* Field: description */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'description';
  $handler->display->display_options['fields']['nothing']['label'] = 'description';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_occupation_image]<h3 class="o-name">[title]</h3>[field_occupation_origin_date]';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = 0;
  $handler->display->display_options['path'] = 'v1/occupations/occupy-directory.geojson';

  /* Display: geojson - Tilemill */
  $handler = $view->new_display('page', 'geojson - Tilemill', 'occupations_geojson_tilemill');
  $handler->display->display_options['display_description'] = 'All Occupation for use in Tilemill';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_geojson';
  $handler->display->display_options['style_options']['data_source']['value'] = 'geofield';
  $handler->display->display_options['style_options']['data_source']['latitude'] = 'field_occupation_image';
  $handler->display->display_options['style_options']['data_source']['longitude'] = 'field_occupation_image';
  $handler->display->display_options['style_options']['data_source']['bbox_top'] = 'field_occupation_image';
  $handler->display->display_options['style_options']['data_source']['bbox_right'] = 'field_occupation_image';
  $handler->display->display_options['style_options']['data_source']['bbox_bottom'] = 'field_occupation_image';
  $handler->display->display_options['style_options']['data_source']['bbox_left'] = 'field_occupation_image';
  $handler->display->display_options['style_options']['data_source']['name_field'] = 'title';
  $handler->display->display_options['style_options']['data_source']['description_field'] = '';
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
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
  /* Field: Content: Founded */
  $handler->display->display_options['fields']['field_occupation_origin_date']['id'] = 'field_occupation_origin_date';
  $handler->display->display_options['fields']['field_occupation_origin_date']['table'] = 'field_data_field_occupation_origin_date';
  $handler->display->display_options['fields']['field_occupation_origin_date']['field'] = 'field_occupation_origin_date';
  $handler->display->display_options['fields']['field_occupation_origin_date']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_occupation_origin_date']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_occupation_origin_date']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_occupation_origin_date']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_occupation_origin_date']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_occupation_origin_date']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_occupation_origin_date']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_occupation_origin_date']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_occupation_origin_date']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_occupation_origin_date']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_occupation_origin_date']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_occupation_origin_date']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_occupation_origin_date']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_occupation_origin_date']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_occupation_origin_date']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_occupation_origin_date']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_occupation_origin_date']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_occupation_origin_date']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_occupation_origin_date']['type'] = 'date_plain';
  $handler->display->display_options['fields']['field_occupation_origin_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_occupation_origin_date']['field_api_classes'] = 0;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = 'occupation_url';
  $handler->display->display_options['fields']['path']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['path']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['path']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['path']['alter']['external'] = 0;
  $handler->display->display_options['fields']['path']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['path']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['path']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['path']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['path']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['path']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['path']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['path']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['path']['alter']['html'] = 0;
  $handler->display->display_options['fields']['path']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['path']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['path']['hide_empty'] = 1;
  $handler->display->display_options['fields']['path']['empty_zero'] = 0;
  $handler->display->display_options['fields']['path']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['path']['absolute'] = 1;
  /* Field: Content: Occupation Image or Icon */
  $handler->display->display_options['fields']['field_occupation_image']['id'] = 'field_occupation_image';
  $handler->display->display_options['fields']['field_occupation_image']['table'] = 'field_data_field_occupation_image';
  $handler->display->display_options['fields']['field_occupation_image']['field'] = 'field_occupation_image';
  $handler->display->display_options['fields']['field_occupation_image']['label'] = 'Occupation Image';
  $handler->display->display_options['fields']['field_occupation_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_occupation_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_occupation_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_occupation_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_occupation_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_occupation_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_occupation_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_occupation_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_occupation_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_occupation_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_occupation_image']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_occupation_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_occupation_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_occupation_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_occupation_image']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_occupation_image']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_occupation_image']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_occupation_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_occupation_image']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_occupation_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_occupation_image']['settings'] = array(
    'image_style' => 'occupation_thumb_sm',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_occupation_image']['field_api_classes'] = 0;
  /* Field: File: Path */
  $handler->display->display_options['fields']['uri']['id'] = 'uri';
  $handler->display->display_options['fields']['uri']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uri']['field'] = 'uri';
  $handler->display->display_options['fields']['uri']['relationship'] = 'node_to_file';
  $handler->display->display_options['fields']['uri']['label'] = 'Occupation Image';
  $handler->display->display_options['fields']['uri']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['uri']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['uri']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['uri']['alter']['external'] = 0;
  $handler->display->display_options['fields']['uri']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['uri']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['uri']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['uri']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['uri']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['uri']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['uri']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['uri']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['uri']['alter']['html'] = 0;
  $handler->display->display_options['fields']['uri']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['uri']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['uri']['hide_empty'] = 1;
  $handler->display->display_options['fields']['uri']['empty_zero'] = 0;
  $handler->display->display_options['fields']['uri']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['uri']['link_to_file'] = 0;
  $handler->display->display_options['fields']['uri']['file_download_path'] = 1;
  $handler->display->display_options['path'] = 'v1/occupations/occupy-directory-tilemill.geojson';
  $export['occupation_map_data'] = $view;

  return $export;
}
