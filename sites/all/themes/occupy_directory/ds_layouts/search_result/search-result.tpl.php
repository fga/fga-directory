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
  $id_classes = 'id flyoutmenu';
  $contact_classes  = 'contact';
  $misc_classes  = 'misc';


?>
<<?php print $layout_wrapper; print $layout_attributes; ?> class="<?php print $classes;?>">

  <!-- Needed to activate contextual links -->
  <?php if (isset($title_suffix['contextual_links'])): ?>
    <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>

    <<?php print $id_wrapper; ?> class="<?php print $id_classes; ?>">
      <?php print $id; ?>
    </<?php print $id_wrapper; ?>>


    <<?php print $contact_wrapper; ?> class="<?php print $contact_classes; ?>">
      <?php print $contact; ?>
    </<?php print $contact_wrapper; ?>>

    <<?php print $misc_wrapper; ?> class="<?php print $misc_classes; ?>">
      <?php print $misc; ?>
    </<?php print $misc_wrapper; ?>>


</<?php print $layout_wrapper ?>>

<!-- Needed to activate display suite support on forms -->
<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
