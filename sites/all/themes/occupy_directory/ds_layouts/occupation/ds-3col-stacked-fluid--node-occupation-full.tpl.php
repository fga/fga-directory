<?php
/**
 * @file
 * Display Suite occupation 3col fluid template.
 *
 */

  // Add sidebar classes so that we can apply the correct width to the center region in css.
  if (($left && !$right) || ($right && !$left)) {
    $classes .= ' group-one-column';
  }

  $classes = 'occupation';
  $header_classes = 'clearfix';
  $left_classes = 'first equal-height-element';
  $right_classes  = 'equal-height-element';
  $footer_classes = 'clearfix';


  if ($left && $right) $classes .= ' group-two-sidebars';
  if ($left) $classes .= ' group-sidebar-left';
  if ($right) $classes .= ' group-sidebar-right';


?>
<<?php print $layout_wrapper; print $layout_attributes; ?> class="ds-3col-stacked-fluid <?php print $classes;?> clearfix">

  <?php if (isset($title_suffix['contextual_links'])): ?>
  <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>

  <<?php print $header_wrapper ?> class="group-header<?php print $header_classes; ?>">
    <?php print $header; ?>
  </<?php print $header_wrapper ?>>

  <?php if ($left): ?>
    <<?php print $left_wrapper ?> class="ds-left <?php print $left_classes; ?>">
      <?php print $left; ?>
    </<?php print $left_wrapper ?>>
  <?php endif; ?>

  <?php if ($right): ?>
    <<?php print $right_wrapper ?> class=" ds-right <?php print $right_classes; ?>">
      <?php print $right; ?>
    </<?php print $right_wrapper ?>>
  <?php endif; ?>

  <?php if ($middle): ?>
    <<?php print $middle_wrapper ?> class="ds-middle <?php print $middle_classes; ?>">
      <?php print $middle; ?>
    </<?php print $middle_wrapper ?>>
  <?php endif; ?>


  <<?php print $footer_wrapper ?> class="group-footer<?php print $footer_classes; ?>">
    <?php print $footer; ?>
  </<?php print $footer_wrapper ?>>

</<?php print $layout_wrapper ?>>

<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>

