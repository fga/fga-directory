<?php
/**
 * @file
 * occupations_total.box.inc
 */

/**
 * Implements hook_default_box().
 */
function occupations_total_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'occupation_count';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Occupation Count';
  $box->options = array(
    'body' => array(
      'value' => '<div id="">
<?php
// Return the total number of published occupations
// todo: cache results!

$result = db_query("SELECT COUNT(*) FROM {node} WHERE type = \'occupation\' AND status = 1")->fetchField();
print \'<span class="count-result">\' . $result . \'</span>&nbsp;<span class="count-label">Occupations</span>\';
?>
</div>',
      'format' => 'php_code',
    ),
    'additional_classes' => '',
  );
  $export['occupation_count'] = $box;

  return $export;
}
