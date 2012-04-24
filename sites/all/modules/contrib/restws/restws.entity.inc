<?php

/**
 * @file
 * RESTful web services module integration for entities.
 */

/**
 * Specifies CRUD and access methods for resources.
 */
interface RestWSResourceControllerInterface {

  /**
   * Returns the property info for the given resource.
   *
   * @return
   *   An array structured as hook_entity_property_info() is structured for an
   *   entity type.
   */
  public function propertyInfo();

  /**
   * Returns a metadata wrapper for the resource with the given id.
   *
   * @return EntityStructureWrapper
   */
  public function wrapper($id);

  /**
   * Create a new resource.
   *
   * @param array $values
   *   Array of values for properties of the resource, keyed by property
   *   name. At least for all required properties values have to be given.
   *
   * @return
   *   The id of the newly created resource.
   */
  public function create(array $values);

  /**
   * Returns an existing resource.
   *
   * @param $id
   *   The id of the resource that should be returned.
   *
   * @return
   *   The internal representation of the resource.
   */
  public function read($id);

  /**
   * Update an existing resource.
   *
   * @param $id
   *   The id of the resource that should be updated.
   * @param array $values
   *   An array of values for the properties to be updated, keyed by property
   *   name.
   */
  public function update($id, array $values);

  /**
   * Delete an existing resource.
   *
   * @param $id
   *   The id of the resource that should be deleted.
   */
  public function delete($id);

  /**
   * Determines access for a given operation and resource.
   *
   * @param $op
   *   Either 'create', 'view' (= read), 'update' or 'delete'.
   * @param $id
   *   The id of the resource.
   *
   * @see entity_access()
   */
  public function access($op, $id);

  /**
   * Returns the name of the resource.
   */
  public function resource();
}

/**
 * Controller for entity-bases resources.
 */
class RestWSEntityResourceController implements RestWSResourceControllerInterface {

  protected $entityType, $entityInfo;

  public function __construct($name, $info) {
    $this->entityType = $name;
    $this->entityInfo = entity_get_info($name);
  }

  public function propertyInfo() {
    return entity_get_property_info($this->entityType);
  }

  public function wrapper($id) {
    return entity_metadata_wrapper($this->entityType, $id);
  }

  public function read($id) {
    return $this->wrapper($id)->value();
  }

  public function create(array $values) {
    try {
      $wrapper = entity_property_values_create_entity($this->entityType, $values);
    }
    catch (EntityMetadataWrapperException $e) {
      throw new RestWSException($e->getMessage(), 406);
    }
    $properties = $wrapper->getPropertyInfo();
    $diff = array_diff_key($values, $properties);
    if (!empty($diff)) {
      throw new RestWSException('Unknown data properties: ' . implode(' ', array_keys($diff)) . '.', 406);
    }
    $wrapper->save();
    return $wrapper->getIdentifier();
  }

  public function update($id, array $values) {
    $wrapper = $this->wrapper($id);
    try {
      foreach ($values as $name => $value) {
        $wrapper->{$name}->set($value);
      }
    }
    catch (EntityMetadataWrapperException $e) {
      throw new RestWSException($e->getMessage(), 406);
    }
    $wrapper->save();
  }

  public function delete($id) {
    entity_delete($this->entityType, $id);
  }

  public function access($op, $id) {
    return entity_access($op, $this->entityType, isset($id) ? $this->wrapper($id)->value() : NULL);
  }

  public function resource() {
    return $this->entityType;
  }
}
