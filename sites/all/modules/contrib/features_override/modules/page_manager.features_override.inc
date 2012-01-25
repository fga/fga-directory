<?php

/**
 * Implementation of hook_default_page_manager_handlers_alter().
 */
function features_override_default_page_manager_handlers_alter(&$items) {
  features_override_features_default_alter($items, "page_manager_handlers");
}

/**
 * Implementation of hook_default_page_manager_pages_alter().
 */
function features_override_default_page_manager_pages_alter(&$items) {
  features_override_features_default_alter($items, "page_manager_pages");
}
