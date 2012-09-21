<?php
/**
 * @file
 * occupations_import_export.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function occupations_import_export_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'occupation_exports_and_data';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Occupation Exports and Data';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Occupation Directory';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_occupation_image' => 'field_occupation_image',
    'title' => 'title',
    'edit_node' => 'edit_node',
    'field_occupation_address' => 'field_occupation_address',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'field_occupation_image' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_occupation_address' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: File Usage: File */
  $handler->display->display_options['relationships']['node_to_file']['id'] = 'node_to_file';
  $handler->display->display_options['relationships']['node_to_file']['table'] = 'file_usage';
  $handler->display->display_options['relationships']['node_to_file']['field'] = 'node_to_file';
  /* Field: Content: Occupation Image or Icon */
  $handler->display->display_options['fields']['field_occupation_image']['id'] = 'field_occupation_image';
  $handler->display->display_options['fields']['field_occupation_image']['table'] = 'field_data_field_occupation_image';
  $handler->display->display_options['fields']['field_occupation_image']['field'] = 'field_occupation_image';
  $handler->display->display_options['fields']['field_occupation_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_occupation_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Location (Address) */
  $handler->display->display_options['fields']['field_occupation_address']['id'] = 'field_occupation_address';
  $handler->display->display_options['fields']['field_occupation_address']['table'] = 'field_data_field_occupation_address';
  $handler->display->display_options['fields']['field_occupation_address']['field'] = 'field_occupation_address';
  $handler->display->display_options['fields']['field_occupation_address']['label'] = 'City';
  $handler->display->display_options['fields']['field_occupation_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_occupation_address']['type'] = 'locality';
  $handler->display->display_options['fields']['field_occupation_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'occupation' => 'occupation',
  );

  /* Display: CSV Download */
  $handler = $view->new_display('views_data_export', 'CSV Download', 'views_data_export_csv');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Occupy Directory in CSV format';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    5 => '5',
    4 => '4',
    3 => '3',
  );
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'directory_%timestamp-yyyy-%timestamp-mm-%timestamp-dd.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 1;
  $handler->display->display_options['style_options']['replace_newlines'] = 1;
  $handler->display->display_options['style_options']['newline_replacement'] = '<br>';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Node UUID */
  $handler->display->display_options['fields']['uuid']['id'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['table'] = 'node';
  $handler->display->display_options['fields']['uuid']['field'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['label'] = 'id';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Founded */
  $handler->display->display_options['fields']['field_occupation_origin_date']['id'] = 'field_occupation_origin_date';
  $handler->display->display_options['fields']['field_occupation_origin_date']['table'] = 'field_data_field_occupation_origin_date';
  $handler->display->display_options['fields']['field_occupation_origin_date']['field'] = 'field_occupation_origin_date';
  $handler->display->display_options['fields']['field_occupation_origin_date']['settings'] = array(
    'format_type' => 'date_short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Founded */
  $handler->display->display_options['fields']['field_occupation_origin_date_1']['id'] = 'field_occupation_origin_date_1';
  $handler->display->display_options['fields']['field_occupation_origin_date_1']['table'] = 'field_data_field_occupation_origin_date';
  $handler->display->display_options['fields']['field_occupation_origin_date_1']['field'] = 'field_occupation_origin_date';
  $handler->display->display_options['fields']['field_occupation_origin_date_1']['label'] = 'Founded-longdate';
  $handler->display->display_options['fields']['field_occupation_origin_date_1']['settings'] = array(
    'format_type' => 'date_long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: General email address */
  $handler->display->display_options['fields']['field_occupation_email_general']['id'] = 'field_occupation_email_general';
  $handler->display->display_options['fields']['field_occupation_email_general']['table'] = 'field_data_field_occupation_email_general';
  $handler->display->display_options['fields']['field_occupation_email_general']['field'] = 'field_occupation_email_general';
  $handler->display->display_options['fields']['field_occupation_email_general']['type'] = 'email_plain';
  /* Field: Content: General phone */
  $handler->display->display_options['fields']['field_occupation_phone_general']['id'] = 'field_occupation_phone_general';
  $handler->display->display_options['fields']['field_occupation_phone_general']['table'] = 'field_data_field_occupation_phone_general';
  $handler->display->display_options['fields']['field_occupation_phone_general']['field'] = 'field_occupation_phone_general';
  /* Field: Content: Location (Address) */
  $handler->display->display_options['fields']['field_occupation_address_9']['id'] = 'field_occupation_address_9';
  $handler->display->display_options['fields']['field_occupation_address_9']['table'] = 'field_data_field_occupation_address';
  $handler->display->display_options['fields']['field_occupation_address_9']['field'] = 'field_occupation_address';
  $handler->display->display_options['fields']['field_occupation_address_9']['label'] = 'Location Name';
  $handler->display->display_options['fields']['field_occupation_address_9']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_occupation_address_9']['alter']['text'] = '[field_occupation_address_9]';
  $handler->display->display_options['fields']['field_occupation_address_9']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_occupation_address_9']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_occupation_address_9']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_occupation_address_9']['type'] = 'name_line';
  $handler->display->display_options['fields']['field_occupation_address_9']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Location';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_occupation_address_1][field_occupation_address_2][field_occupation_address_3][field_occupation_address_4][field_occupation_address_5][field_occupation_address_6][field_occupation_address_7][field_occupation_address_8][field_occupation_address_9]';
  /* Field: Content: Location (Address) */
  $handler->display->display_options['fields']['field_occupation_address_1']['id'] = 'field_occupation_address_1';
  $handler->display->display_options['fields']['field_occupation_address_1']['table'] = 'field_data_field_occupation_address';
  $handler->display->display_options['fields']['field_occupation_address_1']['field'] = 'field_occupation_address';
  $handler->display->display_options['fields']['field_occupation_address_1']['label'] = 'Address 1';
  $handler->display->display_options['fields']['field_occupation_address_1']['alter']['text'] = '[field_occupation_address_1]';
  $handler->display->display_options['fields']['field_occupation_address_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_occupation_address_1']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_occupation_address_1']['type'] = 'thoroughfare';
  $handler->display->display_options['fields']['field_occupation_address_1']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Content: Location (Address) */
  $handler->display->display_options['fields']['field_occupation_address_2']['id'] = 'field_occupation_address_2';
  $handler->display->display_options['fields']['field_occupation_address_2']['table'] = 'field_data_field_occupation_address';
  $handler->display->display_options['fields']['field_occupation_address_2']['field'] = 'field_occupation_address';
  $handler->display->display_options['fields']['field_occupation_address_2']['label'] = 'Address 2';
  $handler->display->display_options['fields']['field_occupation_address_2']['alter']['text'] = '[field_occupation_address_2]';
  $handler->display->display_options['fields']['field_occupation_address_2']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_occupation_address_2']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_occupation_address_2']['type'] = 'premise';
  $handler->display->display_options['fields']['field_occupation_address_2']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Content: Location (Address) */
  $handler->display->display_options['fields']['field_occupation_address_3']['id'] = 'field_occupation_address_3';
  $handler->display->display_options['fields']['field_occupation_address_3']['table'] = 'field_data_field_occupation_address';
  $handler->display->display_options['fields']['field_occupation_address_3']['field'] = 'field_occupation_address';
  $handler->display->display_options['fields']['field_occupation_address_3']['label'] = 'City';
  $handler->display->display_options['fields']['field_occupation_address_3']['alter']['text'] = '[field_occupation_address_3]';
  $handler->display->display_options['fields']['field_occupation_address_3']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_occupation_address_3']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_occupation_address_3']['type'] = 'locality';
  $handler->display->display_options['fields']['field_occupation_address_3']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Content: Location (Address) */
  $handler->display->display_options['fields']['field_occupation_address_8']['id'] = 'field_occupation_address_8';
  $handler->display->display_options['fields']['field_occupation_address_8']['table'] = 'field_data_field_occupation_address';
  $handler->display->display_options['fields']['field_occupation_address_8']['field'] = 'field_occupation_address';
  $handler->display->display_options['fields']['field_occupation_address_8']['label'] = 'City_sub';
  $handler->display->display_options['fields']['field_occupation_address_8']['alter']['text'] = '[field_occupation_address_8]';
  $handler->display->display_options['fields']['field_occupation_address_8']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_occupation_address_8']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_occupation_address_8']['type'] = 'dependent_locality';
  $handler->display->display_options['fields']['field_occupation_address_8']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Content: Location (Address) */
  $handler->display->display_options['fields']['field_occupation_address_4']['id'] = 'field_occupation_address_4';
  $handler->display->display_options['fields']['field_occupation_address_4']['table'] = 'field_data_field_occupation_address';
  $handler->display->display_options['fields']['field_occupation_address_4']['field'] = 'field_occupation_address';
  $handler->display->display_options['fields']['field_occupation_address_4']['label'] = 'State';
  $handler->display->display_options['fields']['field_occupation_address_4']['alter']['text'] = '[field_occupation_address_4]';
  $handler->display->display_options['fields']['field_occupation_address_4']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_occupation_address_4']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_occupation_address_4']['type'] = 'administrative_area';
  $handler->display->display_options['fields']['field_occupation_address_4']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Content: Location (Address) */
  $handler->display->display_options['fields']['field_occupation_address_7']['id'] = 'field_occupation_address_7';
  $handler->display->display_options['fields']['field_occupation_address_7']['table'] = 'field_data_field_occupation_address';
  $handler->display->display_options['fields']['field_occupation_address_7']['field'] = 'field_occupation_address';
  $handler->display->display_options['fields']['field_occupation_address_7']['label'] = 'State_sub';
  $handler->display->display_options['fields']['field_occupation_address_7']['alter']['text'] = '[field_occupation_address_7]';
  $handler->display->display_options['fields']['field_occupation_address_7']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_occupation_address_7']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_occupation_address_7']['type'] = 'sub_administrative_area';
  $handler->display->display_options['fields']['field_occupation_address_7']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Content: Location (Address) */
  $handler->display->display_options['fields']['field_occupation_address_6']['id'] = 'field_occupation_address_6';
  $handler->display->display_options['fields']['field_occupation_address_6']['table'] = 'field_data_field_occupation_address';
  $handler->display->display_options['fields']['field_occupation_address_6']['field'] = 'field_occupation_address';
  $handler->display->display_options['fields']['field_occupation_address_6']['label'] = 'Country';
  $handler->display->display_options['fields']['field_occupation_address_6']['alter']['text'] = '[field_occupation_address_6]';
  $handler->display->display_options['fields']['field_occupation_address_6']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_occupation_address_6']['type'] = 'country';
  $handler->display->display_options['fields']['field_occupation_address_6']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Content: Location (Address) */
  $handler->display->display_options['fields']['field_occupation_address_5']['id'] = 'field_occupation_address_5';
  $handler->display->display_options['fields']['field_occupation_address_5']['table'] = 'field_data_field_occupation_address';
  $handler->display->display_options['fields']['field_occupation_address_5']['field'] = 'field_occupation_address';
  $handler->display->display_options['fields']['field_occupation_address_5']['label'] = 'zip-postal';
  $handler->display->display_options['fields']['field_occupation_address_5']['alter']['text'] = '[field_occupation_address_5]';
  $handler->display->display_options['fields']['field_occupation_address_5']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_occupation_address_5']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_occupation_address_5']['type'] = 'postal_code';
  $handler->display->display_options['fields']['field_occupation_address_5']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Content: Geofield */
  $handler->display->display_options['fields']['field_occupation_geo']['id'] = 'field_occupation_geo';
  $handler->display->display_options['fields']['field_occupation_geo']['table'] = 'field_data_field_occupation_geo';
  $handler->display->display_options['fields']['field_occupation_geo']['field'] = 'field_occupation_geo';
  $handler->display->display_options['fields']['field_occupation_geo']['label'] = 'Latitude';
  $handler->display->display_options['fields']['field_occupation_geo']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_occupation_geo']['type'] = 'geofield_lat';
  $handler->display->display_options['fields']['field_occupation_geo']['settings'] = array(
    'data' => 'full',
    'format' => 'decimal_degrees',
  );
  /* Field: Content: Geofield */
  $handler->display->display_options['fields']['field_occupation_geo_1']['id'] = 'field_occupation_geo_1';
  $handler->display->display_options['fields']['field_occupation_geo_1']['table'] = 'field_data_field_occupation_geo';
  $handler->display->display_options['fields']['field_occupation_geo_1']['field'] = 'field_occupation_geo';
  $handler->display->display_options['fields']['field_occupation_geo_1']['label'] = 'Longitude';
  $handler->display->display_options['fields']['field_occupation_geo_1']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_occupation_geo_1']['type'] = 'geofield_lon';
  $handler->display->display_options['fields']['field_occupation_geo_1']['settings'] = array(
    'data' => 'full',
    'format' => 'decimal_degrees',
  );
  /* Field: Content: Occupation description */
  $handler->display->display_options['fields']['field_occupation_description']['id'] = 'field_occupation_description';
  $handler->display->display_options['fields']['field_occupation_description']['table'] = 'field_data_field_occupation_description';
  $handler->display->display_options['fields']['field_occupation_description']['field'] = 'field_occupation_description';
  $handler->display->display_options['fields']['field_occupation_description']['alter']['strip_tags'] = TRUE;
  /* Field: Content: General Assembly */
  $handler->display->display_options['fields']['field_occupation_general_info']['id'] = 'field_occupation_general_info';
  $handler->display->display_options['fields']['field_occupation_general_info']['table'] = 'field_data_field_occupation_general_info';
  $handler->display->display_options['fields']['field_occupation_general_info']['field'] = 'field_occupation_general_info';
  /* Field: Content: Donate Information */
  $handler->display->display_options['fields']['field_occupation_dontate_info']['id'] = 'field_occupation_dontate_info';
  $handler->display->display_options['fields']['field_occupation_dontate_info']['table'] = 'field_data_field_occupation_dontate_info';
  $handler->display->display_options['fields']['field_occupation_dontate_info']['field'] = 'field_occupation_dontate_info';
  $handler->display->display_options['fields']['field_occupation_dontate_info']['alter']['strip_tags'] = TRUE;
  /* Field: Content: Occupation website */
  $handler->display->display_options['fields']['field_occupation_website']['id'] = 'field_occupation_website';
  $handler->display->display_options['fields']['field_occupation_website']['table'] = 'field_data_field_occupation_website';
  $handler->display->display_options['fields']['field_occupation_website']['field'] = 'field_occupation_website';
  $handler->display->display_options['fields']['field_occupation_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_website']['type'] = 'link_plain';
  /* Field: Content: Additional Occupation websites */
  $handler->display->display_options['fields']['field_occupation_other_websites']['id'] = 'field_occupation_other_websites';
  $handler->display->display_options['fields']['field_occupation_other_websites']['table'] = 'field_data_field_occupation_other_websites';
  $handler->display->display_options['fields']['field_occupation_other_websites']['field'] = 'field_occupation_other_websites';
  $handler->display->display_options['fields']['field_occupation_other_websites']['label'] = 'occupation_websites_extra1';
  $handler->display->display_options['fields']['field_occupation_other_websites']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_occupation_other_websites']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_occupation_other_websites']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_other_websites']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_occupation_other_websites']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_occupation_other_websites']['delta_offset'] = '0';
  /* Field: Content: Additional Occupation websites */
  $handler->display->display_options['fields']['field_occupation_other_websites_1']['id'] = 'field_occupation_other_websites_1';
  $handler->display->display_options['fields']['field_occupation_other_websites_1']['table'] = 'field_data_field_occupation_other_websites';
  $handler->display->display_options['fields']['field_occupation_other_websites_1']['field'] = 'field_occupation_other_websites';
  $handler->display->display_options['fields']['field_occupation_other_websites_1']['label'] = 'occupation_websites_extra2';
  $handler->display->display_options['fields']['field_occupation_other_websites_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_other_websites_1']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_occupation_other_websites_1']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_occupation_other_websites_1']['delta_offset'] = '1';
  /* Field: Content: Additional Occupation websites */
  $handler->display->display_options['fields']['field_occupation_other_websites_2']['id'] = 'field_occupation_other_websites_2';
  $handler->display->display_options['fields']['field_occupation_other_websites_2']['table'] = 'field_data_field_occupation_other_websites';
  $handler->display->display_options['fields']['field_occupation_other_websites_2']['field'] = 'field_occupation_other_websites';
  $handler->display->display_options['fields']['field_occupation_other_websites_2']['label'] = 'occupation_websites_extra3';
  $handler->display->display_options['fields']['field_occupation_other_websites_2']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_other_websites_2']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_occupation_other_websites_2']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_occupation_other_websites_2']['delta_offset'] = '2';
  /* Field: Content: Additional Occupation websites */
  $handler->display->display_options['fields']['field_occupation_other_websites_3']['id'] = 'field_occupation_other_websites_3';
  $handler->display->display_options['fields']['field_occupation_other_websites_3']['table'] = 'field_data_field_occupation_other_websites';
  $handler->display->display_options['fields']['field_occupation_other_websites_3']['field'] = 'field_occupation_other_websites';
  $handler->display->display_options['fields']['field_occupation_other_websites_3']['label'] = 'occupation_websites_extra-other';
  $handler->display->display_options['fields']['field_occupation_other_websites_3']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_other_websites_3']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_occupation_other_websites_3']['delta_offset'] = '3';
  /* Field: Content: Twitter hashtag(s) */
  $handler->display->display_options['fields']['field_occupation_twitter_hash']['id'] = 'field_occupation_twitter_hash';
  $handler->display->display_options['fields']['field_occupation_twitter_hash']['table'] = 'field_data_field_occupation_twitter_hash';
  $handler->display->display_options['fields']['field_occupation_twitter_hash']['field'] = 'field_occupation_twitter_hash';
  $handler->display->display_options['fields']['field_occupation_twitter_hash']['label'] = 'Twitter_hashtag1';
  $handler->display->display_options['fields']['field_occupation_twitter_hash']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_occupation_twitter_hash']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_occupation_twitter_hash']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_occupation_twitter_hash']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_occupation_twitter_hash']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_occupation_twitter_hash']['delta_offset'] = '0';
  /* Field: Content: Twitter hashtag(s) */
  $handler->display->display_options['fields']['field_occupation_twitter_hash_1']['id'] = 'field_occupation_twitter_hash_1';
  $handler->display->display_options['fields']['field_occupation_twitter_hash_1']['table'] = 'field_data_field_occupation_twitter_hash';
  $handler->display->display_options['fields']['field_occupation_twitter_hash_1']['field'] = 'field_occupation_twitter_hash';
  $handler->display->display_options['fields']['field_occupation_twitter_hash_1']['label'] = 'Twitter_hashtag2';
  $handler->display->display_options['fields']['field_occupation_twitter_hash_1']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_occupation_twitter_hash_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_occupation_twitter_hash_1']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_occupation_twitter_hash_1']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_occupation_twitter_hash_1']['delta_offset'] = '1';
  /* Field: Content: Twitter hashtag(s) */
  $handler->display->display_options['fields']['field_occupation_twitter_hash_2']['id'] = 'field_occupation_twitter_hash_2';
  $handler->display->display_options['fields']['field_occupation_twitter_hash_2']['table'] = 'field_data_field_occupation_twitter_hash';
  $handler->display->display_options['fields']['field_occupation_twitter_hash_2']['field'] = 'field_occupation_twitter_hash';
  $handler->display->display_options['fields']['field_occupation_twitter_hash_2']['label'] = 'Twitter_hashtag3';
  $handler->display->display_options['fields']['field_occupation_twitter_hash_2']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_occupation_twitter_hash_2']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_occupation_twitter_hash_2']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_occupation_twitter_hash_2']['delta_offset'] = '2';
  /* Field: Content: Twitter hashtag(s) */
  $handler->display->display_options['fields']['field_occupation_twitter_hash_3']['id'] = 'field_occupation_twitter_hash_3';
  $handler->display->display_options['fields']['field_occupation_twitter_hash_3']['table'] = 'field_data_field_occupation_twitter_hash';
  $handler->display->display_options['fields']['field_occupation_twitter_hash_3']['field'] = 'field_occupation_twitter_hash';
  $handler->display->display_options['fields']['field_occupation_twitter_hash_3']['label'] = 'Twitter_hashtag-other';
  $handler->display->display_options['fields']['field_occupation_twitter_hash_3']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_occupation_twitter_hash_3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_occupation_twitter_hash_3']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_occupation_twitter_hash_3']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_occupation_twitter_hash_3']['delta_offset'] = '3';
  /* Field: Content: Twitter account(s) */
  $handler->display->display_options['fields']['field_occupation_twitter']['id'] = 'field_occupation_twitter';
  $handler->display->display_options['fields']['field_occupation_twitter']['table'] = 'field_data_field_occupation_twitter';
  $handler->display->display_options['fields']['field_occupation_twitter']['field'] = 'field_occupation_twitter';
  $handler->display->display_options['fields']['field_occupation_twitter']['label'] = 'Twitter_account1';
  $handler->display->display_options['fields']['field_occupation_twitter']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_occupation_twitter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_occupation_twitter']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_occupation_twitter']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_occupation_twitter']['delta_offset'] = '0';
  /* Field: Content: Twitter account(s) */
  $handler->display->display_options['fields']['field_occupation_twitter_1']['id'] = 'field_occupation_twitter_1';
  $handler->display->display_options['fields']['field_occupation_twitter_1']['table'] = 'field_data_field_occupation_twitter';
  $handler->display->display_options['fields']['field_occupation_twitter_1']['field'] = 'field_occupation_twitter';
  $handler->display->display_options['fields']['field_occupation_twitter_1']['label'] = 'Twitter_account2';
  $handler->display->display_options['fields']['field_occupation_twitter_1']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_occupation_twitter_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_occupation_twitter_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_occupation_twitter_1']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_occupation_twitter_1']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_occupation_twitter_1']['delta_offset'] = '1';
  /* Field: Content: Twitter account(s) */
  $handler->display->display_options['fields']['field_occupation_twitter_2']['id'] = 'field_occupation_twitter_2';
  $handler->display->display_options['fields']['field_occupation_twitter_2']['table'] = 'field_data_field_occupation_twitter';
  $handler->display->display_options['fields']['field_occupation_twitter_2']['field'] = 'field_occupation_twitter';
  $handler->display->display_options['fields']['field_occupation_twitter_2']['label'] = 'Twitter_account3';
  $handler->display->display_options['fields']['field_occupation_twitter_2']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_occupation_twitter_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_occupation_twitter_2']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_occupation_twitter_2']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_occupation_twitter_2']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_occupation_twitter_2']['delta_offset'] = '2';
  /* Field: Content: Twitter account(s) */
  $handler->display->display_options['fields']['field_occupation_twitter_3']['id'] = 'field_occupation_twitter_3';
  $handler->display->display_options['fields']['field_occupation_twitter_3']['table'] = 'field_data_field_occupation_twitter';
  $handler->display->display_options['fields']['field_occupation_twitter_3']['field'] = 'field_occupation_twitter';
  $handler->display->display_options['fields']['field_occupation_twitter_3']['label'] = 'Twitter_account-other';
  $handler->display->display_options['fields']['field_occupation_twitter_3']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_occupation_twitter_3']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_occupation_twitter_3']['delta_offset'] = '0';
  /* Field: Content: Facebook Page(s) */
  $handler->display->display_options['fields']['field_occupation_facebook']['id'] = 'field_occupation_facebook';
  $handler->display->display_options['fields']['field_occupation_facebook']['table'] = 'field_data_field_occupation_facebook';
  $handler->display->display_options['fields']['field_occupation_facebook']['field'] = 'field_occupation_facebook';
  $handler->display->display_options['fields']['field_occupation_facebook']['label'] = 'Facebook1';
  $handler->display->display_options['fields']['field_occupation_facebook']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_occupation_facebook']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_occupation_facebook']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_occupation_facebook']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_occupation_facebook']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_facebook']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_occupation_facebook']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_occupation_facebook']['delta_offset'] = '0';
  /* Field: Content: Facebook Page(s) */
  $handler->display->display_options['fields']['field_occupation_facebook_1']['id'] = 'field_occupation_facebook_1';
  $handler->display->display_options['fields']['field_occupation_facebook_1']['table'] = 'field_data_field_occupation_facebook';
  $handler->display->display_options['fields']['field_occupation_facebook_1']['field'] = 'field_occupation_facebook';
  $handler->display->display_options['fields']['field_occupation_facebook_1']['label'] = 'Facebook2';
  $handler->display->display_options['fields']['field_occupation_facebook_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_occupation_facebook_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_occupation_facebook_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_facebook_1']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_occupation_facebook_1']['delta_offset'] = '1';
  /* Field: Content: Facebook Page(s) */
  $handler->display->display_options['fields']['field_occupation_facebook_2']['id'] = 'field_occupation_facebook_2';
  $handler->display->display_options['fields']['field_occupation_facebook_2']['table'] = 'field_data_field_occupation_facebook';
  $handler->display->display_options['fields']['field_occupation_facebook_2']['field'] = 'field_occupation_facebook';
  $handler->display->display_options['fields']['field_occupation_facebook_2']['label'] = 'Facebook-other';
  $handler->display->display_options['fields']['field_occupation_facebook_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_occupation_facebook_2']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_occupation_facebook_2']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_facebook_2']['delta_offset'] = '2';
  /* Field: Content: Newspaper URL */
  $handler->display->display_options['fields']['field_occupation_newspaper_url']['id'] = 'field_occupation_newspaper_url';
  $handler->display->display_options['fields']['field_occupation_newspaper_url']['table'] = 'field_data_field_occupation_newspaper_url';
  $handler->display->display_options['fields']['field_occupation_newspaper_url']['field'] = 'field_occupation_newspaper_url';
  $handler->display->display_options['fields']['field_occupation_newspaper_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_newspaper_url']['type'] = 'link_plain';
  /* Field: Content: RSS feeds */
  $handler->display->display_options['fields']['field_occupation_rss']['id'] = 'field_occupation_rss';
  $handler->display->display_options['fields']['field_occupation_rss']['table'] = 'field_data_field_occupation_rss';
  $handler->display->display_options['fields']['field_occupation_rss']['field'] = 'field_occupation_rss';
  $handler->display->display_options['fields']['field_occupation_rss']['label'] = 'RSS1';
  $handler->display->display_options['fields']['field_occupation_rss']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_occupation_rss']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_rss']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_occupation_rss']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_occupation_rss']['delta_offset'] = '0';
  /* Field: Content: RSS feeds */
  $handler->display->display_options['fields']['field_occupation_rss_1']['id'] = 'field_occupation_rss_1';
  $handler->display->display_options['fields']['field_occupation_rss_1']['table'] = 'field_data_field_occupation_rss';
  $handler->display->display_options['fields']['field_occupation_rss_1']['field'] = 'field_occupation_rss';
  $handler->display->display_options['fields']['field_occupation_rss_1']['label'] = 'RSS2';
  $handler->display->display_options['fields']['field_occupation_rss_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_occupation_rss_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_rss_1']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_occupation_rss_1']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_occupation_rss_1']['delta_offset'] = '1';
  /* Field: Content: RSS feeds */
  $handler->display->display_options['fields']['field_occupation_rss_2']['id'] = 'field_occupation_rss_2';
  $handler->display->display_options['fields']['field_occupation_rss_2']['table'] = 'field_data_field_occupation_rss';
  $handler->display->display_options['fields']['field_occupation_rss_2']['field'] = 'field_occupation_rss';
  $handler->display->display_options['fields']['field_occupation_rss_2']['label'] = 'RSS-other';
  $handler->display->display_options['fields']['field_occupation_rss_2']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_occupation_rss_2']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_rss_2']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_occupation_rss_2']['delta_offset'] = '2';
  /* Field: Content: Meetup URL */
  $handler->display->display_options['fields']['field_occupation_meetup_url']['id'] = 'field_occupation_meetup_url';
  $handler->display->display_options['fields']['field_occupation_meetup_url']['table'] = 'field_data_field_occupation_meetup_url';
  $handler->display->display_options['fields']['field_occupation_meetup_url']['field'] = 'field_occupation_meetup_url';
  $handler->display->display_options['fields']['field_occupation_meetup_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_meetup_url']['type'] = 'link_plain';
  /* Field: Content: Youtube channel URLs */
  $handler->display->display_options['fields']['field_occupation_youtube_chan']['id'] = 'field_occupation_youtube_chan';
  $handler->display->display_options['fields']['field_occupation_youtube_chan']['table'] = 'field_data_field_occupation_youtube_chan';
  $handler->display->display_options['fields']['field_occupation_youtube_chan']['field'] = 'field_occupation_youtube_chan';
  $handler->display->display_options['fields']['field_occupation_youtube_chan']['label'] = 'Youtube1';
  $handler->display->display_options['fields']['field_occupation_youtube_chan']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_youtube_chan']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_occupation_youtube_chan']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_occupation_youtube_chan']['delta_offset'] = '0';
  /* Field: Content: Youtube channel URLs */
  $handler->display->display_options['fields']['field_occupation_youtube_chan_1']['id'] = 'field_occupation_youtube_chan_1';
  $handler->display->display_options['fields']['field_occupation_youtube_chan_1']['table'] = 'field_data_field_occupation_youtube_chan';
  $handler->display->display_options['fields']['field_occupation_youtube_chan_1']['field'] = 'field_occupation_youtube_chan';
  $handler->display->display_options['fields']['field_occupation_youtube_chan_1']['label'] = 'Youtube2';
  $handler->display->display_options['fields']['field_occupation_youtube_chan_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_youtube_chan_1']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_occupation_youtube_chan_1']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_occupation_youtube_chan_1']['delta_offset'] = '1';
  /* Field: Content: Youtube channel URLs */
  $handler->display->display_options['fields']['field_occupation_youtube_chan_2']['id'] = 'field_occupation_youtube_chan_2';
  $handler->display->display_options['fields']['field_occupation_youtube_chan_2']['table'] = 'field_data_field_occupation_youtube_chan';
  $handler->display->display_options['fields']['field_occupation_youtube_chan_2']['field'] = 'field_occupation_youtube_chan';
  $handler->display->display_options['fields']['field_occupation_youtube_chan_2']['label'] = 'Youtube-other';
  $handler->display->display_options['fields']['field_occupation_youtube_chan_2']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_youtube_chan_2']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_occupation_youtube_chan_2']['delta_offset'] = '2';
  /* Field: Content: Live video streams */
  $handler->display->display_options['fields']['field_occupation_live_video']['id'] = 'field_occupation_live_video';
  $handler->display->display_options['fields']['field_occupation_live_video']['table'] = 'field_data_field_occupation_live_video';
  $handler->display->display_options['fields']['field_occupation_live_video']['field'] = 'field_occupation_live_video';
  $handler->display->display_options['fields']['field_occupation_live_video']['label'] = 'live_video1';
  $handler->display->display_options['fields']['field_occupation_live_video']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_live_video']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_occupation_live_video']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_occupation_live_video']['delta_offset'] = '0';
  /* Field: Content: Live video streams */
  $handler->display->display_options['fields']['field_occupation_live_video_1']['id'] = 'field_occupation_live_video_1';
  $handler->display->display_options['fields']['field_occupation_live_video_1']['table'] = 'field_data_field_occupation_live_video';
  $handler->display->display_options['fields']['field_occupation_live_video_1']['field'] = 'field_occupation_live_video';
  $handler->display->display_options['fields']['field_occupation_live_video_1']['label'] = 'live_video2';
  $handler->display->display_options['fields']['field_occupation_live_video_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_live_video_1']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_occupation_live_video_1']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_occupation_live_video_1']['delta_offset'] = '1';
  /* Field: Content: Live video streams */
  $handler->display->display_options['fields']['field_occupation_live_video_2']['id'] = 'field_occupation_live_video_2';
  $handler->display->display_options['fields']['field_occupation_live_video_2']['table'] = 'field_data_field_occupation_live_video';
  $handler->display->display_options['fields']['field_occupation_live_video_2']['field'] = 'field_occupation_live_video';
  $handler->display->display_options['fields']['field_occupation_live_video_2']['label'] = 'live_video-other';
  $handler->display->display_options['fields']['field_occupation_live_video_2']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_live_video_2']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_occupation_live_video_2']['delta_offset'] = '2';
  /* Field: Content: Additional social media sites */
  $handler->display->display_options['fields']['field_occupation_social_sites']['id'] = 'field_occupation_social_sites';
  $handler->display->display_options['fields']['field_occupation_social_sites']['table'] = 'field_data_field_occupation_social_sites';
  $handler->display->display_options['fields']['field_occupation_social_sites']['field'] = 'field_occupation_social_sites';
  $handler->display->display_options['fields']['field_occupation_social_sites']['label'] = 'social_media_extra1';
  $handler->display->display_options['fields']['field_occupation_social_sites']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_occupation_social_sites']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_social_sites']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_occupation_social_sites']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_occupation_social_sites']['delta_offset'] = '0';
  /* Field: Content: Additional social media sites */
  $handler->display->display_options['fields']['field_occupation_social_sites_1']['id'] = 'field_occupation_social_sites_1';
  $handler->display->display_options['fields']['field_occupation_social_sites_1']['table'] = 'field_data_field_occupation_social_sites';
  $handler->display->display_options['fields']['field_occupation_social_sites_1']['field'] = 'field_occupation_social_sites';
  $handler->display->display_options['fields']['field_occupation_social_sites_1']['label'] = 'social_media_extra2';
  $handler->display->display_options['fields']['field_occupation_social_sites_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_social_sites_1']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_occupation_social_sites_1']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_occupation_social_sites_1']['delta_offset'] = '1';
  /* Field: Content: Additional social media sites */
  $handler->display->display_options['fields']['field_occupation_social_sites_2']['id'] = 'field_occupation_social_sites_2';
  $handler->display->display_options['fields']['field_occupation_social_sites_2']['table'] = 'field_data_field_occupation_social_sites';
  $handler->display->display_options['fields']['field_occupation_social_sites_2']['field'] = 'field_occupation_social_sites';
  $handler->display->display_options['fields']['field_occupation_social_sites_2']['label'] = 'social_media_extra3';
  $handler->display->display_options['fields']['field_occupation_social_sites_2']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_social_sites_2']['type'] = 'link_absolute';
  $handler->display->display_options['fields']['field_occupation_social_sites_2']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_occupation_social_sites_2']['delta_offset'] = '2';
  /* Field: Content: Additional social media sites */
  $handler->display->display_options['fields']['field_occupation_social_sites_3']['id'] = 'field_occupation_social_sites_3';
  $handler->display->display_options['fields']['field_occupation_social_sites_3']['table'] = 'field_data_field_occupation_social_sites';
  $handler->display->display_options['fields']['field_occupation_social_sites_3']['field'] = 'field_occupation_social_sites';
  $handler->display->display_options['fields']['field_occupation_social_sites_3']['label'] = 'social_media_extra-other';
  $handler->display->display_options['fields']['field_occupation_social_sites_3']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_social_sites_3']['type'] = 'link_absolute';
  $handler->display->display_options['fields']['field_occupation_social_sites_3']['delta_offset'] = '3';
  /* Field: Content: Physical occupation occurring? */
  $handler->display->display_options['fields']['field_occupation_physical']['id'] = 'field_occupation_physical';
  $handler->display->display_options['fields']['field_occupation_physical']['table'] = 'field_data_field_occupation_physical';
  $handler->display->display_options['fields']['field_occupation_physical']['field'] = 'field_occupation_physical';
  $handler->display->display_options['fields']['field_occupation_physical']['label'] = 'Physical occupation occurring';
  $handler->display->display_options['fields']['field_occupation_physical']['delta_offset'] = '0';
  /* Field: Content: Point of contact email addresses */
  $handler->display->display_options['fields']['field_occupation_emails_other']['id'] = 'field_occupation_emails_other';
  $handler->display->display_options['fields']['field_occupation_emails_other']['table'] = 'field_data_field_occupation_emails_other';
  $handler->display->display_options['fields']['field_occupation_emails_other']['field'] = 'field_occupation_emails_other';
  $handler->display->display_options['fields']['field_occupation_emails_other']['delta_offset'] = '0';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = 'Occupy Directory URL';
  $handler->display->display_options['fields']['path']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['path']['alter']['text'] = 'http://directory.occupy.net[path]';
  $handler->display->display_options['fields']['path']['hide_empty'] = TRUE;
  /* Field: Occupation Image */
  $handler->display->display_options['fields']['uri_1']['id'] = 'uri_1';
  $handler->display->display_options['fields']['uri_1']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uri_1']['field'] = 'uri';
  $handler->display->display_options['fields']['uri_1']['relationship'] = 'node_to_file';
  $handler->display->display_options['fields']['uri_1']['ui_name'] = 'Occupation Image';
  $handler->display->display_options['fields']['uri_1']['label'] = 'Occupation_image-orig';
  $handler->display->display_options['fields']['uri_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uri_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['uri_1']['file_download_path'] = TRUE;
  /* Field: Occupation Image */
  $handler->display->display_options['fields']['filename']['id'] = 'filename';
  $handler->display->display_options['fields']['filename']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filename']['field'] = 'filename';
  $handler->display->display_options['fields']['filename']['relationship'] = 'node_to_file';
  $handler->display->display_options['fields']['filename']['ui_name'] = 'Occupation Image';
  $handler->display->display_options['fields']['filename']['label'] = 'Occupation_image-thumb';
  $handler->display->display_options['fields']['filename']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['filename']['alter']['text'] = 'http://directory.occupy.net/sites/default/files/styles/occupation_thumb_med/public/images/occupations/icons/[filename]';
  $handler->display->display_options['fields']['filename']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['filename']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['filename']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Node UUID */
  $handler->display->display_options['sorts']['uuid']['id'] = 'uuid';
  $handler->display->display_options['sorts']['uuid']['table'] = 'node';
  $handler->display->display_options['sorts']['uuid']['field'] = 'uuid';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['path'] = 'directory.csv';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;
  $handler->display->display_options['use_batch'] = 'batch';

  /* Display: Recently Added RSS */
  $handler = $view->new_display('feed', 'Recently Added RSS', 'added_rss');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Occupy Directory RSS, recently added';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['style_options']['description'] = 'Most recently added occupations';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['row_options']['item_length'] = 'rss';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['path'] = 'occupations/added.rss';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;

  /* Display: Recently Updated RSS */
  $handler = $view->new_display('feed', 'Recently Updated RSS', 'updated_rss');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Occupy Directory RSS, recently updated';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['style_options']['description'] = 'Most recently added occupations';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['row_options']['item_length'] = 'rss';
  $handler->display->display_options['row_options']['links'] = TRUE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  $handler->display->display_options['path'] = 'occupations/updated.rss';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;

  /* Display: Recently Added Atom */
  $handler = $view->new_display('page', 'Recently Added Atom', 'atom_recent');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Occupy Directory Atom, recently added';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_xml_style';
  $handler->display->display_options['style_options']['schema'] = 'atom';
  $handler->display->display_options['style_options']['plaintext_output'] = 1;
  $handler->display->display_options['style_options']['content_type'] = 'default';
  $handler->display->display_options['style_options']['header'] = '';
  $handler->display->display_options['style_options']['author'] = 'OccupyDirectoryStaff';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Node UUID */
  $handler->display->display_options['fields']['uuid']['id'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['table'] = 'node';
  $handler->display->display_options['fields']['uuid']['field'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['label'] = 'id';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = 'Link';
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'long';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Location (Address) */
  $handler->display->display_options['fields']['field_occupation_address']['id'] = 'field_occupation_address';
  $handler->display->display_options['fields']['field_occupation_address']['table'] = 'field_data_field_occupation_address';
  $handler->display->display_options['fields']['field_occupation_address']['field'] = 'field_occupation_address';
  $handler->display->display_options['fields']['field_occupation_address']['label'] = 'City';
  $handler->display->display_options['fields']['field_occupation_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_occupation_address']['type'] = 'locality';
  $handler->display->display_options['fields']['field_occupation_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Content: Occupation Image or Icon */
  $handler->display->display_options['fields']['field_occupation_image']['id'] = 'field_occupation_image';
  $handler->display->display_options['fields']['field_occupation_image']['table'] = 'field_data_field_occupation_image';
  $handler->display->display_options['fields']['field_occupation_image']['field'] = 'field_occupation_image';
  $handler->display->display_options['fields']['field_occupation_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_occupation_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'content',
  );
  /* Field: Content: Donate Information */
  $handler->display->display_options['fields']['field_occupation_dontate_info']['id'] = 'field_occupation_dontate_info';
  $handler->display->display_options['fields']['field_occupation_dontate_info']['table'] = 'field_data_field_occupation_dontate_info';
  $handler->display->display_options['fields']['field_occupation_dontate_info']['field'] = 'field_occupation_dontate_info';
  /* Field: Content: Facebook Page(s) */
  $handler->display->display_options['fields']['field_occupation_facebook']['id'] = 'field_occupation_facebook';
  $handler->display->display_options['fields']['field_occupation_facebook']['table'] = 'field_data_field_occupation_facebook';
  $handler->display->display_options['fields']['field_occupation_facebook']['field'] = 'field_occupation_facebook';
  $handler->display->display_options['fields']['field_occupation_facebook']['label'] = 'Facebook-Pages';
  $handler->display->display_options['fields']['field_occupation_facebook']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_facebook']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_occupation_facebook']['delta_offset'] = '0';
  /* Field: Content: General Assembly */
  $handler->display->display_options['fields']['field_occupation_general_info']['id'] = 'field_occupation_general_info';
  $handler->display->display_options['fields']['field_occupation_general_info']['table'] = 'field_data_field_occupation_general_info';
  $handler->display->display_options['fields']['field_occupation_general_info']['field'] = 'field_occupation_general_info';
  /* Field: Content: General email address */
  $handler->display->display_options['fields']['field_occupation_email_general']['id'] = 'field_occupation_email_general';
  $handler->display->display_options['fields']['field_occupation_email_general']['table'] = 'field_data_field_occupation_email_general';
  $handler->display->display_options['fields']['field_occupation_email_general']['field'] = 'field_occupation_email_general';
  $handler->display->display_options['fields']['field_occupation_email_general']['type'] = 'email_plain';
  /* Field: Content: Point of contact email addresses */
  $handler->display->display_options['fields']['field_occupation_emails_other_1']['id'] = 'field_occupation_emails_other_1';
  $handler->display->display_options['fields']['field_occupation_emails_other_1']['table'] = 'field_data_field_occupation_emails_other';
  $handler->display->display_options['fields']['field_occupation_emails_other_1']['field'] = 'field_occupation_emails_other';
  $handler->display->display_options['fields']['field_occupation_emails_other_1']['type'] = 'email_plain';
  $handler->display->display_options['fields']['field_occupation_emails_other_1']['delta_offset'] = '0';
  /* Field: Content: General phone */
  $handler->display->display_options['fields']['field_occupation_phone_general']['id'] = 'field_occupation_phone_general';
  $handler->display->display_options['fields']['field_occupation_phone_general']['table'] = 'field_data_field_occupation_phone_general';
  $handler->display->display_options['fields']['field_occupation_phone_general']['field'] = 'field_occupation_phone_general';
  /* Field: Content: Additional social media sites */
  $handler->display->display_options['fields']['field_occupation_social_sites']['id'] = 'field_occupation_social_sites';
  $handler->display->display_options['fields']['field_occupation_social_sites']['table'] = 'field_data_field_occupation_social_sites';
  $handler->display->display_options['fields']['field_occupation_social_sites']['field'] = 'field_occupation_social_sites';
  $handler->display->display_options['fields']['field_occupation_social_sites']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_social_sites']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_occupation_social_sites']['delta_offset'] = '0';
  /* Field: Content: Live video streams */
  $handler->display->display_options['fields']['field_occupation_live_video']['id'] = 'field_occupation_live_video';
  $handler->display->display_options['fields']['field_occupation_live_video']['table'] = 'field_data_field_occupation_live_video';
  $handler->display->display_options['fields']['field_occupation_live_video']['field'] = 'field_occupation_live_video';
  $handler->display->display_options['fields']['field_occupation_live_video']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_live_video']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_occupation_live_video']['delta_offset'] = '0';
  /* Field: Content: Meetup URL */
  $handler->display->display_options['fields']['field_occupation_meetup_url']['id'] = 'field_occupation_meetup_url';
  $handler->display->display_options['fields']['field_occupation_meetup_url']['table'] = 'field_data_field_occupation_meetup_url';
  $handler->display->display_options['fields']['field_occupation_meetup_url']['field'] = 'field_occupation_meetup_url';
  $handler->display->display_options['fields']['field_occupation_meetup_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_meetup_url']['type'] = 'link_plain';
  /* Field: Content: Newspaper URL */
  $handler->display->display_options['fields']['field_occupation_newspaper_url']['id'] = 'field_occupation_newspaper_url';
  $handler->display->display_options['fields']['field_occupation_newspaper_url']['table'] = 'field_data_field_occupation_newspaper_url';
  $handler->display->display_options['fields']['field_occupation_newspaper_url']['field'] = 'field_occupation_newspaper_url';
  $handler->display->display_options['fields']['field_occupation_newspaper_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_newspaper_url']['type'] = 'link_plain';
  /* Field: Content: Occupation description */
  $handler->display->display_options['fields']['field_occupation_description']['id'] = 'field_occupation_description';
  $handler->display->display_options['fields']['field_occupation_description']['table'] = 'field_data_field_occupation_description';
  $handler->display->display_options['fields']['field_occupation_description']['field'] = 'field_occupation_description';
  /* Field: Content: Founded */
  $handler->display->display_options['fields']['field_occupation_origin_date']['id'] = 'field_occupation_origin_date';
  $handler->display->display_options['fields']['field_occupation_origin_date']['table'] = 'field_data_field_occupation_origin_date';
  $handler->display->display_options['fields']['field_occupation_origin_date']['field'] = 'field_occupation_origin_date';
  $handler->display->display_options['fields']['field_occupation_origin_date']['settings'] = array(
    'format_type' => 'date_long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Occupation website */
  $handler->display->display_options['fields']['field_occupation_website']['id'] = 'field_occupation_website';
  $handler->display->display_options['fields']['field_occupation_website']['table'] = 'field_data_field_occupation_website';
  $handler->display->display_options['fields']['field_occupation_website']['field'] = 'field_occupation_website';
  $handler->display->display_options['fields']['field_occupation_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_website']['type'] = 'link_plain';
  /* Field: Content: Additional Occupation websites */
  $handler->display->display_options['fields']['field_occupation_other_websites']['id'] = 'field_occupation_other_websites';
  $handler->display->display_options['fields']['field_occupation_other_websites']['table'] = 'field_data_field_occupation_other_websites';
  $handler->display->display_options['fields']['field_occupation_other_websites']['field'] = 'field_occupation_other_websites';
  $handler->display->display_options['fields']['field_occupation_other_websites']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_other_websites']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_occupation_other_websites']['delta_offset'] = '0';
  /* Field: Content: Physical occupation occurring? */
  $handler->display->display_options['fields']['field_occupation_physical']['id'] = 'field_occupation_physical';
  $handler->display->display_options['fields']['field_occupation_physical']['table'] = 'field_data_field_occupation_physical';
  $handler->display->display_options['fields']['field_occupation_physical']['field'] = 'field_occupation_physical';
  $handler->display->display_options['fields']['field_occupation_physical']['delta_offset'] = '0';
  /* Field: Content: Point of contact email addresses */
  $handler->display->display_options['fields']['field_occupation_emails_other']['id'] = 'field_occupation_emails_other';
  $handler->display->display_options['fields']['field_occupation_emails_other']['table'] = 'field_data_field_occupation_emails_other';
  $handler->display->display_options['fields']['field_occupation_emails_other']['field'] = 'field_occupation_emails_other';
  $handler->display->display_options['fields']['field_occupation_emails_other']['delta_offset'] = '0';
  /* Field: Content: RSS feeds */
  $handler->display->display_options['fields']['field_occupation_rss']['id'] = 'field_occupation_rss';
  $handler->display->display_options['fields']['field_occupation_rss']['table'] = 'field_data_field_occupation_rss';
  $handler->display->display_options['fields']['field_occupation_rss']['field'] = 'field_occupation_rss';
  $handler->display->display_options['fields']['field_occupation_rss']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_rss']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_occupation_rss']['delta_offset'] = '0';
  /* Field: Content: Twitter account(s) */
  $handler->display->display_options['fields']['field_occupation_twitter']['id'] = 'field_occupation_twitter';
  $handler->display->display_options['fields']['field_occupation_twitter']['table'] = 'field_data_field_occupation_twitter';
  $handler->display->display_options['fields']['field_occupation_twitter']['field'] = 'field_occupation_twitter';
  $handler->display->display_options['fields']['field_occupation_twitter']['delta_offset'] = '0';
  /* Field: Content: Twitter hashtag(s) */
  $handler->display->display_options['fields']['field_occupation_twitter_hash']['id'] = 'field_occupation_twitter_hash';
  $handler->display->display_options['fields']['field_occupation_twitter_hash']['table'] = 'field_data_field_occupation_twitter_hash';
  $handler->display->display_options['fields']['field_occupation_twitter_hash']['field'] = 'field_occupation_twitter_hash';
  $handler->display->display_options['fields']['field_occupation_twitter_hash']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_occupation_twitter_hash']['delta_offset'] = '0';
  /* Field: Content: Youtube channel URLs */
  $handler->display->display_options['fields']['field_occupation_youtube_chan']['id'] = 'field_occupation_youtube_chan';
  $handler->display->display_options['fields']['field_occupation_youtube_chan']['table'] = 'field_data_field_occupation_youtube_chan';
  $handler->display->display_options['fields']['field_occupation_youtube_chan']['field'] = 'field_occupation_youtube_chan';
  $handler->display->display_options['fields']['field_occupation_youtube_chan']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_youtube_chan']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_occupation_youtube_chan']['delta_offset'] = '0';
  /* Field: File: Path */
  $handler->display->display_options['fields']['uri']['id'] = 'uri';
  $handler->display->display_options['fields']['uri']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uri']['field'] = 'uri';
  $handler->display->display_options['fields']['uri']['relationship'] = 'node_to_file';
  $handler->display->display_options['fields']['uri']['file_download_path'] = TRUE;
  /* Field: Content: Location (Address) */
  $handler->display->display_options['fields']['field_occupation_address_1']['id'] = 'field_occupation_address_1';
  $handler->display->display_options['fields']['field_occupation_address_1']['table'] = 'field_data_field_occupation_address';
  $handler->display->display_options['fields']['field_occupation_address_1']['field'] = 'field_occupation_address';
  $handler->display->display_options['fields']['field_occupation_address_1']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_occupation_address_1']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['path'] = 'occupations/added.atom';

  /* Display: Recently Updated Atom */
  $handler = $view->new_display('page', 'Recently Updated Atom', 'atom_updated');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Occupy Directory Atom, recently updated';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_xml_style';
  $handler->display->display_options['style_options']['schema'] = 'atom';
  $handler->display->display_options['style_options']['plaintext_output'] = 1;
  $handler->display->display_options['style_options']['content_type'] = 'default';
  $handler->display->display_options['style_options']['header'] = '';
  $handler->display->display_options['style_options']['author'] = 'OccupyDirectoryStaff';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Node UUID */
  $handler->display->display_options['fields']['uuid']['id'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['table'] = 'node';
  $handler->display->display_options['fields']['uuid']['field'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['label'] = 'id';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = 'Link';
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'long';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Location (Address) */
  $handler->display->display_options['fields']['field_occupation_address']['id'] = 'field_occupation_address';
  $handler->display->display_options['fields']['field_occupation_address']['table'] = 'field_data_field_occupation_address';
  $handler->display->display_options['fields']['field_occupation_address']['field'] = 'field_occupation_address';
  $handler->display->display_options['fields']['field_occupation_address']['label'] = 'City';
  $handler->display->display_options['fields']['field_occupation_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_occupation_address']['type'] = 'locality';
  $handler->display->display_options['fields']['field_occupation_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Content: Occupation Image or Icon */
  $handler->display->display_options['fields']['field_occupation_image']['id'] = 'field_occupation_image';
  $handler->display->display_options['fields']['field_occupation_image']['table'] = 'field_data_field_occupation_image';
  $handler->display->display_options['fields']['field_occupation_image']['field'] = 'field_occupation_image';
  $handler->display->display_options['fields']['field_occupation_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_occupation_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'content',
  );
  /* Field: Content: Donate Information */
  $handler->display->display_options['fields']['field_occupation_dontate_info']['id'] = 'field_occupation_dontate_info';
  $handler->display->display_options['fields']['field_occupation_dontate_info']['table'] = 'field_data_field_occupation_dontate_info';
  $handler->display->display_options['fields']['field_occupation_dontate_info']['field'] = 'field_occupation_dontate_info';
  /* Field: Content: Facebook Page(s) */
  $handler->display->display_options['fields']['field_occupation_facebook']['id'] = 'field_occupation_facebook';
  $handler->display->display_options['fields']['field_occupation_facebook']['table'] = 'field_data_field_occupation_facebook';
  $handler->display->display_options['fields']['field_occupation_facebook']['field'] = 'field_occupation_facebook';
  $handler->display->display_options['fields']['field_occupation_facebook']['label'] = 'Facebook-Pages';
  $handler->display->display_options['fields']['field_occupation_facebook']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_facebook']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_occupation_facebook']['delta_offset'] = '0';
  /* Field: Content: General Assembly */
  $handler->display->display_options['fields']['field_occupation_general_info']['id'] = 'field_occupation_general_info';
  $handler->display->display_options['fields']['field_occupation_general_info']['table'] = 'field_data_field_occupation_general_info';
  $handler->display->display_options['fields']['field_occupation_general_info']['field'] = 'field_occupation_general_info';
  /* Field: Content: General email address */
  $handler->display->display_options['fields']['field_occupation_email_general']['id'] = 'field_occupation_email_general';
  $handler->display->display_options['fields']['field_occupation_email_general']['table'] = 'field_data_field_occupation_email_general';
  $handler->display->display_options['fields']['field_occupation_email_general']['field'] = 'field_occupation_email_general';
  $handler->display->display_options['fields']['field_occupation_email_general']['type'] = 'email_plain';
  /* Field: Content: Point of contact email addresses */
  $handler->display->display_options['fields']['field_occupation_emails_other_1']['id'] = 'field_occupation_emails_other_1';
  $handler->display->display_options['fields']['field_occupation_emails_other_1']['table'] = 'field_data_field_occupation_emails_other';
  $handler->display->display_options['fields']['field_occupation_emails_other_1']['field'] = 'field_occupation_emails_other';
  $handler->display->display_options['fields']['field_occupation_emails_other_1']['type'] = 'email_plain';
  $handler->display->display_options['fields']['field_occupation_emails_other_1']['delta_offset'] = '0';
  /* Field: Content: General phone */
  $handler->display->display_options['fields']['field_occupation_phone_general']['id'] = 'field_occupation_phone_general';
  $handler->display->display_options['fields']['field_occupation_phone_general']['table'] = 'field_data_field_occupation_phone_general';
  $handler->display->display_options['fields']['field_occupation_phone_general']['field'] = 'field_occupation_phone_general';
  /* Field: Content: Additional social media sites */
  $handler->display->display_options['fields']['field_occupation_social_sites']['id'] = 'field_occupation_social_sites';
  $handler->display->display_options['fields']['field_occupation_social_sites']['table'] = 'field_data_field_occupation_social_sites';
  $handler->display->display_options['fields']['field_occupation_social_sites']['field'] = 'field_occupation_social_sites';
  $handler->display->display_options['fields']['field_occupation_social_sites']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_social_sites']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_occupation_social_sites']['delta_offset'] = '0';
  /* Field: Content: Live video streams */
  $handler->display->display_options['fields']['field_occupation_live_video']['id'] = 'field_occupation_live_video';
  $handler->display->display_options['fields']['field_occupation_live_video']['table'] = 'field_data_field_occupation_live_video';
  $handler->display->display_options['fields']['field_occupation_live_video']['field'] = 'field_occupation_live_video';
  $handler->display->display_options['fields']['field_occupation_live_video']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_live_video']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_occupation_live_video']['delta_offset'] = '0';
  /* Field: Content: Meetup URL */
  $handler->display->display_options['fields']['field_occupation_meetup_url']['id'] = 'field_occupation_meetup_url';
  $handler->display->display_options['fields']['field_occupation_meetup_url']['table'] = 'field_data_field_occupation_meetup_url';
  $handler->display->display_options['fields']['field_occupation_meetup_url']['field'] = 'field_occupation_meetup_url';
  $handler->display->display_options['fields']['field_occupation_meetup_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_meetup_url']['type'] = 'link_plain';
  /* Field: Content: Newspaper URL */
  $handler->display->display_options['fields']['field_occupation_newspaper_url']['id'] = 'field_occupation_newspaper_url';
  $handler->display->display_options['fields']['field_occupation_newspaper_url']['table'] = 'field_data_field_occupation_newspaper_url';
  $handler->display->display_options['fields']['field_occupation_newspaper_url']['field'] = 'field_occupation_newspaper_url';
  $handler->display->display_options['fields']['field_occupation_newspaper_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_newspaper_url']['type'] = 'link_plain';
  /* Field: Content: Occupation description */
  $handler->display->display_options['fields']['field_occupation_description']['id'] = 'field_occupation_description';
  $handler->display->display_options['fields']['field_occupation_description']['table'] = 'field_data_field_occupation_description';
  $handler->display->display_options['fields']['field_occupation_description']['field'] = 'field_occupation_description';
  /* Field: Content: Founded */
  $handler->display->display_options['fields']['field_occupation_origin_date']['id'] = 'field_occupation_origin_date';
  $handler->display->display_options['fields']['field_occupation_origin_date']['table'] = 'field_data_field_occupation_origin_date';
  $handler->display->display_options['fields']['field_occupation_origin_date']['field'] = 'field_occupation_origin_date';
  $handler->display->display_options['fields']['field_occupation_origin_date']['settings'] = array(
    'format_type' => 'date_long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Occupation website */
  $handler->display->display_options['fields']['field_occupation_website']['id'] = 'field_occupation_website';
  $handler->display->display_options['fields']['field_occupation_website']['table'] = 'field_data_field_occupation_website';
  $handler->display->display_options['fields']['field_occupation_website']['field'] = 'field_occupation_website';
  $handler->display->display_options['fields']['field_occupation_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_website']['type'] = 'link_plain';
  /* Field: Content: Additional Occupation websites */
  $handler->display->display_options['fields']['field_occupation_other_websites']['id'] = 'field_occupation_other_websites';
  $handler->display->display_options['fields']['field_occupation_other_websites']['table'] = 'field_data_field_occupation_other_websites';
  $handler->display->display_options['fields']['field_occupation_other_websites']['field'] = 'field_occupation_other_websites';
  $handler->display->display_options['fields']['field_occupation_other_websites']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_other_websites']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_occupation_other_websites']['delta_offset'] = '0';
  /* Field: Content: Physical occupation occurring? */
  $handler->display->display_options['fields']['field_occupation_physical']['id'] = 'field_occupation_physical';
  $handler->display->display_options['fields']['field_occupation_physical']['table'] = 'field_data_field_occupation_physical';
  $handler->display->display_options['fields']['field_occupation_physical']['field'] = 'field_occupation_physical';
  $handler->display->display_options['fields']['field_occupation_physical']['delta_offset'] = '0';
  /* Field: Content: Point of contact email addresses */
  $handler->display->display_options['fields']['field_occupation_emails_other']['id'] = 'field_occupation_emails_other';
  $handler->display->display_options['fields']['field_occupation_emails_other']['table'] = 'field_data_field_occupation_emails_other';
  $handler->display->display_options['fields']['field_occupation_emails_other']['field'] = 'field_occupation_emails_other';
  $handler->display->display_options['fields']['field_occupation_emails_other']['delta_offset'] = '0';
  /* Field: Content: RSS feeds */
  $handler->display->display_options['fields']['field_occupation_rss']['id'] = 'field_occupation_rss';
  $handler->display->display_options['fields']['field_occupation_rss']['table'] = 'field_data_field_occupation_rss';
  $handler->display->display_options['fields']['field_occupation_rss']['field'] = 'field_occupation_rss';
  $handler->display->display_options['fields']['field_occupation_rss']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_rss']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_occupation_rss']['delta_offset'] = '0';
  /* Field: Content: Twitter account(s) */
  $handler->display->display_options['fields']['field_occupation_twitter']['id'] = 'field_occupation_twitter';
  $handler->display->display_options['fields']['field_occupation_twitter']['table'] = 'field_data_field_occupation_twitter';
  $handler->display->display_options['fields']['field_occupation_twitter']['field'] = 'field_occupation_twitter';
  $handler->display->display_options['fields']['field_occupation_twitter']['delta_offset'] = '0';
  /* Field: Content: Twitter hashtag(s) */
  $handler->display->display_options['fields']['field_occupation_twitter_hash']['id'] = 'field_occupation_twitter_hash';
  $handler->display->display_options['fields']['field_occupation_twitter_hash']['table'] = 'field_data_field_occupation_twitter_hash';
  $handler->display->display_options['fields']['field_occupation_twitter_hash']['field'] = 'field_occupation_twitter_hash';
  $handler->display->display_options['fields']['field_occupation_twitter_hash']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_occupation_twitter_hash']['delta_offset'] = '0';
  /* Field: Content: Youtube channel URLs */
  $handler->display->display_options['fields']['field_occupation_youtube_chan']['id'] = 'field_occupation_youtube_chan';
  $handler->display->display_options['fields']['field_occupation_youtube_chan']['table'] = 'field_data_field_occupation_youtube_chan';
  $handler->display->display_options['fields']['field_occupation_youtube_chan']['field'] = 'field_occupation_youtube_chan';
  $handler->display->display_options['fields']['field_occupation_youtube_chan']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_youtube_chan']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_occupation_youtube_chan']['delta_offset'] = '0';
  /* Field: File: Path */
  $handler->display->display_options['fields']['uri']['id'] = 'uri';
  $handler->display->display_options['fields']['uri']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uri']['field'] = 'uri';
  $handler->display->display_options['fields']['uri']['relationship'] = 'node_to_file';
  $handler->display->display_options['fields']['uri']['file_download_path'] = TRUE;
  /* Field: Content: Location (Address) */
  $handler->display->display_options['fields']['field_occupation_address_1']['id'] = 'field_occupation_address_1';
  $handler->display->display_options['fields']['field_occupation_address_1']['table'] = 'field_data_field_occupation_address';
  $handler->display->display_options['fields']['field_occupation_address_1']['field'] = 'field_occupation_address';
  $handler->display->display_options['fields']['field_occupation_address_1']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_occupation_address_1']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  $handler->display->display_options['path'] = 'occupations/updated.atom';

  /* Display: JSON */
  $handler = $view->new_display('page', 'JSON', 'export_json');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Occupy Directory in JSON format';
  $handler->display->display_options['display_comment'] = 'All the occupation data as a JSON string!
Caching exceeds memory limit :(';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['plaintext_output'] = 1;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Node UUID */
  $handler->display->display_options['fields']['uuid']['id'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['table'] = 'node';
  $handler->display->display_options['fields']['uuid']['field'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['label'] = 'id';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = 'Link';
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'long';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Location (Address) */
  $handler->display->display_options['fields']['field_occupation_address']['id'] = 'field_occupation_address';
  $handler->display->display_options['fields']['field_occupation_address']['table'] = 'field_data_field_occupation_address';
  $handler->display->display_options['fields']['field_occupation_address']['field'] = 'field_occupation_address';
  $handler->display->display_options['fields']['field_occupation_address']['label'] = 'City';
  $handler->display->display_options['fields']['field_occupation_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_occupation_address']['type'] = 'locality';
  $handler->display->display_options['fields']['field_occupation_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Content: Occupation Image or Icon */
  $handler->display->display_options['fields']['field_occupation_image']['id'] = 'field_occupation_image';
  $handler->display->display_options['fields']['field_occupation_image']['table'] = 'field_data_field_occupation_image';
  $handler->display->display_options['fields']['field_occupation_image']['field'] = 'field_occupation_image';
  $handler->display->display_options['fields']['field_occupation_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_occupation_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'content',
  );
  /* Field: Content: Donate Information */
  $handler->display->display_options['fields']['field_occupation_dontate_info']['id'] = 'field_occupation_dontate_info';
  $handler->display->display_options['fields']['field_occupation_dontate_info']['table'] = 'field_data_field_occupation_dontate_info';
  $handler->display->display_options['fields']['field_occupation_dontate_info']['field'] = 'field_occupation_dontate_info';
  /* Field: Content: Facebook Page(s) */
  $handler->display->display_options['fields']['field_occupation_facebook']['id'] = 'field_occupation_facebook';
  $handler->display->display_options['fields']['field_occupation_facebook']['table'] = 'field_data_field_occupation_facebook';
  $handler->display->display_options['fields']['field_occupation_facebook']['field'] = 'field_occupation_facebook';
  $handler->display->display_options['fields']['field_occupation_facebook']['label'] = 'Facebook-Pages';
  $handler->display->display_options['fields']['field_occupation_facebook']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_facebook']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_occupation_facebook']['delta_offset'] = '0';
  /* Field: Content: General Assembly */
  $handler->display->display_options['fields']['field_occupation_general_info']['id'] = 'field_occupation_general_info';
  $handler->display->display_options['fields']['field_occupation_general_info']['table'] = 'field_data_field_occupation_general_info';
  $handler->display->display_options['fields']['field_occupation_general_info']['field'] = 'field_occupation_general_info';
  /* Field: Content: General email address */
  $handler->display->display_options['fields']['field_occupation_email_general']['id'] = 'field_occupation_email_general';
  $handler->display->display_options['fields']['field_occupation_email_general']['table'] = 'field_data_field_occupation_email_general';
  $handler->display->display_options['fields']['field_occupation_email_general']['field'] = 'field_occupation_email_general';
  $handler->display->display_options['fields']['field_occupation_email_general']['type'] = 'email_plain';
  /* Field: Content: Point of contact email addresses */
  $handler->display->display_options['fields']['field_occupation_emails_other_1']['id'] = 'field_occupation_emails_other_1';
  $handler->display->display_options['fields']['field_occupation_emails_other_1']['table'] = 'field_data_field_occupation_emails_other';
  $handler->display->display_options['fields']['field_occupation_emails_other_1']['field'] = 'field_occupation_emails_other';
  $handler->display->display_options['fields']['field_occupation_emails_other_1']['type'] = 'email_plain';
  $handler->display->display_options['fields']['field_occupation_emails_other_1']['delta_offset'] = '0';
  /* Field: Content: General phone */
  $handler->display->display_options['fields']['field_occupation_phone_general']['id'] = 'field_occupation_phone_general';
  $handler->display->display_options['fields']['field_occupation_phone_general']['table'] = 'field_data_field_occupation_phone_general';
  $handler->display->display_options['fields']['field_occupation_phone_general']['field'] = 'field_occupation_phone_general';
  /* Field: Content: Additional social media sites */
  $handler->display->display_options['fields']['field_occupation_social_sites']['id'] = 'field_occupation_social_sites';
  $handler->display->display_options['fields']['field_occupation_social_sites']['table'] = 'field_data_field_occupation_social_sites';
  $handler->display->display_options['fields']['field_occupation_social_sites']['field'] = 'field_occupation_social_sites';
  $handler->display->display_options['fields']['field_occupation_social_sites']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_social_sites']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_occupation_social_sites']['delta_offset'] = '0';
  /* Field: Content: Live video streams */
  $handler->display->display_options['fields']['field_occupation_live_video']['id'] = 'field_occupation_live_video';
  $handler->display->display_options['fields']['field_occupation_live_video']['table'] = 'field_data_field_occupation_live_video';
  $handler->display->display_options['fields']['field_occupation_live_video']['field'] = 'field_occupation_live_video';
  $handler->display->display_options['fields']['field_occupation_live_video']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_live_video']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_occupation_live_video']['delta_offset'] = '0';
  /* Field: Content: Meetup URL */
  $handler->display->display_options['fields']['field_occupation_meetup_url']['id'] = 'field_occupation_meetup_url';
  $handler->display->display_options['fields']['field_occupation_meetup_url']['table'] = 'field_data_field_occupation_meetup_url';
  $handler->display->display_options['fields']['field_occupation_meetup_url']['field'] = 'field_occupation_meetup_url';
  $handler->display->display_options['fields']['field_occupation_meetup_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_meetup_url']['type'] = 'link_plain';
  /* Field: Content: Newspaper URL */
  $handler->display->display_options['fields']['field_occupation_newspaper_url']['id'] = 'field_occupation_newspaper_url';
  $handler->display->display_options['fields']['field_occupation_newspaper_url']['table'] = 'field_data_field_occupation_newspaper_url';
  $handler->display->display_options['fields']['field_occupation_newspaper_url']['field'] = 'field_occupation_newspaper_url';
  $handler->display->display_options['fields']['field_occupation_newspaper_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_newspaper_url']['type'] = 'link_plain';
  /* Field: Content: Occupation description */
  $handler->display->display_options['fields']['field_occupation_description']['id'] = 'field_occupation_description';
  $handler->display->display_options['fields']['field_occupation_description']['table'] = 'field_data_field_occupation_description';
  $handler->display->display_options['fields']['field_occupation_description']['field'] = 'field_occupation_description';
  /* Field: Content: Founded */
  $handler->display->display_options['fields']['field_occupation_origin_date']['id'] = 'field_occupation_origin_date';
  $handler->display->display_options['fields']['field_occupation_origin_date']['table'] = 'field_data_field_occupation_origin_date';
  $handler->display->display_options['fields']['field_occupation_origin_date']['field'] = 'field_occupation_origin_date';
  $handler->display->display_options['fields']['field_occupation_origin_date']['settings'] = array(
    'format_type' => 'date_long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Occupation website */
  $handler->display->display_options['fields']['field_occupation_website']['id'] = 'field_occupation_website';
  $handler->display->display_options['fields']['field_occupation_website']['table'] = 'field_data_field_occupation_website';
  $handler->display->display_options['fields']['field_occupation_website']['field'] = 'field_occupation_website';
  $handler->display->display_options['fields']['field_occupation_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_website']['type'] = 'link_plain';
  /* Field: Content: Additional Occupation websites */
  $handler->display->display_options['fields']['field_occupation_other_websites']['id'] = 'field_occupation_other_websites';
  $handler->display->display_options['fields']['field_occupation_other_websites']['table'] = 'field_data_field_occupation_other_websites';
  $handler->display->display_options['fields']['field_occupation_other_websites']['field'] = 'field_occupation_other_websites';
  $handler->display->display_options['fields']['field_occupation_other_websites']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_other_websites']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_occupation_other_websites']['delta_offset'] = '0';
  /* Field: Content: Physical occupation occurring? */
  $handler->display->display_options['fields']['field_occupation_physical']['id'] = 'field_occupation_physical';
  $handler->display->display_options['fields']['field_occupation_physical']['table'] = 'field_data_field_occupation_physical';
  $handler->display->display_options['fields']['field_occupation_physical']['field'] = 'field_occupation_physical';
  $handler->display->display_options['fields']['field_occupation_physical']['delta_offset'] = '0';
  /* Field: Content: Point of contact email addresses */
  $handler->display->display_options['fields']['field_occupation_emails_other']['id'] = 'field_occupation_emails_other';
  $handler->display->display_options['fields']['field_occupation_emails_other']['table'] = 'field_data_field_occupation_emails_other';
  $handler->display->display_options['fields']['field_occupation_emails_other']['field'] = 'field_occupation_emails_other';
  $handler->display->display_options['fields']['field_occupation_emails_other']['delta_offset'] = '0';
  /* Field: Content: RSS feeds */
  $handler->display->display_options['fields']['field_occupation_rss']['id'] = 'field_occupation_rss';
  $handler->display->display_options['fields']['field_occupation_rss']['table'] = 'field_data_field_occupation_rss';
  $handler->display->display_options['fields']['field_occupation_rss']['field'] = 'field_occupation_rss';
  $handler->display->display_options['fields']['field_occupation_rss']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_rss']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_occupation_rss']['delta_offset'] = '0';
  /* Field: Content: Twitter account(s) */
  $handler->display->display_options['fields']['field_occupation_twitter']['id'] = 'field_occupation_twitter';
  $handler->display->display_options['fields']['field_occupation_twitter']['table'] = 'field_data_field_occupation_twitter';
  $handler->display->display_options['fields']['field_occupation_twitter']['field'] = 'field_occupation_twitter';
  $handler->display->display_options['fields']['field_occupation_twitter']['delta_offset'] = '0';
  /* Field: Content: Twitter hashtag(s) */
  $handler->display->display_options['fields']['field_occupation_twitter_hash']['id'] = 'field_occupation_twitter_hash';
  $handler->display->display_options['fields']['field_occupation_twitter_hash']['table'] = 'field_data_field_occupation_twitter_hash';
  $handler->display->display_options['fields']['field_occupation_twitter_hash']['field'] = 'field_occupation_twitter_hash';
  $handler->display->display_options['fields']['field_occupation_twitter_hash']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_occupation_twitter_hash']['delta_offset'] = '0';
  /* Field: Content: Youtube channel URLs */
  $handler->display->display_options['fields']['field_occupation_youtube_chan']['id'] = 'field_occupation_youtube_chan';
  $handler->display->display_options['fields']['field_occupation_youtube_chan']['table'] = 'field_data_field_occupation_youtube_chan';
  $handler->display->display_options['fields']['field_occupation_youtube_chan']['field'] = 'field_occupation_youtube_chan';
  $handler->display->display_options['fields']['field_occupation_youtube_chan']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_youtube_chan']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_occupation_youtube_chan']['delta_offset'] = '0';
  /* Field: File: Path */
  $handler->display->display_options['fields']['uri']['id'] = 'uri';
  $handler->display->display_options['fields']['uri']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uri']['field'] = 'uri';
  $handler->display->display_options['fields']['uri']['relationship'] = 'node_to_file';
  $handler->display->display_options['fields']['uri']['file_download_path'] = TRUE;
  /* Field: Content: Location (Address) */
  $handler->display->display_options['fields']['field_occupation_address_1']['id'] = 'field_occupation_address_1';
  $handler->display->display_options['fields']['field_occupation_address_1']['table'] = 'field_data_field_occupation_address';
  $handler->display->display_options['fields']['field_occupation_address_1']['field'] = 'field_occupation_address';
  $handler->display->display_options['fields']['field_occupation_address_1']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_occupation_address_1']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['path'] = 'directory.json';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'json';
  $handler->display->display_options['menu']['description'] = 'The entire directory in JSON format';
  $handler->display->display_options['menu']['weight'] = '11';
  $handler->display->display_options['menu']['name'] = 'menu-feeds-and-exports';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: geojson */
  $handler = $view->new_display('page', 'geojson', 'export_geojson');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Occupy Directory in GEOJSON format';
  $handler->display->display_options['display_comment'] = 'Module is still unstable. Submitted a bunch of patches. needs work.
caching exceeds memory limit :(';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_geojson';
  $handler->display->display_options['style_options']['data_source']['value'] = 'latlon';
  $handler->display->display_options['style_options']['data_source']['latitude'] = 'uuid';
  $handler->display->display_options['style_options']['data_source']['longitude'] = 'uuid';
  $handler->display->display_options['style_options']['data_source']['bbox_top'] = 'uuid';
  $handler->display->display_options['style_options']['data_source']['bbox_right'] = 'uuid';
  $handler->display->display_options['style_options']['data_source']['bbox_bottom'] = 'uuid';
  $handler->display->display_options['style_options']['data_source']['bbox_left'] = 'uuid';
  $handler->display->display_options['style_options']['data_source']['name_field'] = '';
  $handler->display->display_options['style_options']['data_source']['description_field'] = '';
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['content_type'] = 'text/json';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Node UUID */
  $handler->display->display_options['fields']['uuid']['id'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['table'] = 'node';
  $handler->display->display_options['fields']['uuid']['field'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['label'] = 'id';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = 'Link';
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'long';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Location (Address) */
  $handler->display->display_options['fields']['field_occupation_address']['id'] = 'field_occupation_address';
  $handler->display->display_options['fields']['field_occupation_address']['table'] = 'field_data_field_occupation_address';
  $handler->display->display_options['fields']['field_occupation_address']['field'] = 'field_occupation_address';
  $handler->display->display_options['fields']['field_occupation_address']['label'] = 'City';
  $handler->display->display_options['fields']['field_occupation_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_occupation_address']['type'] = 'locality';
  $handler->display->display_options['fields']['field_occupation_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Content: Occupation Image or Icon */
  $handler->display->display_options['fields']['field_occupation_image']['id'] = 'field_occupation_image';
  $handler->display->display_options['fields']['field_occupation_image']['table'] = 'field_data_field_occupation_image';
  $handler->display->display_options['fields']['field_occupation_image']['field'] = 'field_occupation_image';
  $handler->display->display_options['fields']['field_occupation_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_occupation_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'content',
  );
  /* Field: Content: Donate Information */
  $handler->display->display_options['fields']['field_occupation_dontate_info']['id'] = 'field_occupation_dontate_info';
  $handler->display->display_options['fields']['field_occupation_dontate_info']['table'] = 'field_data_field_occupation_dontate_info';
  $handler->display->display_options['fields']['field_occupation_dontate_info']['field'] = 'field_occupation_dontate_info';
  /* Field: Content: Facebook Page(s) */
  $handler->display->display_options['fields']['field_occupation_facebook']['id'] = 'field_occupation_facebook';
  $handler->display->display_options['fields']['field_occupation_facebook']['table'] = 'field_data_field_occupation_facebook';
  $handler->display->display_options['fields']['field_occupation_facebook']['field'] = 'field_occupation_facebook';
  $handler->display->display_options['fields']['field_occupation_facebook']['label'] = 'Facebook-Pages';
  $handler->display->display_options['fields']['field_occupation_facebook']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_facebook']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_occupation_facebook']['delta_offset'] = '0';
  /* Field: Content: General Assembly */
  $handler->display->display_options['fields']['field_occupation_general_info']['id'] = 'field_occupation_general_info';
  $handler->display->display_options['fields']['field_occupation_general_info']['table'] = 'field_data_field_occupation_general_info';
  $handler->display->display_options['fields']['field_occupation_general_info']['field'] = 'field_occupation_general_info';
  /* Field: Content: General email address */
  $handler->display->display_options['fields']['field_occupation_email_general']['id'] = 'field_occupation_email_general';
  $handler->display->display_options['fields']['field_occupation_email_general']['table'] = 'field_data_field_occupation_email_general';
  $handler->display->display_options['fields']['field_occupation_email_general']['field'] = 'field_occupation_email_general';
  $handler->display->display_options['fields']['field_occupation_email_general']['type'] = 'email_plain';
  /* Field: Content: Point of contact email addresses */
  $handler->display->display_options['fields']['field_occupation_emails_other_1']['id'] = 'field_occupation_emails_other_1';
  $handler->display->display_options['fields']['field_occupation_emails_other_1']['table'] = 'field_data_field_occupation_emails_other';
  $handler->display->display_options['fields']['field_occupation_emails_other_1']['field'] = 'field_occupation_emails_other';
  $handler->display->display_options['fields']['field_occupation_emails_other_1']['type'] = 'email_plain';
  $handler->display->display_options['fields']['field_occupation_emails_other_1']['delta_offset'] = '0';
  /* Field: Content: General phone */
  $handler->display->display_options['fields']['field_occupation_phone_general']['id'] = 'field_occupation_phone_general';
  $handler->display->display_options['fields']['field_occupation_phone_general']['table'] = 'field_data_field_occupation_phone_general';
  $handler->display->display_options['fields']['field_occupation_phone_general']['field'] = 'field_occupation_phone_general';
  /* Field: Content: Additional social media sites */
  $handler->display->display_options['fields']['field_occupation_social_sites']['id'] = 'field_occupation_social_sites';
  $handler->display->display_options['fields']['field_occupation_social_sites']['table'] = 'field_data_field_occupation_social_sites';
  $handler->display->display_options['fields']['field_occupation_social_sites']['field'] = 'field_occupation_social_sites';
  $handler->display->display_options['fields']['field_occupation_social_sites']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_social_sites']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_occupation_social_sites']['delta_offset'] = '0';
  /* Field: Content: Live video streams */
  $handler->display->display_options['fields']['field_occupation_live_video']['id'] = 'field_occupation_live_video';
  $handler->display->display_options['fields']['field_occupation_live_video']['table'] = 'field_data_field_occupation_live_video';
  $handler->display->display_options['fields']['field_occupation_live_video']['field'] = 'field_occupation_live_video';
  $handler->display->display_options['fields']['field_occupation_live_video']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_live_video']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_occupation_live_video']['delta_offset'] = '0';
  /* Field: Content: Meetup URL */
  $handler->display->display_options['fields']['field_occupation_meetup_url']['id'] = 'field_occupation_meetup_url';
  $handler->display->display_options['fields']['field_occupation_meetup_url']['table'] = 'field_data_field_occupation_meetup_url';
  $handler->display->display_options['fields']['field_occupation_meetup_url']['field'] = 'field_occupation_meetup_url';
  $handler->display->display_options['fields']['field_occupation_meetup_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_meetup_url']['type'] = 'link_plain';
  /* Field: Content: Newspaper URL */
  $handler->display->display_options['fields']['field_occupation_newspaper_url']['id'] = 'field_occupation_newspaper_url';
  $handler->display->display_options['fields']['field_occupation_newspaper_url']['table'] = 'field_data_field_occupation_newspaper_url';
  $handler->display->display_options['fields']['field_occupation_newspaper_url']['field'] = 'field_occupation_newspaper_url';
  $handler->display->display_options['fields']['field_occupation_newspaper_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_newspaper_url']['type'] = 'link_plain';
  /* Field: Content: Occupation description */
  $handler->display->display_options['fields']['field_occupation_description']['id'] = 'field_occupation_description';
  $handler->display->display_options['fields']['field_occupation_description']['table'] = 'field_data_field_occupation_description';
  $handler->display->display_options['fields']['field_occupation_description']['field'] = 'field_occupation_description';
  /* Field: Content: Founded */
  $handler->display->display_options['fields']['field_occupation_origin_date']['id'] = 'field_occupation_origin_date';
  $handler->display->display_options['fields']['field_occupation_origin_date']['table'] = 'field_data_field_occupation_origin_date';
  $handler->display->display_options['fields']['field_occupation_origin_date']['field'] = 'field_occupation_origin_date';
  $handler->display->display_options['fields']['field_occupation_origin_date']['settings'] = array(
    'format_type' => 'date_long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Occupation website */
  $handler->display->display_options['fields']['field_occupation_website']['id'] = 'field_occupation_website';
  $handler->display->display_options['fields']['field_occupation_website']['table'] = 'field_data_field_occupation_website';
  $handler->display->display_options['fields']['field_occupation_website']['field'] = 'field_occupation_website';
  $handler->display->display_options['fields']['field_occupation_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_website']['type'] = 'link_plain';
  /* Field: Content: Additional Occupation websites */
  $handler->display->display_options['fields']['field_occupation_other_websites']['id'] = 'field_occupation_other_websites';
  $handler->display->display_options['fields']['field_occupation_other_websites']['table'] = 'field_data_field_occupation_other_websites';
  $handler->display->display_options['fields']['field_occupation_other_websites']['field'] = 'field_occupation_other_websites';
  $handler->display->display_options['fields']['field_occupation_other_websites']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_other_websites']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_occupation_other_websites']['delta_offset'] = '0';
  /* Field: Content: Physical occupation occurring? */
  $handler->display->display_options['fields']['field_occupation_physical']['id'] = 'field_occupation_physical';
  $handler->display->display_options['fields']['field_occupation_physical']['table'] = 'field_data_field_occupation_physical';
  $handler->display->display_options['fields']['field_occupation_physical']['field'] = 'field_occupation_physical';
  $handler->display->display_options['fields']['field_occupation_physical']['delta_offset'] = '0';
  /* Field: Content: Point of contact email addresses */
  $handler->display->display_options['fields']['field_occupation_emails_other']['id'] = 'field_occupation_emails_other';
  $handler->display->display_options['fields']['field_occupation_emails_other']['table'] = 'field_data_field_occupation_emails_other';
  $handler->display->display_options['fields']['field_occupation_emails_other']['field'] = 'field_occupation_emails_other';
  $handler->display->display_options['fields']['field_occupation_emails_other']['delta_offset'] = '0';
  /* Field: Content: RSS feeds */
  $handler->display->display_options['fields']['field_occupation_rss']['id'] = 'field_occupation_rss';
  $handler->display->display_options['fields']['field_occupation_rss']['table'] = 'field_data_field_occupation_rss';
  $handler->display->display_options['fields']['field_occupation_rss']['field'] = 'field_occupation_rss';
  $handler->display->display_options['fields']['field_occupation_rss']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_rss']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_occupation_rss']['delta_offset'] = '0';
  /* Field: Content: Twitter account(s) */
  $handler->display->display_options['fields']['field_occupation_twitter']['id'] = 'field_occupation_twitter';
  $handler->display->display_options['fields']['field_occupation_twitter']['table'] = 'field_data_field_occupation_twitter';
  $handler->display->display_options['fields']['field_occupation_twitter']['field'] = 'field_occupation_twitter';
  $handler->display->display_options['fields']['field_occupation_twitter']['delta_offset'] = '0';
  /* Field: Content: Twitter hashtag(s) */
  $handler->display->display_options['fields']['field_occupation_twitter_hash']['id'] = 'field_occupation_twitter_hash';
  $handler->display->display_options['fields']['field_occupation_twitter_hash']['table'] = 'field_data_field_occupation_twitter_hash';
  $handler->display->display_options['fields']['field_occupation_twitter_hash']['field'] = 'field_occupation_twitter_hash';
  $handler->display->display_options['fields']['field_occupation_twitter_hash']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_occupation_twitter_hash']['delta_offset'] = '0';
  /* Field: Content: Youtube channel URLs */
  $handler->display->display_options['fields']['field_occupation_youtube_chan']['id'] = 'field_occupation_youtube_chan';
  $handler->display->display_options['fields']['field_occupation_youtube_chan']['table'] = 'field_data_field_occupation_youtube_chan';
  $handler->display->display_options['fields']['field_occupation_youtube_chan']['field'] = 'field_occupation_youtube_chan';
  $handler->display->display_options['fields']['field_occupation_youtube_chan']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_youtube_chan']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_occupation_youtube_chan']['delta_offset'] = '0';
  /* Field: File: Path */
  $handler->display->display_options['fields']['uri']['id'] = 'uri';
  $handler->display->display_options['fields']['uri']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uri']['field'] = 'uri';
  $handler->display->display_options['fields']['uri']['relationship'] = 'node_to_file';
  $handler->display->display_options['fields']['uri']['file_download_path'] = TRUE;
  /* Field: Content: Location (Address) */
  $handler->display->display_options['fields']['field_occupation_address_1']['id'] = 'field_occupation_address_1';
  $handler->display->display_options['fields']['field_occupation_address_1']['table'] = 'field_data_field_occupation_address';
  $handler->display->display_options['fields']['field_occupation_address_1']['field'] = 'field_occupation_address';
  $handler->display->display_options['fields']['field_occupation_address_1']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_occupation_address_1']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['path'] = 'directory.geojson';

  /* Display: Founded Date RSS */
  $handler = $view->new_display('feed', 'Founded Date RSS', 'founded_rss');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Occupy Directory RSS, founded';
  $handler->display->display_options['display_description'] = 'Occupations that have a founded date, for inclusion on the S17 site.';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['style_options']['description'] = 'Occupations with a founded date';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['row_options']['item_length'] = 'rss';
  $handler->display->display_options['row_options']['links'] = TRUE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Founded (field_occupation_origin_date) */
  $handler->display->display_options['sorts']['field_occupation_origin_date_value']['id'] = 'field_occupation_origin_date_value';
  $handler->display->display_options['sorts']['field_occupation_origin_date_value']['table'] = 'field_data_field_occupation_origin_date';
  $handler->display->display_options['sorts']['field_occupation_origin_date_value']['field'] = 'field_occupation_origin_date_value';
  $handler->display->display_options['sorts']['field_occupation_origin_date_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'occupation' => 'occupation',
  );
  /* Filter criterion: has a Founded Date */
  $handler->display->display_options['filters']['field_occupation_origin_date_value']['id'] = 'field_occupation_origin_date_value';
  $handler->display->display_options['filters']['field_occupation_origin_date_value']['table'] = 'field_data_field_occupation_origin_date';
  $handler->display->display_options['filters']['field_occupation_origin_date_value']['field'] = 'field_occupation_origin_date_value';
  $handler->display->display_options['filters']['field_occupation_origin_date_value']['ui_name'] = 'has a Founded Date';
  $handler->display->display_options['filters']['field_occupation_origin_date_value']['operator'] = 'not empty';
  $handler->display->display_options['path'] = 'occupations/founded.rss';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;
  $export['occupation_exports_and_data'] = $view;

  return $export;
}
