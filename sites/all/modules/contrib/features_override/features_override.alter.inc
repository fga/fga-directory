<?php
// $Id: features_override.alter.inc,v 1.3 2011/02/16 00:28:48 nedjo Exp $

/**
 * Alter default features.
 */
function features_override_features_default_alter(&$items, $component) {
  $overrides = features_override_load_all();
  foreach ($overrides as $override) {
    if (isset($items[$override->component_id]) && $override->component_type == $component && !empty($override->value)) {
      if (isset ($override->value['additions']) && !empty($override->value['additions'])) {
        foreach ($override->value['additions'] as $addition) {
          _features_override_set_item($items[$override->component_id], 'add', $addition['keys'], $addition['value']);
        }
      }
      if (isset ($override->value['deletions']) && !empty($override->value['deletions'])) {
        foreach ($override->value['deletions'] as $deletion) {
          _features_override_set_item($items[$override->component_id], 'delete', $deletion['keys']);
        }
      }
    }
  }
}

/**
 * Set a single addition or deletion for a component.
 */
function _features_override_set_item(&$item, $action, $keys, $value = NULL) {
  $key = array_shift($keys);
  if ($key['type'] == 'object') {
    if (count($keys) && isset($item->{$key['key']})) {
      _features_override_set_item($item->{$key['key']}, $action, $keys, $value);
    }
    else {
      switch($action) {
        case 'add':
          $item->{$key['key']} = $value;
          break;
        case 'delete':
          unset($item->{$key['key']});
          break;
      }
    }
  }
  else {
    if (count($keys) && isset($item[$key['key']])) {
      _features_override_set_item($item[$key['key']], $action, $keys, $value);
    }
    else {
      switch($action) {
        case 'add':
          $item[$key['key']] = $value;
          break;
        case 'delete':
          unset($item[$key['key']]);
          break;
      }
    }
  }
}

