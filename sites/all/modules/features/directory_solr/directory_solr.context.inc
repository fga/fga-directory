<?php
/**
 * @file
 * directory_solr.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function directory_solr_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'solr_search';
  $context->description = 'Expose search facets and properties for solr';
  $context->tag = 'blocks';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'search' => 'search',
        'search*' => 'search*',
      ),
    ),
    'views' => array(
      'values' => array(
        'global_search:page' => 'global_search:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'facetapi-tnxIEBW6zkk501rrRHnPi8n8h4luGDit' => array(
          'module' => 'facetapi',
          'delta' => 'tnxIEBW6zkk501rrRHnPi8n8h4luGDit',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-u1me3Etj2mkbex8xzsCeDIOkr5Q3sRSL' => array(
          'module' => 'facetapi',
          'delta' => 'u1me3Etj2mkbex8xzsCeDIOkr5Q3sRSL',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-Pm5e0jB3Duu7bhnhqVSxmXqfUOMN3ymq' => array(
          'module' => 'facetapi',
          'delta' => 'Pm5e0jB3Duu7bhnhqVSxmXqfUOMN3ymq',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
    'theme_html' => array(
      'class' => 'solr-search',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Expose search facets and properties for solr');
  t('blocks');
  $export['solr_search'] = $context;

  return $export;
}
