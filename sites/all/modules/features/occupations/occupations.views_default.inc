<?php
/**
 * @file
 * occupations.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function occupations_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'occupation_directory';
  $view->description = 'tabbed views to list and manage occupations';
  $view->tag = 'FGA';
  $view->base_table = 'node';
  $view->human_name = 'Occupation Directory';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Directory of Occupations';
  $handler->display->display_options['css_class'] = 'list-occupations node-list';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'apply';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'reset';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'display';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '10, 25, 50, 100, 250, 500, 1000';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = TRUE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'title' => 'title',
    'field_occupation_address' => 'field_occupation_address',
    'status' => 'status',
    'comment_count' => 'comment_count',
    'new_comments' => 'new_comments',
    'last_updated' => 'last_updated',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_occupation_address' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
    'comment_count' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
    'new_comments' => array(
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
    'last_updated' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '<span class="occupation-count">Displaying <span class="occupation-count-span">@start - @end</span> of <span class="occupation-count-total">@total</span> Occupations</span>';
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

  /* Display: Directory List */
  $handler = $view->new_display('page', 'Directory List', 'occupations_list');
  $handler->display->display_options['display_description'] = 'A table showing all Occupations, sorted by ___, paginated x 10';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '-1';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'apply';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'reset';
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'display';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '10, 25, 50, 100, 250, 500, 1000';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_occupation_image' => 'field_occupation_image',
    'rendered_entity' => 'rendered_entity',
    'field_occupation_origin_date' => 'rendered_entity',
    'field_occupation_address' => 'field_occupation_address',
    'field_occupation_address_2' => 'field_occupation_address',
    'field_occupation_address_1' => 'field_occupation_address',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_occupation_image' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'rendered_entity' => array(
      'align' => '',
      'separator' => ' ',
      'empty_column' => 0,
    ),
    'field_occupation_origin_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_occupation_address' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => ', ',
      'empty_column' => 0,
    ),
    'field_occupation_address_2' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_occupation_address_1' => array(
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
  );
  $handler->display->display_options['style_options']['summary'] = 'A listing of all known Occupations';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = 'There aren\'t any listings based on your search criteria, but it\'s only a matter of time.

Do you have the information? <strong><a href="/node/add/occupation">Add an Occupation</a>!</strong>';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Occupation Image or Icon */
  $handler->display->display_options['fields']['field_occupation_image']['id'] = 'field_occupation_image';
  $handler->display->display_options['fields']['field_occupation_image']['table'] = 'field_data_field_occupation_image';
  $handler->display->display_options['fields']['field_occupation_image']['field'] = 'field_occupation_image';
  $handler->display->display_options['fields']['field_occupation_image']['label'] = '';
  $handler->display->display_options['fields']['field_occupation_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_occupation_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_occupation_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_occupation_image']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_occupation_image']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_occupation_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_occupation_image']['settings'] = array(
    'image_style' => 'occupation_thumb_sm',
    'image_link' => 'content',
  );
  /* Field: Content: Rendered Node */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['label'] = 'Name of Occupation';
  $handler->display->display_options['fields']['rendered_entity']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['rendered_entity']['alter']['text'] = '[field_occupation_image] [rendered_entity]';
  $handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['view_mode'] = 'full';
  /* Field: Content: Founded */
  $handler->display->display_options['fields']['field_occupation_origin_date']['id'] = 'field_occupation_origin_date';
  $handler->display->display_options['fields']['field_occupation_origin_date']['table'] = 'field_data_field_occupation_origin_date';
  $handler->display->display_options['fields']['field_occupation_origin_date']['field'] = 'field_occupation_origin_date';
  $handler->display->display_options['fields']['field_occupation_origin_date']['label'] = '';
  $handler->display->display_options['fields']['field_occupation_origin_date']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_occupation_origin_date']['alter']['text'] = 'founded: [field_occupation_origin_date]';
  $handler->display->display_options['fields']['field_occupation_origin_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_occupation_origin_date']['settings'] = array(
    'format_type' => 'date_short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Location (Address) */
  $handler->display->display_options['fields']['field_occupation_address']['id'] = 'field_occupation_address';
  $handler->display->display_options['fields']['field_occupation_address']['table'] = 'field_data_field_occupation_address';
  $handler->display->display_options['fields']['field_occupation_address']['field'] = 'field_occupation_address';
  $handler->display->display_options['fields']['field_occupation_address']['label'] = 'Location';
  $handler->display->display_options['fields']['field_occupation_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_occupation_address']['type'] = 'locality';
  $handler->display->display_options['fields']['field_occupation_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Content: Location (Address) */
  $handler->display->display_options['fields']['field_occupation_address_2']['id'] = 'field_occupation_address_2';
  $handler->display->display_options['fields']['field_occupation_address_2']['table'] = 'field_data_field_occupation_address';
  $handler->display->display_options['fields']['field_occupation_address_2']['field'] = 'field_occupation_address';
  $handler->display->display_options['fields']['field_occupation_address_2']['label'] = 'State/Province';
  $handler->display->display_options['fields']['field_occupation_address_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_occupation_address_2']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_occupation_address_2']['type'] = 'administrative_area';
  $handler->display->display_options['fields']['field_occupation_address_2']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Content: Location (Address) */
  $handler->display->display_options['fields']['field_occupation_address_1']['id'] = 'field_occupation_address_1';
  $handler->display->display_options['fields']['field_occupation_address_1']['table'] = 'field_data_field_occupation_address';
  $handler->display->display_options['fields']['field_occupation_address_1']['field'] = 'field_occupation_address';
  $handler->display->display_options['fields']['field_occupation_address_1']['label'] = 'Country';
  $handler->display->display_options['fields']['field_occupation_address_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_occupation_address_1']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_occupation_address_1']['type'] = 'country';
  $handler->display->display_options['fields']['field_occupation_address_1']['settings'] = array(
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
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Alphabetically by Country */
  $handler->display->display_options['sorts']['field_occupation_address_country']['id'] = 'field_occupation_address_country';
  $handler->display->display_options['sorts']['field_occupation_address_country']['table'] = 'field_data_field_occupation_address';
  $handler->display->display_options['sorts']['field_occupation_address_country']['field'] = 'field_occupation_address_country';
  $handler->display->display_options['sorts']['field_occupation_address_country']['ui_name'] = 'Alphabetically by Country';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Location (Address) (field_occupation_address:country) */
  $handler->display->display_options['arguments']['field_occupation_address_country']['id'] = 'field_occupation_address_country';
  $handler->display->display_options['arguments']['field_occupation_address_country']['table'] = 'field_data_field_occupation_address';
  $handler->display->display_options['arguments']['field_occupation_address_country']['field'] = 'field_occupation_address_country';
  $handler->display->display_options['arguments']['field_occupation_address_country']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_occupation_address_country']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_occupation_address_country']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_occupation_address_country']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_occupation_address_country']['limit'] = '0';
  /* Contextual filter: Content: Location (Address) (field_occupation_address:administrative_area) */
  $handler->display->display_options['arguments']['field_occupation_address_administrative_area']['id'] = 'field_occupation_address_administrative_area';
  $handler->display->display_options['arguments']['field_occupation_address_administrative_area']['table'] = 'field_data_field_occupation_address';
  $handler->display->display_options['arguments']['field_occupation_address_administrative_area']['field'] = 'field_occupation_address_administrative_area';
  $handler->display->display_options['arguments']['field_occupation_address_administrative_area']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_occupation_address_administrative_area']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_occupation_address_administrative_area']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_occupation_address_administrative_area']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_occupation_address_administrative_area']['limit'] = '0';
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
  /* Filter criterion: Content: Location (Address) (field_occupation_address:locality) */
  $handler->display->display_options['filters']['field_occupation_address_locality']['id'] = 'field_occupation_address_locality';
  $handler->display->display_options['filters']['field_occupation_address_locality']['table'] = 'field_data_field_occupation_address';
  $handler->display->display_options['filters']['field_occupation_address_locality']['field'] = 'field_occupation_address_locality';
  $handler->display->display_options['filters']['field_occupation_address_locality']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_occupation_address_locality']['group'] = 2;
  $handler->display->display_options['filters']['field_occupation_address_locality']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_occupation_address_locality']['expose']['operator_id'] = 'field_occupation_address_locality_op';
  $handler->display->display_options['filters']['field_occupation_address_locality']['expose']['label'] = 'City';
  $handler->display->display_options['filters']['field_occupation_address_locality']['expose']['operator'] = 'field_occupation_address_locality_op';
  $handler->display->display_options['filters']['field_occupation_address_locality']['expose']['identifier'] = 'city';
  /* Filter criterion: Content: Location (Address) (field_occupation_address:country) */
  $handler->display->display_options['filters']['field_occupation_address_country']['id'] = 'field_occupation_address_country';
  $handler->display->display_options['filters']['field_occupation_address_country']['table'] = 'field_data_field_occupation_address';
  $handler->display->display_options['filters']['field_occupation_address_country']['field'] = 'field_occupation_address_country';
  $handler->display->display_options['filters']['field_occupation_address_country']['group'] = 2;
  $handler->display->display_options['filters']['field_occupation_address_country']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_occupation_address_country']['expose']['operator_id'] = 'field_occupation_address_country_op';
  $handler->display->display_options['filters']['field_occupation_address_country']['expose']['label'] = 'Country';
  $handler->display->display_options['filters']['field_occupation_address_country']['expose']['operator'] = 'field_occupation_address_country_op';
  $handler->display->display_options['filters']['field_occupation_address_country']['expose']['identifier'] = 'country';
  $handler->display->display_options['filters']['field_occupation_address_country']['expose']['remember'] = TRUE;
  $handler->display->display_options['path'] = 'occupations/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Directory List';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['title'] = 'List';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'main-menu';

  /* Display: Cards */
  $handler = $view->new_display('page', 'Cards', 'occupations_cards');
  $handler->display->display_options['display_description'] = 'Card-like display of occupations';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '25, 50, 100, 250, 500, 1000';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Occupation Image or Icon */
  $handler->display->display_options['fields']['field_occupation_image']['id'] = 'field_occupation_image';
  $handler->display->display_options['fields']['field_occupation_image']['table'] = 'field_data_field_occupation_image';
  $handler->display->display_options['fields']['field_occupation_image']['field'] = 'field_occupation_image';
  $handler->display->display_options['fields']['field_occupation_image']['label'] = '';
  $handler->display->display_options['fields']['field_occupation_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_occupation_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_occupation_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: City */
  $handler->display->display_options['fields']['field_occupation_address']['id'] = 'field_occupation_address';
  $handler->display->display_options['fields']['field_occupation_address']['table'] = 'field_data_field_occupation_address';
  $handler->display->display_options['fields']['field_occupation_address']['field'] = 'field_occupation_address';
  $handler->display->display_options['fields']['field_occupation_address']['ui_name'] = 'City';
  $handler->display->display_options['fields']['field_occupation_address']['label'] = '';
  $handler->display->display_options['fields']['field_occupation_address']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_occupation_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_occupation_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_occupation_address']['type'] = 'locality';
  $handler->display->display_options['fields']['field_occupation_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: State */
  $handler->display->display_options['fields']['field_occupation_address_2']['id'] = 'field_occupation_address_2';
  $handler->display->display_options['fields']['field_occupation_address_2']['table'] = 'field_data_field_occupation_address';
  $handler->display->display_options['fields']['field_occupation_address_2']['field'] = 'field_occupation_address';
  $handler->display->display_options['fields']['field_occupation_address_2']['ui_name'] = 'State';
  $handler->display->display_options['fields']['field_occupation_address_2']['label'] = '';
  $handler->display->display_options['fields']['field_occupation_address_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_occupation_address_2']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_occupation_address_2']['alter']['text'] = '[field_occupation_address_2-administrative_area], ';
  $handler->display->display_options['fields']['field_occupation_address_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_occupation_address_2']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_occupation_address_2']['type'] = 'administrative_area';
  $handler->display->display_options['fields']['field_occupation_address_2']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Country */
  $handler->display->display_options['fields']['field_occupation_address_1']['id'] = 'field_occupation_address_1';
  $handler->display->display_options['fields']['field_occupation_address_1']['table'] = 'field_data_field_occupation_address';
  $handler->display->display_options['fields']['field_occupation_address_1']['field'] = 'field_occupation_address';
  $handler->display->display_options['fields']['field_occupation_address_1']['ui_name'] = 'Country';
  $handler->display->display_options['fields']['field_occupation_address_1']['label'] = '';
  $handler->display->display_options['fields']['field_occupation_address_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_occupation_address_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_occupation_address_1']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_occupation_address_1']['type'] = 'country';
  $handler->display->display_options['fields']['field_occupation_address_1']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Location */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['ui_name'] = 'Location';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = '[field_occupation_address], [field_occupation_address_2][field_occupation_address_1]';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Facebook Page(s) */
  $handler->display->display_options['fields']['field_occupation_facebook']['id'] = 'field_occupation_facebook';
  $handler->display->display_options['fields']['field_occupation_facebook']['table'] = 'field_data_field_occupation_facebook';
  $handler->display->display_options['fields']['field_occupation_facebook']['field'] = 'field_occupation_facebook';
  $handler->display->display_options['fields']['field_occupation_facebook']['label'] = '';
  $handler->display->display_options['fields']['field_occupation_facebook']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_occupation_facebook']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_occupation_facebook']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_facebook']['type'] = 'link_url';
  $handler->display->display_options['fields']['field_occupation_facebook']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_occupation_facebook']['multi_type'] = 'ul';
  /* Field: Content: Occupation website */
  $handler->display->display_options['fields']['field_occupation_website']['id'] = 'field_occupation_website';
  $handler->display->display_options['fields']['field_occupation_website']['table'] = 'field_data_field_occupation_website';
  $handler->display->display_options['fields']['field_occupation_website']['field'] = 'field_occupation_website';
  $handler->display->display_options['fields']['field_occupation_website']['label'] = '';
  $handler->display->display_options['fields']['field_occupation_website']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_occupation_website']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_occupation_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_occupation_website']['type'] = 'link_url';
  /* Field: Content: General email address */
  $handler->display->display_options['fields']['field_occupation_email_general']['id'] = 'field_occupation_email_general';
  $handler->display->display_options['fields']['field_occupation_email_general']['table'] = 'field_data_field_occupation_email_general';
  $handler->display->display_options['fields']['field_occupation_email_general']['field'] = 'field_occupation_email_general';
  $handler->display->display_options['fields']['field_occupation_email_general']['label'] = '';
  $handler->display->display_options['fields']['field_occupation_email_general']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_occupation_email_general']['hide_empty'] = TRUE;
  /* Field: Content: Twitter account(s) */
  $handler->display->display_options['fields']['field_occupation_twitter']['id'] = 'field_occupation_twitter';
  $handler->display->display_options['fields']['field_occupation_twitter']['table'] = 'field_data_field_occupation_twitter';
  $handler->display->display_options['fields']['field_occupation_twitter']['field'] = 'field_occupation_twitter';
  $handler->display->display_options['fields']['field_occupation_twitter']['label'] = '';
  $handler->display->display_options['fields']['field_occupation_twitter']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_occupation_twitter']['alter']['path'] = 'http://twitter.com/[field_occupation_twitter]';
  $handler->display->display_options['fields']['field_occupation_twitter']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['field_occupation_twitter']['alter']['link_class'] = 'twitter';
  $handler->display->display_options['fields']['field_occupation_twitter']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['field_occupation_twitter']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_occupation_twitter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_occupation_twitter']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_occupation_twitter']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_occupation_twitter']['multi_type'] = 'ul';
  $handler->display->display_options['path'] = 'occupations/cards';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Cards';
  $handler->display->display_options['menu']['weight'] = '3';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Directory Moderation */
  $handler = $view->new_display('page', 'Directory Moderation', 'occupations_manage');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Moderate Occupations';
  $handler->display->display_options['display_comment'] = 'we expose a different filter block on the manage occupations page';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'list-occupations node-list manage-occupations table-view curate';
  $handler->display->display_options['display_description'] = 'Curators use this page to manage geograhic-area specific Occupation content via Views Bulk Operations';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'edit any occupation content';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'display/page';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '10, 25, 50, 100, 250, 500, 1000';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'title' => 'title',
    'field_occupation_address' => 'field_occupation_address',
    'status' => 'status',
    'comment_count' => 'comment_count',
    'field_comments_new' => 'field_comments_new',
    'field_comments_willdo' => 'field_comments_willdo',
    'field_comments_rejected' => 'field_comments_rejected',
    'field_comments_done' => 'field_comments_done',
    'last_updated' => 'last_updated',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_occupation_address' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
    'comment_count' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_comments_new' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_comments_willdo' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_comments_rejected' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_comments_done' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
    'last_updated' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Utility links for Curators */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['ui_name'] = 'Utility links for Curators';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<div class="curator-utility-links"><a href="/node/add/occupation">+ Add new Occupation</a></div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '<span class="occupation-count">Displaying <span class="occupation-count-span">@start - @end</span> of <span class="occupation-count-total">@total</span> Occupations</span>';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '25';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'rules_component::rules_batch_update_state_names' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_assign_owner_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_sticky_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::node_promote_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpromote_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_save_action' => array(
      'selected' => 1,
      'postpone_processing' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_by_keyword_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::pathauto_node_update_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
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
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = 'Comments';
  $handler->display->display_options['fields']['comment_count']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['comment_count']['separator'] = '';
  /* Field: Content: New comments count */
  $handler->display->display_options['fields']['field_comments_new']['id'] = 'field_comments_new';
  $handler->display->display_options['fields']['field_comments_new']['table'] = 'field_data_field_comments_new';
  $handler->display->display_options['fields']['field_comments_new']['field'] = 'field_comments_new';
  $handler->display->display_options['fields']['field_comments_new']['label'] = 'New';
  /* Field: Content: Will Do comments count */
  $handler->display->display_options['fields']['field_comments_willdo']['id'] = 'field_comments_willdo';
  $handler->display->display_options['fields']['field_comments_willdo']['table'] = 'field_data_field_comments_willdo';
  $handler->display->display_options['fields']['field_comments_willdo']['field'] = 'field_comments_willdo';
  $handler->display->display_options['fields']['field_comments_willdo']['label'] = 'Will Do';
  /* Field: Content: Rejected comments count */
  $handler->display->display_options['fields']['field_comments_rejected']['id'] = 'field_comments_rejected';
  $handler->display->display_options['fields']['field_comments_rejected']['table'] = 'field_data_field_comments_rejected';
  $handler->display->display_options['fields']['field_comments_rejected']['field'] = 'field_comments_rejected';
  $handler->display->display_options['fields']['field_comments_rejected']['label'] = 'Rejected';
  /* Field: Content: Done comments count */
  $handler->display->display_options['fields']['field_comments_done']['id'] = 'field_comments_done';
  $handler->display->display_options['fields']['field_comments_done']['table'] = 'field_data_field_comments_done';
  $handler->display->display_options['fields']['field_comments_done']['field'] = 'field_comments_done';
  $handler->display->display_options['fields']['field_comments_done']['label'] = 'Done';
  /* Field: Content: Updated/commented date */
  $handler->display->display_options['fields']['last_updated']['id'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['last_updated']['field'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['label'] = 'Last Update';
  $handler->display->display_options['fields']['last_updated']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['last_updated']['date_format'] = 'raw time ago';
  $handler->display->display_options['fields']['last_updated']['custom_date_format'] = '1';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Updated/commented date */
  $handler->display->display_options['sorts']['last_updated']['id'] = 'last_updated';
  $handler->display->display_options['sorts']['last_updated']['table'] = 'node_comment_statistics';
  $handler->display->display_options['sorts']['last_updated']['field'] = 'last_updated';
  $handler->display->display_options['sorts']['last_updated']['order'] = 'DESC';
  $handler->display->display_options['sorts']['last_updated']['expose']['label'] = 'Updated/commented date';
  $handler->display->display_options['sorts']['last_updated']['granularity'] = 'minute';
  /* Sort criterion: Content: Published */
  $handler->display->display_options['sorts']['status']['id'] = 'status';
  $handler->display->display_options['sorts']['status']['table'] = 'node';
  $handler->display->display_options['sorts']['status']['field'] = 'status';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Filter by user&#039;s chosen geographic area */
  $handler->display->display_options['arguments']['field_term_geographic_area_tid']['id'] = 'field_term_geographic_area_tid';
  $handler->display->display_options['arguments']['field_term_geographic_area_tid']['table'] = 'field_data_field_term_geographic_area';
  $handler->display->display_options['arguments']['field_term_geographic_area_tid']['field'] = 'field_term_geographic_area_tid';
  $handler->display->display_options['arguments']['field_term_geographic_area_tid']['ui_name'] = 'Filter by user\'s chosen geographic area';
  $handler->display->display_options['arguments']['field_term_geographic_area_tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_term_geographic_area_tid']['title'] = 'Manage Geographic Area-specific Occupations';
  $handler->display->display_options['arguments']['field_term_geographic_area_tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_term_geographic_area_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_term_geographic_area_tid']['summary']['format'] = 'jump_menu_summary';
  $handler->display->display_options['arguments']['field_term_geographic_area_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_term_geographic_area_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_term_geographic_area_tid']['validate_options']['vocabularies'] = array(
    'geographic_area' => 'geographic_area',
  );
  $handler->display->display_options['arguments']['field_term_geographic_area_tid']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['field_term_geographic_area_tid']['validate']['fail'] = 'ignore';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'occupation' => 'occupation',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: City */
  $handler->display->display_options['filters']['field_occupation_address_locality']['id'] = 'field_occupation_address_locality';
  $handler->display->display_options['filters']['field_occupation_address_locality']['table'] = 'field_data_field_occupation_address';
  $handler->display->display_options['filters']['field_occupation_address_locality']['field'] = 'field_occupation_address_locality';
  $handler->display->display_options['filters']['field_occupation_address_locality']['ui_name'] = 'City';
  $handler->display->display_options['filters']['field_occupation_address_locality']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_occupation_address_locality']['group'] = 1;
  $handler->display->display_options['filters']['field_occupation_address_locality']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_occupation_address_locality']['expose']['operator_id'] = 'field_occupation_address_locality_op';
  $handler->display->display_options['filters']['field_occupation_address_locality']['expose']['label'] = 'City';
  $handler->display->display_options['filters']['field_occupation_address_locality']['expose']['operator'] = 'field_occupation_address_locality_op';
  $handler->display->display_options['filters']['field_occupation_address_locality']['expose']['identifier'] = 'city';
  /* Filter criterion: Content: Location (Address) (field_occupation_address:country) */
  $handler->display->display_options['filters']['field_occupation_address_country']['id'] = 'field_occupation_address_country';
  $handler->display->display_options['filters']['field_occupation_address_country']['table'] = 'field_data_field_occupation_address';
  $handler->display->display_options['filters']['field_occupation_address_country']['field'] = 'field_occupation_address_country';
  $handler->display->display_options['filters']['field_occupation_address_country']['group'] = 1;
  $handler->display->display_options['filters']['field_occupation_address_country']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_occupation_address_country']['expose']['operator_id'] = 'field_occupation_address_country_op';
  $handler->display->display_options['filters']['field_occupation_address_country']['expose']['label'] = 'Country';
  $handler->display->display_options['filters']['field_occupation_address_country']['expose']['operator'] = 'field_occupation_address_country_op';
  $handler->display->display_options['filters']['field_occupation_address_country']['expose']['identifier'] = 'country';
  $handler->display->display_options['filters']['field_occupation_address_country']['expose']['remember'] = TRUE;
  $handler->display->display_options['path'] = 'moderate/occupations';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Moderate Occupations';
  $handler->display->display_options['menu']['weight'] = '33';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Moderate';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'main-menu';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'My Occupations';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['uid']['validate']['type'] = 'user';
  $handler->display->display_options['arguments']['uid']['validate_options']['restrict_roles'] = TRUE;
  $handler->display->display_options['arguments']['uid']['validate_options']['roles'] = array(
    2 => '2',
  );
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
  $handler->display->display_options['block_description'] = 'My Occupations';

  /* Display: user tab */
  $handler = $view->new_display('page', 'user tab', 'my_occupations');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'My Occupations';
  $handler->display->display_options['display_description'] = 'Display occupations owned by the user on their user account';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '10, 25, 50, 100, 250, 500, 1000';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '<span class="occupation-count">You own <span class="occupation-count-total">@total</span> Occupation(s)</span>';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = 'You don\'t have any occupations associated with your account at this time.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Occupation Image or Icon */
  $handler->display->display_options['fields']['field_occupation_image']['id'] = 'field_occupation_image';
  $handler->display->display_options['fields']['field_occupation_image']['table'] = 'field_data_field_occupation_image';
  $handler->display->display_options['fields']['field_occupation_image']['field'] = 'field_occupation_image';
  $handler->display->display_options['fields']['field_occupation_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_occupation_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_occupation_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'content',
  );
  /* Field: Content: Rendered Node */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['label'] = 'Occupation Name';
  $handler->display->display_options['fields']['rendered_entity']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['rendered_entity']['alter']['text'] = '[field_occupation_image] [rendered_entity]';
  $handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['view_mode'] = 'full';
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
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['uid']['validate']['type'] = 'user';
  $handler->display->display_options['arguments']['uid']['validate_options']['type'] = 'either';
  $handler->display->display_options['arguments']['uid']['validate_options']['restrict_roles'] = TRUE;
  $handler->display->display_options['arguments']['uid']['validate_options']['roles'] = array(
    2 => '2',
  );
  $handler->display->display_options['path'] = 'user/%/occupations';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'My Occupations';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $export['occupation_directory'] = $view;

  return $export;
}
