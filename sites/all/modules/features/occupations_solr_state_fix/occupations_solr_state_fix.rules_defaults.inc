<?php
/**
 * @file
 * occupations_solr_state_fix.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function occupations_solr_state_fix_default_rules_configuration() {
  $items = array();
  $items['rules_batch_update_state_names'] = entity_import('rules_config', '{ "rules_batch_update_state_names" : {
      "LABEL" : "Batch Update State Names",
      "PLUGIN" : "rule",
      "TAGS" : [ "occupations_solr_state_fix" ],
      "REQUIRES" : [ "rules", "php" ],
      "ACCESS_EXPOSED" : "1",
      "USES VARIABLES" : { "occupation_node" : { "label" : "Occupation", "type" : "node" } },
      "IF" : [
        { "entity_is_of_type" : { "entity" : [ "occupation-node" ], "type" : "node" } },
        { "entity_has_field" : { "entity" : [ "occupation-node" ], "field" : "field_state_name" } },
        { "node_is_of_type" : {
            "node" : [ "occupation-node" ],
            "type" : { "value" : { "occupation" : "occupation" } }
          }
        }
      ],
      "DO" : [
        { "variable_add" : {
            "USING" : {
              "type" : "text",
              "value" : "\\u003C?php\\r\\n  module_load_include(\\u0027inc\\u0027, \\u0027node\\u0027, \\u0027node.pages\\u0027);\\r\\n\\r\\n  $form = node_form($form, \\u0026$form_state, $occupation_node);\\r\\n  $abbrev = $occupation_node-\\u003Efield_occupation_address[\\u0027und\\u0027][0][\\u0027administrative_area\\u0027];\\r\\n\\r\\n  echo $form[\\u0027field_occupation_address\\u0027][\\u0027und\\u0027][0][\\u0027locality_block\\u0027][\\u0027administrative_area\\u0027][\\u0027#options\\u0027][$abbrev];\\r\\n?\\u003E"
            },
            "PROVIDE" : { "variable_added" : { "state_name" : "State Name" } }
          }
        },
        { "data_set" : {
            "data" : [ "occupation-node:field-state-name" ],
            "value" : [ "state-name" ]
          }
        }
      ]
    }
  }');
  return $items;
}
