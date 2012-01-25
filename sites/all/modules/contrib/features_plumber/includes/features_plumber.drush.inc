<?php

/**
 * @file
 * Features Plumber Drush commands.
 */

/**
 * Implements hook_drush_help().
 */
function features_plumber_drush_help($section) {
  switch ($section) {
    case 'drush:features-component-remove':
      return dt('Remove a component from a feature.');
    case 'drush:features-component-list':
      return dt('List all available components for a feature.');
  }
}

/**
 * Implements hook_drush_command().
 */
function features_plumber_drush_command() {
  $items = array();

  $items['features-component-remove'] = array(
    'description' => dt('Remove a component from a feature.'),
    'arguments' => array(
      'feature-name' => 'The machine name of the feature.',
      'component' => 'The name of the component, ie `views`.',
      'component-value' => 'The value of the component, ie `frontpage` (the machine name of a view.',
    ),
    'aliases' => array('fcr'),
    'examples' => array(
      'drush fcr example_feature views frontpage' => dt('Do not export the frontpage view to the example_feature feature.'),
      'drush fcr all views frontpage' => dt('Ensure that the frontpage view is never autodetected for any feature.'),
    ),
  );
  $items['features-component-list'] = array(
    'description' => dt('List all available components for a feature.'),
    'arguments' => array(
      'feature-name' => 'The machine name of the feature.',
      'component' => 'Optional name of the component.'
    ),
    'aliases' => array('fcl'),
    'examples' => array(
      'drush fcl example_feature' => dt('List the available components to remove from example_feature.'),
      'drush fcl example_feature dependencies' => dt('List the available dependencies to remove from example_feature.'),
    ),
  );

  return $items;
}

function drush_features_component_list($feature, $component = NULL) {
  if ($module = feature_load($feature, TRUE)) {
    features_plumber_include('crud');
    $module->info['dependencies'] = empty($module->info['dependencies']) ? array() : $module->info['dependencies'];

    if (isset($component) && (isset($module->info['features'][$component]) || $component == 'dependencies')) {
      $selected = ($component == 'dependencies') ? $module->info['dependencies'] : $module->info['features'][$component];
      $to_check = array($component => $selected);
    }
    else {
      $to_check = $module->info['features'];
      $to_check['dependencies'] = $module->info['dependencies'];
    }

    $options = $dt_args = array();
    foreach($to_check as $component => $component_vals) {
      if (features_plumber_component_is_supported($component)) {
        $dt_args['@component'] = $component;
        foreach($component_vals as $component_val) {
          $name = features_plumber_generate_name($feature, $component, $component_val);
          $dt_args['@val'] = $component_val;
          $message = ($component == 'dependencies') ? 'dependencies[] = "@val"' : 'features[@component][] = "@val"';
          $options[$name] = dt($message, $dt_args);
        }
      }
    }

    $mark = drush_get_context('DRUSH_NOCOLOR') ? '!value (selected)' : "!value \033[1;32;40m\033[1m(selected)\033[0m";

    // drush_choice_multiple is currently broken, so we have to pass a max value
    // temporarily. See http://drupal.org/node/1154132
    if (!empty($options) && $choices = drush_choice_multiple($options, FALSE, 'Select a component to remove:', '!value', $mark, 0, count($options))) {
      foreach ($choices as $choice) {
        list($feature, $component, $component_val) = explode('__', $choice);

        $dt_args = array(
          '@feature' => $feature,
          '@component' => $component,
          '@component-val' => $component_val,
        );

        if (features_plumber_record_create($feature, $component, $component_val)) {
          drush_log(dt('Successfully queued component @component->@component-val for removal from @feature.', $dt_args), 'success');
        }
      }
      if (drush_confirm(dt('About to overrwrite the feature code. Do you really want to continue?'))) {
        drush_backend_invoke("features-update $feature");
      }
    }
  }
}

function drush_features_plumber_features_component_remove_validate($feature = NULL, $component = NULL, $component_val = NULL) {
  features_plumber_include('crud');

  $dt_args = array(
    '@feature' => $feature,
    '@component' => $component,
    '@component-val' => $component_val,
  );

  if (!isset($feature) || !isset($component) || !isset($component_val)) {
    $message = 'You must specify all arguments for this command';
  }
  elseif (!features_plumber_component_is_supported($component)) {
    $message = 'The component @component is unsupported.';
  }
  elseif (!($feature == FEATURES_PLUMBER_WILDCARD || (module_exists($feature) && $module = feature_load($feature, TRUE)))) {
    $message = 'There is no feature named @feature on this site.';
  }
  elseif (features_plumber_record_exists($feature, $component, $component_val)) {
    if ($feature == FEATURES_PLUMBER_WILDCARD) {
      $message = '@component->@component-val has already been removed from all features.';
    }
    else {
      $message = '@component->@component-val has already been removed from feature @feature.';
    }
  }
  elseif ($feature != FEATURES_PLUMBER_WILDCARD) {
    $dt_args['@feature'] = $module->name;
    $component_vals = array();
    if ($component == 'dependencies') {
      $component_vals = $module->info['dependencies'];
    }
    elseif (isset($module->info['features'][$component])) {
      $component_vals = $module->info['features'][$component];
    }
    if (!in_array($component_val, $component_vals)) {
      $message = 'The component value @component-val does not exist for component @component in feature @feature.';
    }
  }

  if (isset($message)) {
    drush_log(dt($message, $dt_args), 'error');
    return FALSE;
  }
}

function drush_features_component_remove($feature, $component, $component_val) {
  $dt_args = array(
    '@feature' => $feature,
    '@component' => $component,
    '@component-val' => $component_val,
  );

  if (features_plumber_record_create($feature, $component, $component_val)) {
    drush_log(dt('Successfully wrote the record to features_plumber.'));
    if ($feature == FEATURES_PLUMBER_WILDCARD) {
      drush_log(dt('Successfully queued component @component->@component-val for removal from @feature.', $dt_args), 'success');
      if (drush_confirm(dt('Would you like to re-export all your features now?'))) {
        drush_backend_invoke('features-update-all');
      }
    }
    elseif (drush_confirm(dt('About to overrwrite the feature code. Do you really want to continue?'))) {
      drush_backend_invoke("features-update $feature");
    }
  }
}
