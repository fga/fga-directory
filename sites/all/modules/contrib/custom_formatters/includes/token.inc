<?php
/**
 * @file
 * Token module integration.
 */

/**
 * Implements hook_custom_formatters_engine() on behalf of token.module.
 */
function token_custom_formatters_engine_info() {
  $engines = array();

  // Token engine.
  $engines['token'] = array(
    'label' => t('HTML + Tokens'),
    'callbacks' => array(
      'settings form' => 'custom_formatters_engine_token_settings_form',
      'render' => 'custom_formatters_engine_token_render',
      'export' => 'custom_formatters_engine_token_export',
      'help' => 'custom_formatters_engine_token_help',
    ),
    'file' => drupal_get_path('module', 'custom_formatters') . '/engines/token.inc',
  );

  return $engines;
}
