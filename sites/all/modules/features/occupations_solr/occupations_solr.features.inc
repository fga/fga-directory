<?php
/**
 * @file
 * occupations_solr.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function occupations_solr_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_search_api_index().
 */
function occupations_solr_default_search_api_index() {
  $items = array();
  $items['occupations_index'] = entity_import('search_api_index', '{
    "name" : "occupations index",
    "machine_name" : "occupations_index",
    "description" : null,
    "server" : "localhost_server",
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "title" : { "type" : "text", "boost" : "21.0" },
        "field_tags" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_occupation_origin_date" : { "type" : "date" },
        "field_occupation_twitter" : { "type" : "list\\u003Ctext\\u003E", "boost" : "5.0" },
        "field_occupation_email_general" : { "type" : "text", "boost" : "0.8" },
        "field_occupation_emails_other" : { "type" : "list\\u003Ctext\\u003E", "boost" : "0.2" },
        "field_occupation_twitter_hash" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_occupation_type" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_term_geographic_area" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "search_api_language" : { "type" : "string" },
        "field_occupation_address:country" : { "type" : "string" },
        "field_occupation_address:name_line" : { "type" : "text" },
        "field_occupation_address:administrative_area" : { "type" : "text", "boost" : "3.0" },
        "field_occupation_address:sub_administrative_area" : { "type" : "text", "boost" : "2.0" },
        "field_occupation_address:locality" : { "type" : "text", "boost" : "8.0" },
        "field_occupation_address:dependent_locality" : { "type" : "text" },
        "field_occupation_address:postal_code" : { "type" : "text" },
        "field_occupation_address:thoroughfare" : { "type" : "text", "boost" : "2.0" },
        "field_occupation_description:value" : { "type" : "text", "boost" : "3.0" },
        "field_occupation_general_info:value" : { "type" : "text", "boost" : "2.0" },
        "field_occupation_twitter_hash:name" : { "type" : "list\\u003Ctext\\u003E", "boost" : "8.0" },
        "status" : { "type" : "boolean" },
        "author" : { "type" : "integer", "entity_type" : "user" },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : { "default" : "0", "bundles" : { "occupation" : "occupation" } }
        },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : true,
              "field_occupation_twitter" : true,
              "field_occupation_email_general" : true,
              "field_occupation_emails_other" : true,
              "field_occupation_address:name_line" : true,
              "field_occupation_address:administrative_area" : true,
              "field_occupation_address:sub_administrative_area" : true,
              "field_occupation_address:locality" : true,
              "field_occupation_address:dependent_locality" : true,
              "field_occupation_address:postal_code" : true,
              "field_occupation_address:thoroughfare" : true,
              "field_occupation_description:value" : true,
              "field_occupation_general_info:value" : true,
              "field_occupation_twitter_hash:name" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_occupation_twitter" : true,
              "field_occupation_email_general" : true,
              "field_occupation_emails_other" : true,
              "field_occupation_address:name_line" : true,
              "field_occupation_address:administrative_area" : true,
              "field_occupation_address:sub_administrative_area" : true,
              "field_occupation_address:locality" : true,
              "field_occupation_address:dependent_locality" : true,
              "field_occupation_address:postal_code" : true,
              "field_occupation_address:thoroughfare" : true,
              "field_occupation_description:value" : true,
              "field_occupation_general_info:value" : true,
              "field_occupation_twitter_hash:name" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_occupation_twitter" : true,
              "field_occupation_email_general" : true,
              "field_occupation_emails_other" : true,
              "field_occupation_address:name_line" : true,
              "field_occupation_address:administrative_area" : true,
              "field_occupation_address:sub_administrative_area" : true,
              "field_occupation_address:locality" : true,
              "field_occupation_address:dependent_locality" : true,
              "field_occupation_address:postal_code" : true,
              "field_occupation_address:thoroughfare" : true,
              "field_occupation_description:value" : true,
              "field_occupation_general_info:value" : true,
              "field_occupation_twitter_hash:name" : true
            },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_occupation_twitter" : true,
              "field_occupation_email_general" : true,
              "field_occupation_emails_other" : true,
              "field_occupation_address:name_line" : true,
              "field_occupation_address:administrative_area" : true,
              "field_occupation_address:sub_administrative_area" : true,
              "field_occupation_address:locality" : true,
              "field_occupation_address:dependent_locality" : true,
              "field_occupation_address:postal_code" : true,
              "field_occupation_address:thoroughfare" : true,
              "field_occupation_description:value" : true,
              "field_occupation_general_info:value" : true,
              "field_occupation_twitter_hash:name" : true
            },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function occupations_solr_default_search_api_server() {
  $items = array();
  $items['localhost_server'] = entity_import('search_api_server', '{
    "name" : "pantheon solr server",
    "machine_name" : "localhost_server",
    "description" : "Pantheon\\u0027s solr instance uses the non-standard port at 8983",
    "class" : "search_api_solr_service",
    "options" : {
      "host" : "localhost",
      "port" : "8983",
      "path" : "\\/solr",
      "http_user" : "ows",
      "http_pass" : "",
      "excerpt" : 0,
      "retrieve_data" : 0,
      "highlight_data" : 0
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  $items['localhost_solr_server'] = entity_import('search_api_server', '{
    "name" : "localhost solr server",
    "machine_name" : "localhost_solr_server",
    "description" : "local development on kalabox requires a different port (for now)",
    "class" : "search_api_solr_service",
    "options" : {
      "host" : "localhost",
      "port" : "8080",
      "path" : "\\/solr",
      "http_user" : "",
      "http_pass" : "",
      "excerpt" : 0,
      "retrieve_data" : 0,
      "highlight_data" : 0
    },
    "enabled" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}
