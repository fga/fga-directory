jQuery(document).ready(function($) {

	var url = 'http://api.tiles.mapbox.com/v3/occupy.occupy-streets.jsonp';
	var m;

	wax.tilejson(url, function(tilejson) {
	  m = new MM.Map( 'map', new wax.mm.connector(tilejson));
	  wax.mm.interaction()
	    .map(m)
	    .tilejson(tilejson)
	    .on( wax.movetip().parent( m.parent ).events() );
	  m.setZoomRange( 1.9, 6);
	  m.setCenterZoom({ lat: 0, lon: 0 }, 3 );
	});

	$(function() {

		// Zoom into location
		function geocode(query) {
			$.ajax({
				url: 'http://open.mapquestapi.com/nominatim/v1/search?format=json&json_callback=callback&limit=1&q=' + query,
				dataType: 'jsonp',
				jsonpCallback: 'callback',
				success: function (value) {
					value = value[0];
					if (value === undefined) {
						alert('The search you tried did not return a result.');
					} else {
						easey().map(m)
						.to(m.locationCoordinate({ lat: value.lat, lon: value.lon })
						.zoomTo(6))
						.run(4000);
					}
				}
			});
		}

		var input = $('input.search');
		$('form.location').submit(function (e){
			e.preventDefault();
			var inputValue = input.val(),
			encodedInput = encodeURIComponent(inputValue);
			geocode(encodedInput);
		});

	});

})

