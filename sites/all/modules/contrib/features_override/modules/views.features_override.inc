<?php

/**
 * Implementation of hook_views_default_views_alter().
 */
function features_override_views_default_views_alter(&$items) {
  features_override_features_default_alter($items, "views");
}

