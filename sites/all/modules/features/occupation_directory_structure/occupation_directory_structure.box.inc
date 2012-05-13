<?php
/**
 * @file
 * occupation_directory_structure.box.inc
 */

/**
 * Implements hook_default_box().
 */
function occupation_directory_structure_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'social_media';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'social media links';
  $box->options = array(
    'body' => array(
      'value' => '<p><a href="http://www.facebook.com/OccupyDirectory" target="_blank"><img alt="facebook" alt="facebook" class="facebook-icon" id="facebook-icon" src="/sites/all/themes/occupy_directory/assets/facebook.png" style="width: 19px; height: 20px;"></a>&nbsp; <a href="https://twitter.com/#!/OWSdirectory" alt="twitter" target="_blank"><img alt="twitter" class="twitter-icon" id="twitter-icon" src="/sites/all/themes/occupy_directory/assets/twitter.png" style="width: 27px; height: 19px;"></a></p>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['social_media'] = $box;

  return $export;
}
