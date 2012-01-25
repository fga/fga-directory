<?php

/**
 * Implementation of hook_strongarm_alter().
 */
function features_override_strongarm_alter(&$items) {
  features_override_features_default_alter($items, "variable");
}
