<?php
// $Id: features_override_ctools_export_ui.inc,v 1.5 2011/02/12 05:17:13 nedjo Exp $

$plugin = array(
  'schema' => 'features_override',
  'access' => 'administer features',
  'menu' => array(
    'menu title' => 'Override',
    'menu item' => 'features-override',
    'menu prefix' => 'admin/structure/features',
    'menu description' => 'Administer overrides of feature components.',
  ),
  'title' => t('Features override'),
  'title singular' => t('features override'),
  'title plural' => t('features overrides'),
  'title singular proper' => t('Features override'),
  'title plural proper' => t('Features overrides'),
);

function features_override_ctools_export_ui_form(&$form, &$form_state) {
  $item = $form_state['item'];

  if ($overrides = features_override_get_overrides()) {
    $options[0] = t('Select an overridden item');
    foreach ($overrides as $component => $items) {
      if (!isset($options[$component])) {
        $options[$component] = array();
      }
      foreach (array_keys($items) as $name) {
        $options[$component][$component . '|' . $name] = $name;
      }
    }
    $form['item'] = array(
      '#title' => t('Item'),
      '#type' => 'select',
      '#options' => $options,
      '#default_value' => !empty($item->component_type) && !empty($item->component_id) ? $item->component_type . '|' . $item->component_id : 0,
      '#description' => t('Select an overridden component.'),
    );
    $form['description'] = array(
      '#title' => t('Description'),
      '#type' => 'textfield',
      '#default_value' => !empty($item->description) ? $item->description : '',
      '#description' => t('Enter a description for this component override.'),
    );
  }
  else {
    $form = array(
      array(
        '#type' => 'item',
        '#markup' => '<p>' . t('No overridden components found.') . '</p>',
      ),
    );
  }
}

function features_override_ctools_export_ui_form_validate(&$form, &$form_state) {
  list($form_state['values']['component_type'], $form_state['values']['component_id']) = explode('|', $form_state['values']['item']);
  $overrides = features_override_get_overrides();
  $form_state['values']['value'] = $overrides[$form_state['values']['component_type']][$form_state['values']['component_id']];
}

