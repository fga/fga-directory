<?php

/**
 * @file
 * Extends the php-json-ld library to support additional methods.
 */


/**
 * An extended JSON-LD processor.
 */
class JsonLdDrupalProcessor extends JsonLdProcessor {
   /**
    * Converts an RDF graph into a JSON-LD object.
    *
    * @param rdf the context to use.
    *
    * @return the compacted value.
    */

  public function fromRDF($rdf) {
    // Basic implementation of the JSON-LD fromRDF method.
    $output = array();
    $output['@context'] = $rdf->ns;
    $output['@id'] = $rdf->uri;

    $properties = $rdf->index[$rdf->uri];

    // Extract resource types.
    if (!empty($properties['http://www.w3.org/1999/02/22-rdf-syntax-ns#type'])) {
      foreach ($properties['http://www.w3.org/1999/02/22-rdf-syntax-ns#type'] as $type) {
        $output['@type'][] = $type['value'];
      }
      unset($properties['http://www.w3.org/1999/02/22-rdf-syntax-ns#type']);
    }

    // Add other properties to the JSON-LD output.
    foreach ($properties as $p => $property) {
      foreach ($property as $object) {
        switch ($object['type']) {
          case 'uri' :
            $output[$p][] = array(
              '@id' => $object['value'],
            );
            break;
          case 'bnode' :
            // @todo
          case 'var' :
            // @todo
          case 'literal':
          default:
            $json_object = array('@value' => $object['value']);
            if (!empty($object['datatype'])) {
              $json_object['@type'] = $object['datatype'];
            }
            $output[$p][] = $json_object;
            break;
        }
      }
    }

    return $output;
  }
}
