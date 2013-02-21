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

  // Exported menu link: main-menu:node/1
  $menu_links['main-menu:node/1'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/1',
    'router_path' => 'node/%',
    'link_title' => 'About',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
  );
  // Exported menu link: main-menu:node/2
  $menu_links['main-menu:node/2'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/2',
    'router_path' => 'node/%',
    'link_title' => 'Get Involved',
    'options' => array(),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
  );
  // Exported menu link: main-menu:search
  $menu_links['main-menu:search'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'search',
    'router_path' => 'search',
    'link_title' => 'Directory',
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
    'weight' => '-7',
  );
  // Exported menu link: main-menu:user/logout
  $menu_links['main-menu:user/logout'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'user/logout',
    'router_path' => 'user/logout',
    'link_title' => 'Log Out',
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
    'weight' => '43',
  );
  // Exported menu link: menu-add-your-occupation:node/add/occupation
  $menu_links['menu-add-your-occupation:node/add/occupation'] = array(
    'menu_name' => 'menu-add-your-occupation',
    'link_path' => 'node/add/occupation',
    'router_path' => 'node/add/occupation',
    'link_title' => 'Add an Occupation!',
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
  // Exported menu link: menu-social-media-links:https://twitter.com/#!/OWSdirectory
  $menu_links['menu-social-media-links:https://twitter.com/#!/OWSdirectory'] = array(
    'menu_name' => 'menu-social-media-links',
    'link_path' => 'https://twitter.com/#!/OWSdirectory',
    'router_path' => '',
    'link_title' => 'Twitter',
    'options' => array(
      'attributes' => array(
        'title' => 'Find us on Twitter',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: menu-social-media-links:https://www.facebook.com/OccupyDirectory
  $menu_links['menu-social-media-links:https://www.facebook.com/OccupyDirectory'] = array(
    'menu_name' => 'menu-social-media-links',
    'link_path' => 'https://www.facebook.com/OccupyDirectory',
    'router_path' => '',
    'link_title' => 'Facebook',
    'options' => array(
      'attributes' => array(
        'title' => 'Connect to the Occupy Directory on Facebook!',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('About');
  t('Add an Occupation!');
  t('Atom (new)');
  t('Atom (updated)');
  t('CSV');
  t('CSV (now)');
  t('Directory');
  t('Facebook');
  t('Get Involved');
  t('Log Out');
  t('RSS (new)');
  t('RSS (updated)');
  t('Twitter');
  t('json');


  return $menu_links;
}
