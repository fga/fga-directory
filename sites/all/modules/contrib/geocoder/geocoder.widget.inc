<?php

/**
 * Implements hook_field_widget_info().
 */
function geocoder_field_widget_info() {
  return array(
    'geocoder' => array(
      'label' => t('Geocode from another field'),
      'field types' => array('geofield', 'geolocation_latlng', 'location'),
      'behaviors' => array(
        'multiple values' => FIELD_BEHAVIOR_CUSTOM,
        'default value' => FIELD_BEHAVIOR_NONE,
      ),
    ),
  );
}

/**
 * Implements field_widget_settings_form().
 */
function geocoder_field_widget_settings_form($this_field, $instance) {
  $settings = $instance['widget']['settings'];
  
  $entity_fields = field_info_instances($instance['entity_type'], $instance['bundle']);
  $all_fields = field_info_fields();
  $supported_field_types = geocoder_supported_field_types();
  $processors = geocoder_handler_info();
  $handlers_by_type = array();
  $field_types = array();
  $valid_fields = array();
  $available_handlers = array();
  
  // Add in the title/name
  //@@TODO Do this programatically by getting entity_info
  switch ($instance['entity_type']) {
    case 'node':
      $all_fields['title'] = array(
        'field_name' => 'title',
        'type' => 'text',
      );

      $entity_fields['title']['label'] = t('Title');
      break;

    case 'taxonomy_term':
      $all_fields['name'] = array(
        'field_name' => 'name',
        'type' => 'text',
      );

      $entity_fields['name']['label'] = t('Name');
      break;
  }
  
  // Get a list of all valid fields that we both support and are part of this entity
  foreach ($all_fields as $field) {
    if (array_key_exists($field['field_name'], $entity_fields)) {
      if (in_array($field['type'], array_keys($supported_field_types)) && ($field['field_name'] != $this_field['field_name'])) {
        $valid_fields[$field['field_name']] = $entity_fields[$field['field_name']]['label'];
        foreach ($supported_field_types[$field['type']] as $handler) {
          $available_handlers[$handler] = $processors[$handler]['title'];
          $handlers_by_type[$field['type']][] = $handler;
          $field_types[$field['field_name']] = $field['type'];
        }
      }
    }
  }
  
  $form['geocoder_field'] = array(
    '#type' => 'select',
    '#title' => t('Geocode from field'),
    '#default_value' => isset($settings['geocoder_field']) ? $settings['geocoder_field']: '',
    '#options' => $valid_fields,
    '#description' => t('Select which field you would like to geocode from.'),
    '#required' => TRUE,
    '#attributes' => array('onchange' => 'geocoder_admin_field_selected();'),
  );
  
  $form['geocoder_handler'] = array(
    '#type' => 'select',
    '#title' => t('Geocoder'),
    '#prefix' => '<div id="geocoder-handler-div">',
    '#suffix' => '</div>',
    '#default_value' => isset($settings['geocoder_handler']) ? $settings['geocoder_handler']: '',
    '#options' => $available_handlers,
    '#description' => t('Select which type of geocoding handler you would like to use'),
    '#attributes' => array('onchange' => 'geocoder_admin_handler_selected();'),
    '#required' => TRUE,
  );
  
  $form['handler_settings'] = array(
    '#tree' => TRUE,
  );
  
  // Add the handler settings forms
  foreach ($processors as $handler_id => $handler) {
    if (isset($handler['settings_callback']) || isset($handler['terms_of_service'])) {
      $default_values = isset($settings['handler_settings'][$handler_id]) ? $settings['handler_settings'][$handler_id] : array();
      $form['handler_settings'][$handler_id] = array();
      $form['handler_settings'][$handler_id]['#type'] = 'fieldset';
      $form['handler_settings'][$handler_id]['#attributes'] = array('class' => array('geocoder-handler-setting', 'geocoder-handler-setting-' . $handler_id));
      $form['handler_settings'][$handler_id]['#title'] = $handler['title'] . ' Settings';      

      if (isset($handler['terms_of_service'])) {
        $form['handler_settings'][$handler_id]['tos'] = array(
          '#type' => 'item',
          '#markup' => t('This handler has terms of service. Click the following link to learn more.') . ' ' . l($handler['terms_of_service'], $handler['terms_of_service']),
        );
      }

      if (isset($handler['settings_callback'])) {
        $settings_callback = $handler['settings_callback'];
        $form['handler_settings'][$handler_id] = array_merge($form['handler_settings'][$handler_id], $settings_callback($default_values));
      }
    }
  }
  
  $form['delta_handling'] = array(
    '#type' => 'select',
    '#title' => t('Multi-value input handling'),
    '#description' => t('Should geometries from multiple inputs be: <ul><li>Matched with each input (e.g. One POINT for each address field)</li><li>Aggregated into a single MULTIPOINT geofield (e.g. One MULTIPOINT polygon from multiple address fields)</li><li>Broken up into multiple geometries (e.g. One MULTIPOINT to multiple POINTs.)</li></ul>'),
    '#default_value' => isset($settings['delta_handling']) ? $settings['delta_handling']: 'default',
    '#options' => array(
      'default' => 'Match Multiples (default)',
      'm_to_s' =>  'Multiple to Single',
      's_to_m' =>  'Single to Multiple',
      'c_to_s' =>  'Concatenate to Single',
      'c_to_m' =>  'Concatenate to Multiple',
    ),
    '#required' => TRUE,
  );
  
  drupal_add_js(array('geocoder_widget_settings' => array('handlers' => $handlers_by_type, 'types' => $field_types)), 'setting');
  drupal_add_js(drupal_get_path('module', 'geocoder') . '/geocoder.admin.js', 'file');
  
  return $form;
}

/**
 * Implements hook_field_attach_presave().
 *
 * Geocoding for the geocoder widget is done here to ensure that only validated
 * and fully processed fields values are accessed.
 */
function geocoder_field_attach_presave($entity_type, $entity) {
  // Loop over any geofield using our geocode widget
  $entity_info = entity_get_info($entity_type);
  $bundle_name = empty($entity_info['entity keys']['bundle']) ? $entity_type : $entity->{$entity_info['entity keys']['bundle']};
  foreach (field_info_instances($entity_type, $bundle_name) as $field_instance) {
    if ($field_instance['widget']['type'] === 'geocoder') {
      // Required settings
      if (isset($field_instance['widget']['settings']['geocoder_handler']) && isset($field_instance['widget']['settings']['geocoder_field'])) {
        $handler = geocoder_get_handler($field_instance['widget']['settings']['geocoder_handler']);
        $field_name = is_array($field_instance['widget']['settings']['geocoder_field']) ? reset($field_instance['widget']['settings']['geocoder_field']) : $field_instance['widget']['settings']['geocoder_field'];
        $target_info = field_info_field($field_instance['field_name']);
        $target_type = $target_info['type'];
        
        // Get the handler-specific-settings
        if (isset($field_instance['widget']['settings']['handler_settings'][$handler['name']])) {
          $handler_settings = $field_instance['widget']['settings']['handler_settings'][$handler['name']];
        }
        
        // Determine how we deal with deltas (multi-value fields)
        if (empty($field_instance['widget']['settings']['delta_handling'])) {
          $delta_handling = 'default';
        }
        else {
          $delta_handling = $field_instance['widget']['settings']['delta_handling'];
        }
        
        list($field_info, $items) = geocoder_widget_get_field_data($entity_type, $entity, $field_name, $delta_handling);
        
        if (is_array($items) && count($items)) {
          $values = array();
          
          // Geocode geometries
          $geometries = array();
          foreach ($items as $delta => $item) {
            // Geocode any value from our source field.
            try {
              if (isset($handler_settings)) {
                $geometry = call_user_func($handler['field_callback'], $field_info, $item, $handler_settings);
              }
              else {
                $geometry = call_user_func($handler['field_callback'], $field_info, $item);
              }
              if ($geometry instanceof Geometry) {
                $geometries[] = $geometry;
              }
            }
            catch (Exception $e) {
              drupal_set_message($e->getMessage(), 'error');
            }
          }
          
          if (empty($geometries)) $values = array(NULL);
          else {
            // Resolve multiple-values - get back values from our delta-resolver
            $values = geocoder_widget_resolve_deltas($geometries, $delta_handling, $target_type);
          }
          
          // Set the values - geofields do not support languages
          $entity->{$field_instance['field_name']}[LANGUAGE_NONE] = $values;
        }
      }
    }
  }
}


/**
 * Get field items and info
 * 
 * We always pass the full field-item array (with all columns) to the handler, but there is some preprocessing
 * that we need to do for the special case of entity-labels and multi-field contactenation
 * For these two special cases we "mock-up" a text-field and pass it back for geocoding
 */
function geocoder_widget_get_field_data($entity_type, $entity, $field_name, $delta_handling) {
  $entity_info = entity_get_info($entity_type);
  
  // First check to see if it's an entity field
  if (in_array($field_name, $entity_info['entity keys'])) {
    $items[]['value'] = $entity->$field_name;
    $field_info = array(
      'type' => 'text',
      'entity key' => TRUE,
    );
  }
  else {
    // It's a normal field-api field
    $field_info = field_info_field($field_name);
    $langcode = field_language($entity_type, $entity, $field_name);
    $items = field_get_items($entity_type, $entity, $field_name, $langcode);
  }
  
  // Check if we should concatenate
  if ($delta_handling == 'c_to_s' || $delta_handling == 'c_to_m') {
    $support_concat = array('text', 'text_long', 'computed', 'text_with_summary', 'computed');
    if (!in_array($field_info['type'], $support_concat)) {
      drupal_set_message(t('Trying to concatenate a non-text field'));
      return;
    }
    $concat = '';
    foreach ($items as $item) {
      $concat .= trim($item['value']) . ', ';
    }
    $concat = trim($concat, ', ');
    $items = array(array('value' => $concat));
    $field_info = array(
      'type' => 'text',
      'concated' => TRUE,
    );
  }
  
  return array(
    $field_info,
    $items, 
  );
}

/**
 * Geocder Widget - Resolve Deltas
 * 
 * Given a list of geometries, and user configuration on how to handle deltas, 
 * we created a list of items to be inserted into the fields.
 */
function geocoder_widget_resolve_deltas($geometries, $delta_handling = 'default', $field_type) {
  $values = array();
  
  // Default delta handling: just pass one delta to the next
  if ($delta_handling == 'default') {
    foreach ($geometries as $geometry) {
      $values[] = geocoder_widget_values_from_geometry($geometry, $field_type);
    }
  }
  
  // Single-to-multiple handling - if we can, explode out the component geometries
  if ($delta_handling == 's_to_m' || $delta_handling = 'c_to_m') {
    $type = $geometries[0]->geometryType();
    if (in_array($type, array('MultiPoint', 'MultiLineString', 'MultiPolygon', 'GeometryCollection'))) {
      $components = $geometries[0]->getComponents();
      foreach ($components as $component) {
        $values[] = geocoder_widget_values_from_geometry($component, $field_type);
      }
    }
    else {
      $values[] = geocoder_widget_values_from_geometry($geometries[0], $field_type);
    }
  }
  
  // For multiple-to-single handling, run it though geometryReduce
   if ($delta_handling == 'm_to_s' || $delta_handling = 'c_to_s') {
    $reduced_geom = geoPHP::geometryReduce($geometries);
    $values[] = geocoder_widget_values_from_geometry($reduced_geom, $field_type);
  }
  
  return $values;
}

/**
 * Geocder Widget - Field values from geometry
 * 
 * Given a geometry and the field type, return back a values array for that field.
 * The passed back array represents a single delta. 
 */
function geocoder_widget_values_from_geometry($geometry, $field_type) {
  if ($field_type == 'geofield') return geofield_get_values_from_geometry($geometry);
  if ($field_type == 'geolocation_latlng') {
    $centroid = $geometry->centroid();
    $lat = $centroid->y();
    $lng = $centroid->x();
    
    return array(
      'lat' => $lat,
      'lng' => $lng,
      'lat_sin' => sin(deg2rad($lat)),
      'lat_cos' => cos(deg2rad($lng)),
      'lng_rad' => deg2rad($lng),
    );
  }
  if ($field_type == 'location') {
    $centroid = $geometry->centroid();
    return array(
      'latitude' => $centroid->y(),
      'longitude' => $centroid->x(),
      'source' => 2,
    );
  }
}


/**
 * Geocoder Widget - Parse an address field
 */
function geocoder_widget_parse_addressfield($field_item) {
  $address = '';
  if (!empty($field_item['premise']))                 $address .= $field_item['premise'] . ',';
  if (!empty($field_item['thoroughfare']))            $address .= $field_item['thoroughfare'] . ',';
  if (!empty($field_item['locality']))                $address .= $field_item['locality'] . ',';
  if (!empty($field_item['administrative_area']))     $address .= $field_item['administrative_area'] . ',';
  if (!empty($field_item['sub_administrative_area'])) $address .= $field_item['sub_administrative_area'] . ',';
  if (!empty($field_item['country']))                 $address .= $field_item['country'] . ',';
  if (!empty($field_item['postal_code']))             $address .= $field_item['postal_code'] . ',';
  
  $address = rtrim($address, ', ');
  
  return $address;
}
