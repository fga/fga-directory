<?php
/**
 * @file
 * CTools Export UI plugin for SexyBookmarks profiles.
 */

$plugin = array(
  'schema' => 'formatters',
  'access' => 'administer custom formatters',

  'menu' => array(
    'menu prefix' => 'admin/structure',
    'menu item' => 'formatters',
    'menu title' => 'Formatters',
    'menu description' => 'Administer Formatters.',
  ),

  'title singular' => t('formatter'),
  'title singular proper' => t('Formatter'),
  'title plural' => t('formatters'),
  'title plural proper' => t('Formatters'),

  'handler' => 'custom_formatters_ui',

  'form' => array(
    'settings' => 'custom_formatters_export_ui_form',
    'submit' => 'custom_formatters_export_ui_form_submit',
  ),

  'export' => array(
    'admin_title' => 'label',
    'admin_description' => 'description',
  ),
);

/**
 * Custom Formatters settings form.
 */
function custom_formatters_export_ui_form(&$form, &$form_state) {
  drupal_add_js(drupal_get_path('module', 'custom_formatters') . '/scripts/custom_formatters.admin.js');
  $item = $form_state['item'];

  $engines = module_invoke_all('custom_formatters_engine_info');
  $engine = !empty($form_state['values']['mode']) ? $form_state['values']['mode'] : (
    !empty($item->mode) ? $item->mode : key($engines)
  );
  if (isset($engines[$engine]['file']) && file_exists($engines[$engine]['file'])) {
    require_once $engines[$engine]['file'];
  }

  $disable = FALSE;
  if ($form_state['op'] != 'add') {
    $disable = custom_formatters_formatter_is_active($item);
    if ($disable) {
      drupal_set_message(t('As the Formatter is currently in use, certain features have been disabled.'), 'warning');
    }
  }

  $form['info']['#title'] = t('Basic information');
  $form['info']['#type'] = 'fieldset';
  $form['info']['#collapsible'] = TRUE;
  $form['info']['#collapsed'] = $form_state['op'] != 'add';

  $form['info']['label']['#title'] = t('Formatter name');

  $form['info']['description'] = array(
    '#title' => t('Description'),
    '#type' => 'textarea',
    '#default_value' => $item->description,
  );

  $options = array();
  foreach ($engines as $key => $option) {
    $options[$key] = $option['label'];
  }
  $form['info']['mode'] = array(
    '#title' => t('Format'),
    '#type' => 'select',
    '#options' => $options,
    '#default_value' => $engine,
    '#ajax' => array(
      'callback' => 'custom_formatters_export_ui_form_js',
      'wrapper' => 'engine-wrapper',
    ),
  );

  $form['engine'] = array(
    '#type' => 'container',
    '#prefix' => '<div id="engine-wrapper">',
    '#suffix' => '</div>'
  );
  $form['engine']['field_types'] = array(
    '#title' => t('Field type(s)'),
    '#type' => 'textfield',
    '#default_value' => $item->field_types,
    '#required' => TRUE,
    '#description' => t('Enter a comma-separated list of field types (file, image, text, text_long, etc).'),
    '#autocomplete_path' => 'js/formatters/autocomplete',
    '#ajax' => array(
      'callback' => 'custom_formatters_export_ui_form_js',
      'wrapper' => 'engine-wrapper',
    ),
    '#disabled' => $disable,
  );
  $form['engine']['code'] = array(
    '#title' => t('Formatter'),
    '#type' => 'textarea',
    '#default_value' =>!empty($item->code) ? $item->code : '',
    '#required' => TRUE,
    '#rows' => 10,
  );

  $options = _custom_formatters_preview_variables($form, $form_state);
  $form['engine']['preview'] = array(
    '#title' => t('Preview'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#weight' => 100,
    '#theme' => 'custom_formatters_export_ui_form_preview',
    '#tree' => TRUE,
  );
  $form['engine']['preview']['entity_type'] = array(
    '#title' => t('Entity type'),
    '#type' => 'select',
    '#options' => $options['entity_types'],
    '#default_value' => 'node',
    '#disabled' => empty($options['entity_types']),
    '#ajax' => array(
      'callback' => 'custom_formatters_export_ui_form_js',
      'wrapper' => 'engine-wrapper',
    ),
  );
  $form['engine']['preview']['bundle'] = array(
    '#title' => t('Bundle'),
    '#type' => 'select',
    '#options' => $options['bundles'],
    '#disabled' => empty($options['bundles']),
    '#ajax' => array(
      'callback' => 'custom_formatters_export_ui_form_js',
      'wrapper' => 'engine-wrapper',
    ),
  );
  $form['engine']['preview']['field'] = array(
    '#title' => t('Field'),
    '#type' => 'select',
    '#options' => $options['fields'],
    '#disabled' => empty($options['fields']),
    '#ajax' => array(
      'callback' => 'custom_formatters_export_ui_form_js',
      'wrapper' => 'engine-wrapper',
    ),
  );
  $form['engine']['preview']['entity'] = array(
    '#title' => t('Entity'),
    '#type' => 'select',
    '#options' => $options['entities'],
    '#disabled' => empty($options['entities']),
  );
  $form['engine']['preview']['options'] = array(
    '#type' => 'container',
  );
  $form['engine']['preview']['button'] = array(
    '#type' => 'button',
    '#value' => t('Preview'),
    '#ajax' => array(
      'callback' => 'custom_formatters_export_ui_form_js_preview',
      'wrapper' => 'preview-wrapper',
    ),
    '#disabled' => empty($options['entities']),
  );
  $form['engine']['preview']['preview'] = array(
    '#type' => 'container',
    '#prefix' => '<div id="preview-wrapper">',
    '#suffix' => '</div>',
  );

  $engines[$engine]['callbacks']['settings form']($form['engine'], $form_state, $item);

  $form['buttons']['edit'] = array(
    '#type' => 'submit',
    '#value' => t('Save & Edit'),
  );
}

function _custom_formatters_preview_variables($form, $form_state) {
  $options = array();
  $item = !empty($form_state['values']) ? $form_state['values'] : (array) $form_state['item'];

  // Entity Types
  $options['entity_types'] = array();
  $entity_types = entity_get_info();
  foreach ($entity_types as $key => $entity) {
    if ($entity['fieldable']) {
      $options['entity_types'][$key] = $entity['label'];
    }
  }

  // Bundles
  $options['bundles'] = array();
  if (!empty($options['entity_types'])) {
    $entity_type = !empty($item['preview']['entity_type']) ? $item['preview']['entity_type'] : 'node';
    foreach ($entity_types[$entity_type]['bundles'] as $key => $bundle) {
      $options['bundles'][$key] = $bundle['label'];
    }
  }

  // Fields
  $options['fields'] = array();
  if (!empty($options['bundles'])) {
    $bundle = !empty($item['preview']['bundle']) && isset($options['bundles'][$item['preview']['bundle']])
      ? $item['preview']['bundle'] : key($options['bundles']);
    $fields = field_info_instances($entity_type, $bundle);
    foreach ($fields as $key => $field) {
      $field_info = field_info_field_by_id($field['field_id']);
      if (in_array($field_info['type'], drupal_explode_tags($item['field_types']))) {
        $options['fields'][$key] = $field['label'];
      }
    }
  }

  // Entities
  $options['entities'] = array();
  if (!empty($options['fields'])) {
    $field = !empty($item['preview']['field']) ? $item['preview']['field'] : key($options['fields']);
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', $entity_type)
      ->entityCondition('bundle', $bundle)
      ->fieldCondition($field);
    $result = $query->execute();
    $entities = entity_load($entity_type, array_keys($result[$entity_type]));
    foreach ($entities as $key => $entity) {
      $options['entities'][$key] = "Entity ID #{$key}";
    }
  }

  return $options;
}

function custom_formatters_export_ui_form_js($form, $form_state) {
  // Clear messages.
  drupal_get_messages(NULL, TRUE);

  $engines = module_invoke_all('custom_formatters_engine_info');
  $engine = $form_state['values']['mode'];
  if (isset($engines[$engine]['file']) && file_exists($engines[$engine]['file'])) {
    require_once $engines[$engine]['file'];
  }

  return $form['engine'];
}

function custom_formatters_export_ui_form_js_preview($form, $form_state) {
  // Clear messages.
  drupal_get_messages(NULL, TRUE);

  $obj_type = $form_state['values']['preview']['entity_type'];
  $objects = entity_load($obj_type, array($form_state['values']['preview']['entity']));
  $object = $objects[$form_state['values']['preview']['entity']];
  $field = field_info_field($form_state['values']['preview']['field']);
  $instance = field_info_instance($obj_type, $field['field_name'], $form_state['values']['preview']['bundle']);
  $langcode = field_language($obj_type, $object, $field['field_name']);
  $items = $object->{$field['field_name']}[$langcode];
  $display = $instance['display']['default'];
  $formatter = (object) $form_state['values'];

  $js = drupal_add_js();
  $form['engine']['preview']['preview']['content'] = array(
    '#markup' => render(custom_formatters_field_formatter_view($obj_type, $object, $field, $instance, $langcode, $items, $display, $formatter)),
  );

  $js = array_diff_assoc(drupal_add_js(), $js);
  $form['engine']['preview']['preview']['content']['#markup'] .= drupal_get_js('header', $js);

  return $form['engine']['preview']['preview'];
}

/**
 * Submit callback for Custom Formatters settings form.
 */
function custom_formatters_export_ui_form_submit(&$form, &$form_state) {
  field_cache_clear();
  if ($form_state['values']['op'] == t('Save & Edit')) {
    $destination = "admin/structure/formatters/list/{$form_state['values']['name']}/edit";
    $_GET['destination'] = isset($_GET['destination']) ? $destination . "?destination={$_GET['destination']}" : $destination;
  }
}

/**
 * Provide a form for displaying an export.
 */
function custom_formatters_export_ui_export_form($form, &$form_state, $item, $title = '') {
  $form['mode'] = array(
    '#type' => 'select',
    '#title' => t('Mode'),
    '#options' => array(
      'default' => t('CTools exportable (default)'),
      'drupal' => t('Drupal API')
    ),
    '#default_value' => 'default',
    '#ajax' => array(
      'callback' => 'custom_formatters_export_ui_export_form_js',
      'wrapper' => 'export-wrapper',
    ),
  );

  $form['export'] = array(
    '#type' => 'container',
    '#prefix' => '<div id="export-wrapper">',
    '#suffix' => '</div>',
  );

  $mode = isset($form_state['values']['mode']) ? $form_state['values']['mode'] : $form['mode']['#default_value'];
  switch ($mode) {
    case 'default':
      $code = ctools_export_crud_export('formatters', $item);
      break;

    case 'drupal':
      $engines = module_invoke_all('custom_formatters_engine_info');
      $engine = $item->mode;
      if (isset($engines[$engine]['file']) && file_exists($engines[$engine]['file'])) {
        require_once $engines[$engine]['file'];
      }

      $module = isset($form_state['values']['module']) ? $form_state['values']['module'] : t('MYMODULE');
      $form['export']['module'] = array(
        '#type' => 'textfield',
        '#title' => t('Module name'),
        '#default_value' => $module,
        '#ajax' => array(
          'callback' => 'custom_formatters_export_ui_export_form_js',
          'wrapper' => 'export-wrapper',
        ),
      );

      $code = $engines[$engine]['callbacks']['export']($item, $module);
      break;
  }

  $lines = substr_count($code, "\n");
  $form['export']['code'] = array(
    '#type' => 'textarea',
    '#title' => $title,
    '#value' => $code,
    '#rows' => $lines,
  );

  return $form;
}

function custom_formatters_export_ui_export_form_js($form, $form_state) {
  return $form['export'];
}

/**
 * Field Types autocomplete callback.
 */
function custom_formatters_autocomplete($string = '') {
  // The user enters a comma-separated list of fields. We only autocomplete the last tag.
  $array = drupal_explode_tags($string);

  // Fetch last field.
  $last_string = trim(array_pop($array));
  $matches = array();
  if ($last_string != '') {
    $prefix = count($array) ? implode(', ', $array) . ', ' : '';

    $fields = array_keys(field_info_field_types());
    // Give modules a chance to alter fields.
    //drupal_alter('custom_formatters_fields', $fields);

    sort($fields);
    foreach ($fields as $field) {
      if (preg_match('/^' . drupal_strtolower($last_string) . '/', $field)) {
        $matches[$prefix . $field] = check_plain($field);
      }
    }
  }

  drupal_json_output($matches);
}

/**
 * Theme for Preview form.
 */
function theme_custom_formatters_export_ui_form_preview($variable) {
  $form = $variable['form'];
  $output = '';

  $output .= theme('table', array(
    'rows' => array(
      array(
        render($form['entity_type']),
        render($form['bundle']),
        render($form['field']),
        render($form['entity']),
      ),
      array(
        array('data' => render($form['options']), 'colspan' => 3),
        render($form['button'])
      ),
    ),
  ));

  $output .= render($form['preview']);

  return $output;
}
