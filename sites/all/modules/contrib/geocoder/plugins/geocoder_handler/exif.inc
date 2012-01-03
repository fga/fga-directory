<?php // $Id: imagefield.inc,v 1.3 2009/03/02 18:14:07 vauxia Exp $


if (function_exists('exif_read_data')) {
	$plugin = array(
	  'title' => t("Image/exif"),
	  'description' => t('Get a location from an image that was taken with a GPS enabled phone or camera'),
	  'callback' => 'geocoder_exif',
	  'field_types' => array('file','image'),
	  'field_callback' => 'geocoder_exif_field',
	);
}

function geocoder_exif($filepath) {
	geocoder_load_geophp();
  if ($data = exif_read_data($filepath)) {
    if (!isset($data['GPSLatitudeRef'])) return FALSE;
    $lat = geocoder_exif_from($data['GPSLatitudeRef'], $data['GPSLatitude']);
    $lon = geocoder_exif_from($data['GPSLongitudeRef'], $data['GPSLongitude']);
    $point = new Point($lon, $lat);
    return $point;
  }
  else return FALSE;
}

function geocoder_exif_field($field, $field_item) {
  $file = file_load($field_item['value']);
  return geocoder_exif($file->uri);
}

function geocoder_exif_from($dir, $data) {
  foreach ($data as $k => $item) {
    list($deg, $pct) = explode('/', $item);
    if ($pct) $data[$k] = $deg / $pct;
  }
  $point = (float) $data[0] + ($data[1] / 60) + ($data[2] / 3600);
  if (in_array($dir, array('S', 'W'))) $point = $point * -1;
  return $point;
}
