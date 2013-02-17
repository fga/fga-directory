<?php

/**
 * @file
 * Display Suite search-result configuration.
 */

function ds_search_result() {
  return array(
    'label' => t('search-result'),
    'regions' => array(
      'id' => t('id'),
      'contact' => t('contact'),
      'misc' => t('misc'),
    ),
    'css' => TRUE,
    'image' => TRUE,
  );
}
