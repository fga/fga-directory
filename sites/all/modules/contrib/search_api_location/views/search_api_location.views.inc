<?php
/**
 * @file
 * Provide views data for Search API location
 */

/**
 * Implements hook_views_data_alter().
 */
function search_api_location_views_data_alter(&$data) {

  foreach (search_api_index_load_multiple(FALSE) as $index) {

    $sf = _search_api_location_get_locationfield($index->id);

    if ($sf) {
      $sf = str_replace(":", "_", $sf);
      $locationfield = &$data['search_api_index_' . $index->machine_name][$sf];

      $locationfield['filter']['handler'] = 'SearchApiViewsHandlerFilterLocation';
      $locationfield['filter']['type'] = 'location';
    }
  }
}
