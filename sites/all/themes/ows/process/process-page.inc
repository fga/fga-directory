<?php

function ows_alpha_process_page(&$variables) {
  $path_to_subtheme = drupal_get_path('theme', 'ows');
  drupal_add_js($path_to_subtheme . '/js/directory.js');
}