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

  $openlayers_maps = new stdClass();
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
        'centerpoint' => '-18.632815554265, 20.961436761951',
        'zoom' => '2',
      ),
      'restrict' => array(
        'restrictextent' => 0,
        'restrictedExtent' => '',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_keyboarddefaults' => array(),
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
    ),
    'default_layer' => 'mapbox_world_glass',
    'layers' => array(
      'mapbox_world_glass' => 'mapbox_world_glass',
      'mapbox_world_bright' => 'mapbox_world_bright',
      'occupation_map_data_openlayers_1' => 'occupation_map_data_openlayers_1',
    ),
    'layer_weight' => array(
      'occupations_geojson' => '-5',
      'occupation_map_data_openlayers_1' => '-4',
      'geofield_formatter' => '0',
      'openlayers_geojson_picture_this' => '0',
    ),
    'layer_styles' => array(
      'occupations_geojson' => 'default_marker_black_small',
      'geofield_formatter' => '0',
      'openlayers_geojson_picture_this' => '0',
      'occupation_map_data_openlayers_1' => 'default_marker_black_small',
    ),
    'layer_styles_select' => array(
      'occupations_geojson' => 'default_marker_black_small',
      'geofield_formatter' => '0',
      'openlayers_geojson_picture_this' => '0',
      'occupation_map_data_openlayers_1' => 'default_marker_black_small',
    ),
    'layer_activated' => array(
      'occupation_map_data_openlayers_1' => 'occupation_map_data_openlayers_1',
      'occupations_geojson' => 0,
      'geofield_formatter' => 0,
      'openlayers_geojson_picture_this' => 0,
    ),
    'layer_switcher' => array(
      'occupation_map_data_openlayers_1' => 0,
      'occupations_geojson' => 0,
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

  $openlayers_maps = new stdClass();
  $openlayers_maps->disabled = FALSE; /* Edit this to true to make a default openlayers_maps disabled initially */
  $openlayers_maps->api_version = 1;
  $openlayers_maps->name = 'occupations_mapbox';
  $openlayers_maps->title = 'Occupations Mapbox';
  $openlayers_maps->description = 'All Occupations Map leveraging Mapbox tiles as a baselayer for the world view and geojson for the data';
  $openlayers_maps->data = array(
    'width' => 'auto',
    'height' => '500px',
    'image_path' => 'sites/all/modules/contrib/openlayers/themes/default_dark/img/',
    'css_path' => 'sites/all/modules/contrib/openlayers/themes/default_dark/style.css',
    'proxy_host' => '',
    'hide_empty_map' => 0,
    'center' => array(
      'initial' => array(
        'centerpoint' => '-18.632815554265, 20.961436761951',
        'zoom' => '2',
      ),
      'restrict' => array(
        'restrictextent' => 0,
        'restrictedExtent' => '',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_keyboarddefaults' => array(),
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
          'occupations_geojson' => 'occupations_geojson',
        ),
      ),
      'openlayers_behavior_zoompanel' => array(),
    ),
    'default_layer' => 'occupations_mapbox_tms',
    'layers' => array(
      'occupy_mapbox_1' => 'occupy_mapbox_1',
      'mapbox_world_glass' => 'mapbox_world_glass',
      'mapbox_xyz' => 'mapbox_xyz',
      'occupations_mapbox_tms' => 'occupations_mapbox_tms',
      'occupations_geojson' => 'occupations_geojson',
    ),
    'layer_weight' => array(
      'occupations_geojson' => '-5',
      'occupation_map_data_openlayers_1' => '-2',
      'openlayers_geojson_picture_this' => '0',
      'geofield_formatter' => '0',
    ),
    'layer_styles' => array(
      'geofield_formatter' => '0',
      'openlayers_geojson_picture_this' => '0',
      'occupation_map_data_openlayers_1' => 'default_marker_black_small',
      'occupations_geojson' => 'default_marker_gold',
    ),
    'layer_styles_select' => array(
      'geofield_formatter' => '0',
      'openlayers_geojson_picture_this' => '0',
      'occupation_map_data_openlayers_1' => 'default_marker_black_small',
      'occupations_geojson' => 'default_marker_gold',
    ),
    'layer_activated' => array(
      'occupations_geojson' => 'occupations_geojson',
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
  $export['occupations_mapbox'] = $openlayers_maps;

  return $export;
}
