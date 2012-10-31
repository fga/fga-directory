<?php

class apachesolr_views_handler_filter extends views_handler_filter {
  function query() {
    if (!empty($this->value)) {
      if (is_array($this->value)) {
        $this->value = implode(' OR ', $this->value);
      }
      $this->query->add_where($this->options['group'], "$this->real_field", $this->value, $this->operator);
    }
  }

  /**
   * Provide a simple textfield for equality
   */
  function value_form(&$form, &$form_state) {
    $form['value'] = array(
      '#type' => 'textfield',
      '#title' => t($this->definition['title']),
      '#default_value' => $this->value,
    );
  }
}