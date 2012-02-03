<?php
/**
 * @file
 * occupations_import_export.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function occupations_import_export_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'occupation_csv';
  $feeds_importer->config = array(
    'name' => 'Occupation CSV',
    'description' => 'CSV files listing occupations',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'occupation',
        'expire' => '-1',
        'author' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'Occupation Name',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'Facebook pages',
            'target' => 'field_occupation_facebook:url',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Primary website',
            'target' => 'field_occupation_website:url',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'other websites []',
            'target' => 'field_occupation_other_websites:url',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Country',
            'target' => 'field_occupation_address:country',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'State/Prov/Terr',
            'target' => 'field_occupation_address:administrative_area',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'City',
            'target' => 'field_occupation_address:locality',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'ZIP/postal code',
            'target' => 'field_occupation_address:postal_code',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'intersection closest to your physical center',
            'target' => 'field_occupation_address:thoroughfare',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'RSS feed(s) []',
            'target' => 'field_occupation_rss:url',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'meetup URL',
            'target' => 'field_occupation_meetup_url:url',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'facebook page(s) []',
            'target' => 'field_occupation_facebook:url',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'livestream URL(s) []',
            'target' => 'field_occupation_live_video:url',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'twitter user @account(s) []',
            'target' => 'field_occupation_twitter',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'youtube channel URL(s) []',
            'target' => 'field_occupation_youtube_chan:url',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'Occupation founded date',
            'target' => 'field_occupation_origin_date:start',
            'unique' => FALSE,
          ),
          16 => array(
            'source' => 'general email',
            'target' => 'field_occupation_email_general',
            'unique' => FALSE,
          ),
          17 => array(
            'source' => 'general phone #',
            'target' => 'field_occupation_phone_general',
            'unique' => FALSE,
          ),
          18 => array(
            'source' => 'legacy notes',
            'target' => 'field_occupation_notes_legacy',
            'unique' => FALSE,
          ),
          19 => array(
            'source' => 'notes',
            'target' => 'field_occupation_notes',
            'unique' => FALSE,
          ),
          20 => array(
            'source' => 'needs fixing',
            'target' => 'field_occupation_needs_fixing',
            'unique' => FALSE,
          ),
          21 => array(
            'source' => 'newspaper URL',
            'target' => 'field_occupation_newspaper_url:url',
            'unique' => FALSE,
          ),
          22 => array(
            'source' => 'twitter #hash #tags []',
            'target' => 'field_occupation_twitter_hash',
            'unique' => FALSE,
          ),
          23 => array(
            'source' => 'location name',
            'target' => 'field_occupation_address:name_line',
            'unique' => FALSE,
          ),
          24 => array(
            'source' => 'additional emails []',
            'target' => 'field_occupation_emails_other',
            'unique' => FALSE,
          ),
          25 => array(
            'source' => 'donate info',
            'target' => 'field_occupation_dontate_info',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['occupation_csv'] = $feeds_importer;

  return $export;
}
