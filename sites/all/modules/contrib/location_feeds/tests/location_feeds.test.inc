<?php

/**
 * @file
 *
 * Test functions for the location_feeds module
 *
 * @author: Elliott Foster
 */

require_once(drupal_get_path('module', 'location') . '/tests/location_testcase.php');
require_once(drupal_get_path('module', 'feeds') . '/tests/feeds_mapper.test');

/**
 * Class for testing Feeds <em>location</em> mapper.
 */
class FeedsMapperLocationTestCase extends FeedsMapperTestCase {

  public function createLocationType(&$settings, $add = array()) {
    // find a non-existent random type name.
    $types = _node_types_build()->types;
    do {
      $name = strtolower($this->randomName(3, 'type_'));
    } while (in_array($name, $types));

    // Get the (settable) defaults.
    $defaults = LocationTestCase::getLocationFieldDefaults();

    $settings = array(
      'name' => $name,
      'type' => $name,
      'location_settings' => array(
        'multiple' => array(
          'max' => 1,
          'add' => 1,
        ),
        'form' => array(
          'fields' => $defaults,
        ),
      ),
    );

    //$settings['location_settings'] = array_merge_recursive($settings['location_settings'], $add);
    LocationTestCase::flattenPostData($settings);
    $add = array('location_settings' => $add);
    LocationTestCase::flattenPostData($add);
    $settings = array_merge($settings, $add);
    $this->drupalPost('admin/structure/types/add', $settings, 'Save content type');
    $this->refreshVariables();
    $settings = variable_get('location_settings_node_'. $name, array());
    return $name;
  }

  public function saveUserLocationSettings(&$settings) {
    // Get the (settable) defaults.
    $defaults = LocationTestCase::getLocationFieldDefaults();

    $settings = array(
      'location_settings_user' => array(
        'multiple' => array(
          'max' => 1,
          'add' => 1,
        ),
        'form' => array(
          'fields' => $defaults,
        ),
      ),
    );
    LocationTestCase::flattenPostData($settings);
    $this->drupalPost('admin/config/people/accounts', $settings, 'Save configuration');
    $this->refreshVariables();
    $settings = variable_get('location_settings_user', array());
  }

}

