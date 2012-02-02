<?php
/**
 * @file
 * occupations.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function occupations_field_group_info() {
  $export = array();

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_occupate_rss_links|node|occupation|rss';
  $field_group->group_name = 'group_occupate_rss_links';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'occupation';
  $field_group->mode = 'rss';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'links',
    'weight' => '11',
    'children' => array(
      0 => 'field_occupation_website',
      1 => 'field_occupation_twitter',
      2 => 'field_occupation_social_sites',
      3 => 'field_occupation_live_video',
      4 => 'field_occupation_email_general',
      5 => 'field_occupation_emails_other',
      6 => 'field_occupation_other_websites',
      7 => 'field_occupation_rss',
      8 => 'field_occupation_donate_url',
      9 => 'field_occupation_newspaper_url',
      10 => 'field_occupation_meetup_url',
      11 => 'field_occupation_facebook',
      12 => 'field_occupation_youtube_chan',
      13 => 'field_occupation_twitter_hash',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_occupate_rss_links|node|occupation|rss'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_occupation_admin|node|occupation|form';
  $field_group->group_name = 'group_occupation_admin';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'occupation';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Administration',
    'weight' => '3',
    'children' => array(
      0 => 'field_occupation_notes_legacy',
      1 => 'field_occupation_notes',
      2 => 'field_occupation_needs_fixing',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_occupation_admin|node|occupation|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_occupation_contact_info|node|occupation|form';
  $field_group->group_name = 'group_occupation_contact_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'occupation';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_occupation_infogroup';
  $field_group->data = array(
    'label' => 'contact information',
    'weight' => '3',
    'children' => array(
      0 => 'field_occupation_address',
      1 => 'field_occupation_website',
      2 => 'field_occupation_email_general',
      3 => 'field_occupation_emails_other',
      4 => 'field_occupation_phone_general',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_occupation_contact_info|node|occupation|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_occupation_infogroup|node|occupation|form';
  $field_group->group_name = 'group_occupation_infogroup';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'occupation';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Container',
    'weight' => '2',
    'children' => array(
      0 => 'group_occupation_links',
      1 => 'group_occupation_contact_info',
      2 => 'group_occupation_information',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_occupation_infogroup|node|occupation|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_occupation_information|node|occupation|form';
  $field_group->group_name = 'group_occupation_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'occupation';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_occupation_infogroup';
  $field_group->data = array(
    'label' => 'Occupation Information',
    'weight' => '4',
    'children' => array(
      0 => 'field_occupation_origin_date',
      1 => 'field_occupation_description',
      2 => 'field_occupation_physical',
      3 => 'field_occupation_general_info',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_occupation_information|node|occupation|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_occupation_links|node|occupation|form';
  $field_group->group_name = 'group_occupation_links';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'occupation';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_occupation_infogroup';
  $field_group->data = array(
    'label' => 'Links',
    'weight' => '5',
    'children' => array(
      0 => 'field_occupation_twitter',
      1 => 'field_occupation_social_sites',
      2 => 'field_occupation_live_video',
      3 => 'field_occupation_other_websites',
      4 => 'field_occupation_rss',
      5 => 'field_occupation_donate_url',
      6 => 'field_occupation_newspaper_url',
      7 => 'field_occupation_meetup_url',
      8 => 'field_occupation_facebook',
      9 => 'field_occupation_youtube_chan',
      10 => 'field_occupation_twitter_hash',
      11 => 'field_occupation_dontate_info',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_occupation_links|node|occupation|form'] = $field_group;

  return $export;
}
