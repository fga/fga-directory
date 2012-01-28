<?php
/**
 * @file
 * Overridable template file for talk page.
 *
 * Available variables:
 *   $comment_count represents the number of comments on the node.
 *   $comments represents the rendered comments, form, and/or link.
 *   $node represents the node whose comments we're displaying.
 *   $title represents the title of the talk page. Defaults to "Talk".
 */
?>
<div class="talk-page">
  <?php if ($comment_count == 0): ?>
    <div class="talk-page-empty-message">
      <?php print t('There are currently no comments on this page.'); ?>
    </div>
  <?php endif; ?>
  <?php print $comments; ?>
</div>
