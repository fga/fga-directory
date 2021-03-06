<?php
/**
 * @file
 * Google Layer Type
 */

/**
 * Define the Ctools plugin options.
 */
$plugin = array(
  'title' => t('Google'),
  'description' => t('Google Maps API Map'),
  'layer_type' => array(
    'file' => 'openlayers_layer_type_google.inc',
    'class' => 'openlayers_layer_type_google',
    'parent' => 'openlayers_layer_type',
  ),
);

/**
 * OpenLayers Google Layer Type class
 */
class openlayers_layer_type_google extends openlayers_layer_type {
  function __construct($layer = array(), $map = array()) {
    parent::__construct($layer, $map);
    if (isset($this->data)) {
      $this->data += $this->options_init();
    }
    else {
      $this->data = $this->options_init();
    }
  }
  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'serverResolutions' => openlayers_get_resolutions('900913'),
      'maxExtent' => openlayers_get_extent('900913'),
      'projection' => array('900913'),
      'layer_type' => 'google',
      'layer_handler' => 'google',
      'baselayer' => TRUE,
      'animationEnabled' => TRUE,
    );
  }

  /**
   * Options form which generates layers
   */
  function options_form($defaults = array()) {
    $google_layer_types = array(
      'hybrid' => 'Hybrid',
      'normal' => 'Normal',
      'satellite' => 'Satellite',
      'physical' => 'Physical',
    );
    return array(
      'type' => array(
        '#title' => t('Google Layer Type'),
        '#type' => 'select',
        '#default_value' => isset($this->data['type']) ? $this->data['type'] : 'normal',
        '#options' => $google_layer_types
      ),
      'layer_type' => array(
        '#type' => 'hidden',
        '#value' => 'openlayers_layer_type_google'
      ),
      'numZoomLevels' => array(
        '#type' => 'textfield',
        '#title' => t('Number of Zoom Levels'),
        '#description' => t('Satellite and hybrid maps are occasionally
          unavailable at higher zoom levels.'),
        '#default_value' => isset($this->data['numZoomLevels']) ?
          $this->data['numZoomLevels'] : '15'
      ),
      'animationEnabled' => array(
        '#type' => 'checkbox',
        '#title' => t('Animation Enabled'),
        '#description' => t('This enables the Google Maps API zooming animation.
          If you are having issues with your Google layer, it may be helpful
          to turn this off.'),
        '#default_value' => isset($this->data['animationEnabled']) ?
          $this->data['animationEnabled'] : TRUE
      ),
    );
  }

  /**
   * Layer-type-wide settings form
   */
  function settings_form() {
    return array(
      'openlayers_google_version' => array(
        '#type' => 'select',
        '#title' => t('Google Maps API version'),
        '#description' => t('If you use Google Maps v3, an API key is not necessary.'),
        '#options' => array(
          '2' => t('v2'),
          '3.5' => t('v3.5'),
        ),
        '#default_value' => variable_get('openlayers_google_version', '3.5'),
      ),
      'openlayers_layers_google_api' => array(
        '#type' => 'textfield',
        '#title' => t('Google API Key'),
        '#default_value' => variable_get('openlayers_layers_google_api', ''),
        '#description' => t('<a href="@google">Obtain an API key from Google for your domain</a>',
          array('@google' => 'http://code.google.com/apis/maps/signup.html'))
      ),
      'openlayers_layers_google_language' => array(
        '#type' => 'textfield',
        '#title' => t('Language'),
        '#description' => t('This will set the language used
          for the interface (like attribution) as well as tiles,
          as supported by Google.  By default, Google Map API will
          determine the language automatically.  Only use this is you
          want to force a specific language.  Please see
          <a href="!url">this list of languages</a>.',
          array('!url' => 'http://sites.google.com/site/tomihasa/google-language-codes')
        ),
        '#default_value' => variable_get('openlayers_layers_google_language', ''),
      ),
    );
  }

  /**
   * Render.
   */
  function render(&$map) {
    static $google_maps_included;

    if (!isset($google_maps_included)) {
      // Include files.
      drupal_add_js(drupal_get_path('module', 'openlayers') .
        '/plugins/layer_types/openlayers_layer_type_google.js');

      $version = variable_get('openlayers_google_version', '3.5');
      if ($version == '2') {
        // Create URL for google include
        $url = '//maps.google.com/maps?file=api&sensor=false&v=' . $version;
        $key = variable_get('openlayers_layers_google_api', variable_get('googlemap_api_key', ''));
        $url = !empty($key) ? '&key=' . $key : '';
      }
      else {
        // Create URL for google include
        $url = '//maps.google.com/maps/api/js?sensor=false&v=' . $version;
      }

      $lang = variable_get('openlayers_layers_google_language', '');
      // Google v2 uses hl and v3 uses language
      $url .= !empty($lang) ? '&hl=' . $lang : '';
      $url .= !empty($lang) ? '&language=' . $lang : '';

      drupal_add_js($url, 'external');
      $google_maps_included = TRUE;
    }
    return $this->options;
  }
}
