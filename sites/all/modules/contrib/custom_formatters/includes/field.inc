<?php
/**
 * @file
 * Field module integration.
 */

/**
 * Implements hook_field_formatter_info().
 */
function custom_formatters_field_formatter_info() {
  $formatters = array();
  $settings = variable_get('custom_formatters_settings', array('label_prefix' => TRUE, 'label_prefix_value' => t('Custom')));

  foreach (custom_formatters_crud_load_all(TRUE) as $key => $formatter) {
    $label = $settings['label_prefix'] ? "{$settings['label_prefix_value']}: {$formatter->label}" : $formatter->label;
    $formatters["custom_formatters_{$key}"] = array(
      'label' => $label,
      'field types' => drupal_explode_tags($formatter->field_types),
    );
  }

  return $formatters;
}

/**
 * Implements hook_field_formatter_view().
 */
function custom_formatters_field_formatter_view($obj_type, $object, $field, $instance, $langcode, $items, $display, $formatter = NULL) {
  $element = array();

  $formatter = empty($formatter) ? custom_formatters_crud_load(drupal_substr($display['type'], 18)) : $formatter;
  if (isset($formatter) && !empty($items)) {
    $engines = module_invoke_all('custom_formatters_engine_info');
    $engine = $formatter->mode;
    if (isset($engines[$engine]['file']) && file_exists($engines[$engine]['file'])) {
      require_once $engines[$engine]['file'];
    }

    if (function_exists($function = $engines[$engine]['callbacks']['render'])) {
      $element = array(
        array(
          '#markup' => $function($formatter, $obj_type, $object, $field, $instance, $langcode, $items, $display),
        )
      );
    }

    // Allow other modules to modify the element.
    drupal_alter('custom_formatters_field_formatter_view_element', $element, $formatter);
  }

  return $element;
}
