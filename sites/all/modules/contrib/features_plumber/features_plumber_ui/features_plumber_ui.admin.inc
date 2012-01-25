<?php

/**
 * @file
 * Features plumber admin.
 */

/**
 * Configuration settings form.
 */
function features_plumber_ui_settings_form() {
  $form = array();

  $form['features_plumber_export_records'] = array(
    '#type' => 'checkbox',
    '#title' => t('Export Features Plumber records'),
    '#description' => t('If checked, Features Plumber records will get exported to the features themselves. It is handy to uncheck this value if you are working in a development environment and do not want features_plumber running on the production/staging environment.'),
    '#default_value' => variable_get('features_plumber_export_records', TRUE),
  );
  $form['features_plumber_ui_hide_component'] = array(
    '#type' => 'checkbox',
    '#title' => t('Hide Features Plumber records'),
    '#description' => t('If unchecked, you will see Features Plumber records as an available component in the Features create form.'),
    '#default_value' => variable_get('features_plumber_ui_hide_component', TRUE),
  );

  $form = system_settings_form($form);

  // Uncomment and update the callback to override the default system settings submit handler.
  // $form['#submit'] = array('_settings_form_submit');

  return $form;
}
