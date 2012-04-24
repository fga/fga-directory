<?php

/**
 * @file
 * This file contains no working PHP code; it exists to provide additional
 * documentation for doxygen as well as to document hooks in the standard
 * Drupal manner.
 */


/**
 * @defgroup restws RestWS module integrations.
 *
 * Module integrations with the restws module.
 */

/**
 * @defgroup restws_hooks RestWS' hooks
 * @{
 * Hooks that can be implemented by other modules in order to extend restws.
 */

/**
 * Define restws compatible resources.
 *
 * This hook is required in order to add new restws resources.
 *
 * @return
 *   An array of information about the module's provided resources.
 *   The array contains a sub-array for each resource, with the resource name as
 *   the key. Resource names may only contain lowercase alpha-numeric characters
 *   and underscores and should be prefixed with the providing module name.
 *   Possible attributes for each sub-array are:
 *   - label: The label of the resource. Start capitalized.
 *   - class: The name of the controller class for the resource. The class has
 *     to implement the RestWSResourceControllerInterface. Required.
 *
 * @see MyModuleBookResourceController
 */
function hook_restws_resource_info() {
  return array(
    'mymodule_book' => array(
      'label' => t('Book'),
      'class' => 'MyModuleBookResourceController',
    ),
    'mymodule_status' => array(
      'label' => t('Status'),
      'class' => 'MyModuleStatusResourceController',
    ),
  );
}

/**
 * Alter available resource information.
 *
 * @param array $resource_info
 *   @see hook_restws_resource_info().
 */
function hook_restws_resource_info_alter(&$resource_info) {
  $resource_info['node']['class'] = 'MySpecialNodeResourceController';
}

/**
 * Define restws compatible formats.
 *
 * This hook is required in order to add new restws formats.
 *
 * @return
 *   An array of information about the module's provided formats.
 *   The array contains a sub-array for each format, with the format name as
 *   the key. Format names may only contain lowercase alpha-numeric characters
 *   and underscores.
 *   Possible attributes for each sub-array are:
 *   - label: The label of the format. Start capitalized.
 *   - class: The name of the class for the format. The class has to implement
 *     the RestWSFormatInterface. Required.
 *   - mime type: The official internet media type (MIME type) of the format.
 *     Required.
 */
function hook_restws_format_info() {
  return array(
    'json' => array(
      'label' => t('JSON'),
      'class' => 'RestWSFormatJSON',
      'mime type' => 'application/json',
    ),
    'xml' => array(
      'label' => t('XML'),
      'class' => 'RestWSFormatXML',
      'mime type' => 'application/xml',
    ),
  );
}

/**
 * Alter available format information.
 *
 * @param array $format_info
 *   @see hook_restws_format_info().
 */
function hook_restws_format_info_alter(&$format_info) {
  $format_info['json']['class'] = 'MyJsonFormatHandler';
}

/**
 * Alter the incoming request array.
 *
 * @param array $request
 *   A request array that contains the following items:
 *   - op: operation string, one of create, read, update or delete.
 *   - format: object implementing RestWSFormatInterface.
 *   - resource: object implementing RestWSResourceControllerInterface.
 *   - id: resource identifier or NULL for the create operation.
 *   - payload: array containing data attached to this request, if any.
 */
function hook_restws_request_alter(array &$request) {
  if ($request['resource']->resource() == 'node') {
    $request['format'] = restws_format('json');
  }
}

/**
 * @}
 */

/**
 * Example controller class for the mymodule_book resource.
 */
class MyModuleBookResourceController implements RestWSResourceControllerInterface {

  /**
   * @see hook_entity_property_info()
   * @see RestWSResourceControllerInterface::propertyInfo()
   */
  public function propertyInfo() {
    return array(
      'properties' => array(
        'title' => array(
          'type' => 'text',
          'label' => t('Book title'),
          'setter callback' => 'entity_property_verbatim_set',
        ),
        'author' => array(
          'type' => 'text',
          'label' => t('Author'),
          'setter callback' => 'entity_property_verbatim_set',
        ),
        'pages' => array(
          'type' => 'integer',
          'label' => t('Number of pages'),
          'setter callback' => 'entity_property_verbatim_set',
        ),
        'price' => array(
          'type' => 'decimal',
          'label' => t('Price'),
          'setter callback' => 'entity_property_verbatim_set',
        ),
      ),
    );
  }

  /**
   * @see RestWSResourceControllerInterface::wrapper()
   */
  public function wrapper($id) {
    $book = mymodule_book_load($id);
    $info = $this->propertyInfo();
    return entity_metadata_wrapper('mymodule_book', $book, array('property info' => $info['properties']));
  }

  /**
   * @see RestWSResourceControllerInterface::create()
   */
  public function create(array $values) {
    try {
      $book = mymodule_book_save($values);
      return $book->id;
    }
    catch (Exception $e) {
      throw new RestWSException('Creation error', 406);
    }
  }

  /**
   * @see RestWSResourceControllerInterface::read()
   */
  public function read($id) {
    return mymodule_book_load($id);
  }

  /**
   * @see RestWSResourceControllerInterface::update()
   */
  public function update($id, array $values) {
    throw new RestWSException('Not implemented', 501);
  }

  /**
   * @see RestWSResourceControllerInterface::delete()
   */
  public function delete($id) {
    try {
      mymodule_book_delete($id);
    }
    catch (Exception $e) {
      throw new RestWSException('Book not found', 404);
    }
  }

  /**
   * @see RestWSResourceControllerInterface::access()
   */
  public function access($op, $id) {
    return mymodule_book_access($op, $id);
  }

  /**
   * @see RestWSResourceControllerInterface::resource()
   */
  public function resource() {
    return 'mymodule_book';
  }
}
