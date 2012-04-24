<?php

/**
 * @file
 * RESTful web services module formats.
 */

/**
 * Interface implemented by formatter implementations for the http client.
 */
interface RestWSFormatInterface {

  /**
   * Gets the representation of a resource.
   *
   * @param RestWSResourceControllerInterface $resourceController
   *   The controller used to retrieve the resource.
   * @param $id
   *   The id of the resource that should be returned.
   *
   * @return
   *   The representation of the resource.
   */
  public function viewResource($resourceController, $id);

  /**
   * Create a resource.
   *
   * @param RestWSResourceControllerInterface $resourceController
   *   The controller used to create the resource.
   * @param $data
   *   The representation of the resource.
   *
   * @return
   *   The id of the newly created resource.
   */
  public function createResource($resourceController, $data);

  /**
   * Update a resource.
   *
   * @param RestWSResourceControllerInterface $resourceController
   *   The controller used to update the resource.
   * @param $id
   *   The id of the resource that should be updated.
   * @param $data
   *   The representation of the resource.
   */
  public function updateResource($resourceController, $id, $data);

  /**
   * Delete a resource.
   *
   * @param RestWSResourceControllerInterface $resourceController
   *   The controller used to update the resource.
   * @param $id
   *   The id of the resource that should be deleted.
   */
  public function deleteResource($resourceController, $id);


  /**
   * Returns the mime type of this format, e.g. 'application/json' or
   * 'application/xml'.
   */
  public function mimeType();
}

/**
 * A base for all simple formats that are just serializing/unserializing an array of property values.
 */
abstract class RestWSBaseFormat implements RestWSFormatInterface {

  protected $formatName;
  protected $formatInfo;

  public function __construct($name, $info) {
    $this->formatName = $name;
    $this->formatInfo = $info;
  }

  /**
   * Gets the representation of a resource.
   */
  public function viewResource($resourceController, $id) {
    $values = self::getData($resourceController->wrapper($id));
    return $this->serialize($values);
  }

  /**
   * Creates a new resource.
   */
  public function createResource($resourceController, $data) {
    $values = $this->unserialize($data);
    $id = $resourceController->create($values);
    $ref = self::getResourceReference($resourceController->resource(), $id);
    return $this->serialize($ref);
  }

  /**
   * Updates a resource.
   */
  public function updateResource($resourceController, $id, $data) {
    $values = $this->unserialize($data);
    $resourceController->update($id, $values);
    // Return an empty representation.
    return $this->serialize(array());
  }

  /**
   * Deletes a resource.
   */
  public function deleteResource($resourceController, $id) {
    $resourceController->delete($id);
    // Return an empty representation.
    return $this->serialize(array());
  }

  public function mimeType() {
    return $this->formatInfo['mime type'];
  }

  /**
   * Gets a simple PHP array using URI references for some wrapped data.
   */
  public static function getData($wrapper) {
    $data = array();
    $filtered = restws_property_access_filter($wrapper);
    foreach ($filtered as $name => $property) {
      try {
        if ($property instanceof EntityDrupalWrapper) {
          // For referenced entities only return the URI.
          if ($id = $property->getIdentifier()) {
            $data[$name] = self::getResourceReference($property->type(), $id);
          }
        }
        elseif ($property instanceof EntityValueWrapper) {
          $data[$name] = $property->value();
        }
        elseif ($property instanceof EntityListWrapper || $property instanceof EntityStructureWrapper) {
          $data[$name] = self::getData($property);
        }
      }
      catch (EntityMetadataWrapperException $e) {
        // A property causes problems - ignore that.
      }
    }
    return $data;
  }

  public static function getResourceReference($resource, $id) {
    return array(
      'uri' => restws_resource_uri($resource, $id),
      'id' => $id,
      'resource' => $resource,
    );
  }
}

/**
 * Filters out properties where view access is not allowed for the current user.
 *
 * @param $wrapper
 *   EntityMetadataWrapper that should be checked.
 *
 * @return
 *   An array of properties where access is allowed, keyed by their property
 *   name.
 */
function restws_property_access_filter($wrapper) {
  $filtered = array();
  foreach ($wrapper as $name => $property) {
    if ($property->access('view')) {
      $filtered[$name] = $property;
    }
  }
  return $filtered;
}

/**
 * A formatter to format json.
 */
class RestWSFormatJSON extends RestWSBaseFormat {

  public function serialize($values) {
    return drupal_json_encode($values);
  }

  public function unserialize($data) {
    return drupal_json_decode($data);
  }
}

/**
 * A formatter for XML.
 */
class RestWSFormatXML extends RestWSBaseFormat {

  /**
   * Gets the representation of a resource.
   */
  public function viewResource($resourceController, $id) {
    $xml = new DOMDocument('1.0', 'utf-8');
    $element = $xml->createElement($resourceController->resource());
    self::addToXML($xml, $element, $resourceController->wrapper($id));
    $xml->appendChild($element);
    return $xml->saveXML();
  }

  /**
   * Creates a new resource.
   */
  public function createResource($resourceController, $data) {
    $values = $this->unserialize($data);
    $id = $resourceController->create($values);

    $xml = new DOMDocument('1.0', 'utf-8');
    $element = $xml->createElement('uri');
    self::setXMLReference($element, $resourceController->resource(), $id);
    $xml->appendChild($element);
    return $xml->saveXML();
  }

  public function serialize($data) {
    // Return an empty XML document.
    $xml = new DOMDocument('1.0', 'utf-8');
    return $xml->saveXML();
  }

  public function unserialize($data) {
    $xml = simplexml_load_string($data);
    return self::xmlToArray($xml);
  }

  /**
   * Turns the xml structure into an array of values.
   */
  public static function xmlToArray(SimpleXMLElement $xml) {
    $children = $xml->children();
    foreach ($xml->children() as $name => $element) {
      $result[$name] = self::xmlToArray($element);
    }
    if (!isset($result)) {
      $result = ($string = (string) $xml) ? $string : NULL;
    }
    return $result;
  }

  /**
   * Adds the data of the given wrapper to the given XML element.
   */
  public static function addToXML(DOMDocument $doc, DOMNode $parent, $wrapper) {
    $filtered = restws_property_access_filter($wrapper);
    foreach ($filtered as $name => $property) {
      try {
        if ($property instanceof EntityDrupalWrapper) {
          // For referenced entities only return the URI.
          if ($id = $property->getIdentifier()) {
            $element = $doc->createElement(is_numeric($name) ? 'item' : $name);
            $parent->appendChild($element);
            self::setXMLReference($element, $property->type(), $id);
          }
        }
        elseif ($property instanceof EntityValueWrapper) {
          $escaped = $doc->createTextNode($property->value());
          $element = $doc->createElement(is_numeric($name) ? 'item' : $name);
          $element->appendChild($escaped);
          $parent->appendChild($element);
        }
        elseif ($property instanceof EntityListWrapper || $property instanceof EntityStructureWrapper) {
          $element = $doc->createElement(is_numeric($name) ? 'item' : $name);
          $parent->appendChild($element);
          self::addToXML($doc, $element, $property);
        }
      }
      catch (EntityMetadataWrapperException $e) {
        // A property causes problems - ignore that.
      }
    }
  }

  public static function setXMLReference(DOMElement $node, $resource, $id) {
    $node->nodeValue = restws_resource_uri($resource, $id);
    $node->setAttribute('resource', $resource);
    $node->setAttribute('id', $id);
  }
}

/**
 * A simple formatter for RDF. Requires the RDF module for the mapping.
 */
class RestWSFormatRDF extends RestWSBaseFormat {

  protected $namespaces;

  public function __construct($name, $info) {
    parent::__construct($name, $info);
    $this->namespaces = rdf_get_namespaces();
    $this->namespaces['rdf'] = 'http://www.w3.org/1999/02/22-rdf-syntax-ns#';
  }

  /**
   * Gets the representation of a resource.
   */
  public function viewResource($resourceController, $id) {
    $xml = new DOMDocument('1.0', 'utf-8');
    $rdf_element = $xml->createElementNS($this->namespaces['rdf'], 'rdf:RDF');
    $xml->appendChild($rdf_element);

    $element = $xml->createElementNS($this->namespaces['rdf'], 'rdf:Description');
    $element->setAttributeNS($this->namespaces['rdf'], 'rdf:about', restws_resource_uri($resourceController->resource(), $id));

    // Add the RDF type of the resource if there is a mapping.
    $entity = $resourceController->read($id);
    if (!empty($entity->rdf_mapping['rdftype'])) {
      foreach ($entity->rdf_mapping['rdftype'] as $rdf_type) {
        $type_element = $xml->createElementNS($this->namespaces['rdf'], 'rdf:type');
        list($ns, $name) = explode(':', $rdf_type);
        $type_element->setAttributeNS($this->namespaces['rdf'], 'rdf:resource', $this->namespaces[$ns] . $name);
        $element->appendChild($type_element);
      }
    }

    $this->addToXML($xml, $element, $resourceController->wrapper($id));
    $rdf_element->appendChild($element);
    return $xml->saveXML();
  }

  public function createResource($resourceController, $data) {
    throw new RestWSException('Not implemented', 501);
  }

  public function updateResource($resourceController, $id, $data) {
    throw new RestWSException('Not implemented', 501);
  }

  /**
   * Adds the data of the given wrapper to the given XML element.
   */
  public function addToXML(DOMDocument $doc, DOMNode $parent, $wrapper) {
    $filtered = restws_property_access_filter($wrapper);
    foreach ($filtered as $name => $property) {
      try {
        if ($property instanceof EntityDrupalWrapper) {
          // For referenced entities only return the URI.
          if ($id = $property->getIdentifier()) {
            $element = $this->addRdfElement($doc, $wrapper, $name);
            $parent->appendChild($element);
            $this->addReference($doc, $element, $property->type(), $id);
          }
        }
        elseif ($property instanceof EntityValueWrapper) {
          $element = $this->addRdfElement($doc, $wrapper, $name);
          $parent->appendChild($element);
          $element->nodeValue = $property->value();
        }
        elseif ($property instanceof EntityListWrapper || $property instanceof EntityStructureWrapper) {
          $element = $this->addRdfElement($doc, $wrapper, $name);
          $parent->appendChild($element);
          $node = $doc->createElementNS($this->namespaces['rdf'], 'rdf:Description');
          $element->appendChild($node);
          $this->addToXML($doc, $node, $property);
        }
      }
      catch (EntityMetadataWrapperException $e) {
        // A property causes problems - ignore that.
      }
    }
  }

  public function addReference(DomDocument $doc, DOMElement $node, $resource, $id) {
    $element = $doc->createElementNS($this->namespaces['rdf'], 'rdf:Description');
    $element->setAttributeNS($this->namespaces['rdf'], 'rdf:about', restws_resource_uri($resource, $id));
    $node->appendChild($element);
  }

  /**
   * Adds an RDF element for the given property of the wrapper using the RDF mapping.
   */
  public function addRdfElement(DOMDOcument $doc, EntityMetadataWrapper $wrapper, $name) {
    if ($wrapper instanceof EntityDrupalWrapper) {
      $entity = $wrapper->value();
      if (!empty($entity->rdf_mapping[$name])) {
        // Just make use of the first predicate for now.
        $predicate = reset($entity->rdf_mapping[$name]['predicates']);
        list($ns, $qname) = explode(':', $predicate);
        $element = $doc->createElementNS($this->namespaces[$ns], $predicate);

        if (!empty($entity->rdf_mapping[$name]['datatype'])) {
          $element->setAttributeNS($this->namespaces['rdf'], 'rdf:datatype', $entity->rdf_mapping[$name]['datatype']);
        }
      }
    }
    if (!isset($element)) {
      // For other elements just use the site URL as namespace.
      $element = $doc->createElementNS(url('', array('absolute' => TRUE)), 'site:' . (is_numeric($name) ? 'item' : $name));
    }
    return $element;
  }
}
