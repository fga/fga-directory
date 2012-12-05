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
  $ds_fieldsetting->id = 'node|occupation|occupation_search_result';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'occupation';
  $ds_fieldsetting->view_mode = 'occupation_search_result';
  $ds_fieldsetting->settings = array(
    'ds_switch_field' => array(
      'weight' => '8',
      'label' => 'inline',
      'format' => 'default',
      'formatter_settings' => array(
        'vms' => array(
          'full' => 'expand',
          'teaser' => '',
          'rss' => '',
          'occupation_search_result' => '',
          'search' => '',
        ),
        'ft' => array(),
      ),
    ),
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
  $ds_field->field = 'twitter_user_link';
  $ds_field->label = 'twitter user link';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'occupation|*';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<a href="https://twitter.com/[node:field-occupation-twitter]">[node:field-occupation-twitter]</a>',
      'format' => 'ds_code',
    ),
    'use_token' => 1,
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
        10 => 'ds_switch_field',
        11 => 'field_occupation_website',
        12 => 'field_occupation_email_general',
        13 => 'field_occupation_twitter',
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
      'ds_switch_field' => 'ds_content',
      'field_occupation_website' => 'ds_content',
      'field_occupation_email_general' => 'ds_content',
      'field_occupation_twitter' => 'ds_content',
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
  $ds_view_mode->label = 'search';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['occupation_search_result'] = $ds_view_mode;

  return $export;
}
