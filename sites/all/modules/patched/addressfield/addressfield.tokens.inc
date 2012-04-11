<?php

/**
 * @file
 * Token module integration.
 */
 
/**
 * Implements hook_token_info().
 */
function addressfield_token_info() {
  
  $type = array(
    'name' => t('Addressfield fields'),
    'description' => t('Tokens related to addressfield field instances.'),
    'needs-data' => 'addressfield-field',
    'field' => TRUE,
  );
  
  $info['country-code'] = array(
    'name' => t('Country code'),
    'description' => t('The country code value.'),
  );
  
  $info['country-name'] = array(
    'name' => t('Country name'),
    'description' => t('The country name value.'),
  );
  
  $info['state_province-name'] = array(
    'name' => t('State/Province name'),
    'description' => t('The state/province name value.'),
  );
  
    $info['city-name'] = array(
    'name' => t('City name'),
    'description' => t('The city name value.'),
  );
  
  $info['postal-code'] = array(
    'name' => t('Postal code'),
    'description' => t('The postal code value.'),
  );
  
  return array(
    'types' => array('addressfield-field' => $type),
    'tokens' => array('addressfield-field' => $info),
  );
}

/**
 * Implements hook_tokens().
 */
function addressfield_tokens($type, $tokens, array $data = array(), array $options = array()) {

  if (isset($options['language'])) {
    $url_options['language'] = $options['language'];
    $language_code = $options['language']->language;
  }
  else {
    $language_code = LANGUAGE_NONE;
  }
  $sanitize = !empty($options['sanitize']);
  
  $replacements = array();
  
  if ($type == 'addressfield-field') {
    if (isset($data['addressfield-field'][$language_code][0])) {

      foreach ($tokens as $name => $original) {
        switch ($name) {
          case 'country-code':
            $replacements[$original] = $data['addressfield-field'][$language_code][0]['country'];
            break;

          case 'country-name':
            $countries = _addressfield_country_options_list();
            $replacements[$original] = $sanitize ? check_plain($countries[$data['addressfield-field'][$language_code][0]['country']]) : $countries[$data['addressfield-field'][$language_code][0]['country']];
            break;

          case 'state_province-name':
            $replacements[$original] = $sanitize ? check_plain($data['addressfield-field'][$language_code][0]['administrative_area']) : $data['addressfield-field'][$language_code][0]['administrative_area'];
            break;

          case 'city-name':
            $replacements[$original] = $sanitize ? check_plain($data['addressfield-field'][$language_code][0]['locality']) : $data['addressfield-field'][$language_code][0]['locality'];
            break;

          case 'postal-code':
            $replacements[$original] = $sanitize ? check_plain($data['addressfield-field'][$language_code][0]['postal_code']) : $data['addressfield-field'][$language_code][0]['postal_code'];
            break;
        }
      }
    }
  }
  
  if ($type == 'entity') {
    // Find all address fields.
    $address_fields = addressfield_get_address_fields();
    
    // Generate tokens using pattern above.
    foreach ($address_fields as $field_name) {
      if ($addressfield_tokens = token_find_with_prefix($tokens, $field_name)) {
        $replacements += token_generate('addressfield-field', $addressfield_tokens, array('addressfield-field' => $data['entity']->$field_name), $options);
      }
    }
  }
  
  return $replacements;
}

/**
 * Implements hook_token_info_alter().
 */
function addressfield_token_info_alter(&$data) {
  // Get the info on all fields.
  $fields = field_info_fields();
  
  $address_fields = addressfield_get_address_fields();
  
  foreach ($address_fields as $field_name) {
    foreach ($data['tokens'] as $bundle => $token){
      if (isset($data['tokens'][$bundle][$field_name])) {
        // Add a type to the address field.
        $data['tokens'][$bundle][$field_name]['type'] = 'addressfield-field';
      }
    }
  }
  
}

