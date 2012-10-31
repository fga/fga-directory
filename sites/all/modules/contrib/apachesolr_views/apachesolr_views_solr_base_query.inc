<?php

/**
 * Custom SolrBaseQuery class for Apachesolr Views.
 *
 * Needed to set proper base path for facets.
 */
class ApachesolrViewsSolrBaseQuery extends SolrBaseQuery {
  public function getPath($new_keywords = NULL) {
    if (isset($new_keywords)) {
      return $this->base_path . '/' . $new_keywords;
    }
    return $this->base_path;
  }
}
