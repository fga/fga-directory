<?php
/**
 * @file
 * directory_solr.ds_extras.inc
 */

/**
 * Implements hook_ds_vd_info().
 */
function directory_solr_ds_vd_info() {
  $export = array();

  $ds_vd = new stdClass();
  $ds_vd->api_version = 1;
  $ds_vd->vd = 'directory_global_search-search_page';
  $ds_vd->label = 'Directory_global_search: Page (Views template)';
  $export['directory_global_search-search_page'] = $ds_vd;

  return $export;
}
