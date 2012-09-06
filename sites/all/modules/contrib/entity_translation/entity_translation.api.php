<?php

/**
 * @file
 * API documentation for Entity Translation module.
 */

/**
 * Allow modules to define their own translation info.
 *
 * @return
 *   An array of entity translation info to be merged into the entity info.
 *   The translation info is an associative array that has to match the
 *   following sample structure:
 *   @code
 *   array(
 *     // Three nested sub-arrays keyed respectively by entity type and the
 *     // 'translation' keys: the first one is the key defined by the core
 *     // entity system, while the nested one registers Translation as a
 *     // translation handler.
 *     'custom_entity' => array(
 *       'translation' => array(
 *         'translation' => array(
 *           'class' => the entity class name,
 *           'base path' => the base menu path to which attach the administration UI,
 *           'access callback' => the access callback for the admin pages,
 *           'access arguments' => the access arguments,
 *           // The edit form information, used to add the retranslate checkbox
 *           // to the entity edit form (if empty the edit form will not be
 *           // altered by Translation).
 *           'edit form' => TRUE,
 *         ),
 *       ),
 *     ),
 *   );
 */
function hook_translation_info($types = NULL) {
  $info['custom_entity'] = array(
    'translation' => array(
      'entity_translation' => array(
        'class' => 'EntityTranslationCustomEntityHandler',
        'base path' => 'custom_entity/%custom_entity',
        'access callback' => 'custom_entity_tab_access',
        'access arguments' => array(1),
        'edit form' => TRUE,
      ),
    ),
  );

  return $info;
}

/**
 * Allow modules to react on translation events.
 *
 * @param string $entity_type
 *   The type of entity; e.g. 'node' or 'user'.
 * @param object $entity
 *   The entity to be translated.
 * @param string $langcode
 *   The language code of the translation.
 */
function hook_entity_translation_save($entity_type, $entity, $langcode) {
  $function = 'pathauto_' . $entity_type . '_update_alias';
  if (function_exists($function)) {
    $options = array('language' => $langcode);
    $function($entity, 'update', $options);
  }
}
