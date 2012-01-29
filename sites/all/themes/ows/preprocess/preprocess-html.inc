<?php
function ows_alpha_preprocess_html(&$vars) {
  //adding the google stylesheet for fonts
  debug('hi there');
  drupal_add_css('http://fonts.googleapis.com/css?family=Didact+Gothic');
}