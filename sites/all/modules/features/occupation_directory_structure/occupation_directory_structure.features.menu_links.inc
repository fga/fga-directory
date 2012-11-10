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
    'link_title' => 'Add an Entry!',
    'options' => array(
      'attributes' => array(
        'title' => 'Add your occupation, assembly, camp or project!',
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
    'link_title' => 'CSV (now)',
    'options' => array(
      'attributes' => array(
        'title' => 'a CSV that is generated on-the-fly.',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
  );
  // Exported menu link: menu-feeds-and-exports:directory.json
  $menu_links['menu-feeds-and-exports:directory.json'] = array(
    'menu_name' => 'menu-feeds-and-exports',
    'link_path' => 'directory.json',
    'router_path' => 'directory.json',
    'link_title' => 'json',
    'options' => array(
      'attributes' => array(
        'title' => 'The entire directory in JSON format',
      ),
    ),
    'module' => 'system',
    'hidden' => '1',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '11',
  );
  // Exported menu link: menu-feeds-and-exports:http://directory.occupy.net/directory-daily.csv
  $menu_links['menu-feeds-and-exports:http://directory.occupy.net/directory-daily.csv'] = array(
    'menu_name' => 'menu-feeds-and-exports',
    'link_path' => 'http://directory.occupy.net/directory-daily.csv',
    'router_path' => '',
    'link_title' => 'CSV',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
  );
  // Exported menu link: menu-feeds-and-exports:occupations/added.atom
  $menu_links['menu-feeds-and-exports:occupations/added.atom'] = array(
    'menu_name' => 'menu-feeds-and-exports',
    'link_path' => 'occupations/added.atom',
    'router_path' => 'occupations/added.atom',
    'link_title' => 'Atom (new)',
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
    'weight' => '-46',
  );
  // Exported menu link: menu-feeds-and-exports:occupations/added.rss
  $menu_links['menu-feeds-and-exports:occupations/added.rss'] = array(
    'menu_name' => 'menu-feeds-and-exports',
    'link_path' => 'occupations/added.rss',
    'router_path' => 'occupations/added.rss',
    'link_title' => 'RSS (new)',
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
  // Exported menu link: menu-feeds-and-exports:occupations/updated.atom
  $menu_links['menu-feeds-and-exports:occupations/updated.atom'] = array(
    'menu_name' => 'menu-feeds-and-exports',
    'link_path' => 'occupations/updated.atom',
    'router_path' => 'occupations/updated.atom',
    'link_title' => 'Atom (updated)',
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
    'weight' => '-45',
  );
  // Exported menu link: menu-feeds-and-exports:occupations/updated.rss
  $menu_links['menu-feeds-and-exports:occupations/updated.rss'] = array(
    'menu_name' => 'menu-feeds-and-exports',
    'link_path' => 'occupations/updated.rss',
    'router_path' => 'occupations/updated.rss',
    'link_title' => 'RSS (updated)',
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
  // Translatables
  // Included for use with string extractors like potx.
  t('Add an Entry!');
  t('Atom (new)');
  t('Atom (updated)');
  t('CSV');
  t('CSV (now)');
  t('RSS (new)');
  t('RSS (updated)');
  t('json');


  return $menu_links;
}
