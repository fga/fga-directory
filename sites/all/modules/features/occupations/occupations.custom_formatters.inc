<?php
/**
 * @file
 * occupations.custom_formatters.inc
 */

/**
 * Implements hook_custom_formatters_defaults().
 */
function occupations_custom_formatters_defaults() {
  $export = array();

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'twitter_account_link';
  $formatter->label = 'twitter account link';
  $formatter->description = '@user_name links to the Twitter account';
  $formatter->mode = 'php';
  $formatter->field_types = 'text';
  $formatter->code = 'foreach ($variables[\'#items\'] as $delta => $item) {

  //dpm(var_export(strpos($item[\'safe_value\'], \'@\'), TRUE));

  $name = strpos($item[\'safe_value\'], \'@\') === 0 ? substr($item[\'safe_value\'], 1) : $item[\'safe_value\'];
  $items[] = l(\'@\'.$name, \'http://twitter.com/\'.$name, array(\'class\' => \'twitter-username\', ));
}

return implode(\', \', $items);';
  $export['twitter_account_link'] = $formatter;

  return $export;
}
