<?php

/**
 * @file
 *  Canned view to display a summary of all site content.
 */

/**
 * Implements hook_views_default_views().
 */
function revisioning_views_default_views() {
  /*
   * View 'revisioning_content_summary'
   */
  $view = new view;
  $view->name = 'revisioning_content_summary';
  $view->description = 'Summary of moderated and unmoderated site content.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = '';
  $view->core = 0;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => 2,
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = 20;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'type' => 'type',
    'changed' => 'changed',
    'name' => 'name',
    'number_of_revisions' => 'number_of_revisions',
    'state' => 'state',
    'view_node' => 'view_node',
    'edit_node' => 'edit_node',
    'timestamp' => 'timestamp',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'type' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'changed' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'name' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'number_of_revisions' => array(
      'sortable' => 0,
      'separator' => '',
    ),
    'state' => array(
      'sortable' => 0,
      'separator' => '',
    ),
    'view_node' => array(
      'separator' => '',
    ),
    'edit_node' => array(
      'separator' => '',
    ),
    'timestamp' => array(
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['text']['id'] = 'area';
  $handler->display->display_options['header']['text']['table'] = 'views';
  $handler->display->display_options['header']['text']['field'] = 'area';
  $handler->display->display_options['header']['text']['empty'] = FALSE;
  $handler->display->display_options['header']['text']['content'] = 'Summary of site content';
  $handler->display->display_options['header']['text']['format'] = '2';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['text']['id'] = 'area';
  $handler->display->display_options['empty']['text']['table'] = 'views';
  $handler->display->display_options['empty']['text']['field'] = 'area';
  $handler->display->display_options['empty']['text']['empty'] = FALSE;
  $handler->display->display_options['empty']['text']['content'] = 'No content matches your query.';
  $handler->display->display_options['empty']['text']['format'] = '2';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'node/[nid]/view';
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Last updated';
  $handler->display->display_options['fields']['changed']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['html'] = 0;
  $handler->display->display_options['fields']['changed']['hide_empty'] = 0;
  $handler->display->display_options['fields']['changed']['empty_zero'] = 0;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Author';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  /* Field: Content: Revision moderation */
  $handler->display->display_options['fields']['revision_moderation']['id'] = 'revision_moderation';
  $handler->display->display_options['fields']['revision_moderation']['table'] = 'node';
  $handler->display->display_options['fields']['revision_moderation']['field'] = 'revision_moderation';
  $handler->display->display_options['fields']['revision_moderation']['label'] = 'Mod?';
  $handler->display->display_options['fields']['revision_moderation']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['revision_moderation']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['revision_moderation']['alter']['path'] = 'node/[nid]/revisions';
  $handler->display->display_options['fields']['revision_moderation']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['revision_moderation']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['revision_moderation']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['revision_moderation']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['revision_moderation']['alter']['html'] = 0;
  $handler->display->display_options['fields']['revision_moderation']['empty'] = 'No';
  $handler->display->display_options['fields']['revision_moderation']['hide_empty'] = 1;
  $handler->display->display_options['fields']['revision_moderation']['empty_zero'] = 0;
  /* Field: Content: Revisions */
  $handler->display->display_options['fields']['number_of_revisions']['id'] = 'number_of_revisions';
  $handler->display->display_options['fields']['number_of_revisions']['table'] = 'node';
  $handler->display->display_options['fields']['number_of_revisions']['field'] = 'number_of_revisions';
  $handler->display->display_options['fields']['number_of_revisions']['label'] = 'Rev.';
  $handler->display->display_options['fields']['number_of_revisions']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['number_of_revisions']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['number_of_revisions']['alter']['alt'] = 'View revision summary';
  $handler->display->display_options['fields']['number_of_revisions']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['number_of_revisions']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['number_of_revisions']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['number_of_revisions']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['number_of_revisions']['alter']['html'] = 0;
  $handler->display->display_options['fields']['number_of_revisions']['hide_empty'] = 0;
  $handler->display->display_options['fields']['number_of_revisions']['empty_zero'] = 0;
  /* Field: Content: State */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'node';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_node']['empty_zero'] = 0;
  /* Field: Content: Has new content */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['timestamp']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['timestamp']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['html'] = 0;
  $handler->display->display_options['fields']['timestamp']['hide_empty'] = 0;
  $handler->display->display_options['fields']['timestamp']['empty_zero'] = 0;
  $handler->display->display_options['fields']['timestamp']['link_to_node'] = 0;
  $handler->display->display_options['fields']['timestamp']['comments'] = 0;
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  /* Filter criterion: Content: Revision moderation */
  $handler->display->display_options['filters']['revision_moderation']['id'] = 'revision_moderation';
  $handler->display->display_options['filters']['revision_moderation']['table'] = 'node';
  $handler->display->display_options['filters']['revision_moderation']['field'] = 'revision_moderation';
  $handler->display->display_options['filters']['revision_moderation']['exposed'] = TRUE;
  $handler->display->display_options['filters']['revision_moderation']['expose']['operator_id'] = 'revision_moderation_op';
  $handler->display->display_options['filters']['revision_moderation']['expose']['label'] = 'Moderated?';
  $handler->display->display_options['filters']['revision_moderation']['expose']['operator'] = 'revision_moderation_op';
  $handler->display->display_options['filters']['revision_moderation']['expose']['identifier'] = 'revision_moderation';
  $handler->display->display_options['filters']['revision_moderation']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['revision_moderation']['expose']['reduce'] = 0;
  /* Filter criterion: Content: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'node';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['exposed'] = TRUE;
  $handler->display->display_options['filters']['state']['expose']['operator_id'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['label'] = 'State';
  $handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
  $handler->display->display_options['filters']['state']['expose']['reduce'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'content-summary';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Content summary';
  $handler->display->display_options['menu']['description'] = 'Summary of site content';
  $handler->display->display_options['menu']['weight'] = '-1';
  $translatables['revisioning_content_summary'] = array(
    t('Defaults'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Summary of site content'),
    t('No content matches your query.'),
    t('Nid'),
    t('Title'),
    t('node/[nid]/view'),
    t('Type'),
    t('Last updated'),
    t('Author'),
    t('Mod?'),
    t('node/[nid]/revisions'),
    t('No'),
    t('Rev.'),
    t('View revision summary'),
    t('State'),
    t('Moderated?'),
    t('Page'),
  );

  $views[$view->name] = $view;
  return $views;
}
