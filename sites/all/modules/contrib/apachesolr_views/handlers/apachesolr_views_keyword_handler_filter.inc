<?php

/**
 * Fulltext keyword search.
 */
class apachesolr_views_keyword_handler_filter extends apachesolr_views_handler_filter {
  function query() {
    if (!empty($this->value)) {
      $this->query->add_parameter('q', $this->value);
    }
  }
}
