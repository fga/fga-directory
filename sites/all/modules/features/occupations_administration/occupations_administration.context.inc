<?php
/**
 * @file
 * occupations_administration.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function occupations_administration_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'manage_occupations';
  $context->description = 'Set up blocks differently when occupations are being managed';
  $context->tag = 'blocks';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'occupation_directory:occupations_manage' => 'occupation_directory:occupations_manage',
        'occupations_count:total_occupations' => 'occupations_count:total_occupations',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-914bc2c4fe4a3310e751e161b901751d' => array(
          'module' => 'views',
          'delta' => '914bc2c4fe4a3310e751e161b901751d',
          'region' => 'preface_first',
          'weight' => '-10',
        ),
      ),
    ),
    'menu' => 'occupations',
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Set up blocks differently when occupations are being managed');
  t('blocks');
  $export['manage_occupations'] = $context;

  return $export;
}
