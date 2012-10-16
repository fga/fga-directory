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
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "custom_formatters" && $api == "custom_formatters") {
    return array("version" => "2");
  }
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "openlayers" && $api == "openlayers_maps") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function occupations_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function occupations_image_default_styles() {
  $styles = array();

  // Exported image style: occupation_thumb_med.
  $styles['occupation_thumb_med'] = array(
    'name' => 'occupation_thumb_med',
    'effects' => array(
      2 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '92',
          'height' => '92',
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: occupation_thumb_sm.
  $styles['occupation_thumb_sm'] = array(
    'name' => 'occupation_thumb_sm',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '50',
          'height' => '50',
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function occupations_node_info() {
  $items = array(
    'occupation' => array(
      'name' => t('Occupation'),
      'base' => 'node_content',
      'description' => t('An occupation is a multi-field, geo-coded entity, with taxonomies and publishing workflows.'),
      'has_title' => '1',
      'title_label' => t('Name of Occupation'),
      'help' => t('<p><strong>Occupations</strong> in this context are defined as geographically based. Organizations that don\'t hold physical space, like <em>Occupy the Environment</em>, or organizations in solidarity to the movement, like <em>Occupy Air Force</em>, will be considered in their own right after the initial directory is up and running. We will also soon be adding listings for broader geographies, like state and country-wide "occupations."</p>



<p>Further down the line, we will be incorporating <em>groups</em> also. That\'s big. That\'s awesome. BUT –– that\'s the future (not the present; please don\'t submit your group yet)!</p>'),
    ),
  );
  return $items;
}

/**
 * Implements hook_rdf_default_mappings().
 */
function occupations_rdf_default_mappings() {
  $rdf_mappings = array();

  // Exported RDF mapping: twitter_hashtags
  $rdf_mappings['taxonomy_term']['twitter_hashtags'] = array(
    'rdftype' => array(
      0 => 'skos:Concept',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'rdfs:label',
        1 => 'skos:prefLabel',
      ),
    ),
    'description' => array(
      'predicates' => array(
        0 => 'skos:definition',
      ),
    ),
    'vid' => array(
      'predicates' => array(
        0 => 'skos:inScheme',
      ),
      'type' => 'rel',
    ),
    'parent' => array(
      'predicates' => array(
        0 => 'skos:broader',
      ),
      'type' => 'rel',
    ),
  );

  // Exported RDF mapping: occupation_type
  $rdf_mappings['taxonomy_term']['occupation_type'] = array(
    'rdftype' => array(
      0 => 'skos:Concept',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'rdfs:label',
        1 => 'skos:prefLabel',
      ),
    ),
    'description' => array(
      'predicates' => array(
        0 => 'skos:definition',
      ),
    ),
    'vid' => array(
      'predicates' => array(
        0 => 'skos:inScheme',
      ),
      'type' => 'rel',
    ),
    'parent' => array(
      'predicates' => array(
        0 => 'skos:broader',
      ),
      'type' => 'rel',
    ),
  );

  // Exported RDF mapping: occupation
  $rdf_mappings['node']['occupation'] = array(
    'rdftype' => array(
      0 => 'ows:Occupation',
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
        1 => 'foaf:phone',
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
        0 => 'ows:website',
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
        0 => 'ows:meetup_url',
      ),
    ),
    'field_occupation_live_video' => array(
      'type' => 'rel',
      'predicates' => array(
        0 => 'ows:live_video_stream',
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
    'field_occupation_twitter' => array(
      'type' => 'property',
      'predicates' => array(
        0 => 'ows:twitter_account',
      ),
    ),
  );

  return $rdf_mappings;
}
