<?php
/**
 * @file
 * Display Suite search-result template.
 *
 * Available variables:
 *
 * Layout:
 * - $classes: String of classes that can be used to style this layout.
 * - $contextual_links: Renderable array of contextual links.
 * - $layout_wrapper: wrapper surrounding the layout.
 *
 * Regions:
 *
 * - $left: Rendered content for the "left" region.
 * - $left_classes: String of classes that can be used to style the "left" region.
 *
 * - $middle: Rendered content for the "middle" region.
 * - $middle_classes: String of classes that can be used to style the "middle" region.
 *
 * - $right: Rendered content for the "right" region.
 * - $right_classes: String of classes that can be used to style the "right" region.
 */

  $classes = 'search-result clearfix';
  $left_classes = 'flyoutmenu';
  $right_classes  = '';


?>

  <!-- Needed to activate contextual links -->
  <?php if (isset($title_suffix['contextual_links'])): ?>
    <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>

    <<?php print $left_wrapper; ?> class="ds-left <?php print $left_classes; ?>">
      <?php print $left; ?>
    </<?php print $left_wrapper; ?>>


    <<?php print $right_wrapper; ?> class="ds-right <?php print $right_classes; ?>">
      <?php print $right; ?>
    </<?php print $right_wrapper; ?>>


<!-- Needed to activate display suite support on forms -->
<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
