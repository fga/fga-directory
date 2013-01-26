<?php

/**
 * @file
 */

function _mapbox_layers_info() {
  $info = array();
  $info['mapbox_streets'] = array(
    'name'=> t('MapBox Streets'),
    'description' => t('MapBox Streets'),
    'layername' => 'mapbox-streets',
    'minzoom' => 0,
    'maxzoom' => 16
  );
  $info['mapbox_world_bright'] = array(
    'name' => t('MapBox World Bright'),
    'description' => t('MapBox World Bright'),
    'layername' => 'world-bright',
    'minzoom' => 0,
    'maxzoom' => 11,
  );
  $info['mapbox_world_dark'] = array(
    'name' => t('MapBox World Dark'),
    'description' => t('MapBox World Dark'),
    'layername' => 'world-dark',
    'minzoom' => 0,
    'maxzoom' => 11,
  );
  $info['mapbox_world_glass'] = array(
    'name' => t('MapBox World Glass'),
    'description' => t('MapBox World Glass'),
    'layername' => 'world-glass',
    'minzoom' => 0,
    'maxzoom' => 11,
  );
  $info['mapbox_world_light'] = array(
    'name' => t('MapBox World Light'),
    'description' => t('MapBox World Light'),
    'layername' => 'world-light',
    'minzoom' => 0,
    'maxzoom' => 11,
  );
  $info['mapbox_world_print'] = array(
    'name' => t('MapBox World Print'),
    'description' => t('MapBox World Print'),
    'layername' => 'world-print',
    'minzoom' => 0,
    'maxzoom' => 9,
  );
  $info['mapbox_world_black'] = array(
    'name' => t('MapBox World Black'),
    'description' => t('MapBox World Black'),
    'layername' => 'world-black',
    'minzoom' => 0,
    'maxzoom' => 11,
  );

  return $info;
}

function _mapbox_openlayers_layers() {
  $info = _mapbox_layers_info();
  $resolutions = array_combine(range(0, 18), openlayers_get_resolutions('900913'));

  $export = array();
  foreach ($info as $key => $item) {
    $openlayers_layers = new stdClass;
    $openlayers_layers->disabled = FALSE; /* Edit this to true to make a default openlayers_layers disabled initially */
    $openlayers_layers->api_version = 1;
    $openlayers_layers->name = $key;
    $openlayers_layers->title = $item['name'];
    $openlayers_layers->description = $item['description'];
    $openlayers_layers->data = array(
      'urls' => array(
        0 => 'http://a.tiles.mapbox.com/mapbox/',
        1 => 'http://b.tiles.mapbox.com/mapbox/',
        2 => 'http://c.tiles.mapbox.com/mapbox/',
        3 => 'http://d.tiles.mapbox.com/mapbox/',
      ),
      'layername' => $item['layername'],
      'layer_type' => 'openlayers_layer_type_mapbox',
      'osm' => FALSE,
      'baselayer' => TRUE,
      'type' => 'png',
      'resolutions' => array_intersect_key($resolutions, array_flip(range($item['minzoom'], $item['maxzoom']))),
      'projection' => array('900913'),
    );
    $export[$key] = $openlayers_layers;
  }

  return $export;
}
