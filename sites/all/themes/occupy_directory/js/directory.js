directory = {};

Drupal.behaviors.occupy_directory = {

	attach: function (context, settings) {


    /* 
      Let's detect whether device relies on touches or clicks, then sets event strings accordingly 
      @Todo, see about handling 'mouseout' if 'touchend' outside target.
    */
    // Defaults
    directory.settings = {
      click_string: 'click',
      hover_string: 'mouseover',
      device: 'mouse'
    }
    // If device supports  touch we set our event strings to be touch events
    if ("ontouchstart" in document.documentElement) {
      directory.settings.click_string = 'touchend';
      directory.settings.hover_string = 'touchstart';
      directory.settings.device = 'touch';
    }

    var facetSidebar = jQuery( '.solr-search #region-sidebar-first' );
    var results = jQuery( '#region-content' );

    if ( facetSidebar[0] ) {

      function resize_sidebar() {
        var h = jQuery( results ).height();
        facetSidebar.css( { 'height': h } );
      }

      resize_sidebar();

      jQuery(window).resize( function() {
        resize_sidebar();
      });

    }

    if( jQuery('.flyoutmenu') && directory.settings.device ){
  
      jQuery( '.flyoutmenu' ).each( function() {
        this.bind( 'touchstart', function( e ){
          jQuery( this ).addClass('active');
        });        
        this.bind( 'touchstart', function( e ){
          jQuery( this ).addClass('active');
        });        
      });

    }

    /* A quick hack that replaces # with %23 in twitter hash URLS */
    jQuery( 'a.twitterhash_js_hook' ).each( function() {
      var href = jQuery( this ).attr( 'href' ).replace( 'search/#', 'search/%23' );
      jQuery(this).attr('href', href );
    });

    /* Setting up search result title to also trigger the .ds-left hover that shows the description if present */
    jQuery( '.search-result' ).each( function() {
      var el, title, hover_string, click_string;
      hover_string = Drupal.behaviors.occupy_directory.settings.hover_string;
      click_string = Drupal.behaviors.occupy_directory.settings.click_string;
      el = jQuery( this );
      title = jQuery( el.find( 'h3.org.title' ));
      console.log( 'el', el );
      console.log( 'title', title );
      // Hover
      el.bind( hover_string , function(e) {
        var left_el = jQuery( this ).find( '.ds-left' );
        console.log( left_el );
        left_el.hover();
        left_el = null;
      });
      // el.bind( click_string, function(e) {
      //   console.log("::::", document.elementFromPoint(e.pageX, e.pageY));
      //   left_el.addClass('active');
      //   e.preventDefault();
      // });
      // clean up so we don't inadvertently spill memory.
      el = title = null;
    });

    /*
    Overriding Drupal.CTools.Modal.show, to bind esc to 'dismiss' on show and unbind the keydown on hide
    */
    if( Drupal.CTools && Drupal.CTools.Modal ){
      jQuery.extend(
        Drupal.CTools.Modal,
        { 
          show: function( choice ){
            
            var opts = {};

            if (choice && typeof choice == 'string' && Drupal.settings[choice]) {
              // This notation guarantees we are actually copying it.
              jQuery.extend(true, opts, Drupal.settings[choice]);
            } else if (choice) {
              jQuery.extend(true, opts, choice);
            }

            var defaults = {
              modalTheme: 'CToolsModalDialog',
              throbberTheme: 'CToolsModalThrobber',
              animation: 'show',
              animationSpeed: 'fast',
              modalSize: {
                type: 'scale',
                width: .8,
                height: .8,
                addWidth: 0,
                addHeight: 0,
                // How much to remove from the inner content to make space for the theming.
                contentRight: 25,
                contentBottom: 45
              },
              modalOptions: {
                opacity: .55,
                background: '#fff'
              }
            };

            var settings = {};
            jQuery.extend(true, settings, defaults, Drupal.settings.CToolsModal, opts);

            if (Drupal.CTools.Modal.currentSettings && Drupal.CTools.Modal.currentSettings != settings) {
             Drupal.CTools.Modal.modal.remove();
             Drupal.CTools.Modal.modal = null;
            }

            Drupal.CTools.Modal.currentSettings = settings;

            var resize = function(e) {
              // When creating the modal, it actually exists only in a theoretical
              // place that is not in the DOM. But once the modal exists, it is in the
              // DOM so the context must be set appropriately.
              var context = e ? document : Drupal.CTools.Modal.modal;

              if (Drupal.CTools.Modal.currentSettings.modalSize.type == 'scale') {
                var width = jQuery(window).width() * Drupal.CTools.Modal.currentSettings.modalSize.width;
               var height = jQuery(window).height() * Drupal.CTools.Modal.currentSettings.modalSize.height;
              } else {
                var width = Drupal.CTools.Modal.currentSettings.modalSize.width;
                var height = Drupal.CTools.Modal.currentSettings.modalSize.height;
              }

              // Use the additionol pixels for creating the width and height.
              jQuery('div.ctools-modal-content', context).css({
                'width': width + Drupal.CTools.Modal.currentSettings.modalSize.addWidth + 'px',
               'height': height + Drupal.CTools.Modal.currentSettings.modalSize.addHeight + 'px'
              });
              jQuery('div.ctools-modal-content .modal-content', context).css({
               'width': (width - Drupal.CTools.Modal.currentSettings.modalSize.contentRight) + 'px',
               'height': (height - Drupal.CTools.Modal.currentSettings.modalSize.contentBottom) + 'px'
              });
            }

            if (!Drupal.CTools.Modal.modal) {
             Drupal.CTools.Modal.modal = jQuery(Drupal.theme(settings.modalTheme));
             if (settings.modalSize.type == 'scale') {
               jQuery(window).bind('resize', resize);
             }
            }

            resize();
            jQuery(document).bind( 'keydown.modalclose', function( e ){
              if( e.which == 27 ){
                Drupal.CTools.Modal.dismiss();
                jQuery(document).unbind( 'keydown.modalclose' );
              }
            });

            jQuery('span.modal-title', Drupal.CTools.Modal.modal).html(Drupal.CTools.Modal.currentSettings.loadingText);
            Drupal.CTools.Modal.modalContent(Drupal.CTools.Modal.modal, settings.modalOptions, settings.animation, settings.animationSpeed);
            jQuery('#modalContent .modal-content').html(Drupal.theme(settings.throbberTheme));
          }
        }
      );
    }
	}
}
