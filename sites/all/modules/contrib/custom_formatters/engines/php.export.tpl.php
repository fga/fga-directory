<?php
/**
 * @file
 */
?>
/**
 * Implements hook_field_formatter_info().
 */
function <?php echo $module; ?>_field_formatter_info() {
  return array(
    '<?php echo $module; ?>_<?php echo $item->name; ?>' => array(
      'label' => t('<?php echo $item->label; ?>'),
      'field types' => array('<?php echo implode('\', \'', drupal_explode_tags($item->field_types)); ?>'),
    ),
  );
}

/**
 * Implements hook_field_formatter_view().
 */
function <?php echo $module; ?>_field_formatter_view($obj_type, $object, $field, $instance, $langcode, $items, $display) {
  $element = array();

  // Build variables array for formatter.
  $variables = array(
    '#obj_type' => $obj_type,
    '#object' => $object,
    '#field' => $field,
    '#instance' => $instance,
    '#langcode' => $langcode,
    '#items' => $items,
    '#display' => $display,
  );

  if (function_exists($function = "{$display['module']}_field_formatter_{$display['type']}")) {
    $element[0] = array(
      '#markup' => $function($variables),
    );
  }

  return $element;
}

/**
 * Field Formatter; <?php echo $item->label; ?>.
 */
function <?php echo $module; ?>_field_formatter_<?php echo $module; ?>_<?php echo $item->name; ?>($variables) {
<?php foreach (explode("\n", $item->code) as $line) : ?>
  <?php echo $line . "\n"; ?>
<?php endforeach; ?>
}
