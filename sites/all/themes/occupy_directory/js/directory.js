directory = {};

Drupal.behaviors.occupy_directory = {

  closeActiveFacetListing: function(){
    if( Drupal.behaviors.occupy_directory.activeFacetDrawer ){
      Drupal.behaviors.occupy_directory.activeFacetDrawer.removeClass('active');
      Drupal.behaviors.occupy_directory.activeFacetDrawer = null;
    }
  },

	attach: function (context, settings) {

    // console.log( 'context', context );
    // console.log( 'settings', settings );
    /* 
      Let's detect whether device relies on touches or clicks, then sets event strings accordingly 
      @Todo, see about handling 'mouseout' if 'touchend' outside target.
    */
    // Defaults
    Drupal.behaviors.occupy_directory.settings = {
      click_string: 'click',
      hover_string: 'mouseover',
      device: 'mouse'
    }

    // If device supports  touch we set our event strings to be touch events
    if ("ontouchstart" in document.documentElement) {
      Drupal.behaviors.occupy_directory.settings.click_string = 'touchend';
      Drupal.behaviors.occupy_directory.settings.hover_string = 'touchstart';
      Drupal.behaviors.occupy_directory.settings.device = 'touch';
    }

    if( jQuery('.flyoutmenu') && Drupal.behaviors.occupy_directory.settings.device == 'touch'){
  
      jQuery( '.flyoutmenu' ).each( function() {
        jQuery( this ).bind( Drupal.behaviors.occupy_directory.settings.click_string, function( e ){
          if( e ) e.preventDefault();
          jQuery( this ).addClass('active');
        });
      });

    }

    var comments = jQuery("#comments");
  
    if( comments ){
      console.log( "comments", comments );
      var suggestAndEditButton = jQuery('.ds-right .links.inline .comment-add a');
      suggestAndEditButton.bind( Drupal.behaviors.occupy_directory.settings.click_string, function( e ) {
        e.preventDefault();
        comments.addClass('visible');
      }); 

      console.log( "suggestAndEditButton", suggestAndEditButton );

      var suggestedEditLogToggle = jQuery( '#suggested-edit-log-toggle' );

      if( suggestedEditLogToggle ){

        suggestedEditLogToggle.bind( Drupal.behaviors.occupy_directory.settings.click_string, function( e ) {
          e.preventDefault();
          if( jQuery( this ).html().indexOf( 'Show') > -1 ){
            jQuery( this ).html('Hide previous suggestions');
          }else{
            jQuery( this ).html('Show previous suggestions');
          }
          jQuery( this ).toggleClass('open');
          jQuery( '#suggested-edit-log').toggle( 350 );
        });

      }

    }

    if( context.location && context.location.pathname && context.location.pathname == "/search" ){

      // store a reference to the current active drawer
      var activeDrawer = Drupal.behaviors.occupy_directory.activeFacetDrawer;

      // if you click outside the facet drawer it closes the current active facet drawer
      jQuery( 'body' ).click( function( e ){
        Drupal.behaviors.occupy_directory.closeActiveFacetListing();
      });


      // Loop through each facet block
      jQuery( '.block-facetapi' ).each( function() { 

        var currentBlock = jQuery( this );

        // Add a close link if none exists and append it to the drawer
        if( !currentBlock.find( '.content a.close' ).length > 0 ){
          // create anchor tag
          var closeLink = jQuery( '<a>', {
            href: '#',
            title: 'Dismiss this search filter',
            text: 'Close'
          }).appendTo( currentBlock.find('.content') );
          // add the click event to close it
          closeLink.bind( Drupal.behaviors.occupy_directory.settings.click_string, function( e ){
            e.stopPropagation();
            Drupal.behaviors.occupy_directory.closeActiveFacetListing();
          });
        }

        // Add events so that when you click on a facet header we hide any active ones and show the new one
        jQuery( this ).bind( Drupal.behaviors.occupy_directory.settings.click_string , function( e ){
          // prevent click from registering
          // this prevents the click attached to body (mean to close the drawer on close outside) from being fired
          e.stopPropagation();
          // close the active listing (we've made this method part of Drupal.behaviors.occupy_directory so that other classes can also call it)
          Drupal.behaviors.occupy_directory.closeActiveFacetListing();
          // now we show the clicked drawer
          jQuery( this ).addClass('active');
          // and we set activeDrawer to the new reference.
          Drupal.behaviors.occupy_directory.activeFacetDrawer = jQuery( this );
        });
      });

    }


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
