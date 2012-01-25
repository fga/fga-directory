<?php

/**
 * Implementation of hook_default_wysiwyg_profile_alter().
 */
function features_override_default_wysiwyg_profile_alter(&$items) {
  features_override_features_default_alter($items, "wysiwyg_profile");
}

/**
 * Implementation of hook_field_default_fields_alter().
 */
function features_override_field_default_fields_alter(&$items) {
  features_override_features_default_alter($items, "field");
}

/**
 * Implementation of hook_filter_default_formats_alter().
 */
function features_override_filter_default_formats_alter(&$items) {
  features_override_features_default_alter($items, "filter");
}

/**
 * Implementation of hook_image_default_styles_alter().
 */
function features_override_image_default_styles_alter(&$items) {
  features_override_features_default_alter($items, "image");
}

/**
 * Implementation of hook_menu_default_menu_custom_alter().
 */
function features_override_menu_default_menu_custom_alter(&$items) {
  features_override_features_default_alter($items, "menu_custom");
}

/**
 * Implementation of hook_menu_default_menu_links_alter().
 */
function features_override_menu_default_menu_links_alter(&$items) {
  features_override_features_default_alter($items, "menu_links");
}

/**
 * Implementation of hook_menu_default_items_alter().
 */
function features_override_menu_default_items_alter(&$items) {
  features_override_features_default_alter($items, "menu");
}

/**
 * Implementation of hook_node_info_alter().
 */
function features_override_node_info_alter(&$items) {
  features_override_features_default_alter($items, "node");
}

/**
 * Implementation of hook_taxonomy_default_vocabularies_alter().
 */
function features_override_taxonomy_default_vocabularies_alter(&$items) {
  features_override_features_default_alter($items, "taxonomy");
}

/**
 * Implementation of hook_user_default_roles_alter().
 */
function features_override_user_default_roles_alter(&$items) {
  features_override_features_default_alter($items, "user_role");
}

/**
 * Implementation of hook_user_default_permissions_alter().
 */
function features_override_user_default_permissions_alter(&$items) {
  features_override_features_default_alter($items, "user_permission");
}

