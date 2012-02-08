<?php
/**
 * @file
 * FileField Paths module integration.
 */

/**
 * Implements hook_filefield_paths_field_settings().
 */
function filefield_paths_filefield_paths_field_settings() {
  return array(
    'file_path' => array(
      'title' => 'File path',
      'sql' => 'filepath',

      'form' => array(
        'file_path' => array(
          '#maxlength' => 512,
          '#size' => 128,
        ),
      ),
    ),

    'file_name' => array(
      'title' => 'File name',
      'sql' => 'filename',

      'form' => array(
        'file_name' => array(
          '#type' => 'textfield',
          '#title' => t('File name'),
          '#default_value' => '[file:ffp-name-only-original].[file:ffp-extension-original]',
        ),
      ),
    )
  );
}

/**
 * Implements hook_filefield_paths_process_file().
 */
function filefield_paths_filefield_paths_process_file($new, &$file, $settings, &$entity, $type, &$update) {
  if ($new && !empty($file['field']['filename'])) {
    $field = field_info_field($file['name']);
    $token_data = array('file' => file_load($file['field']['fid']), $type => $entity);

    // Process filename.
    $file['filename']['old'] = $file['field']['filename'];
    $file['filename']['new'] = !empty($settings['filename']['value'])
      ? filefield_paths_process_string($settings['filename']['value'], $token_data, $settings['filename'])
      : $file['field']['filename'];

    // Process filepath.
    $file['filepath']['old'] = $file['field']['uri'];
    $file['filepath']['new'] = "{$field['settings']['uri_scheme']}://" . filefield_paths_process_string($settings['filepath']['value'] . "/{$file['filename']['new']}", $token_data, $settings['filepath']);

    // Finalize files if necessary.
    $dirname = drupal_dirname($file['filepath']['new']);
    if ($dirname != drupal_dirname($file['field']['uri']) || $file['filename']['new'] != $file['field']['filename']) {
      if (file_prepare_directory($dirname, FILE_CREATE_DIRECTORY) && file_move((object) $file['field'], $file['filepath']['new'])) {
        $update->entity = TRUE;

        // Fix reference to old paths.
        $file['filepath']['new'] = str_replace($file['filename']['old'], $file['filename']['new'], $file['filepath']['new']);

        // Process regular expression.
        _filefield_paths_replace_path($file['filepath']['old'], $file['filepath']['new'], $entity, $update);

        // Store new filename in file Array
        $file['field']['filename'] = $file['filename']['new'];
        $file['field']['uri'] = $file['filepath']['new'];
      }
    }
  }
}

/**
 * Implements hook_filefield_paths_cleanup().
 */
function filefield_paths_filefield_paths_cleanup($ffp, $name) {
  foreach ($ffp['#files'] as $file) {
    if (isset($file['filepath'])) {
      $scheme = file_uri_scheme($file['filepath']['old']);
      $paths = explode('/', str_replace("{$scheme}://", '', drupal_dirname($file['filepath']['old'])));
      while ($paths) {
        if (@drupal_rmdir("{$scheme}://" . implode('/', $paths)) == TRUE) {
          array_pop($paths);
          continue;
        }
        break;
      }
    }
  }
}
