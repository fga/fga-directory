<?php

/**
 * @file
 * System display plugin.
 */

/**
 * Plugin to handle replacement of existing system paths.
 *
 * @ingroup views_display_plugins
 */
class views_plugin_display_system extends views_plugin_display {
  /**
   * The system display requires a path.
   */
  function has_path() {
    return TRUE;
  }

  // @todo Needed?
  function uses_breadcrumb() {
    return TRUE;
  }

  function option_definition() {
    $options = parent::option_definition();

    $options['path'] = array(
      'default' => '',
    );

    return $options;
  }

  /**
   * Add this display's path information to Drupal's menu system.
   */
  function execute_hook_menu(&$callbacks) {
    $items = array();

    // Replace % with the link to our standard views argument loader
    // views_arg_load().
    $bits = explode('/', $this->get_option('path'));
    $page_arguments = array($this->view->name, $this->display->id);
    $this->view->init_handlers();
    $view_arguments = $this->view->argument;

    // Replace % with %views_arg for menu autoloading and add to the
    // page arguments so the argument actually comes through.
    foreach ($bits as $pos => $bit) {
      if ($bit == '%') {
        $argument = array_shift($view_arguments);
        if (!empty($argument->options['specify_validation']) && $argument->options['validate']['type'] != 'none') {
          $bits[$pos] = '%views_arg';
        }
        $page_arguments[] = $pos;
      }
    }

    $path = implode('/', $bits);
    if (!$path) {
      return $items;
    }

    $access_plugin = $this->get_plugin('access');
    if (!isset($access_plugin)) {
      $access_plugin = views_get_plugin('access', 'none');
    }

    // Get access callback might return an array of the callback + the dynamic arguments.
    $access_plugin_callback = $access_plugin->get_access_callback();

    if (is_array($access_plugin_callback)) {
      $access_arguments = array();

      // Find the plugin arguments.
      $access_plugin_method = array_shift($access_plugin_callback);
      $access_plugin_arguments = array_shift($access_plugin_callback);
      if (!is_array($access_plugin_arguments)) {
        $access_plugin_arguments = array();
      }

      $access_arguments[0] = array($access_plugin_method, &$access_plugin_arguments);

      // Move the plugin arguments to the access arguments array.
      $i = 1;
      foreach ($access_plugin_arguments as $key => $value) {
        if (is_int($value)) {
          $access_arguments[$i] = $value;
          $access_plugin_arguments[$key] = $i;
          $i++;
        }
      }
    }
    else {
      $access_arguments = array($access_plugin_callback);
    }

    $items[$path] = array(
      // default views page entry
      'page callback' => 'views_page',
      'page arguments' => $page_arguments,
      // Default access check (per display)
      'access callback' => 'views_access',
      'access arguments' => $access_arguments,
      // Identify URL embedded arguments and correlate them to a handler
      'load arguments'  => array($this->view->name, $this->display->id, '%index'),
    );

    // Setup a list of keys on the router item for $path, which we are going to
    // replace. Since the menu system inherits router item properties to child
    // paths, we need to ensure that child paths do not inherit the properties
    // for the view, but instead, get the original properties of $path.
    $keys = array_fill_keys(array_keys($items[$path]), NULL);
    $keys += array(
      'file' => NULL,
      'file path' => NULL,
    );

    // Grep all callbacks for router items below the target path.
    $num_parent_parts = count(explode('/', $path));
    $children = preg_grep('@^' . preg_quote($path, '@') . '/@', array_keys($callbacks));
    // Ensure correct inheritance of properties on the original parent path
    // (being replaced) to child items.
    foreach ($children as $child_path) {
      // Default local tasks can be skipped, since the only properties that
      // matter for them are 'title', 'description', and 'weight'.
      if (!isset($callbacks[$child_path]['type']) || $callbacks[$child_path]['type'] != MENU_DEFAULT_LOCAL_TASK) {
        // If this is a direct child, copy original properties form parent path.
        $num_child_parts = count(explode('/', $child_path));
        if (isset($callbacks[$path]) && ($num_parent_parts + 1 == $num_child_parts)) {
          // Copy properties from the parent item, which are not set on the
          // child. The menu system would normally inherit these to the child.
          $callbacks[$child_path] += array_intersect_key($callbacks[$path], $keys);
          // Some properties may not be set on the original parent item, but
          // are set on the new views parent item. The menu system would inherit
          // these to children; prevent that by setting NULL values.
          $callbacks[$child_path] += $keys;
        }
      }
    }

    // If the original parent path already existed, copy over its remaining
    // properties.
    // @todo Above inheritance code can probably be moved into this condition.
    if (isset($callbacks[$path])) {
      $items[$path] += $callbacks[$path];
    }

    return $items;
  }

  /**
   * Build and render the page view.
   *
   * Since we replace an existing page, we need to invoke views_set_page_view().
   * Also set the page title, because original page callbacks might do this.
   */
  function execute() {
    views_set_page_view($this->view);

    // Prior to this being called, the $view should already be set to this
    // display, and arguments should be set on the view.
    $this->view->build();
    if (!empty($this->view->build_info['fail'])) {
      return drupal_not_found();
    }
    // @todo Needed?
    $this->view->get_breadcrumb(TRUE);

    drupal_set_title(filter_xss_admin($this->view->get_title()), PASS_THROUGH);

    // @todo This is super-likely the totally wrong place to add our CSS; better
    //   suggestions and patches welcome.
    drupal_add_css(drupal_get_path('module', 'admin_views') . '/admin_views.css');

    return $this->view->render();
  }

  /**
   * Provide the summary for page options in the views UI.
   *
   * This output is returned as an array.
   */
  function options_summary(&$categories, &$options) {
    parent::options_summary($categories, $options);

    $categories['system'] = array(
      'title' => t('System path settings'),
    );

    $path = strip_tags('/' . $this->get_option('path'));
    if (empty($path)) {
      $path = t('None');
    }

    $options['path'] = array(
      'category' => 'system',
      'title' => t('Path'),
      'value' => views_ui_truncate($path, 24),
    );
  }

  /**
   * Provide the default form for setting options.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    switch ($form_state['section']) {
      case 'path':
        $form['#title'] .= t('An existing menu path this view replaces');
        $form['path'] = array(
          '#type' => 'textfield',
          '#description' => t('This view replaces this path on your site. You may use "%" for dynamic arguments. For example: "node/%/feed".'),
          '#default_value' => $this->get_option('path'),
          '#field_prefix' => '<span dir="ltr">' . url(NULL, array('absolute' => TRUE)) . (variable_get('clean_url', 0) ? '' : '?q='),
          '#field_suffix' => '</span>&lrm;',
          '#attributes' => array('dir'=>'ltr'),
        );
        break;
    }
  }

  function options_validate(&$form, &$form_state) {
    parent::options_validate($form, $form_state);

    switch ($form_state['section']) {
      case 'path':
        if (strpos($form_state['values']['path'], '%') === 0) {
          form_error($form['path'], t('"%" may not be used for the first segment of a path.'));
        }
        // Automatically remove '/' from path.
        $form_state['values']['path'] = trim($form_state['values']['path'], '/');
        break;
    }
  }

  function options_submit(&$form, &$form_state) {
    parent::options_submit($form, $form_state);

    switch ($form_state['section']) {
      case 'path':
        $this->set_option('path', $form_state['values']['path']);
        break;
    }
  }

  function get_argument_text() {
    return array(
      'filter value not present' => t('When the filter value is <em>NOT</em> in the URL'),
      'filter value present' => t('When the filter value <em>IS</em> in the URL or a default is provided'),
      'description' => t('The contextual filter values is provided by the URL.'),
    );
  }

  function get_pager_text() {
    return array(
      'items per page title' => t('Items per page'),
      'items per page description' => t('The number of items to display per page. Enter 0 for no limit.')
    );
  }
}
