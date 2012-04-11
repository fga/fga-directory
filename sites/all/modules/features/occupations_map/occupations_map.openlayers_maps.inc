<?php
/**
 * @file
 * occupations_map.openlayers_maps.inc
 */

/**
 * Implements hook_openlayers_maps().
 */
function occupations_map_openlayers_maps() {
  $export = array();

  $openlayers_maps = new stdClass;
  $openlayers_maps->disabled = FALSE; /* Edit this to true to make a default openlayers_maps disabled initially */
  $openlayers_maps->api_version = 1;
  $openlayers_maps->name = 'occupation_map';
  $openlayers_maps->title = 'Occupation Map';
  $openlayers_maps->description = 'Map of all occupations';
  $openlayers_maps->data = array(
    'width' => 'auto',
    'height' => '500px',
    'image_path' => 'sites/all/modules/contrib/openlayers/themes/default_dark/img/',
    'css_path' => 'sites/all/modules/contrib/openlayers/themes/default_dark/style.css',
    'proxy_host' => '',
    'hide_empty_map' => 0,
    'center' => array(
      'initial' => array(
        'centerpoint' => '0,0',
        'zoom' => '2',
      ),
      'restrict' => array(
        'restrictextent' => 0,
        'restrictedExtent' => '',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_keyboarddefaults' => array(),
      'openlayers_behavior_attribution' => array(
        'seperator' => '',
      ),
      'openlayers_behavior_layerswitcher' => array(
        'ascending' => 1,
        'roundedCorner' => 1,
        'roundedCornerColor' => '#222222',
      ),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 1,
        'zoomBoxEnabled' => 1,
        'documentDrag' => 0,
      ),
      'openlayers_behavior_popup' => array(
        'layers' => array(
          'occupation_map_data_openlayers_1' => 'occupation_map_data_openlayers_1',
        ),
      ),
      'openlayers_behavior_zoompanel' => array(),
      'openlayers_behavior_zoomtomaxextent' => array(),
    ),
    'default_layer' => 'osm_mapnik',
    'layers' => array(
      'mapquest_osm' => 'mapquest_osm',
      'mapquest_openaerial' => 'mapquest_openaerial',
      'osm_mapnik' => 'osm_mapnik',
      'osm_tah' => 'osm_tah',
      'occupation_map_data_openlayers_1' => 'occupation_map_data_openlayers_1',
    ),
    'layer_weight' => array(
      'occupation_map_data_openlayers_1' => '0',
      'openlayers_geojson_picture_this' => '0',
      'geofield_formatter' => '0',
    ),
    'layer_styles' => array(
      'geofield_formatter' => '0',
      'openlayers_geojson_picture_this' => '0',
      'occupation_map_data_openlayers_1' => 'default_marker_black_small',
    ),
    'layer_styles_select' => array(
      'geofield_formatter' => '0',
      'openlayers_geojson_picture_this' => '0',
      'occupation_map_data_openlayers_1' => 'default_marker_black_small',
    ),
    'layer_activated' => array(
      'occupation_map_data_openlayers_1' => 'occupation_map_data_openlayers_1',
      'geofield_formatter' => 0,
      'openlayers_geojson_picture_this' => 0,
    ),
    'layer_switcher' => array(
      'occupation_map_data_openlayers_1' => 'occupation_map_data_openlayers_1',
      'geofield_formatter' => 0,
      'openlayers_geojson_picture_this' => 0,
    ),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'default',
      'select' => 'default_select',
      'temporary' => 'default',
    ),
  );
  $export['occupation_map'] = $openlayers_maps;

  return $export;
}
