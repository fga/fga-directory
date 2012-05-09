<?php


/**
 * @file
 * A filter for compressing bckups with zip, gz bzip etc.
 */

/**
 * A filter for compressing backup files.
 *
 * @ingroup backup_migrate_filters
 */
class backup_migrate_filter_compression extends backup_migrate_filter {
  var $op_weights = array('backup' => 100, 'restore' => -100);

  /**
   * This function is called on a backup file after the backup has been completed.
   */
  function backup($file, &$settings) {
    return $this->_backup_migrate_file_compress($file, $settings);
  }

  /**
   * This function is called on a backup file before importing it.
   */
  function restore($file, &$settings) {
    return $this->_backup_migrate_file_decompress($file);
  }

  /**
   * Get the form for the settings for this filter.
   */
  function backup_settings_default() {
    $options = $this->_backup_migrate_get_compression_form_item_options();
    return array('compression' => isset($options['gzip']) ? 'gzip' : 'none');
  }

  /**
   * Get the form for the settings for this filter.
   */
  function backup_settings_form($settings) {
    $form = array();
    $compression_options = $this->_backup_migrate_get_compression_form_item_options();
    $form['file']['compression'] = array(
      "#type" => count($compression_options) > 1 ? "select" : 'value',
      "#title" => t("Compression"),
      "#options" => $compression_options,
      "#default_value" => $settings['compression'],
    );
    return $form;
  }

  /**
   * Return a list of backup filetypes.
   */
  function file_types() {
    return array(
      "gzip" => array(
        "extension" => "gz",
        "filemime" => "application/x-gzip",
        "backup" => TRUE,
        "restore" => TRUE,
      ),
      "bzip" => array(
        "extension" => "bz",
        "filemime" => "application/x-bzip",
        "backup" => TRUE,
        "restore" => TRUE,
      ),
      "bzip2" => array(
        "extension" => "bz2",
        "filemime" => "application/x-bzip",
        "backup" => TRUE,
        "restore" => TRUE,
      ),
      "zip" => array(
        "extension" => "zip",
        "filemime" => "application/zip",
        "backup" => TRUE,
        "restore" => TRUE,
      ),
    );
  }

  /**
   * Get the compression options as an options array for a form item.
   */
  function _backup_migrate_get_compression_form_item_options() {
    $compression_options = array("none" => t("No Compression"));
    if (@function_exists("gzencode")) {
      $compression_options['gzip'] = t("GZip");
    }
    if (@function_exists("bzcompress")) {
      $compression_options['bzip'] = t("BZip");
    }
    if (class_exists('ZipArchive')) {
      $compression_options['zip'] = t("Zip", array(), array('context' => 'compression format'));
    }
    return $compression_options;
  }

  protected function _backup_migrate_filter_is_supported($name) {
    $filters = stream_get_filters();
    $conversions = array(
      'zlib' => 'zlib.*',
      'bzip2' => 'bzip2.*',
      'convert' => 'convert.*',
    );

    $parts = explode('.', $name);
    $key = strtolower($parts[0]);
    if (isset($conversions[$key])) {
      $name = $conversions[$key];
    }

    return in_array($name, $filters);
  }

  function _backup_migrate_filter($source, $dest, $filter, $mode = STREAM_FILTER_READ) {
    // If no zlib support, fail fast.
    if (!$this->_backup_migrate_filter_is_supported($filter)) {
      drupal_set_message('Filter is not available: ' . $filter, 'error');
      return FALSE;
    }
    $in = fopen($source, 'rb');
    $out = fopen($dest, 'w+');

    if (empty($in) || empty($out)) {
      $params = array('%in' => $source, '%out' => $dest);
      watchdog('backup_migrate', 'Could not copy %in to %out', $params, WATCHDOG_WARNING);
      return FALSE;
    }
    stream_filter_prepend($in, $filter, $mode);
    $count = stream_copy_to_stream($in, $out);
    fclose($in);
    fclose($out);
    drupal_set_message(t('%bytes bytes copied.', array('%bytes' => (int) $count)), 'status');

    return $count > 0;
  }

  /**
   * Gzip encode a file.
   */
  function _backup_migrate_gzip_encode($source, $dest, $level = 9) {
    return $this->_backup_migrate_filter($source, $dest, 'zlib.deflate', STREAM_FILTER_READ);
  }

  /**
   * Gzip decode a file.
   */
  function _backup_migrate_gzip_decode($source, $dest) {
    return $this->_backup_migrate_filter($source, $dest, 'zlib.inflate', STREAM_FILTER_READ);
  }


  /**
   * Bzip encode a file.
   */
  function _backup_migrate_bzip_encode($source, $dest) {
    return $this->_backup_migrate_filter($source, $dest, 'bzip2.compress', STREAM_FILTER_READ);
  }

  /**
   * Bzip decode a file.
   */
  function _backup_migrate_bzip_decode($source, $dest) {
    return $this->_backup_migrate_filter($source, $dest, 'bzip2.decompress', STREAM_FILTER_READ);
  }

  /**
   * Zip encode a file.
   */
  function _backup_migrate_zip_encode($source, $dest, $filename) {
    $success = FALSE;
    if (class_exists('ZipArchive')) {
      $zip = new ZipArchive;
      $res = $zip->open($dest, constant("ZipArchive::CREATE"));
      if ($res === TRUE) {
        $zip->addFile($source, $filename);
        $success = $zip->close();
      }
    }
    return $success;
  }

  /**
   * Zip decode a file.
   */
  function _backup_migrate_zip_decode($source, $dest) {
    $success = FALSE;
    if (class_exists('ZipArchive')) {
      $zip = new ZipArchive;
      if (($fp_out = fopen($dest, "w")) && ($zip->open($source))) {
        $filename = ($zip->getNameIndex(0));
        if ($fp_in = $zip->getStream($filename)) {
          while (!feof($fp_in)) {
            fwrite($fp_out, fread($fp_in, 1024 * 512));
          }
          $success = TRUE;
        }
      }
      @fclose($fp_in);
      @fclose($fp_out);
    }
    return $success;
  }

  /**
   * Compress a file with the given settings.
   *  Also updates settings to reflect new file mime and file extension.
   */
  function _backup_migrate_file_compress($file, $settings) {
    switch ($settings->filters['compression']) {
      case "gzip":
        $from = $file->push_type('gzip');
        if (!$success = $this->_backup_migrate_gzip_encode($from, $file->filepath(), 9)) {
          $file = NULL;
        }
        break;

      case "bzip":
        $from = $file->push_type('bzip2');
        if (!$success = $this->_backup_migrate_bzip_encode($from, $file->filepath())) {
          $file = NULL;
        }
        break;

      case "zip":
        $filename = $file->filename();
        $from = $file->push_type('zip');
        if (!$success = $this->_backup_migrate_zip_encode($from, $file->filepath(), $filename)) {
          $file = NULL;
        }
        break;
    }
    if (!$file) {
      _backup_migrate_message("Could not compress backup file. Try backing up without compression.", array(), 'error');
    }

    return $file;
  }

  /**
   * Decompress a file with the given settings.
   *  Also updates settings to reflect new file mime and file extension.
   */
  function _backup_migrate_file_decompress($file) {
    $success = FALSE;

    switch ($file->type_id()) {
      case "gzip":
        $from = $file->pop_type();
        $success = $this->_backup_migrate_gzip_decode($from->filepath(), $file->filepath());
        break;

      case "bzip":
      case "bzip2":
        $from = $file->pop_type();
        $success = $this->_backup_migrate_bzip_decode($from->filepath(), $file->filepath());
        break;

      case "zip":
        $from = $file->pop_type();
        $success = $this->_backup_migrate_zip_decode($from->filepath(), $file->filepath());
        break;

      default:
        return $file;
      break;
    }

    if (!$success) {
      _backup_migrate_message("Could not decompress backup file. Please check that the file is valid.", array(), 'error');
    }
    return $success ? $file : NULL;
  }
}

