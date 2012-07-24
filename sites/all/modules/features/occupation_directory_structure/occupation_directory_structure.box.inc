<?php
/**
 * @file
 * occupation_directory_structure.box.inc
 */

/**
 * Implements hook_default_box().
 */
function occupation_directory_structure_default_box() {
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

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'occupynet_nav';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'occupy.net navbar';
  $box->options = array(
    'body' => array(
      'value' => ' <script type="text/javascript" src="https://nav.occupy.net/occupynet_nav.js"></script>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['occupynet_nav'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'social_media';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'social media links';
  $box->options = array(
    'body' => array(
      'value' => '<p><a href="http://www.facebook.com/OccupyDirectory" target="_blank"><img alt="facebook" alt="facebook" class="facebook-icon" id="facebook-icon" src="/sites/all/themes/occupy_directory/assets/facebook.png" style="width: 19px; height: 20px;"></a>&nbsp; <a href="https://twitter.com/#!/OWSdirectory" alt="twitter" target="_blank"><img alt="twitter" class="twitter-icon" id="twitter-icon" src="/sites/all/themes/occupy_directory/assets/twitter.png" style="width: 27px; height: 19px;"></a></p>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['social_media'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'twitter_pull';
  $box->plugin_key = 'simple';
  $box->title = 'Twitter feed';
  $box->description = 'Twitter Pull';
  $box->options = array(
    'body' => array(
      'value' => '<?php
if (function_exists(\'twitter_pull_render\')) { print twitter_pull_render(\'@OWSdirectory\', false, 6); }
?>',
      'format' => 'php_code',
    ),
    'additional_classes' => 'twitter-pull',
  );
  $export['twitter_pull'] = $box;

  return $export;
}
