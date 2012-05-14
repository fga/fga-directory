<?php

/**
 * @file
 * This file is empty by default because the base theme chain (Alpha & Omega) provides
 * all the basic functionality. However, in case you wish to customize the output that Drupal
 * generates through Alpha & Omega this file is a good place to do so.
 * 
 * Alpha comes with a neat solution for keeping this file as clean as possible while the code
 * for your subtheme grows. Please read the README.txt in the /preprocess and /process subfolders
 * for more information on this topic.
 */
 
/* alpha does define alpha_exclude_options($theme), 
 * but it's more staightforward to exclude our module styles here 
 */
function occupy_directory_css_alter(&$css) { 
  if(module_exists('twitter_pull')) { 
    unset($css[drupal_get_path('module','twitter_pull').'/twitter-pull-listing.css']);
  }
}