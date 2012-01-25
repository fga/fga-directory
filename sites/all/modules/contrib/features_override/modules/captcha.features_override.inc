<?php

/**
 * Implementation of hook_captcha_default_points_alter().
 */
function features_override_captcha_default_points_alter(&$items) {
  features_override_features_default_alter($items, "captcha_points");
}
