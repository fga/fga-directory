<?php

/**
 * Class that allows searching the site with Apache Solr through a view.
 */
class apachesolr_views_handler_argument extends views_handler_argument {
  public function query() {
    $this->query->add_filter($this->real_field, $this->argument);
  }
}
