<?php

/**
 * Implementation of hook_default_panels_mini_alter().
 */
function features_override_default_panels_mini_alter(&$items) {
  features_override_features_default_alter($items, "panels_mini");
}
