<?php

/**
 * @file
 * Add tokens pertaining to the Revisioning module.
 *
 * @ingroup token
 */

/**
 * Implements hook_token_info().
 */
function revisioning_token_info() {
  // First specify token type(s)
  $info['types']['revision'] = array(
    'name' => t("Revisions"),
    'description' => t('Tokens related to revisions of individual content items, or "node revisions".'),
    'needs-data' => 'node',
  );
  // Then specify the tokens
  $info['tokens']['revision']['author'] = array(
    'name' => t("Author"),
    'description' => t("The author (editor) of the revision"),
    'type' => 'user'
  );
  $info['tokens']['revision']['body'] = array(
    'name' => t("Body"),
    'description' => t("The main body text of the revision")
  );
  $info['tokens']['revision']['created'] = array(
    'name' => t("Timestamp"),
    'description' => t("The date and time the revision was created."),
    'type' => 'date'
  );
  $info['tokens']['revision']['title'] = array(
    'name' => t("Title"),
    'description' => t("The title of the revision")
  );
  $info['tokens']['revision']['vid'] = array(
    'name' => t("Revision ID"),
    'description' => t("The unique ID of the revision"),
  );
  return $info;
}

/**
 * Implements hook_tokens().
 */
function revisioning_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $replacements = array();

  if ($type == 'revision' && !empty($data['revision'])) {
    $revision = $data['revision'];

    foreach ($tokens as $name => $original) {
      switch ($name) {

        case 'title':
          $title = $revision->title;
          $replacements[$original] = empty($options['sanitize']) ? $title : check_plain($title);
          break;

        case 'body':
          $text = $revision->body[$revision->language][0]['value'];
          $replacements[$original] = empty($options['sanitize']) ? $text : $check_plan($text);
          break;

        case 'vid':
          $replacements[$original] = $revision->vid;
          break;
      }
    }
    // Chained token relationships for revision author and revision timestamp
    // These fan out into sub-token fields, e.g author:name, author:mail etc.
    if ($author_tokens = token_find_with_prefix($tokens, 'author')) {
      $author = user_load($revision->revision_uid);
      $replacements += token_generate('user', $author_tokens, array('user' => $author), $options);
    }
    if ($created_tokens = token_find_with_prefix($tokens, 'created')) {
      $replacements += token_generate('date', $created_tokens, array('date' => $revision->revision_timestamp), $options);
    }
  }
  return $replacements;
}
