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

  // Exported menu: menu-add-your-occupation
  $menus['menu-add-your-occupation'] = array(
    'menu_name' => 'menu-add-your-occupation',
    'title' => 'Add your Occupation',
    'description' => '',
  );
  // Exported menu: menu-feeds-and-exports
  $menus['menu-feeds-and-exports'] = array(
    'menu_name' => 'menu-feeds-and-exports',
    'title' => 'Feeds and Exports',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Add your Occupation');
  t('Feeds and Exports');


  return $menus;
}
