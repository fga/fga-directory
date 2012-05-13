<?php
/**
 * @file
 * occupation_directory_structure.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function occupation_directory_structure_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'front';
  $context->description = 'Is the front page';
  $context->tag = 'pages';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
        'world-map' => 'world-map',
      ),
    ),
    'views' => array(
      'values' => array(
        'map_displays:page' => 'map_displays:page',
        'map_displays:page_mapbox' => 'map_displays:page_mapbox',
      ),
    ),
  );
  $context->reactions = array(
    'delta' => array(
      'delta_template' => 'directory_fullmap',
    ),
    'theme_html' => array(
      'class' => 'fullwidth-map',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Is the front page');
  t('pages');
  $export['front'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sidewide_blocks';
  $context->description = 'Blocks as they appear in a sitewide context';
  $context->tag = 'blocks';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-user-menu' => array(
          'module' => 'system',
          'delta' => 'user-menu',
          'region' => 'user_first',
          'weight' => '-10',
        ),
        'menu-menu-add-your-occupation' => array(
          'module' => 'menu',
          'delta' => 'menu-add-your-occupation',
          'region' => 'footer_first',
          'weight' => '-16',
        ),
        'menu-menu-feeds-and-exports' => array(
          'module' => 'menu',
          'delta' => 'menu-feeds-and-exports',
          'region' => 'footer_first',
          'weight' => '-15',
        ),
        'boxes-social_media' => array(
          'module' => 'boxes',
          'delta' => 'social_media',
          'region' => 'footer_first',
          'weight' => '-14',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks as they appear in a sitewide context');
  t('blocks');
  $export['sidewide_blocks'] = $context;

  return $export;
}
