<?php
/**
 * @file
 * Display Suite occupation template.
 *
 * Available variables:
 *
 * Layout:
 * - $classes: String of classes that can be used to style this layout.
 * - $contextual_links: Renderable array of contextual links.
 *
 * Regions:
 *
 * - $header: Rendered content for the "header" region.
 * - $header_classes: String of classes that can be used to style the "header" region.
 *
 * - $left: Rendered content for the "left" region.
 * - $left_classes: String of classes that can be used to style the "left" region.
 *
 * - $right: Rendered content for the "right" region.
 * - $right_classes: String of classes that can be used to style the "right" region.
 *
 * - $footer: Rendered content for the "footer" region.
 * - $footer_classes: String of classes that can be used to style the "footer" region.
 */
  // Add sidebar classes so that we can apply the correct width in css.
  if (($left && !$right) || ($right && !$left)) {
    $classes .= ' group-one-column';
  }

  $classes = 'occupation';
  $header_classes = 'grid-10 prefix-1 suffix-1 pull-1';
  $left_classes = 'grid-3 first equal-height-element';
  $right_classes  = 'grid-6 equal-height-element';
  $footer_classes = 'grid-10 clearfix';
?>

<<?php print $layout_wrapper; print $layout_attributes; ?> class="<?php print $classes;?> clearfix">

  <!-- Needed to activate contextual links -->
  <?php if (isset($title_suffix['contextual_links'])): ?>
    <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>


  <?php if ($header): ?>
    <<?php print $header_wrapper; ?> class="ds-header <?php print $header_classes; ?>">
      <?php print $header; ?>
    </<?php print $header_wrapper; ?>>
  <?php endif; ?>

  <?php if ($left && $right): ?>
    <div class="equal-height-container clearfix">
  <?php endif; ?>

    <?php if ($left): ?>
      <<?php print $left_wrapper; ?> class="ds-left <?php print $left_classes; ?>">
        <?php print $left; ?>
      </<?php print $left_wrapper; ?>>
    <?php endif; ?>

    <?php if ($right): ?>
      <<?php print $right_wrapper; ?> class="ds-right <?php print $right_classes; ?>">
        <?php print $right; ?>
      </<?php print $right_wrapper; ?>>
    <?php endif; ?>

  <?php if ($left && $right): ?>
    </div>
  <?php endif; ?>


  <?php if ($footer): ?>
    <<?php print $footer_wrapper; ?> class="ds-footer <?php print $footer_classes; ?>">
      <?php print $footer; ?>
    </<?php print $footer_wrapper; ?>>
  <?php endif; ?>


</<?php print $layout_wrapper ?>>

<!-- Needed to activate display suite support on forms -->
<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
