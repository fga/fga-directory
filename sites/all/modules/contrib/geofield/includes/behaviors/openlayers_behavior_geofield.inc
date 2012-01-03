<?php

/**
 * @file
 * Implementation of OpenLayers behavior.
 */

/**
 * Map Form Values Behavior
 */
class openlayers_behavior_geofield extends openlayers_behavior {

  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'feature_types' => array(),
      'wkt' => '',
    );
  }

  function options_form($defaults = array()) {
    $features = array(
      'point' => t('Point'),
      'path' => t('Path'),
      'polygon' => t('Polygon'),
    );

    return array(
      'feature_types' => array(
        '#title' => t('Available Features'),
        '#type' => 'checkboxes',
        '#options' => $features,
        '#description' => t('Select what features are available to draw.'),
        '#default_value' => isset($defaults['feature_types']) ? $defaults['feature_types'] : array(),
      ),
    );
  }

  /**
   * Render.
   */
  function render(&$map) {
    $geopath = drupal_get_path('module', 'geofield');
    drupal_add_css($geopath . '/includes/behaviors/css/openlayers_behavior_geofield.css');
    drupal_add_js($geopath . '/includes/behaviors/js/openlayers_behavior_geofield.js');
    return $this->options;
  }
}
