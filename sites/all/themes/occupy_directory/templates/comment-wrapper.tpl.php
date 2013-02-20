<?php

/**
 * @file
 * Default theme implementation to provide an HTML container for comments.
 *
 * Available variables:
 * - $content: The array of content-related elements for the node. Use
 *   render($content) to print them all, or
 *   print a subset such as render($content['comment_form']).
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default value has the following:
 *   - comment-wrapper: The current template type, i.e., "theming hook".
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * The following variables are provided for contextual information.
 * - $node: Node object the comments are attached to.
 * The constants below the variables show the possible values and should be
 * used for comparison.
 * - $display_mode
 *   - COMMENT_MODE_FLAT
 *   - COMMENT_MODE_THREADED
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess_comment_wrapper()
 *
 * @ingroup themeable
 */
?>
<div id="comments" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php /*
  if ($content['comments'] && $node->type != 'forum'): ?>
  <div class="comment-instructions">
  <p>This is a community managed project that relies on people like you to keep the data current!
  If something is incomplete or incorrect please suggest an edit using the form below.
  Edits will typically be reviewed and implemented within 24 hours.</p>
  </div>
  <?php endif;*/?>
  <div class="comment-form-container">
    <?php if ($content['comment_form']): ?>
      <h2 class="title comment-form"><?php print t('Suggest an Edit'); ?></h2>
      <?php print render($content['comment_form']); ?>
    <?php endif; ?>
  </div>

  <a title="See previously suggested comments…" id="suggested-edit-log-toggle" class="icon toggle-comments" href="#"><?php print t( 'Show previous suggestions' );?></a>
  <div id="suggested-edit-log">
    <?php print render($title_prefix); ?>
    <h3 class="title"><?php print t('Previously Suggested Edit(s)'); ?></h3>
    <?php print render($title_suffix); ?>
   <?php print render($content['comments']); ?>
  </div>

</div>
