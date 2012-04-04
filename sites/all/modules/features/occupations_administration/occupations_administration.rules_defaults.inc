<?php
/**
 * @file
 * occupations_administration.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function occupations_administration_default_rules_configuration() {
  $items = array();
  $items['rules_comment_notification'] = entity_import('rules_config', '{ "rules_comment_notification" : {
      "LABEL" : "Comment notification",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "notifications" ],
      "REQUIRES" : [ "rules", "comment" ],
      "ON" : [ "comment_insert" ],
      "DO" : [
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "5" : "5" } },
            "subject" : "A comment has been added to [comment:node:title] on [site:name]",
            "message" : "A comment has been added to [site:name] ([site:url]): \\u000D\\u000A\\u000D\\u000ANode:\\u000D\\u000A[comment:node:title] ([comment:node:url])\\u000D\\u000A\\u000D\\u000AAuthor:\\u000D\\u000A[comment:name]\\u000D\\u000A\\u000D\\u000ABody:\\u000D\\u000A[comment:body]\\u000D\\u000A\\u000D\\u000AClick here to moderate the comment: [comment:edit-url]"
          }
        }
      ]
    }
  }');
  $items['rules_new_occupation_notification'] = entity_import('rules_config', '{ "rules_new_occupation_notification" : {
      "LABEL" : "New occupation notification",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "notifications" ],
      "REQUIRES" : [ "rules" ],
      "ON" : [ "node_insert" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "occupation" : "occupation" } }
          }
        },
        { "user_has_role" : { "account" : [ "node:author" ], "roles" : { "value" : { "2" : "2" } } } }
      ],
      "DO" : [
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "5" : "5" } },
            "subject" : "[node:title] has been added to [site:name] for approval",
            "message" : "An occupation has been added to [site:name] ([site:url]) for approval:\\u000D\\u000A\\u000D\\u000ANode:\\u000D\\u000A[node:title]\\u000D\\u000A\\u000D\\u000AAuthor:\\u000D\\u000A[node:author:name]\\u000D\\u000A\\u000D\\u000ALocation:\\u000D\\u000A[node:field_occupation_address]\\u000D\\u000A\\u000D\\u000ADescription:\\u000D\\u000A[node:field_occupation_description]\\u000D\\u000A\\u000D\\u000AClick here to view the occupation: [node:url]"
          }
        },
        { "drupal_message" : { "message" : "Thank you for submitting an occupation. You will be notified when it is added to the site, after approval by one of our moderators." } }
      ]
    }
  }');
  $items['rules_occupation_approved_notification'] = entity_import('rules_config', '{ "rules_occupation_approved_notification" : {
      "LABEL" : "Occupation approved notification",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "notifications" ],
      "REQUIRES" : [ "rules" ],
      "ON" : [ "node_update" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "occupation" : "occupation" } }
          }
        },
        { "node_is_published" : { "node" : [ "node" ] } },
        { "NOT node_is_published" : { "node" : [ "node-unchanged" ] } },
        { "user_has_role" : { "account" : [ "node:author" ], "roles" : { "value" : { "2" : "2" } } } }
      ],
      "DO" : [
        { "mail" : {
            "to" : "[node:author:mail]",
            "subject" : "[node:title] is now live on [site:name]!",
            "message" : "[node:author:name],\\u000D\\u000A\\u000D\\u000A[node:title], the occupation you submitted to [site:name], has been approved and is now live!\\u000D\\u000A\\u000D\\u000AYou can view and edit your occupation by clicking here: [node:url]\\u000D\\u000A\\u000D\\u000A- The Occupy Directory team"
          }
        }
      ]
    }
  }');
  $items['rules_redirect_occupation_curators_at_login'] = entity_import('rules_config', '{ "rules_redirect_occupation_curators_at_login" : {
      "LABEL" : "Redirect Occupation Curators at login",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "Redirect Occupation Curators at login" ],
      "REQUIRES" : [ "rules" ],
      "ON" : [ "user_login" ],
      "IF" : [
        { "user_has_role" : { "account" : [ "account" ], "roles" : { "value" : { "5" : "5" } } } }
      ],
      "DO" : [
        { "redirect" : {
            "url" : "occupations\\u002Fmanage\\u002F[account:field-term-geographic-area]",
            "force" : 0
          }
        }
      ]
    }
  }');
  return $items;
}
