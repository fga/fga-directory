<?php

/**
 * Implementation of hook_context_default_contexts_alter().
 */
function features_override_context_default_contexts_alter(&$items) {
  features_override_features_default_alter($items, "context");
}
