<?php
function ows_alpha_preprocess_node(&$vars) {
  
  if ($vars['node']->type == 'occupation') {
    $vars['content_attributes_array']['class'][] = 'grid-6';
  }
  
}