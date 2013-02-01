<?php

/**
 * @file
 * Display Suite occupation configuration.
 */

function ds_occupation() {
  return array(
    'label' => t('occupation'),
    'regions' => array(
      'left' => t('left'),
      // 'content' => t('content'),
      'right' => t('right'),
    ),
    // Uncomment if you want to include a CSS file for this layout (occupation.css)
    'css' => FALSE,
    // Uncomment if this is a template for a node form.
    // 'form' => TRUE,
   'image' => TRUE,
  );
}
