<?php
// $Id$

/**
 * @file
 * Plugin to provide a yahoo geocoder.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t("Yahoo Placefinder"),
  'description' => t('Geocodes via Yahoo Placefinder'),
  'callback' => 'geocoder_yahoo',
  'field_types' => array('text','text_long','addressfield','text_with_summary','computed'),
  'field_callback' => 'geocoder_yahoo_field',
);

/**
 * Process Markup
 */
function geocoder_yahoo($address, $return = 'point') {
  $geocoder_settings = variable_get("geocoder_settings",array());
  $consumer_key = $geocoder_settings["geocoder_apikey_yahoo"];
  $request=drupal_http_request("http://where.yahooapis.com/geocode?location=" . urlencode($address) . "&flags=J&appid={$consumer_key}");
  $data=json_decode($request->data);

  geocoder_load_geophp();
  return _geocoder_yahoo_geometry($data, $return);
}

function geocoder_yahoo_field($field, $field_item) {
  if ($field['type'] == 'text' || $field['type'] == 'text_long' || $field['type'] == 'text_with_summary' || $field['type'] == 'computed') {
    return geocoder_yahoo($field_item['value']);
  }
  if ($field['type'] == 'addressfield') {
    $address = '';
    if (!empty($field_item['premise']))                 $address .= $field_item['premise'].',';
    if (!empty($field_item['thoroughfare']))            $address .= $field_item['thoroughfare'].',';
    if (!empty($field_item['locality']))                $address .= $field_item['locality'].',';
    if (!empty($field_item['administrative_area']))     $address .= $field_item['administrative_area'].',';
    if (!empty($field_item['sub_administrative_area'])) $address .= $field_item['sub_administrative_area'].',';
    if (!empty($field_item['country']))                 $address .= $field_item['country'].',';
    if (!empty($field_item['postal_code']))             $address .= $field_item['postal_code'].',';

    $address = rtrim($address,', ');
    return geocoder_yahoo($address);
  }
}

function _geocoder_yahoo_geometry(&$data, $return = 'point') {
  if(!isset($data->ResultSet->Results[0]->longitude, $data->ResultSet->Results[0])) {
    return NULL;
  }
  switch($return) {
    case "point":
      return new Point ($data->ResultSet->Results[0]->longitude, $data->ResultSet->Results[0]->latitude);
      break;
  }
}

