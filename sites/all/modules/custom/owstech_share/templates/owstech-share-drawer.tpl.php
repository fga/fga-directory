<section class="owstech-share">
  <h4 class='actuator'><a title="Share"><?php print $owstech_share_actuator_text;?></a></h4>
  <div class="drawer">
    <ul>

      <!-- @todo, these li's could possibly be turned into a forloop based on the checkbox values from the menu forms -->
      <?php if( $owstech_share_include_facebook ):?>
      <li>
        <a class="icon facebook" rel="nofollow" title="<?php print $share_cta_fb;?>" target="_blank" href="<?php print $share_url_fb;?> ">
          <?php print $share_cta_fb;?>
        </a>
      </li>
      <?php endif;?>

      <?php if( $owstech_share_include_twitter ):?>
      <li>
        <a class="icon twitter" rel="nofollow" title="<?php print $share_cta_twitter;?>" target="_blank" href="<?php print $share_url_twitter;?>">
          <?php print $share_cta_twitter;?>
        </a>
      </li>
      <?php endif;?>

      <?php if( $owstech_share_include_googleplus ):?>
      <li>
        <a class="icon google-plus" rel="nofollow" title="<?php print $share_cta_googleplus;?>" target="_blank" href="<?php print $share_url_googleplus;?>">
          <?php print $share_cta_googleplus;?>
        </a>
      </li>
      <?php endif;?>

      <?php if( $owstech_share_include_reddit ):?>
      <li>
        <a class="icon reddit" rel="nofollow" title="<?php print $share_cta_reddit;?>" target="_blank" href="<?php print $share_url_reddit;?>">
          <?php print $share_cta_reddit;?>
        </a>
      </li>
      <?endif;?>

    </ul>
  </div>
<section>
