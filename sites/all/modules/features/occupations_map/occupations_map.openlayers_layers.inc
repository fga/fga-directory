<?php
/**
 * @file
 * occupations_map.openlayers_layers.inc
 */

/**
 * Implements hook_openlayers_layers().
 */
function occupations_map_openlayers_layers() {
  $export = array();

  $openlayers_layers = new stdClass();
  $openlayers_layers->disabled = FALSE; /* Edit this to true to make a default openlayers_layers disabled initially */
  $openlayers_layers->api_version = 1;
  $openlayers_layers->name = 'mapbox_xyz';
  $openlayers_layers->title = 'Mapbox XYZ';
  $openlayers_layers->description = 'loading with XYZ';
  $openlayers_layers->data = array(
    'base_url' => 'http://a.tiles.mapbox.com/v3/occupy.map-7o6g1bgq/${z}/${x}/${y}.png',
    'layer_type' => 'openlayers_layer_type_xyz',
    'serverResolutions' => array(
      '39135.758475' => '39135.758475',
      '19567.8792375' => '19567.8792375',
      '9783.93961875' => '9783.93961875',
      '4891.96980938' => '4891.96980938',
      '2445.98490469' => '2445.98490469',
      '1222.99245234' => '1222.99245234',
      '611.496226172' => '611.496226172',
      '305.748113086' => '305.748113086',
      '152.874056543' => '152.874056543',
      '76.4370282715' => '76.4370282715',
      '38.2185141357' => '38.2185141357',
      '19.1092570679' => '19.1092570679',
      '9.55462853394' => '9.55462853394',
      '4.77731426697' => '4.77731426697',
      '2.38865713348' => '2.38865713348',
    ),
    'wrapDateLine' => 1,
    'projection' => array(
      0 => '900913',
    ),
  );
  $export['mapbox_xyz'] = $openlayers_layers;

  $openlayers_layers = new stdClass();
  $openlayers_layers->disabled = FALSE; /* Edit this to true to make a default openlayers_layers disabled initially */
  $openlayers_layers->api_version = 1;
  $openlayers_layers->name = 'occupations_geojson';
  $openlayers_layers->title = 'Occupations geojson';
  $openlayers_layers->description = 'output using views geojson module';
  $openlayers_layers->data = array(
    'url' => 'v1/occupations/occupy-directory.geojson',
    'geojson_data' => '',
    'layer_type' => 'openlayers_layer_type_geojson',
  );
  $export['occupations_geojson'] = $openlayers_layers;

  $openlayers_layers = new stdClass();
  $openlayers_layers->disabled = FALSE; /* Edit this to true to make a default openlayers_layers disabled initially */
  $openlayers_layers->api_version = 1;
  $openlayers_layers->name = 'occupations_mapbox_tms';
  $openlayers_layers->title = 'Mapbox TMS';
  $openlayers_layers->description = 'loading mapbox layer with TMS spec';
  $openlayers_layers->data = array(
    'base_url' => 'http://a.tiles.mapbox.com/v3/',
    'layername' => 'occupy.map-7o6g1bgq',
    'baselayer' => 1,
    'type' => 'png',
    'resolutions' => array(
      0 => 39135.758475,
      1 => 19567.8792375,
      2 => 9783.93961875,
      3 => 4891.96980938,
      4 => 2445.98490469,
      5 => 1222.99245234,
      6 => 611.496226172,
      7 => 305.748113086,
      8 => 152.874056543,
      9 => 76.4370282715,
      10 => 38.2185141357,
    ),
    'wrapDateLine' => 1,
    'layer_type' => 'openlayers_layer_type_tms',
  );
  $export['occupations_mapbox_tms'] = $openlayers_layers;

  $openlayers_layers = new stdClass();
  $openlayers_layers->disabled = FALSE; /* Edit this to true to make a default openlayers_layers disabled initially */
  $openlayers_layers->api_version = 1;
  $openlayers_layers->name = 'occupy_mapbox_1';
  $openlayers_layers->title = 'Mapbox occupy streets';
  $openlayers_layers->description = 'baselayer provided by mapbox module';
  $openlayers_layers->data = array(
    'urls' => array(
      0 => 'http://a.tiles.mapbox.com/v3/occupy/',
    ),
    'layername' => 'occupy.map-7o6g1bgq',
    'layer_type' => 'openlayers_layer_type_mapbox',
    'osm' => 0,
    'baselayer' => 1,
    'type' => 'png',
    'resolutions' => array(
      0 => 39135.758475,
      1 => 19567.8792375,
      2 => 9783.93961875,
      3 => 4891.96980938,
      4 => 2445.98490469,
      5 => 1222.99245234,
      6 => 611.496226172,
      7 => 305.748113086,
      8 => 152.874056543,
      9 => 76.4370282715,
      10 => 38.2185141357,
      11 => 19.1092570679,
      12 => 9.55462853394,
      13 => 4.77731426697,
      14 => 2.38865713348,
    ),
    'projection' => array(
      0 => '900913',
    ),
  );
  $export['occupy_mapbox_1'] = $openlayers_layers;

  return $export;
}
