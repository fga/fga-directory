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

  // Exported menu: main-menu.
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => 'Main menu',
    'description' => 'The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.',
  );
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
  t('Main menu');
  t('Social Media Links');
  t('The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.');


  return $menus;
}
