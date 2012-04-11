<?php
/**
 * @file
 * Token engine for Custom Formatters modules.
 */

/**
 * Implements custom_formatters_engine_hook_theme_alter().
 */
function custom_formatters_engine_token_theme_alter(&$theme) {
  $theme['custom_formatters_token_export'] = array(
    'variables' => array(
      'item' => NULL,
      'module' => NULL,
    ),
    'template' => 'token.export',
    'path' => drupal_get_path('module', 'custom_formatters') . '/engines',
  );
}

/**
 * Settings form callback for Custom Formatters Token engine.
 */
function custom_formatters_engine_token_settings_form(&$form, $form_state, $item) {
  $options = array();
  foreach (field_info_field_types() as $type => $field) {
    $options[$field['module']][$type] = $field['label'];
  }
  $form['field_types']['#type'] = 'select';
  $form['field_types']['#options'] = $options;
  unset($form['field_types']['#description']);

  $fieldable = array();
  $entity_types = entity_get_info();
  foreach ($entity_types as $entity_type => $entity) {
    if ($entity['fieldable']) {
      $fieldable[] = $entity_type;
    }
  }

  $field_type = !empty($form_state['values']['field_types']) ? $form_state['values']['field_types'] : (
    !empty($item->field_types) ? $item->field_types : key($options)
  );
  $field = str_replace('_', '-', $field_type) . '-field';
  $info = token_get_info($field);
  $field_value = $info['field-value-type'];
  $form['tokens'] = array(
    '#title' => t('Tokens'),
    '#type' => 'fieldset',
    '#description' => theme('token_tree', array('token_types' => array_merge(
      array($field_value),
      $fieldable
    ))),
    '#weight' => 50,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
}

/**
 * Render callback for Custom Formatters Token engine.
 */
function custom_formatters_engine_token_render($formatter, $obj_type, $object, $field, $instance, $langcode, $items, $display) {
  $output = '';

  $info = token_get_info(str_replace('_', '-', $field['type']) . '-field');
  $field_value = $info['field-value-type'];

  foreach ($items as $item) {
    $output .= token_replace($formatter->code, array(
      $obj_type => $object,
      $field_value => $item,
      'item' => $item,
    ));
  }

  return $output;
}

/**
 * Export callback for Custom Formatters Token engine.
 */
function custom_formatters_engine_token_export($item, $module) {
  return theme('custom_formatters_token_export', array('item' => $item, 'module' => $module));
}

/**
 * Help callback for Custom Formatters Token engine.
 */
function custom_formatters_engine_token_help() {
  return t('A HTML + Token Formatter utilizes Drupal Tokens and the Token module to create easy yet powerful formatters.') . "<br />\n"
       . t('All available Tokens can be navigated via the Tokens fieldset displayed below the Formatter field.');
}
