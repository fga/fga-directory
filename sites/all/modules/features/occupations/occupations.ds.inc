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
  $ds_fieldsetting->id = 'node|occupation|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'occupation';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'share_this_node_block' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'address_city_state_country' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h1',
        'class' => 'page-title',
        'ft' => array(),
      ),
    ),
    'comments' => array(
      'weight' => '50',
      'label' => 'above',
      'format' => 'default',
    ),
    'field_occupation_dontate_info' => array(
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
    'twitter_user_link' => array(
      'weight' => '10',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
    'address_city_state_country' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'twitter_hashtags_link' => array(
      'weight' => '12',
      'label' => 'hidden',
      'format' => 'default',
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
    'links' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
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
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_occupation_facebook' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
    'field_occupation_twitter_hash' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
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
      'value' => '<address class="vcard">
  <span class="adr">
   <span class="locality">[node:field_occupation_address:city-name]</span> <abbr class="region">[node:field_occupation_address:state_province-name]</abbr> <span class=country-name">[node:field_occupation_address:country-code]</span>
  </span>
</address>',
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
  $ds_field->label = 'twitter hashtags linked';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'occupation|*';
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
  
   $hashtags[] = l( $hashtag, \'https://twitter.com/search?q=%23\' . $tag );
 }
}
return implode($hashtags, \', \');
?>  ',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['twitter_hashtags_link'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'twitter_user_link';
  $ds_field->label = 'twitter users linked';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'occupation|*';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php //dsm($entity); ?>
<?php
$tweeters = array();
/*
  @Review
  Thiago made this modification, kept existing code intact.
  Assumption being that DS code field is for displaying the frontend content, and that any need to get the \'raw stuff\' would be using field_get_items in a preprocess function.
*/
$ul_string = \'<ul class="tweeters">\';
foreach (field_get_items(\'node\', $entity, \'field_occupation_twitter\') as $tweeter) {
  if( !empty($tweeter[\'safe_value\']) ) {
    $val = l( $tweeter[\'safe_value\'] , \'https://twitter.com/\' . trim($tweeter[\'safe_value\']) );
    $tweeters[] = $val;
    $ul_string .= "<li>" . $val . "</li>";
  }
}
$ul_string .= "</ul>";
//return implode($tweeters, \',\');
return $ul_string;
?>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['twitter_user_link'] = $ds_field;

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
  $ds_layout->layout = 'occupation';
  $ds_layout->settings = array(
    'regions' => array(
      'right' => array(
        0 => 'title',
        2 => 'group_links_social',
        4 => 'share_this_node_block',
        5 => 'group_header',
        7 => 'group_links_resources',
        8 => 'group_meta',
        9 => 'group_links_media',
        10 => 'group_links_news',
        12 => 'group_occupation_description',
        13 => 'field_occupation_type',
        15 => 'field_occupation_origin_date',
        19 => 'group_listings',
        20 => 'field_occupation_meetup_url',
        22 => 'field_occupation_live_video',
        24 => 'field_occupation_newspaper_url',
        25 => 'field_occupation_other_websites',
        26 => 'field_occupation_youtube_chan',
        27 => 'field_occupation_facebook',
        28 => 'field_occupation_description',
        29 => 'field_occupation_twitter',
        30 => 'field_occupation_twitter_hash',
        31 => 'field_occupation_physical',
        33 => 'field_occupation_general_info',
        35 => 'field_occupation_social_sites',
        36 => 'field_occupation_rss',
        37 => 'comments',
      ),
      'left' => array(
        1 => 'address_city_state_country',
        3 => 'group_contact',
        6 => 'group_location',
        11 => 'group_donate_info',
        14 => 'field_occupation_dontate_info',
        16 => 'field_occupation_donate_url',
        17 => 'field_occupation_image',
        18 => 'field_occupation_website',
        21 => 'field_occupation_email_general',
        23 => 'field_occupation_phone_general',
        32 => 'field_occupation_address',
        34 => 'field_occupation_geo',
      ),
    ),
    'fields' => array(
      'title' => 'right',
      'address_city_state_country' => 'left',
      'group_links_social' => 'right',
      'group_contact' => 'left',
      'share_this_node_block' => 'right',
      'group_header' => 'right',
      'group_location' => 'left',
      'group_links_resources' => 'right',
      'group_meta' => 'right',
      'group_links_media' => 'right',
      'group_links_news' => 'right',
      'group_donate_info' => 'left',
      'group_occupation_description' => 'right',
      'field_occupation_type' => 'right',
      'field_occupation_dontate_info' => 'left',
      'field_occupation_origin_date' => 'right',
      'field_occupation_donate_url' => 'left',
      'field_occupation_image' => 'left',
      'field_occupation_website' => 'left',
      'group_listings' => 'right',
      'field_occupation_meetup_url' => 'right',
      'field_occupation_email_general' => 'left',
      'field_occupation_live_video' => 'right',
      'field_occupation_phone_general' => 'left',
      'field_occupation_newspaper_url' => 'right',
      'field_occupation_other_websites' => 'right',
      'field_occupation_youtube_chan' => 'right',
      'field_occupation_facebook' => 'right',
      'field_occupation_description' => 'right',
      'field_occupation_twitter' => 'right',
      'field_occupation_twitter_hash' => 'right',
      'field_occupation_physical' => 'right',
      'field_occupation_address' => 'left',
      'field_occupation_general_info' => 'right',
      'field_occupation_geo' => 'left',
      'field_occupation_social_sites' => 'right',
      'field_occupation_rss' => 'right',
      'comments' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
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
      'left' => array(
        0 => 'field_occupation_image',
        2 => 'field_occupation_description',
        3 => 'group_title_loc',
        5 => 'title',
        7 => 'address_city_state_country',
      ),
      'right' => array(
        1 => 'field_occupation_email_general',
        4 => 'field_occupation_website',
        6 => 'group_twitter_links',
        8 => 'field_occupation_facebook',
        9 => 'group_linklists',
        10 => 'field_occupation_origin_date',
        11 => 'links',
        12 => 'field_occupation_other_websites',
        13 => 'field_occupation_social_sites',
        14 => 'twitter_user_link',
        15 => 'field_occupation_twitter_hash',
        16 => 'twitter_hashtags_link',
      ),
    ),
    'fields' => array(
      'field_occupation_image' => 'left',
      'field_occupation_email_general' => 'right',
      'field_occupation_description' => 'left',
      'group_title_loc' => 'left',
      'field_occupation_website' => 'right',
      'title' => 'left',
      'group_twitter_links' => 'right',
      'address_city_state_country' => 'left',
      'field_occupation_facebook' => 'right',
      'group_linklists' => 'right',
      'field_occupation_origin_date' => 'right',
      'links' => 'right',
      'field_occupation_other_websites' => 'right',
      'field_occupation_social_sites' => 'right',
      'twitter_user_link' => 'right',
      'field_occupation_twitter_hash' => 'right',
      'twitter_hashtags_link' => 'right',
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
