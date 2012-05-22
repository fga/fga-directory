jQuery(document).ready(function($) {

//	var url = 'http://api.tiles.mapbox.com/v3/occupy.occupy-streets.jsonp';
//  var url = 'http://a.tiles.mapbox.com/v3/occupy.map-7o6g1bgq,occupydirectory.map-9qnjiyrn.jsonp';
	  var url = 'http://a.tiles.mapbox.com/v3/occupydirectory.map-lzygvfea.jsonp';
	  var m;

	wax.tilejson(url, function(tilejson) {
	  m = new MM.Map( 'map', new wax.mm.connector(tilejson));
	  wax.mm.interaction()
	    .map(m)
	    .tilejson(tilejson)
	    .on( wax.movetip().parent( m.parent ).events() );
	  m.setZoomRange( 1.9, 11);
	  m.setCenterZoom({ lat: 19, lon: 9.7 }, 2 );
	  
	  // Add zoom controls [?]
   // wax.mm.zoomer(map, tilejson).appendTo(map.parent);

    // Add interactivity (tooltips)
  //  var interaction = wax.mm.interaction().map(map).tilejson(tilejson)
   //     .on(wax.tooltip().parent(map.parent).events());
    
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
						.zoomTo(8))
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

