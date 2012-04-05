<?php
/**
 * @file
 * occupation_directory_structure.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function occupation_directory_structure_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-add-your-occupation:node/add/occupation
  $menu_links['menu-add-your-occupation:node/add/occupation'] = array(
    'menu_name' => 'menu-add-your-occupation',
    'link_path' => 'node/add/occupation',
    'router_path' => 'node/add/occupation',
    'link_title' => '+ add your occupation!',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: menu-feeds-and-exports:directory.csv
  $menu_links['menu-feeds-and-exports:directory.csv'] = array(
    'menu_name' => 'menu-feeds-and-exports',
    'link_path' => 'directory.csv',
    'router_path' => 'directory.csv',
    'link_title' => 'CSV',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
  );
  // Exported menu link: menu-feeds-and-exports:occupations/added.atom
  $menu_links['menu-feeds-and-exports:occupations/added.atom'] = array(
    'menu_name' => 'menu-feeds-and-exports',
    'link_path' => 'occupations/added.atom',
    'router_path' => 'occupations/added.atom',
    'link_title' => 'Atom (recently added)',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-47',
  );
  // Exported menu link: menu-feeds-and-exports:occupations/added.rss
  $menu_links['menu-feeds-and-exports:occupations/added.rss'] = array(
    'menu_name' => 'menu-feeds-and-exports',
    'link_path' => 'occupations/added.rss',
    'router_path' => 'occupations/added.rss',
    'link_title' => 'RSS (recently added)',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
  );
  // Exported menu link: menu-feeds-and-exports:occupations/json
  $menu_links['menu-feeds-and-exports:occupations/json'] = array(
    'menu_name' => 'menu-feeds-and-exports',
    'link_path' => 'occupations/json',
    'router_path' => 'occupations/json',
    'link_title' => 'json',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: menu-feeds-and-exports:occupations/updated.atom
  $menu_links['menu-feeds-and-exports:occupations/updated.atom'] = array(
    'menu_name' => 'menu-feeds-and-exports',
    'link_path' => 'occupations/updated.atom',
    'router_path' => 'occupations/updated.atom',
    'link_title' => 'Atom (recently updated)',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: menu-feeds-and-exports:occupations/updated.rss
  $menu_links['menu-feeds-and-exports:occupations/updated.rss'] = array(
    'menu_name' => 'menu-feeds-and-exports',
    'link_path' => 'occupations/updated.rss',
    'router_path' => 'occupations/updated.rss',
    'link_title' => 'RSS (recently updated)',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('+ add your occupation!');
  t('Atom (recently added)');
  t('Atom (recently updated)');
  t('CSV');
  t('RSS (recently added)');
  t('RSS (recently updated)');
  t('json');


  return $menu_links;
}