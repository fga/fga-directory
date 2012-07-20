<?php

/**
 * @file
 * Provides the views handler for location fields
 */

class SearchApiViewsHandlerFilterLocation extends SearchApiViewsHandlerFilter {

  /**
   * Provide a form for setting the filter value.
   */
  public function value_form(&$form, &$form_state) {

    $field = $this->options['id'];
    $default_value = array();

    // Check if the input filter is filled in.
    if (isset($form_state['input'][$field])) {
      $default_value['lat'] = $form_state['input'][$field]['lat'];
      $default_value['lng'] = $form_state['input'][$field]['lng'];
      $default_value['radius'] = $form_state['input'][$field]['radius'];
    }
    else {
      $default_value['lat'] = $this->options['lat'];
      $default_value['lng'] = $this->options['lng'];
      $default_value['radius'] = $this->options['radius'];
    }

    $default_value['radius_min'] = $this->options['radius_min'];
    $default_value['radius_max'] = $this->options['radius_max'];
    $default_value['radius_step'] = $this->options['radius_step'];
    $default_value['radius_measure'] = $this->options['radius_measure'];

    $form['value'] = array(
      '#type' => 'search_api_location_pick',
      '#default_value' => $default_value,
    );
  }

  /**
   * Default location settings
   */
  public function option_definition() {
    $options = parent::option_definition();

    $options['lat'] = array('default' => '51.03826129999999');
    $options['lng'] = array('default' => '3.7125661000000036');
    $options['radius'] = array('default' => '5');
    $options['radius_min'] = array('default' => '5');
    $options['radius_max'] = array('default' => '100');
    $options['radius_step'] = array('default' => '5');
    $options['radius_measure'] = array('default' => 'km');

    return $options;
  }

  /**
   * Alter and extend the options form
   */
  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    unset($form['operator']);
    unset($form['value']);
    $form['label'] = $form['expose']['label'];
    unset($form['expose']);

    $form['spatial'] = array(
      '#type' => 'search_api_location_pick',
      '#default_value' => array(
        'lat' => $this->options['lat'],
        'lng' => $this->options['lng'],
        'radius' => $this->options['radius'],
        'radius_min' => $this->options['radius_min'],
        'radius_max' => $this->options['radius_max'],
        'radius_step' => $this->options['radius_step'],
        'radius_measure' => $this->options['radius_measure'],
        'edit_mode' => TRUE,
      ),
    );
  }

  /**
   * Add this filter to the query.
   */
  public function query() {

    $field = str_replace(":", "_", $this->real_field);

    if (isset($this->view->exposed_input[$field]['radius'])) {

      $spatial = array();
      $spatial['lat'] = $this->view->exposed_input[$field]['lat'];
      $spatial['lng'] = $this->view->exposed_input[$field]['lng'];
      $spatial['radius'] = $this->view->exposed_input[$field]['radius'];
      $spatial['radius_measure'] = $this->options['radius_measure'];
      $spatial['field'] = $this->real_field;

      $this->query->setOption('spatial', $spatial);
    }
  }
}
