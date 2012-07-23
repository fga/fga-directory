<?php
/**
 * @file
 * occupations.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function occupations_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'directory_listing';
  $context->description = 'list view of occupations';
  $context->tag = 'pages';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'occupation_directory:occupations_list' => 'occupation_directory:occupations_list',
      ),
    ),
  );
  $context->reactions = array(
    'theme_html' => array(
      'class' => 'occupations-list',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('list view of occupations');
  t('pages');
  $export['directory_listing'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'search_occupations';
  $context->description = 'we want to search occupations from everywhere except when we manage occupations';
  $context->tag = 'blocks';
  $context->conditions = array(
    'context' => array(
      'values' => array(
        '~manage_occupations' => '~manage_occupations',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-fb774b8c338b94662d3aab27b7b1bfc9' => array(
          'module' => 'views',
          'delta' => 'fb774b8c338b94662d3aab27b7b1bfc9',
          'region' => 'preface_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('blocks');
  t('we want to search occupations from everywhere except when we manage occupations');
  $export['search_occupations'] = $context;

  return $export;
}
