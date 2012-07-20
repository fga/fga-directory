<?php

class openlayers_solr_type extends openlayers_layer_type_raw {

  /**
   * Options form which generates layers
   */
  function options_form() {
    $environments = apachesolr_load_all_environments();
    $apachesolr_servers = array();
    foreach ($environments as $key => $data) {
      $apachesolr_servers[$key] = $data['name'];
    }

    return array(
      'apache_server' => array(
        '#title' => t('Apachesolr Server'),
        '#type' => 'select',
        '#default_value' => isset($this->data['apache_server']) ? $this->data['apache_server'] : apachesolr_default_environment(),
        '#options' => $apachesolr_servers
      ),
      'layer_type' => array(
        '#type' => 'hidden',
        '#value' => 'openlayers_solr_type'
      ),
    );
  }
  /**
   * Get features for the current search
   *
   * @return
   *   array of features
   */
  function get_features() {
    $solr_server = isset($this->data['apache_server']) ? $this->data['apache_server'] : apachesolr_default_environment();
    $solr_server = "apachesolr@$solr_server";
    $results = apachesolr_static_response_cache($solr_server);

    return $this->_get_points($results);
  }

  protected function _get_points($results) {
    $features = array();
    if (!empty($results->response->docs)) {
      foreach ($results->response->docs as $doc) {
        if (!empty($doc->ss_geo_wkt)) {
          $features[] = array(
            'projection' => '4326',
            'wkt' => $doc->ss_geo_wkt,
            'attributes' => array(
              'title' => $doc->label,
              'description' => l($doc->label, $doc->path),
            ),
          );
        }
      }
    }

    return $features;
  }

  /**
   * Render.
   */
  function render(&$map) {
    $this->data['features'] = $this->get_features();
    return parent::render($map);
  }
}