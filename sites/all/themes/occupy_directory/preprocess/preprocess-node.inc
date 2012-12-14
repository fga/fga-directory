<?php
// function occupy_directory_alpha_preprocess_node(&$vars) {  
//   dpm( debug_backtrace() );
// 	if ($vars['node']->type == 'occupation') {
// 		$vars['content_attributes_array']['class'][] = 'grid-6';
// 		//$vars['field_occupation_origin_date'] = render($view['field_occupation_origin_date']);
// 	}
// }

function occupy_directory_alpha_proprocess_page(&$vars) {
  watchdog('hi', 'hihihi' );
  dpm( $vars );
  dpm( debug_backtrace() );
}