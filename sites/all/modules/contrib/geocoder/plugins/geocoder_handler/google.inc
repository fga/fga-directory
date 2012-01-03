<?php
// $Id$

/**
 * @file
 * Plugin to provide a google geocoder.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t("Google Geocoder"),
  'description' => t('Geocodes via google geocoder'),
  'callback' => 'geocoder_google',
  'field_types' => array('text','text_long','addressfield','text_with_summary','computed'),
  'field_callback' => 'geocoder_google_field',
);

/**
 * Process Markup
 */
function geocoder_google($address, $return = 'point') {
  geocoder_load_geophp();
  return geoPHP::load($address,'google_geocode',$return);
}

function geocoder_google_field($field, $field_item) {
  if ($field['type'] == 'text' || $field['type'] == 'text_long' || $field['type'] == 'text_with_summary' || $field['type'] == 'computed') {
    return geocoder_google($field_item['value']);
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
    return geocoder_google($address);
  }
}
