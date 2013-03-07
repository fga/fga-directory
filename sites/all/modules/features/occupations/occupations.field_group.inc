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

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_additional_links|node|occupation|search';
  $field_group->group_name = 'group_additional_links';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'occupation';
  $field_group->mode = 'search';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Additional Links',
    'weight' => '45',
    'children' => array(),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_additional_links|node|occupation|search'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_av_links|node|occupation|full';
  $field_group->group_name = 'group_av_links';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'occupation';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_links_media';
  $field_group->data = array(
    'label' => 'Link Listing',
    'weight' => '13',
    'children' => array(
      0 => 'field_occupation_live_video',
      1 => 'field_occupation_youtube_chan',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Link Listing',
      'instance_settings' => array(
        'classes' => 'link-listing',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_av_links|node|occupation|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_comments|node|occupation|full';
  $field_group->group_name = 'group_comments';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'occupation';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Comments',
    'weight' => '8',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Comments',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_comments|node|occupation|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact|node|occupation|full';
  $field_group->group_name = 'group_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'occupation';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact Info',
    'weight' => '1',
    'children' => array(
      0 => 'field_occupation_website',
      1 => 'field_occupation_email_general',
      2 => 'field_occupation_phone_general',
      3 => 'group_location',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Contact Info',
      'instance_settings' => array(
        'classes' => 'hcard',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_contact|node|occupation|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content_main|node|occupation|full';
  $field_group->group_name = 'group_content_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'occupation';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main Content',
    'weight' => '28',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Main Content',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_content_main|node|occupation|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_donate_info|node|occupation|full';
  $field_group->group_name = 'group_donate_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'occupation';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Donation Info',
    'weight' => '2',
    'children' => array(
      0 => 'field_occupation_dontate_info',
      1 => 'field_occupation_donate_url',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Donation Info',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_donate_info|node|occupation|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_header|node|occupation|full';
  $field_group->group_name = 'group_header';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'occupation';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Header',
    'weight' => '4',
    'children' => array(
      0 => 'title',
      1 => 'group_meta',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Header',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_header|node|occupation|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_header|node|occupation|occupation_search_result';
  $field_group->group_name = 'group_header';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'occupation';
  $field_group->mode = 'occupation_search_result';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Header',
    'weight' => '0',
    'children' => array(
      0 => 'share_this_node_block',
      1 => 'title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_header|node|occupation|occupation_search_result'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_info_misc|node|occupation|full';
  $field_group->group_name = 'group_info_misc';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'occupation';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Misc Info',
    'weight' => '3',
    'children' => array(
      0 => 'field_occupation_origin_date',
      1 => 'submitted_by',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Misc Info',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_info_misc|node|occupation|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_linklists|node|occupation|search';
  $field_group->group_name = 'group_linklists';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'occupation';
  $field_group->mode = 'search';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Links',
    'weight' => '3',
    'children' => array(
      0 => 'field_occupation_website',
      1 => 'field_occupation_email_general',
      2 => 'field_occupation_facebook',
      3 => 'twitter_users_hashtags_linked',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Links',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_linklists|node|occupation|search'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_links_media|node|occupation|full';
  $field_group->group_name = 'group_links_media';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'occupation';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_listings';
  $field_group->data = array(
    'label' => 'Video & Audio',
    'weight' => '19',
    'children' => array(
      0 => 'group_av_links',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Video & Audio',
      'instance_settings' => array(
        'classes' => 'link-group',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_links_media|node|occupation|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_links_news|node|occupation|full';
  $field_group->group_name = 'group_links_news';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'occupation';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_listings';
  $field_group->data = array(
    'label' => 'News & Info',
    'weight' => '20',
    'children' => array(
      0 => 'group_news_and_info_linkgroup',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'News & Info',
      'instance_settings' => array(
        'classes' => 'link-group',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_links_news|node|occupation|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_links_resources|node|occupation|full';
  $field_group->group_name = 'group_links_resources';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'occupation';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Other Resources',
    'weight' => '29',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Other Resources',
      'instance_settings' => array(
        'classes' => 'grouplinks',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_links_resources|node|occupation|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_links_social|node|occupation|full';
  $field_group->group_name = 'group_links_social';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'occupation';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Social Media',
    'weight' => '17',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Social Media',
      'instance_settings' => array(
        'classes' => 'grouplinks',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_links_social|node|occupation|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_listings|node|occupation|full';
  $field_group->group_name = 'group_listings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'occupation';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Group Links',
    'weight' => '7',
    'children' => array(
      0 => 'field_occupation_social_sites',
      1 => 'field_occupation_rss',
      2 => 'field_occupation_facebook',
      3 => 'twitter_hashtags_link',
      4 => 'twitter_user_link',
      5 => 'group_links_media',
      6 => 'group_links_news',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Group Links',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_listings|node|occupation|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_location|node|occupation|full';
  $field_group->group_name = 'group_location';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'occupation';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_contact';
  $field_group->data = array(
    'label' => 'Location',
    'weight' => '20',
    'children' => array(
      0 => 'field_occupation_address',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Location',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_location|node|occupation|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_meta|node|occupation|full';
  $field_group->group_name = 'group_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'occupation';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_header';
  $field_group->data = array(
    'label' => 'Meta',
    'weight' => '10',
    'children' => array(
      0 => 'field_occupation_type',
      1 => 'address_city_state_country',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Meta',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_meta|node|occupation|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_news_and_info_linkgroup|node|occupation|full';
  $field_group->group_name = 'group_news_and_info_linkgroup';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'occupation';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_links_news';
  $field_group->data = array(
    'label' => 'Link Listing',
    'weight' => '40',
    'children' => array(
      0 => 'field_occupation_other_websites',
      1 => 'field_occupation_newspaper_url',
      2 => 'field_occupation_meetup_url',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Link Listing',
      'instance_settings' => array(
        'classes' => 'link-listing',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_news_and_info_linkgroup|node|occupation|full'] = $field_group;

  $field_group = new stdClass();
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

  $field_group = new stdClass();
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
    'weight' => '5',
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

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_occupation_comment_counts|node|occupation|form';
  $field_group->group_name = 'group_occupation_comment_counts';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'occupation';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Comment Counts',
    'weight' => '6',
    'children' => array(
      0 => 'field_comments_done',
      1 => 'field_comments_new',
      2 => 'field_comments_rejected',
      3 => 'field_comments_willdo',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_occupation_comment_counts|node|occupation|form'] = $field_group;

  $field_group = new stdClass();
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

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_occupation_description|node|occupation|full';
  $field_group->group_name = 'group_occupation_description';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'occupation';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Occupation Description',
    'weight' => '6',
    'children' => array(
      0 => 'field_occupation_description',
      1 => 'field_occupation_physical',
      2 => 'field_occupation_general_info',
      3 => 'mapbox_static_map_full',
      4 => 'comments',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Occupation Description',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_occupation_description|node|occupation|full'] = $field_group;

  $field_group = new stdClass();
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
    'weight' => '4',
    'children' => array(
      0 => 'group_occupation_contact_info',
      1 => 'group_occupation_information',
      2 => 'group_occupation_links',
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

  $field_group = new stdClass();
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
      4 => 'field_occupation_dontate_info',
      5 => 'field_occupation_donate_url',
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

  $field_group = new stdClass();
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
      5 => 'field_occupation_newspaper_url',
      6 => 'field_occupation_meetup_url',
      7 => 'field_occupation_facebook',
      8 => 'field_occupation_youtube_chan',
      9 => 'field_occupation_twitter_hash',
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

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_occupation_links|node|occupation|occupation_search_result';
  $field_group->group_name = 'group_occupation_links';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'occupation';
  $field_group->mode = 'occupation_search_result';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'links',
    'weight' => '6',
    'children' => array(
      0 => 'field_occupation_website',
      1 => 'field_occupation_twitter',
      2 => 'field_occupation_email_general',
      3 => 'field_occupation_facebook',
      4 => 'field_occupation_twitter_hash',
      5 => 'twitter_user_link',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'links',
      'instance_settings' => array(
        'classes' => 'links',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_occupation_links|node|occupation|occupation_search_result'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_occupation_teaser|node|occupation|occupation_search_result';
  $field_group->group_name = 'group_occupation_teaser';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'occupation';
  $field_group->mode = 'occupation_search_result';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Teaser',
    'weight' => '0',
    'children' => array(
      0 => 'field_occupation_description',
      1 => 'field_occupation_image',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Teaser',
      'instance_settings' => array(
        'classes' => 'teaser',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_occupation_teaser|node|occupation|occupation_search_result'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_title_loc|node|occupation|search';
  $field_group->group_name = 'group_title_loc';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'occupation';
  $field_group->mode = 'search';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Title, location',
    'weight' => '1',
    'children' => array(
      0 => 'address_city_state_country',
      1 => 'title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Title, location',
      'instance_settings' => array(
        'classes' => 'clearfix',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_title_loc|node|occupation|search'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_twitter_links_wraper|node|occupation|search';
  $field_group->group_name = 'group_twitter_links_wraper';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'occupation';
  $field_group->mode = 'search';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'twitter-links-wrapper',
    'weight' => '48',
    'children' => array(
      0 => 'twitter_hashtags_link',
      1 => 'twitter_user_link',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'twitter-links-wrapper',
      'instance_settings' => array(
        'classes' => 'item-wrapper',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_twitter_links_wraper|node|occupation|search'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_twitter_links_wrapper|node|occupation|form';
  $field_group->group_name = 'group_twitter_links_wrapper';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'occupation';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Twitter Links Wrapper',
    'weight' => '43',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Twitter Links Wrapper',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_twitter_links_wrapper|node|occupation|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_twitter_links|node|occupation|search';
  $field_group->group_name = 'group_twitter_links';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'occupation';
  $field_group->mode = 'search';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Twitter Links',
    'weight' => '3',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Twitter Links',
      'instance_settings' => array(
        'classes' => 'flyoutmenu icon twitter',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_twitter_links|node|occupation|search'] = $field_group;

  return $export;
}
