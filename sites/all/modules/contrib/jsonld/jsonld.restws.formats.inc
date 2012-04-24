<?php

/**
 * Formatters for all RDF serialization formats.
 */
class JsonldRestWSFormatJsonld extends RDFxRestWSBaseFormat {
  public function viewResource($resourceController, $id) {
    $rdf = rdfx_get_rdf_model($resourceController->resource(), $id);
    return json_encode(jsonld_fromrdf($rdf));
  }
}
