<?php

/**
 * @file
 * Display Suite search-result configuration.
 */

function ds_search_result() {
  return array(
    'label' => t('search-result'),
    'regions' => array(
      'left' => t('left'),
      'right' => t('right'),
    ),
    'css' => TRUE,
    'image' => TRUE,
  );
}
