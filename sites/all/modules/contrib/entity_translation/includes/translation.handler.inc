<?php

/**
 * @file
 * Default translation handler for the translation module.
 */


/**
 * Interface for enabling entity translation.
 *
 * Defines a set of methods to allow any entity to be processed by the entity
 * translation UI.
 */
interface EntityTranslationHandlerInterface {

  /**
   * Load the translation data into the wrapped entity.
   */
  public function loadTranslations();

  /**
   * Write the translation status to the storage.
   */
  public function saveTranslations();

  /**
   * Return the translation data for the current (wrapped) entity.
   */
  public function getTranslations();

  /**
   * Add/edit an entity translation.
   *
   * @param $translation
   *   A translation array as defined by the translation table's schema.
   * @param $values
   *   Optional. the values that should be assigned to the field translations.
   */
  public function setTranslation($translation, $values = NULL);

  /**
   * Remove a translation from the translation set.
   *
   * @param $langcode
   *   The language code of the translation to be removed.
   */
  public function removeTranslation($langcode);

  /**
   * Initialize the translation set by creating the original translation.
   */
  public function initTranslations();

  /**
   * Update the translation set from the current entity status.
   */
  public function updateTranslations();

  /**
   * Remove all translations from the translation set.
   */
  public function removeTranslations();

  /**
   * Initialize the language of the original field values.
   *
   * Ensure that the original translation language matches the language assigned
   * to the original field values.
   *
   * @return
   *   TRUE if any initialization was necessary, FALSE otherwise.
   */
  public function initOriginalTranslation();

  /**
   * Return the entity language.
   */
  public function getLanguage();

  /**
   * Set the language of the orginal translation.
   *
   * @param $langcode
   *   The language code of the original content values.
   */
  public function setOriginalLanguage($langcode);

  /**
   * Return TRUE if the entity is currently being translated.
   */
  public function isTranslating();

  /**
   * Notify the translation handler that its wrapped entity is being translated.
   *
   * @param $translating
   *   A boolean value.
   */
  public function setTranslating($translating);

  /**
   * Return TRUE if a new revision of the entity has just been created.
   */
  public function isRevision();

  /**
   * Replace the wrapped entity.
   *
   * @param $entity
   *   The entity to be translated.
   */
  public function setEntity($entity);

  /**
   * Set the translation update status.
   *
   * @param $outdated
   *   A boolean value.
   */
  public function setOutdated($outdated);

  /**
   * Return the base path for the current entity.
   *
   * This path will be prepended to the URL of any administration page.
   *
   * @return
   *   A string to be used as a URL path prefix.
   */
  public function getBasePath();

  /**
   * Return the path of the entity edit form.
   */
  public function getEditPath();

  /**
   * Return the path of the entity view page.
   */
  public function getViewPath();

  /**
   * A string allowing the user to identify the entity.
   */
  public function getLabel();

  /**
   * Check if the user can perform the given operation on the wrapped entity.
   *
   * @param $op
   *   The operation to be performed.
   *
   * @return
   *   TRUE if the user is allowed to perform the given operation, FALSE
   *   otherwise.
   */
  public function getAccess($op);

  /**
   * Return TRUE if the entity supports URL aliasing.
   */
  public function isAliasEnabled();
}

/**
 * Class implementing the default entity translation behaviours.
 */
class EntityTranslationDefaultHandler implements EntityTranslationHandlerInterface {

  protected $entityType;
  protected $entity;
  protected $entityInfo;
  protected $entityId;

  private $translating;
  private $outdated;

  private $basePath;
  private $editPath;
  private $viewPath;

  public function __construct($entity_type, $entity_info, $entity, $entity_id) {
    $this->entityType = $entity_type;
    $this->entityInfo = $entity_info;
    $this->entity = $entity;
    $this->entityId = $entity_id;

    $this->translating = FALSE;
    $this->outdated = FALSE;

    $info = $entity_info['translation']['entity_translation'];
    $this->basePath = $this->getPathInstance($info['base path']);
    $this->editPath = isset($info['edit path']) ? $this->getPathInstance($info['edit path']) : FALSE;
    $this->viewPath = isset($info['view path']) ? $this->getPathInstance($info['view path']) : FALSE;
  }

  /**
   * Read the translation data from the storage.
   */
  public static function loadMultiple($entity_type, $entities) {
    $entity_info = entity_get_info($entity_type);
    $translations_key = $entity_info['entity keys']['translations'];

    foreach ($entities as $id => $entity) {
      $entities[$id]->{$translations_key} = EntityTranslationDefaultHandler::emptyTranslations();
    }

    $results = db_select('entity_translation', 'et')
      ->fields('et')
      ->condition('entity_type', $entity_type)
      ->condition('entity_id', array_keys($entities), 'IN')
      ->orderBy('entity_id')
      ->orderBy('created')
      ->execute();

    foreach ($results as $row) {
      $id = $row->entity_id;
      $entities[$id]->{$translations_key}->data[$row->language] = (array) $row;

      // Only the original translation has an empty source.
      if (empty($row->source)) {
        $entities[$id]->{$translations_key}->original = $row->language;
      }
    }
  }

  public function loadTranslations() {
    if (isset($this->entityId)) {
      $this->loadMultiple($this->entityType, array($this->entityId => $this->entity));
    }
    else {
      $this->entity->{$this->getTranslationsKey()} = $this->emptyTranslations();
    }
  }

  public function saveTranslations() {
    // Delete and insert, rather than update, in case a value was added.
    db_delete('entity_translation')
      ->condition('entity_type', $this->entityType)
      ->condition('entity_id', $this->entityId)
      ->execute();

    $translations = $this->getTranslations();

    if (count($translations->data)) {
      global $user;

      $columns = array('entity_type', 'entity_id', 'language', 'source', 'uid', 'status', 'translate', 'created', 'changed');
      $query = db_insert('entity_translation')->fields($columns);

      // These values should overridde the translation ones as they are not
      // supposed to change.
      $overrides = array(
        'entity_id' => $this->entityId,
        'entity_type' => $this->entityType,
      );

      // These instead are just defaults.
      $defaults = array(
        'source' => '',
        'uid' => $user->uid,
        'translate' => 0,
        'status' => 0,
        'created' => REQUEST_TIME,
        'changed' => REQUEST_TIME,
      );

      foreach ($translations->data as $langcode => $translation) {
        $translation = $overrides + $translation + $defaults;
        if ($this->outdated && $langcode != $translations->original) {
          $translation['translate'] = 1;
        }
        $query->values($translation);
      }

      $query->execute();
    }
  }

  public function getTranslations() {
    $translations_key = $this->getTranslationsKey();

    // Lazy load translations if for some reason the wrapped entity did not go
    // through hook_entity_load().
    if (!isset($this->entity->{$translations_key})) {
      $this->loadTranslations();
    }

    return $this->entity->{$translations_key};
  }

  public function setTranslation($translation, $values = NULL) {
    if (isset($translation['source']) && $translation['language'] == $translation['source']) {
      throw new Exception('Invalid translation language');
    }

    $translations = $this->getTranslations();
    $langcode = $translation['language'];

    $this->setTranslating(TRUE);

    if (isset($translations->data[$langcode])) {
      $translation = array_merge($translations->data[$langcode], $translation);
      $translation['changed'] = REQUEST_TIME;
    }

    $translations->data[$langcode] = $translation;

    if (is_array($values)) {
      // Update field translations.
      list(, , $bundle) = entity_extract_ids($this->entityType, $this->entity);
      foreach (field_info_instances($this->entityType, $bundle) as $instance) {
        $field_name = $instance['field_name'];
        $field = field_info_field($field_name);
        if ($field['translatable'] && isset($values[$field_name])) {
          $this->entity->{$field_name}[$langcode] = $values[$field_name][$langcode];
        }
      }
    }
  }

  public function removeTranslation($langcode) {
    $translations_key = $this->getTranslationsKey();

    if (!empty($langcode)) {
      unset($this->entity->{$translations_key}->data[$langcode]);
    }
    else {
      $this->entity->{$translations_key}->data = array();
    }

    list(, , $bundle) = entity_extract_ids($this->entityType, $this->entity);

    // Remove field translations.
    foreach (field_info_instances($this->entityType, $bundle) as $instance) {
      $field_name = $instance['field_name'];
      $field = field_info_field($field_name);

      if ($field['translatable']) {
        if (!empty($langcode)) {
          $this->entity->{$field_name}[$langcode] = array();
        }
        else {
          $this->entity->{$field_name} = array();
        }
      }
    }
  }

  public function initTranslations() {
    $langcode = $this->getLanguage();

    if (!empty($langcode)) {
      $translation = array('language' => $langcode, 'status' => (int) $this->getStatus());
      $this->setTranslation($translation);
      $this->setOriginalLanguage($langcode);
    }
  }

  public function updateTranslations() {
    $langcode = $this->getLanguage();

    // Only create a translation on edit if the translation set is empty:
    // the entity might have been created with language set to "language
    // neutral".
    if (empty($this->getTranslations()->data)) {
      $this->initTranslations();
    }
    elseif (!empty($langcode) && !$this->isTranslating()) {
      $this->setOriginalLanguage($langcode);
    }
  }

  public function removeTranslations() {
    $this->removeTranslation(NULL);
  }

  public function initOriginalTranslation() {
    $fixed = FALSE;
    $translations = $this->getTranslations();
    list(, , $bundle) = entity_extract_ids($this->entityType, $this->entity);

    foreach (field_info_instances($this->entityType, $bundle) as $instance) {
      $field_name = $instance['field_name'];
      $field = field_info_field($field_name);
      $langcode = count($this->entity->{$field_name}) == 1 ? key($this->entity->{$field_name}) : $translations->original;

      if ($langcode == LANGUAGE_NONE && $field['translatable']) {
        $this->entity->{$field_name}[$translations->original] = $this->entity->{$field_name}[$langcode];
        $this->entity->{$field_name}[$langcode] = array();
        $fixed = TRUE;
      }
    }

    return $fixed;
  }

  public function getLanguage() {
    return language_default()->language;
  }

  public function setLanguage($langcode) {
    $this->language = $langcode;
  }

  public function setOriginalLanguage($langcode) {
    $translations = $this->getTranslations();

    if (isset($translations->original) && $translations->original != $langcode) {
      $translations->data[$langcode] = $translations->data[$translations->original];
      $translations->data[$langcode]['language'] = $langcode;
      unset($translations->data[$translations->original]);
    }

    $translations->original = $langcode;
  }

  public function isTranslating() {
    return $this->translating;
  }

  public function setTranslating($translating) {
    $this->translating = $translating;
  }

  public function isRevision() {
    return FALSE;
  }

  public function setEntity($entity) {
    $this->entity = $entity;
  }

  public function setOutdated($outdated) {
    $this->outdated = $outdated;
  }

  public function getBasePath() {
    return $this->basePath;
  }

  public function getEditPath() {
    return $this->editPath;
  }

  public function getViewPath() {
    return $this->viewPath;
  }

  public function getLabel() {
    if (($label = entity_label($this->entityType, $this->entity)) !== FALSE) {
      return $label;
    }
    else {
      return "{$this->entityType}:{$this->getEntityId()}" ;
    }
  }

  public function getAccess($op) {
    return TRUE;
  }

  public function isAliasEnabled() {
    return !empty($this->entityInfo['translation']['entity_translation']['alias']);
  }

  /**
   * Return the translation object key for the wrapped entity type.
   */
  protected function getTranslationsKey() {
    return $this->entityInfo['entity keys']['translations'];
  }

  /**
   * Return the entity accessibility.
   */
  protected function getStatus() {
    return TRUE;
  }

  /**
   * Return the entity identifier.
   */
  protected function getEntityId() {
    return $this->entityId;
  }

  /**
   * Return an instance of the given path.
   *
   * @param $path
   *   An internal path containing the entity id wildcard.
   *
   * @return
   *   The instantiated path.
   */
  protected function getPathInstance($path) {
    $wildcard = $this->entityInfo['translation']['entity_translation']['path wildcard'];
    return str_replace($wildcard, $this->getEntityId(), $path);
  }

  /**
   * Return an empty translations data structure.
   */
  protected static function emptyTranslations() {
    return (object) array('original' => NULL, 'data' => array());
  }
}
