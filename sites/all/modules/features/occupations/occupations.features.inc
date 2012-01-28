<?php
/**
 * @file
 * occupations.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function occupations_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function occupations_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implements hook_node_info().
 */
function occupations_node_info() {
  $items = array(
    'occupation' => array(
      'name' => t('Occupation'),
      'base' => 'node_content',
      'description' => t('Occupation. This content type is very much a work in progress. The current fields are 100% proof of concept.'),
      'has_title' => '1',
      'title_label' => t('Name of Occupation'),
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implements hook_rdf_default_mappings().
 */
function occupations_rdf_default_mappings() {
  $rdf_mappings = array();

  // Exported RDF mapping: occupation
  $rdf_mappings['node']['occupation'] = array(
    'rdftype' => array(
      0 => 'foaf:Group',
      1 => 'schema:Organization',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'foaf:name',
        1 => 'schema:name',
      ),
      'type' => 'property',
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'field_occupation_origin_date' => array(
      'type' => 'property',
      'predicates' => array(
        0 => 'schema:foundingDate',
      ),
      'datatype' => 'xsd:date',
      'callback' => 'date_iso8601',
    ),
    'field_occupation_description' => array(
      'type' => 'property',
      'predicates' => array(
        0 => 'schema:description',
      ),
    ),
    'field_occupation_phone_general' => array(
      'type' => 'property',
      'predicates' => array(
        0 => 'schema:telephone',
      ),
    ),
    'field_occupation_image' => array(
      'type' => 'rel',
      'predicates' => array(
        0 => 'schema:image',
        1 => 'foaf:img',
      ),
    ),
    'field_occupation_website' => array(
      'type' => 'property',
      'predicates' => array(
        0 => 'schema:url',
      ),
    ),
    'field_occupation_physical' => array(
      'type' => 'property',
      'predicates' => array(
        0 => 'schema:phy',
      ),
    ),
    'field_occupation_social_sites' => array(
      'type' => 'property',
      'predicates' => array(
        0 => 'rdfs:seeAlso',
      ),
    ),
    'field_occupation_email_general' => array(
      'type' => 'property',
      'predicates' => array(
        0 => 'foaf:mbox',
      ),
    ),
    'field_occupation_other_websites' => array(
      'type' => 'property',
      'predicates' => array(
        0 => 'rdfs:seeAlso',
      ),
    ),
    'field_occupation_rss' => array(
      'type' => 'property',
      'predicates' => array(
        0 => 'rdfs:seeAlso',
      ),
    ),
    'field_occupation_donate_url' => array(
      'type' => 'property',
      'predicates' => array(
        0 => 'rdfs:seeAlso',
      ),
    ),
    'field_occupation_newspaper_url' => array(
      'type' => 'property',
      'predicates' => array(
        0 => 'rdfs:seeAlso',
      ),
    ),
    'field_occupation_meetup_url' => array(
      'type' => 'property',
      'predicates' => array(
        0 => 'rdfs:seeAlso',
      ),
    ),
    'field_occupation_facebook' => array(
      'type' => 'property',
      'predicates' => array(
        0 => 'rdfs:seeAlso',
      ),
    ),
    'field_occupation_youtube_chan' => array(
      'type' => 'property',
      'predicates' => array(
        0 => 'rdfs:seeAlso',
      ),
    ),
    'field_occupation_twitter_hash' => array(
      'type' => 'property',
      'predicates' => array(
        0 => 'rdfs:seeAlso',
      ),
    ),
  );

  return $rdf_mappings;
}
