<?php
/**
 * @file
 * occupations.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function occupations_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:occupations
  $menu_links['main-menu:occupations'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'occupations',
    'router_path' => 'occupations',
    'link_title' => 'Directory',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Directory');


  return $menu_links;
}
