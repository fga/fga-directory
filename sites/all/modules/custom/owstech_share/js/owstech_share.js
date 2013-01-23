Drupal.behaviors.owstech_share = {

	attach: function(context, settings){
    if ( console && console.log ) console.log( 'Drupal.behaviors.owstech_share', context, settings );
    jQuery( '.drawer ul li a' ).click( function( e ){
      var href, className, win_title, w, h;
      href = jQuery( this ).attr('href');
      className = jQuery( this ).attr('class');
      switch ( className ) {
        case 'icon facebook':
          win_title = 'share_facebook';
          w = 450;
          h = 290;
        break;
        case 'icon twitter':
          win_title = 'share_twitter';
          w = 450;
          h = 380;
        break;
        case 'icon googleplus':
          win_title = 'share_google-plus';
          w = 475;
          h = 180;
        break;
        case 'icon reddit':
          win_title = 'share_reddit';
          w = 450;
          h = 500;
        break;
        default:
          win_title = 'share_popup';
          w = 450;
          h = 290;
        break;
      } 
      window.open( href, win_title, 'width=' + w + ',height=' + h + ',resizeable=1,status=false,toolbar=false,location=false');
      e.preventDefault();
    });

  }

};
