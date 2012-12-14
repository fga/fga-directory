
Drupal.behaviors.occupy_directory = {
	attach: function(context, settings){
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
                // How much to remove from the inner content to make space for the
                // theming.
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
                console.log( "ESCAPE!");
                Drupal.CTools.Modal.dismiss();
                jQuery(document).unbind( 'keydown.modalclose' );
              }
            });

            jQuery('span.modal-title', Drupal.CTools.Modal.modal).html(Drupal.CTools.Modal.currentSettings.loadingText);
            Drupal.CTools.Modal.modalContent(Drupal.CTools.Modal.modal, settings.modalOptions, settings.animation, settings.animationSpeed);
            jQuery('#modalContent .modal-content').html(Drupal.theme(settings.throbberTheme));
          }
          //////////
        }
      );
    }
	}
}
