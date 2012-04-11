<?php

/**
 * @file MapBox layer type definition for OpenLayers
 */
class openlayers_layer_type_mapbox extends openlayers_layer_type {

  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'urls' => array(
        'http://a.tiles.mapbox.com/mapbox/',
        'http://b.tiles.mapbox.com/mapbox/',
        'http://c.tiles.mapbox.com/mapbox/',
        'http://d.tiles.mapbox.com/mapbox/',
      ),
      'serverResolutions' => openlayers_get_resolutions('900913'),
      'maxExtent' => openlayers_get_extent('900913'),
      'projection' => array('900913'),
      'osm' => FALSE,
      'layername' => '',
      'baselayer' => TRUE,
      'layer_handler' => 'MapBox',
      'type' => 'png',
    );
  }

  /**
   * Options form which generates layers
   */
  function options_form() {
    if (!isset($this->data)) {
      $this->data = $this->options_init();
    }
    return array(
      'urls' => array(
        '#type' => 'textarea',
        '#title' => t('Base URLs'),
        '#description' => t('The list of base URLs specified on !tiles (with trailing "/"). For details, visit the !support site.', array(
          '!tiles' => l(t('TileStream'), 'http://tiles.mapbox.com/'),
          '!support' => l(t('MapBox Support'), 'http://support.mapbox.com/kb/tilestream/using-tilestream-with-drupal'),
        )),
        '#default_value' => !empty($this->data['urls']) ? implode("\n", $this->data['urls']) : '',
      ),
      'layername' => array(
        '#type' => 'textfield',
        '#title' => t('MapBox Layer Name'),
        '#description' => t('The layer name specified on !tiles.', array(
          '!tiles' => l(t('TileStream'), 'http://tiles.mapbox.com/'),
        )),
        '#default_value' => $this->data['layername']
      ),
      'layer_type' => array(
        '#type' => 'hidden',
        '#value' => 'openlayers_layer_type_mapbox',
      ),
      'osm' => array(
        '#type' => 'checkbox',
        '#default_value' => $this->data['osm'],
        '#title' => t('OSM Attribution'),
        '#description' => t('Required if OpenStreetMap data is used.'),
      ),
      'baselayer' => array(
        '#type' => 'checkbox',
        '#default_value' => $this->data['baselayer'],
        '#title' => t('BaseLayer'),
        '#description' => t('Uncheck to make this map an overlay.'),
      ),
      'type' => array(
        '#title' => t('File extension'),
        '#type' => 'select',
        '#default_value' => $this->data['type'],
        '#options' => drupal_map_assoc(array('png', 'jpg')),
      ),
      'resolutions' => array(
        '#type' => 'select',
        '#multiple' => TRUE,
        '#options' => array_combine(array_map('strval', openlayers_get_resolutions('900913')), range(0, 18)),
        '#title' => t('Zoom Level Range'),
        '#default_value' => isset($this->data['resolutions']) ? array_map('strval', $this->data['resolutions']) : array(),
      ),
      'projection' => array(
        '0' => array(
          '#type' => 'hidden',
          '#value' => '900913',
        ),
      ),
    );
  }

  /**
   * Override to_record().
   */
  function to_record() {
    // Convert urls.
    if (!empty($this->data['urls'])) {
      $urls = explode("\n", $this->data['urls']);
      $this->data['urls'] = array();
      foreach ($urls as $url) {
        $url = trim($url);
        if (!empty($url) && strrpos($url, '/') === (strlen($url) - 1)) {
          $this->data['urls'][] = $url;
        }
      }
    }

    return parent::to_record();
  }

  /**
   * Render.
   */
  function render(&$map) {
    drupal_add_js(drupal_get_path('module', 'mapbox') . '/includes/layer_types/mapbox.js');
    drupal_add_css(drupal_get_path('module', 'mapbox') . '/js/mapbox.css');
    return $this->options;
  }
}
