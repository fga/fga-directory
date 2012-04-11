<article<?php print $attributes; ?>>
  <?php print $user_picture; ?>
  
  <?php if (!$page && $title): ?>
  <header>
    <?php print render($title_prefix); ?>
    <h2<?php print $title_attributes; ?>><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></h2>
    <?php print render($title_suffix); ?>
    <?php //print render($content['field_occupation_origin_date']); ?>
  </header>
  <?php endif; ?>
  
  <?php if ($display_submitted): ?>
  <footer class="submitted"><?php print $date; ?> -- <?php print $name; ?></footer>
  <?php endif; ?>  
  
  <div class="content-grid container-12">
    <div<?php print $content_attributes; ?>>
      <?php
        // We hide the comments and links now so that we can render them later.
        hide($content['comments']);
        hide($content['links']);
        hide($content['group_links_social']);
        hide($content['group_links_news']);
        hide($content['group_links_resources']);
        hide($content['group_links_media']);
        hide($content['group_donate_info']);
        //hide($content['field_occupation_origin_date']);
        print render($content);
      ?>
      
      <div class="clearfix">
    <?php if (!empty($content['links'])): ?>
      <nav class="links node-links clearfix"><?php print render($content['links']); ?></nav>
    <?php endif; ?>

    <?php print render($content['comments']); ?>
  </div>
      
    </div>
    
    <div class="occupy-links-primary grid-3">
      <?php
        print render($content['group_links_social']);
        print render($content['group_links_media']);
        ?>
    </div>
    <div class="occupy-links-secondary grid-3">
      <?php
        print render($content['group_links_news']);
        print render($content['group_links_resources']);
        ?>
    </div>
    <div class="occupy-links-tertiary grid-6">
      <?php
        print render($content['group_donate_info']);
        ?>
    </div>
  </div>
</article>