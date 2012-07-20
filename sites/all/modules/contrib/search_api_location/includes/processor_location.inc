<?php

/**
 * @file
 * Provides the Search API processor for location based search
 */

class SearchApiLocation extends SearchApiAbstractProcessor {

  /**
   * Constructor
   */
  public function __construct(SearchApiIndex $index, array $options = array()) {
    parent::__construct($index, $options);
    $this->options += array(
      'location_searchtype' => 1,
    );
  }

  /**
   * Check if one of the fields in the index supports location based search
   */
  public function supportsIndex(SearchApiIndex $index) {

    foreach ($index->options['fields'] as $key => $value) {
      if (isset($value['real_type']) && $value['real_type'] == 'location') {
        return TRUE;
      }
    }

    return FALSE;
  }

  /**
   * Select the location based search type
   */
  public function configurationForm() {
    $form = parent::configurationForm();

    foreach ($form['fields']['#options'] as $key => $value) {
      if (!isset($this->index->options['fields'][$key]['real_type']) ||
      $this->index->options['fields'][$key]['real_type'] != 'location') {
        unset($form['fields']['#options'][$key]);
        unset($form['fields']['#default_value'][$key]);
      }
    }

    $form += array(
      'location_searchtype' => array(
        '#type' => 'radios',
        '#title' => t('Search type'),
        '#description' => t('Select the type of location based search you want to use.'),
        '#options' => array(
          '1' => 'distance around a point (latitude, longitude and radius)',
        ),
        '#default_value' => $this->options['location_searchtype'],
      ),
    );

    return $form;
  }

  /**
   * Adds the location based search info to the query object
   */
  public function preprocessSearchQuery(SearchApiQuery $query) {

    $locationfield = _search_api_location_get_locationfield($query->getIndex()->id);

    $search_id = explode(':', $query->getOption('search id'));

    if ($locationfield && $search_id[0] == "search_api_page") {

      $keys = $query->getKeys();
      $spatial = _search_api_location_get_location($keys);
      $spatial['field'] = $locationfield;

      $entity_query = new EntityFieldQuery();
      $result = $entity_query
        ->entityCondition('entity_type', 'search_api_page')
        ->propertyCondition('path', $search_id[1])
        ->execute();

      // Get the search page id and load the search page.
      $page_id = array_shift(array_keys($result['search_api_page']));
      $page = search_api_page_load($page_id);

      // Add the measure, so we can recalculate the radius value if necessery.
      $spatial['radius_measure'] = $page->options['spatial'] ['radius_measure'];

      $query->setOption('spatial', $spatial);

      $query->keys(_search_api_location_get_keys($keys));
      $keys = $query->getKeys();
    }
    elseif ($locationfield && $search_id[0] == "search_api_views") {
      // Everyting happens in the location filter.
    }
  }

  /**
   * Alter the results
   */
  public function postprocessSearchResults(array &$response, SearchApiQuery $query) {
    return;
  }
}
