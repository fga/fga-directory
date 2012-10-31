<?php

/**
 * Field handler for Solr fields.
 */
class apachesolr_views_handler_field extends views_handler_field {

  // Retrieve value from Solr result document.
  function get_value($values, $field = NULL) {
    $alias = isset($field) ? $this->aliases[$field] : $this->field_alias;
    if (isset($values->{$alias})) {
      if (is_array($values->{$alias})) {
        return implode(" ", $values->{$alias});
      }
      else {
        return $values->{$alias};
      }
    }
  }

  /**
   * Called to determine what to tell the clicksorter.
   */
  function click_sort($order) {
    $sort_field = (isset($this->definition['click sort field']) ? $this->definition['click sort field'] : $this->real_field);
    $this->query->add_sort($sort_field, $order);
  }

}