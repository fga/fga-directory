<?php

/**
 * @file
 * Display Suite nugget configuration.
 */

function ds_nugget() {
  return array(
    'label' => t('nugget'),
    'regions' => array(
      'left' => t('left'),
      'middle' => t('middle'),
      'right' => t('right'),
    ),
    'css' => TRUE,
    'image' => TRUE,
  );
}
