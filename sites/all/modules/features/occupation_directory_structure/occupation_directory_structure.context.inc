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
  $context->name = 'directory_get_involved';
  $context->description = 'context for get-involved page';
  $context->tag = 'blocks';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'get-involved' => 'get-involved',
        'node/2' => 'node/2',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'webform-client-block-3' => array(
          'module' => 'webform',
          'delta' => 'client-block-3',
          'region' => 'content',
          'weight' => '8',
        ),
        'boxes-twitter_pull' => array(
          'module' => 'boxes',
          'delta' => 'twitter_pull',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('blocks');
  t('context for get-involved page');
  $export['directory_get_involved'] = $context;

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
    'block' => array(
      'blocks' => array(
        'directory-directory-map' => array(
          'module' => 'directory',
          'delta' => 'directory-map',
          'region' => 'content',
          'weight' => '-10',
        ),
        'boxes-occupation_count' => array(
          'module' => 'boxes',
          'delta' => 'occupation_count',
          'region' => 'branding',
          'weight' => '-10',
        ),
      ),
    ),
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
  $context->name = 'occupy_directory_about';
  $context->description = 'about page';
  $context->tag = 'blocks';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'about' => 'about',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-twitter_pull' => array(
          'module' => 'boxes',
          'delta' => 'twitter_pull',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('about page');
  t('blocks');
  $export['occupy_directory_about'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'public';
  $context->description = 'for non-admins, we display things differently';
  $context->tag = 'blocks';
  $context->conditions = array(
    'user' => array(
      'values' => array(
        'anonymous user' => 'anonymous user',
        'occupation registrant' => 'occupation registrant',
        'unconfirmed' => 'unconfirmed',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-occupynet_nav' => array(
          'module' => 'boxes',
          'delta' => 'occupynet_nav',
          'region' => 'navbar',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('blocks');
  t('for non-admins, we display things differently');
  $export['public'] = $context;

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
        'ajax_register-ajax_register_block' => array(
          'module' => 'ajax_register',
          'delta' => 'ajax_register_block',
          'region' => 'menu',
          'weight' => '9',
        ),
        'menu-menu-social-media-links' => array(
          'module' => 'menu',
          'delta' => 'menu-social-media-links',
          'region' => 'footer_first',
          'weight' => '-10',
        ),
        'menu-menu-add-your-occupation' => array(
          'module' => 'menu',
          'delta' => 'menu-add-your-occupation',
          'region' => 'footer_first',
          'weight' => '0',
        ),
        'menu-menu-feeds-and-exports' => array(
          'module' => 'menu',
          'delta' => 'menu-feeds-and-exports',
          'region' => 'footer_first',
          'weight' => '10',
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
