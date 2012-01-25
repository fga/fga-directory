<?php
/**
 * @file
 * Views Implementation for UUID
 */

/**
 * Implementation of hook_views_data_alter().
 */
function uuid_views_data_alter(&$data) {
  $info = entity_get_info();
  foreach ($info as $entity_info) {
    $table = $entity_info['base table'];
    $schema = drupal_get_schema($table);
    $data[$table]['uuid'] = array(
      'title' => t('@type UUID', array('@type' => $entity_info['label'])),
      'help' => t(
        'Universally Unique Identifier for @type objects.',
        array('@type' => $entity_info['label'])
      ),
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
        'allow empty' => TRUE,
        'help' => 'Filter on a UUID',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_string',
        'help' => 'Argument on a UUID',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
        'help' => 'Sort on UUID',
      ),
    );
  }
}
