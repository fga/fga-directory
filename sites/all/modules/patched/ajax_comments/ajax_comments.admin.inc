<?php

/**
 * @file
 * AJAX comments settings form.
 */

/**
 * AJAX comments settings form.
 */
function ajax_comments_settings() {
  $form['ajax_comments_node_types'] = array(
    '#title' => t('Content types'),
    '#type' => 'checkboxes',
    '#description' => t('Select node types you want to activate ajax comments on. If you select nothing, AJAX Comments will be enabled everywhere.'),
    '#default_value' => variable_get('ajax_comments_node_types', array()),
    '#options' => node_type_get_names(),
  );
  $form['ajax_comments_notify'] = array(
    '#title' => t('Notification Message'),
    '#type' => 'checkbox',
    '#description' => t('Add notification message to comment when posted.'),
    '#default_value' => variable_get('ajax_comments_notify', ''),
  );
  return system_settings_form($form);
}
