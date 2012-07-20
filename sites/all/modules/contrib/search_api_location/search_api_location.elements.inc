<?php
/**
 * @file
 * Provides the location element to use in forms
 */

/**
 * Implements hook_element_info().
 */
function search_api_location_element_info() {
  $elements = array();
  $elements['search_api_location_pick'] = array(
    '#input' => FALSE,
    '#process' => array('search_api_location_element_process'),
   // '#theme' => 'locationradius',
    '#theme_wrappers' => array('form_element'),
    '#options' => array(),
  );

  return $elements;
}

/**
 * Processor for the search_api_location_pick field
 */
function search_api_location_element_process($element, $form_state, $complete_form) {

  $id = $element['#id'];
  $form_id = $complete_form['form_id'];

  $lat_value = isset($form_state['input']['lat']) ? $form_state['input']['lat'] : $element['#default_value']['lat'];
  $lng_value = isset($form_state['input']['lng']) ? $form_state['input']['lng'] : $element['#default_value']['lng'];
  $radius_value = isset($form_state['input']['radius']) ? $form_state['input']['radius'] : $element['#default_value']['radius'];
  $radius_min_value = isset($form_state['input']['radius_min']) ? $form_state['input']['radius_min'] : $element['#default_value']['radius_min'];
  $radius_max_value = isset($form_state['input']['radius_max']) ? $form_state['input']['radius_max'] : $element['#default_value']['radius_max'];
  $radius_step_value = isset($form_state['input']['radius_step']) ? $form_state['input']['radius_step'] : $element['#default_value']['radius_step'];
  $radius_measure_value = isset($form_state['input']['radius_measure']) ? $form_state['input']['radius_measure'] : $element['#default_value']['radius_measure'];

  $radius_measure_options = array(
    'm' => 'meter',
    'km' => 'kilometer',
    'mi' => 'mile',
  );

  $element['address'] = array(
    '#type' => 'textfield',
    '#maxlength' => 120,
    '#attributes' => array(
      'id' => $id . '-address',
    ),
    '#field_suffix' => '<a id="' . $id . '-geocode">' . t('Get location') . '</a>',
  );

  $element['help'] = array(
    '#attributes' => array(
      'id' => $id . '-help',
    ),
    '#markup' => t('Enter an address / location in the textfield or click on the map to set the marker'),
  );

  $element['gmap'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => $id . '-gmap',
      'style' => array('width:100%; height:400px;'),
    ),
  );

  $element['radius'] = array(
    '#type' => 'textfield',
    '#title' => t('Radius'),
    '#size' => 3,
    '#default_value' => $radius_value,
    '#field_suffix' => $radius_measure_options[$radius_measure_value],
    '#parents' => array_merge($element['#parents'], array('radius')),
  );

  $element['slider'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => $id . '-slider',
    ),
  );

  if (!empty($element['#default_value']['edit_mode'])) {

    $element['radius_min'] = array(
      '#type' => 'textfield',
      '#title' => t('Radius minimum value'),
      '#size' => 3,
      '#default_value' => $radius_min_value,
      '#parents' => array_merge($element['#parents'], array('radius_min')),
    );

    $element['radius_max'] = array(
      '#type' => 'textfield',
      '#title' => t('Radius maximum value'),
      '#size' => 3,
      '#default_value' => $radius_max_value,
      '#parents' => array_merge($element['#parents'], array('radius_max')),
    );

    $element['radius_step'] = array(
      '#type' => 'textfield',
      '#title' => t('Radius step value'),
      '#size' => 3,
      '#default_value' => $radius_step_value,
      '#parents' => array_merge($element['#parents'], array('radius_step')),
    );

    $element['radius_measure'] = array(
      '#type' => 'select',
      '#title' => t('Radius measure value'),
      '#options' => $radius_measure_options,
      '#default_value' => $radius_measure_value,
      '#parents' => array_merge($element['#parents'], array('radius_measure')),
    );
  }

  $element['lat'] = array(
    '#type' => 'hidden',
    '#attributes' => array(
      'id' => $id . '-lat',
    ),
    '#default_value' => $lat_value,
    '#parents' => array_merge($element['#parents'], array('lat')),
  );

  $element['lng'] = array(
    '#type' => 'hidden',
    '#attributes' => array(
      'id' => $id . '-lng',
    ),
    '#default_value' => $lng_value,
    '#parents' => array_merge($element['#parents'], array('lng')),
  );

  // Add the javascript stuff.
  drupal_add_library('system', 'ui.slider');

  $element['googlemap']['#attached']['js'][] = array(
    'data' => 'http://www.google.com/jsapi',
    'type' => 'external',
  );

  $element['googlemap']['#attached']['js'][] = array(
    'data' => 'http://maps.google.com/maps/api/js?sensor=false',
    'type' => 'external',
  );

  $element['googlemap']['#attached']['js'][] = array(
    'data' => drupal_get_path('module', 'search_api_location') . '/search_api_location.pick.js',
    'type' => 'file',
    'scope' => 'footer',
  );

  $searchapilocation = array(
    $id => array(
      'lat' => $lat_value,
      'lng' => $lng_value,
      'radius_min' => $radius_min_value,
      'radius_max' => $radius_max_value,
      'radius_step' => $radius_step_value,
      'radius_measure' => $radius_measure_value,
    ),
  );

  $element['googlemap']['#attached']['js'][] = array('data' => array('searchapilocation' => $searchapilocation), 'type' => 'setting');

  return $element;
}
