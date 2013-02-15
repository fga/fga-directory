<?php
/**
 * @file
 * occupation_directory_structure.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function occupation_directory_structure_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-add-your-occupation.
  $menus['menu-add-your-occupation'] = array(
    'menu_name' => 'menu-add-your-occupation',
    'title' => 'Footer Links',
    'description' => '',
  );
  // Exported menu: menu-feeds-and-exports.
  $menus['menu-feeds-and-exports'] = array(
    'menu_name' => 'menu-feeds-and-exports',
    'title' => 'Feeds and Exports',
    'description' => '',
  );
  // Exported menu: menu-social-media-links.
  $menus['menu-social-media-links'] = array(
    'menu_name' => 'menu-social-media-links',
    'title' => 'Social Media Links',
    'description' => 'Global social media links for the directory\'s social media accounte/sites/presence',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Feeds and Exports');
  t('Footer Links');
  t('Global social media links for the directory\'s social media accounte/sites/presence');
  t('Social Media Links');


  return $menus;
}
