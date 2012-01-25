<?php

/**
 * Generate include files for features_override support, saving
 * them to the public files directory.
 */
function features_override_extend() {
  $form = array();
  $compontents = array();
  foreach (features_get_components() as $component => $info) {
    if (isset($info['default_hook']) && 
      (!isset($info['module']) || $info['module'] != 'features_override') && 
      !module_hook('features_override', $info['default_hook'] . '_alter')) {
      $components[] = isset($info['name']) ? $info['name']  . ' (' . $component . ')' : $component;
    }
  }

  if (!empty($components)) {
    $items = theme('item_list', array('items' => $components, 'type' => 'ul'));
    $form['#prefix'] = t('The following features compontents are not yet available for overriding:') . $items;
    $form['actions']['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Generate additional include files'),
    );
  }
  else {
    $form['#prefix'] = t('All features compontent are already available for overriding.');
  }
  return $form;
}

/**
 * Submit callback for features_override_extend form.
 */
function features_override_extend_submit() {
  features_override_generate();
}

/**
 * Generate include files for features_override support, saving
 * them to the public files directory.
 */
function features_override_generate() {
  $files = array();
  foreach (features_get_components() as $component => $info) {
    if (isset($info['default_hook']) && 
      (!isset($info['module']) || $info['module'] != 'features_override') && 
      !module_hook('features_override', $info['default_hook'] . '_alter')) {
      // Assign any component that doesn't specify a module to the features 
      // module.
      $module = isset($info['module']) ? $info['module'] : 'features';
      $code = array();
      $code[] = "/**";
      $code[] = " * Implementation of hook_{$info['default_hook']}_alter().";
      $code[] = " */";
      $code[] = 'function features_override_'. $info['default_hook'] .'_alter(&$items) {';
      $code[] = '  features_override_features_default_alter($items, "' . $component .'");';
      $code[] = "}";
      $code = implode("\n", $code);
      $files[$module][] = $code;
    }
  }
  $generated = array();
  $dir = 'public://features_override';
  // Ensure that the directory exists and is writable, if possible.
  file_prepare_directory($dir, FILE_CREATE_DIRECTORY);
  $module_dir = drupal_get_path('module', 'features_override') . '/modules';
  // Finalize strings to be written to files and generate files.
  foreach ($files as $module => $contents) {
    $name = $module . '.features_override.inc';
    if (file_exists($module_dir . '/' . $name)) {
      $header = file_get_contents($module_dir . '/' . $name);
    }
    else {
      $header = "<?php";
    }
    $contents = $header . "\n\n" . implode("\n\n", $contents) . "\n";
    $dest = $dir . '/' . $name;
    file_unmanaged_save_data($contents, $dest, FILE_EXISTS_REPLACE);
    $generated[] = 'modules/' . $name;
  }
  if (!empty($generated)) {
    $additions = '';
    foreach ($generated as $file) {
      $additions .= "files[] = $file\n";
    }
    $contents = file_get_contents(drupal_get_path('module', 'features_override') . '/features_override.info');
    $dest = $dir . '/features_override.info';
    file_unmanaged_save_data($contents . $additions, $dest, FILE_EXISTS_REPLACE);
    drupal_set_message(t('New include files and an updated features_override.info file were generated in !dir. The new include files and can be copied to !module_dir and features_override.info copied to the features_override install directory to enable features override functionality for additional compontent types. Please also submit these changes as a patch to the Features Overide module.', array('!dir' => $dir, '!module_dir' => $module_dir)));
  }
}
