<?php
/**
 * @file
 * occupations.openlayers_maps.inc
 */

/**
 * Implements hook_openlayers_maps().
 */
function occupations_openlayers_maps() {
  $export = array();

  $openlayers_maps = new stdClass();
  $openlayers_maps->disabled = FALSE; /* Edit this to true to make a default openlayers_maps disabled initially */
  $openlayers_maps->api_version = 1;
  $openlayers_maps->name = 'occupation_geofield_map';
  $openlayers_maps->title = 'Occupation Geofield Map';
  $openlayers_maps->description = 'A Map Used for Geofield Output on the Occupation Node';
  $openlayers_maps->data = array(
    'width' => '300px',
    'height' => '300px',
    'image_path' => 'sites/all/modules/contrib/openlayers/themes/default_dark/img/',
    'css_path' => 'sites/all/modules/contrib/openlayers/themes/default_dark/style.css',
    'proxy_host' => '',
    'hide_empty_map' => 0,
    'center' => array(
      'initial' => array(
        'centerpoint' => '',
        'zoom' => '12',
      ),
      'restrict' => array(
        'restrictextent' => 0,
        'restrictedExtent' => '',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_keyboarddefaults' => array(),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 0,
        'zoomBoxEnabled' => 0,
        'documentDrag' => 0,
      ),
      'openlayers_behavior_zoompanel' => array(),
      'openlayers_behavior_zoomtolayer' => array(
        'zoomtolayer' => 'geofield_formatter',
        'point_zoom_level' => '10',
      ),
    ),
    'default_layer' => 'occupations_mapbox_tms',
    'layers' => array(
      'occupations_mapbox_tms' => 'occupations_mapbox_tms',
      'geofield_formatter' => 'geofield_formatter',
    ),
    'layer_weight' => array(
      'geofield_formatter' => '-8',
      'occupation_map_data_openlayers_1' => '0',
      'openlayers_geojson_picture_this' => '0',
      'occupations_geojson' => '0',
    ),
    'layer_styles' => array(
      'occupations_geojson' => '0',
      'openlayers_geojson_picture_this' => '0',
      'occupation_map_data_openlayers_1' => '0',
      'geofield_formatter' => 'default_marker_gold',
    ),
    'layer_styles_select' => array(
      'occupations_geojson' => '0',
      'openlayers_geojson_picture_this' => '0',
      'occupation_map_data_openlayers_1' => '0',
      'geofield_formatter' => 'default_marker_gold',
    ),
    'layer_activated' => array(
      'geofield_formatter' => 'geofield_formatter',
      'occupations_geojson' => 0,
      'openlayers_geojson_picture_this' => 0,
      'occupation_map_data_openlayers_1' => 0,
    ),
    'layer_switcher' => array(
      'geofield_formatter' => 0,
      'occupations_geojson' => 0,
      'openlayers_geojson_picture_this' => 0,
      'occupation_map_data_openlayers_1' => 0,
    ),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'default',
      'select' => 'default',
      'temporary' => 'default',
    ),
  );
  $export['occupation_geofield_map'] = $openlayers_maps;

  $openlayers_maps = new stdClass();
  $openlayers_maps->disabled = FALSE; /* Edit this to true to make a default openlayers_maps disabled initially */
  $openlayers_maps->api_version = 1;
  $openlayers_maps->name = 'occupation_geofield_widget_map';
  $openlayers_maps->title = 'Occupation Geofield Widget Map';
  $openlayers_maps->description = 'Map Used for Geofield Input on Occupation nodes';
  $openlayers_maps->data = array(
    'width' => '300px',
    'height' => '300px',
    'image_path' => 'sites/all/modules/contrib/openlayers/themes/default_dark/img/',
    'css_path' => 'sites/all/modules/contrib/openlayers/themes/default_dark/style.css',
    'proxy_host' => '',
    'hide_empty_map' => 0,
    'center' => array(
      'initial' => array(
        'centerpoint' => '-73.983285504857, 40.722772974328',
        'zoom' => '11',
      ),
      'restrict' => array(
        'restrictextent' => 0,
        'restrictedExtent' => '',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_geofield' => array(
        'feature_types' => array(
          'point' => 'point',
          'polygon' => 'polygon',
          'path' => 0,
        ),
        'allow_edit' => 1,
      ),
      'openlayers_behavior_keyboarddefaults' => array(),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 1,
        'zoomBoxEnabled' => 1,
        'documentDrag' => 0,
      ),
      'openlayers_behavior_panzoombar' => array(
        'zoomWorldIcon' => 0,
        'panIcons' => 1,
      ),
    ),
    'default_layer' => 'occupations_mapbox_tms',
    'layers' => array(
      'occupations_mapbox_tms' => 'occupations_mapbox_tms',
    ),
    'layer_weight' => array(
      'occupations_geojson' => '-5',
      'occupation_map_data_openlayers_1' => '-2',
      'geofield_formatter' => '0',
      'openlayers_geojson_picture_this' => '0',
    ),
    'layer_styles' => array(
      'occupations_geojson' => '0',
      'geofield_formatter' => '0',
      'openlayers_geojson_picture_this' => '0',
      'occupation_map_data_openlayers_1' => '0',
    ),
    'layer_styles_select' => array(
      'occupations_geojson' => '0',
      'geofield_formatter' => '0',
      'openlayers_geojson_picture_this' => '0',
      'occupation_map_data_openlayers_1' => '0',
    ),
    'layer_activated' => array(
      'occupations_geojson' => 0,
      'geofield_formatter' => 0,
      'openlayers_geojson_picture_this' => 0,
      'occupation_map_data_openlayers_1' => 0,
    ),
    'layer_switcher' => array(
      'occupations_geojson' => 0,
      'geofield_formatter' => 0,
      'openlayers_geojson_picture_this' => 0,
      'occupation_map_data_openlayers_1' => 0,
    ),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'default',
      'select' => 'default_select',
      'temporary' => 'default',
    ),
  );
  $export['occupation_geofield_widget_map'] = $openlayers_maps;

  return $export;
}
