<?php
/**
 * @file
 * Token engine for Custom Formatters modules.
 */

function custom_formatters_engine_php_theme_alter(&$theme) {
  $theme['custom_formatters_php_export'] = array(
    'variables' => array(
      'item' => NULL,
      'module' => NULL,
    ),
    'template' => 'php.export',
    'path' => drupal_get_path('module', 'custom_formatters') . '/engines',
  );
}

/**
 * Settings form callback for Custom Formatters PHP engine.
 */
function custom_formatters_engine_php_settings_form(&$form) {
  $form['code']['#description'] = t('Enter the PHP code that will be evaluated. You should NOT include %php tags. The $variables object is available.', array('%php' => '<?php ?>'));

  $form['preview']['options']['dpm'] = array(
    '#type' => 'checkbox',
    '#title' => t('Output !variables array (requires !devel module).', array('!variables' => '<strong>' . t('$variables') . '</strong>', '!devel' => l(t('Devel'), 'http://drupal.org/project/devel'))),
    '#default_value' => module_exists('devel'),
    '#disabled' => !module_exists('devel'),
  );
}

/**
 * Render callback for Custom Formatters PHP engine.
 */
function custom_formatters_engine_php_render($formatter, $obj_type, $object, $field, $instance, $langcode, $items, $display) {
  global $theme_path, $theme_info, $conf;

  // Store current theme path.
  $old_theme_path = $theme_path;

  // Restore theme_path to the theme, as long as php_eval() executes,
  // so code evaluated will not see the caller module as the current theme.
  // If theme info is not initialized get the path from theme_default.
  if (!isset($theme_info)) {
    $theme_path = drupal_get_path('theme', $conf['theme_default']);
  }
  else {
    $theme_path = dirname($theme_info->filename);
  }

  // Build variables array for formatter.
  $variables = array(
    '#obj_type' => $obj_type,
    '#object' => $object,
    '#field' => $field,
    '#instance' => $instance,
    '#langcode' => $langcode,
    '#items' => $items,
    '#display' => $display,
  );

  // DPM $variables.
  if (module_exists('devel') && isset($formatter->preview) && $formatter->preview['options']['dpm']) {
    dpm($variables);
  }

  ob_start();
  print eval($formatter->code);
  $output = ob_get_contents();
  ob_end_clean();

  // Recover original theme path.
  $theme_path = $old_theme_path;

  return $output;
}

/**
 * Export callback for Custom Formatters PHP engine.
 */
function custom_formatters_engine_php_export($item, $module) {
  return theme('custom_formatters_php_export', array('item' => $item, 'module' => $module));
}

/**
 * Help callback for Custom Formatters PHP engine.
 */
function custom_formatters_engine_php_help() {
  return t('A PHP Formatter is essentially a standard Drupal API Field Formatter, the primary difference is that all availble parameters have been bundled into a !variables array for ease of use.', array('!variables' => '<strong>$variables</strong>')) . "<br />\n"
       . t('The Formatter should be PHP code that returns a value and it should NOT include %php tags.', array('%php' => '<?php ?>')) . "\n";
}
