<?php
/**
 * @file
 * occupations_import_export.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function occupations_import_export_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'default_feeds_tamper';
  $strongarm->value = array(
    'occupation_csv-facebook_pages-explode' => FALSE,
    'occupation_csv-other_websites___-explode' => FALSE,
    'occupation_csv-rss_feed_s____-explode' => FALSE,
    'occupation_csv-facebook_page_s____-explode' => FALSE,
    'occupation_csv-livestream_url_s____-explode' => FALSE,
    'occupation_csv-twitter_user__account_s____-explode' => FALSE,
    'occupation_csv-twitter__hash__tags___-explode' => FALSE,
    'occupation_csv-youtube_channel_url_s____-explode' => FALSE,
    'occupation_csv-country-convert_case' => FALSE,
    'occupation_csv-state-convert_case' => FALSE,
    'occupation_csv-state-convert_case_province' => FALSE,
    'occupation_csv-country-convert_country_to_iso_code' => FALSE,
    'occupation_csv-additional_emails___-explode' => FALSE,
  );
  $export['default_feeds_tamper'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'feeds_reschedule';
  $strongarm->value = FALSE;
  $export['feeds_reschedule'] = $strongarm;

  return $export;
}
