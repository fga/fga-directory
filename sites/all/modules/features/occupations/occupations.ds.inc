<?php
/**
 * @file
 * occupations.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function occupations_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'comment|comment_node_occupation|default';
  $ds_fieldsetting->entity_type = 'comment';
  $ds_fieldsetting->bundle = 'comment_node_occupation';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'post_date' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'ds_post_date_long',
    ),
  );
  $export['comment|comment_node_occupation|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|occupation|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'occupation';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'address_city_state_country' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'mapbox_static_map_full' => array(
      'weight' => '10',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'share_this_node_block' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'twitter_hashtags_link' => array(
      'weight' => '0',
      'label' => 'above',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
          'classes' => 'link-group',
          'lb' => 'Twitter Hashtags',
        ),
      ),
    ),
    'twitter_user_link' => array(
      'weight' => '0',
      'label' => 'above',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
          'classes' => 'link-group',
          'lb' => 'Twitter Users',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'links' => array(
      'weight' => '15',
      'label' => 'above',
      'format' => 'default',
    ),
    'comments' => array(
      'weight' => '-10',
      'label' => 'above',
      'format' => 'default',
    ),
    'submitted_by' => array(
      'weight' => '50',
      'label' => 'hidden',
      'format' => 'ds_time_ago',
    ),
    'field_occupation_social_sites' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Additional Social Media Sites',
          'lb-el' => 'h3',
          'lb-def-at' => TRUE,
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'link-group',
          'ow-def-cl' => TRUE,
          'ow-at' => '',
          'ow-def-at' => TRUE,
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => 'link-listing',
          'fis-at' => '',
          'fis-def-at' => TRUE,
        ),
      ),
    ),
    'field_occupation_live_video' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
    'field_occupation_other_websites' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
    'field_occupation_rss' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'RSS Feeds',
          'lb-el' => 'h3',
          'lb-def-at' => TRUE,
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'link-group',
          'ow-def-cl' => TRUE,
          'ow-at' => '',
          'ow-def-at' => TRUE,
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => 'link-listing',
          'fis-at' => '',
          'fis-def-at' => TRUE,
        ),
      ),
    ),
    'field_occupation_newspaper_url' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
    'field_occupation_meetup_url' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
    'field_occupation_facebook' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Facebook Page(s)',
          'lb-el' => 'h3',
          'lb-def-at' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'link-group',
          'ow-def-cl' => TRUE,
          'ow-at' => '',
          'ow-def-at' => TRUE,
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => 'link-listing',
          'fis-at' => '',
          'fis-def-at' => TRUE,
        ),
      ),
    ),
    'field_occupation_youtube_chan' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
  );
  $export['node|occupation|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|occupation|occupation_search_result';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'occupation';
  $ds_fieldsetting->view_mode = 'occupation_search_result';
  $ds_fieldsetting->settings = array(
    'address_city_state_country' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'span',
          'ow-cl' => 'city',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'address_latitude' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'span',
          'ow-cl' => 'latitude',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'longitude' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
        ),
      ),
    ),
    'twitter_user_link' => array(
      'weight' => '15',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h3',
        'class' => 'fn org title',
        'ft' => array(),
      ),
    ),
    'field_occupation_description' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'p',
          'ow-cl' => 'description',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_occupation_image' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'span',
          'fi-cl' => 'image',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
  );
  $export['node|occupation|occupation_search_result'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|occupation|search';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'occupation';
  $ds_fieldsetting->view_mode = 'search';
  $ds_fieldsetting->settings = array(
    'address_city_state_country' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'twitter_users_hashtags_linked' => array(
      'weight' => '20',
      'label' => 'above',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Twitter Users and Hashes ',
          'lb-el' => 'h3',
          'lb-def-at' => TRUE,
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'flyoutmenu icon twitter',
          'ow-def-cl' => TRUE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'item-wrapper',
          'fi-at' => '',
          'fi-def-at' => TRUE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'title' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h3',
        'class' => 'fn org title',
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'submitted_by' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'ds_time_ago',
    ),
    'field_occupation_origin_date' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
          'lb' => 'Founded',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_occupation_image' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
        ),
      ),
    ),
    'field_occupation_website' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'icon site',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_occupation_email_general' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'icon email',
          'fi-at' => '',
          'fi-def-at' => TRUE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_occupation_facebook' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'h3',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'flyoutmenu icon facebook',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => 'item-wrapper',
          'fis-at' => '',
          'fis-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['node|occupation|search'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'taxonomy_term|twitter_hashtags|default';
  $ds_fieldsetting->entity_type = 'taxonomy_term';
  $ds_fieldsetting->bundle = 'twitter_hashtags';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'twitter_hashes_taxonomyterms' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
  );
  $export['taxonomy_term|twitter_hashtags|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function occupations_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'address_city_state_country';
  $ds_field->label = 'City State Country';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'occupation|*';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<div class="adr">
   <span class="locality">[node:field_occupation_address:city-name]</span>
   <abbr class="region">[node:field_occupation_address:state_province-name]</abbr>
   <span class=country-name">[node:field_occupation_address:country-code]</span>
</div>
',
      'format' => 'ds_code',
    ),
    'use_token' => 1,
  );
  $export['address_city_state_country'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'address_latitude';
  $ds_field->label = 'Latitude';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '[node:field-occupation-geo:lat]',
      'format' => 'ds_code',
    ),
    'use_token' => 1,
  );
  $export['address_latitude'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'city';
  $ds_field->label = 'City';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'occupation|*';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<span class="locality">[node:field_occupation_address:city-name]</span>',
      'format' => 'ds_code',
    ),
    'use_token' => 1,
  );
  $export['city'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'country';
  $ds_field->label = 'Country';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'occupation|*';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<span class="country-name">[node:field_occupation_address:country-code]</span>',
      'format' => 'ds_code',
    ),
    'use_token' => 1,
  );
  $export['country'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'longitude';
  $ds_field->label = 'Longitude';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'occupation|*';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<span class="longitude">[node:field-occupation-geo:lon]</span>',
      'format' => 'ds_code',
    ),
    'use_token' => 1,
  );
  $export['longitude'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'mapbox_static_map_full';
  $ds_field->label = 'mapbox static map full';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'occupation|full';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<img alt="map marking the location of [node:title] " src="http://api.tiles.mapbox.com/v3/occupydirectory.map-1tyybpog/url-bit.ly%2FMvRTGQ([node:field-occupation-geo:lon],[node:field-occupation-geo:lat])/[node:field-occupation-geo:lon],[node:field-occupation-geo:lat],12/640x252.jpg70" />
',
      'format' => 'ds_code',
    ),
    'use_token' => 1,
  );
  $export['mapbox_static_map_full'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'share_this_node_block';
  $ds_field->label = 'Share this Node Block';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'occupation|*';
  $ds_field->properties = array(
    'block' => 'owstech_share|owstech-share',
    'block_render' => '1',
  );
  $export['share_this_node_block'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'state';
  $ds_field->label = 'State/Province';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<abbr class="region">[node:field_occupation_address:state_province-name]</abbr>&nbsp;',
      'format' => 'ds_code',
    ),
    'use_token' => 1,
  );
  $export['state'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'twitter_hashes_taxonomyterms';
  $ds_field->label = 'Twitter Hashes';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
    'taxonomy_term' => 'taxonomy_term',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<a class=\'twitterhash_js_hook\' href="https://twitter.com/search/[term:name]" target="_blank">[term:name]</a>
',
      'format' => 'php_code',
    ),
    'use_token' => 1,
  );
  $export['twitter_hashes_taxonomyterms'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'twitter_hashtags_link';
  $ds_field->label = 'Twitter Hashtags Linked';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'occupation|*';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php

$hashtag_tids = field_get_items(\'node\', $entity, \'field_occupation_twitter_hash\');
$ul_string = "";
if( count( $hashtag_tids ) ){
  $ul_string = \'<ul class="twitter_hashes">\';
  foreach ($hashtag_tids as $term) {
   if( !empty($term[\'tid\']) ) {
     
    $term = taxonomy_term_load($term[\'tid\']);
    $hashtag = trim($term->name);
    
    if (strpos($hashtag, \'#\') === 0) {
      $tag = trim($hashtag, \'#\');
    }
    
     $ul_string .= "<li>" . l( $hashtag, \'https://twitter.com/search?q=%23\' . $tag ) . "</li>";
   }
  }
  $ul_string .= "</ul>";
}
return $ul_string;
?>  ',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['twitter_hashtags_link'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'twitter_user_link';
  $ds_field->label = 'Twitter Users Linked';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'occupation|*';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php
$fieldItems = field_get_items(\'node\', $entity, \'field_occupation_twitter\');
$ul_string = "";
if( count( $fieldItems ) ){
$ul_string = \'<ul class="tweeters">\';
  foreach ( $fieldItems as $tweeter) {
    if( !empty($tweeter[\'safe_value\']) ) {
      $val = l( $tweeter[\'safe_value\'] , \'https://twitter.com/\' . trim($tweeter[\'safe_value\']) );
      $ul_string .= "<li>" . $val . "</li>";
    }
  }
  $ul_string .= "</ul>";
}
return $ul_string;
?>
',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['twitter_user_link'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'twitter_users_hashtags_linked';
  $ds_field->label = 'Twitter users + hashtags linked';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'occupation|search';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php //dsm($entity); ?>

<?php
$hashtag_tids = field_get_items(\'node\', $entity, \'field_occupation_twitter_hash\');

foreach ($hashtag_tids as $term) {
 if( !empty($term[\'tid\']) ) {

  $term = taxonomy_term_load($term[\'tid\']);
  $hashtag = trim($term->name);

  if (strpos($hashtag, \'#\') === 0) {
    $tag = trim($hashtag, \'#\');
  }
if( $hashtag ){
   $hashtags[] = \'<li>\' . l( $hashtag, \'https://twitter.com/search?q=%23\' . $tag ) . \'</li>\';
}
 }
}

$tweeters = array();
foreach (field_get_items(\'node\', $entity, \'field_occupation_twitter\') as $tweeter) {
  if( !empty($tweeter[\'safe_value\']) ) {
    $tweeters[]  = \'<li>\' . l( $tweeter[\'safe_value\'] , \'https://twitter.com/\' . trim($tweeter[\'safe_value\']) ) . \'</li>\';
  }
}

return \'<ul>\' .  implode($hashtags, \'\') . implode($tweeters, \'\') . \'</ul>\';

?>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['twitter_users_hashtags_linked'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function occupations_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|occupation|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'occupation';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_3col_stacked_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'middle' => array(
        0 => 'comments',
        1 => 'twitter_user_link',
        2 => 'address_city_state_country',
        3 => 'twitter_hashtags_link',
        4 => 'title',
        7 => 'group_header',
        9 => 'group_occupation_description',
        10 => 'field_occupation_type',
        12 => 'group_listings',
        14 => 'group_meta',
        15 => 'mapbox_static_map_full',
        19 => 'field_occupation_live_video',
        20 => 'field_occupation_youtube_chan',
        21 => 'group_av_links',
        23 => 'field_occupation_description',
        24 => 'field_occupation_physical',
        25 => 'field_occupation_facebook',
        27 => 'field_occupation_general_info',
        28 => 'field_occupation_social_sites',
        29 => 'group_links_media',
        30 => 'group_links_news',
        32 => 'field_occupation_rss',
        34 => 'group_news_and_info_linkgroup',
        36 => 'field_occupation_newspaper_url',
        37 => 'field_occupation_other_websites',
        38 => 'field_occupation_meetup_url',
      ),
      'left' => array(
        5 => 'field_occupation_image',
        8 => 'group_contact',
        11 => 'field_occupation_dontate_info',
        13 => 'field_occupation_donate_url',
        16 => 'field_occupation_website',
        17 => 'field_occupation_email_general',
        18 => 'field_occupation_phone_general',
        26 => 'field_occupation_address',
        31 => 'group_location',
        33 => 'group_donate_info',
        35 => 'field_occupation_origin_date',
        39 => 'submitted_by',
      ),
      'right' => array(
        6 => 'share_this_node_block',
        22 => 'links',
      ),
    ),
    'fields' => array(
      'comments' => 'middle',
      'twitter_user_link' => 'middle',
      'address_city_state_country' => 'middle',
      'twitter_hashtags_link' => 'middle',
      'title' => 'middle',
      'field_occupation_image' => 'left',
      'share_this_node_block' => 'right',
      'group_header' => 'middle',
      'group_contact' => 'left',
      'group_occupation_description' => 'middle',
      'field_occupation_type' => 'middle',
      'field_occupation_dontate_info' => 'left',
      'group_listings' => 'middle',
      'field_occupation_donate_url' => 'left',
      'group_meta' => 'middle',
      'mapbox_static_map_full' => 'middle',
      'field_occupation_website' => 'left',
      'field_occupation_email_general' => 'left',
      'field_occupation_phone_general' => 'left',
      'field_occupation_live_video' => 'middle',
      'field_occupation_youtube_chan' => 'middle',
      'group_av_links' => 'middle',
      'links' => 'right',
      'field_occupation_description' => 'middle',
      'field_occupation_physical' => 'middle',
      'field_occupation_facebook' => 'middle',
      'field_occupation_address' => 'left',
      'field_occupation_general_info' => 'middle',
      'field_occupation_social_sites' => 'middle',
      'group_links_media' => 'middle',
      'group_links_news' => 'middle',
      'group_location' => 'left',
      'field_occupation_rss' => 'middle',
      'group_donate_info' => 'left',
      'group_news_and_info_linkgroup' => 'middle',
      'field_occupation_origin_date' => 'left',
      'field_occupation_newspaper_url' => 'middle',
      'field_occupation_other_websites' => 'middle',
      'field_occupation_meetup_url' => 'middle',
      'submitted_by' => 'left',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'section',
      'middle' => 'div',
      'right' => 'section',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'article',
    'layout_attributes' => '',
    'layout_attributes_merge' => 0,
    'hide_page_title' => '1',
    'page_option_title' => '',
  );
  $export['node|occupation|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|occupation|occupation_search_result';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'occupation';
  $ds_layout->view_mode = 'occupation_search_result';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_occupation_teaser',
        1 => 'field_occupation_image',
        2 => 'title',
        3 => 'field_occupation_description',
        4 => 'field_occupation_type',
        5 => 'address_city_state_country',
        6 => 'address_latitude',
        7 => 'longitude',
        8 => 'group_occupation_links',
        9 => 'field_occupation_origin_date',
        10 => 'field_occupation_website',
        11 => 'field_occupation_email_general',
        12 => 'field_occupation_twitter',
        13 => 'twitter_user_link',
        14 => 'field_occupation_twitter_hash',
        15 => 'field_occupation_facebook',
      ),
    ),
    'fields' => array(
      'group_occupation_teaser' => 'ds_content',
      'field_occupation_image' => 'ds_content',
      'title' => 'ds_content',
      'field_occupation_description' => 'ds_content',
      'field_occupation_type' => 'ds_content',
      'address_city_state_country' => 'ds_content',
      'address_latitude' => 'ds_content',
      'longitude' => 'ds_content',
      'group_occupation_links' => 'ds_content',
      'field_occupation_origin_date' => 'ds_content',
      'field_occupation_website' => 'ds_content',
      'field_occupation_email_general' => 'ds_content',
      'field_occupation_twitter' => 'ds_content',
      'twitter_user_link' => 'ds_content',
      'field_occupation_twitter_hash' => 'ds_content',
      'field_occupation_facebook' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 0,
  );
  $export['node|occupation|occupation_search_result'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|occupation|search';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'occupation';
  $ds_layout->view_mode = 'search';
  $ds_layout->layout = 'search_result';
  $ds_layout->settings = array(
    'regions' => array(
      'right' => array(
        0 => 'field_occupation_email_general',
        6 => 'group_linklists',
        7 => 'submitted_by',
        8 => 'field_occupation_website',
        9 => 'field_occupation_origin_date',
        10 => 'twitter_users_hashtags_linked',
        11 => 'field_occupation_facebook',
      ),
      'left' => array(
        1 => 'field_occupation_image',
        2 => 'field_occupation_description',
        3 => 'group_title_loc',
        4 => 'title',
        5 => 'address_city_state_country',
      ),
    ),
    'fields' => array(
      'field_occupation_email_general' => 'right',
      'field_occupation_image' => 'left',
      'field_occupation_description' => 'left',
      'group_title_loc' => 'left',
      'title' => 'left',
      'address_city_state_country' => 'left',
      'group_linklists' => 'right',
      'submitted_by' => 'right',
      'field_occupation_website' => 'right',
      'field_occupation_origin_date' => 'right',
      'twitter_users_hashtags_linked' => 'right',
      'field_occupation_facebook' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
      'left' => array(
        'flyoutmenu' => 'flyoutmenu',
      ),
    ),
    'wrappers' => array(
      'left' => 'section',
      'right' => 'section',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 0,
  );
  $export['node|occupation|search'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'taxonomy_term|twitter_hashtags|default';
  $ds_layout->entity_type = 'taxonomy_term';
  $ds_layout->bundle = 'twitter_hashtags';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'twitter_hashes_taxonomyterms',
      ),
    ),
    'fields' => array(
      'twitter_hashes_taxonomyterms' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 0,
  );
  $export['taxonomy_term|twitter_hashtags|default'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function occupations_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'occupation_search_result';
  $ds_view_mode->label = 'Search Row';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['occupation_search_result'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'search';
  $ds_view_mode->label = 'Search Result';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['search'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'twitter_hashes';
  $ds_view_mode->label = 'Twitter hash link';
  $ds_view_mode->entities = array(
    'node' => 'node',
    'taxonomy_term' => 'taxonomy_term',
  );
  $export['twitter_hashes'] = $ds_view_mode;

  return $export;
}
