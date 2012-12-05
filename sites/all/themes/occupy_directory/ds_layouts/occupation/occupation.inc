<?php

/**
 * @file
 * Display Suite occupation configuration.
 */

function ds_occupation() {
  return array(
    'label' => t('occupation'),
    'regions' => array(
      'header' => t('header'),
      'left' => t('left'),
      'right' => t('right'),
      'footer' => t('footer'),
    ),
    // Uncomment if you want to include a CSS file for this layout (occupation.css)
    'css' => TRUE,
    // Uncomment if this is a template for a node form.
    // 'form' => TRUE,
   'image' => TRUE,
  );
}
