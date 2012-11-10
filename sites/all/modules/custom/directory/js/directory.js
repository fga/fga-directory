Drupal.behaviors.directory = {

	attach: function(context, settings){

		function resizeMap(){
			var winh = jQuery(window).height();
			var map = jQuery( '#map-embed-wrapper' );
			map.css( { 'width': '100%', 'height': winh - map.offset().top } );				
		}

		if( jQuery( '#map-embed-wrapper' ) ) {
			resizeMap();
			jQuery(window).resize( function(){
				resizeMap();
			});
		}

	}

};