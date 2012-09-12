<?php

/**
 * @file
 * Node translation handler for the translation module.
 */


/**
 * Node translation handler.
 *
 * Overrides default behaviours for Node properties.
 */
class EntityTranslationNodeHandler extends EntityTranslationDefaultHandler {

  public function __construct($entity_type, $entity_info, $entity, $entity_id) {
    parent::__construct('node', $entity_info, $entity, $entity_id);
  }

  public function isRevision() {
    return !empty($this->entity->revision);
  }

  public function getLanguage() {
    return $this->entity->language;
  }

  public function getAccess($op) {
    return node_access($op, $this->entity);
  }

  protected function getStatus() {
    return (boolean) $this->entity->status;
  }
}
