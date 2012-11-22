<?php
/**
 * @file
 * directory_views_search.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function directory_views_search_context_default_contexts() {
  $export = array();

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
        '~solr_search' => '~solr_search',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('blocks');
  t('we want to search occupations from everywhere except when we manage occupations');
  $export['search_occupations'] = $context;

  return $export;
}
