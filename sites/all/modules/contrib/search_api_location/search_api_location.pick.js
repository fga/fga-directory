

(function ($) {

  var geocoder;
  Drupal.searchapilocation = new Object();
  Drupal.searchapilocation.maps = new Array();
  Drupal.searchapilocation.markers = new Array();
  Drupal.searchapilocation.circles = new Array();

  geocoder = new google.maps.Geocoder();

  var lat;
  var lng;
  var latLng;
  var myOptions;
  var browserSupportFlag =  new Boolean();
  var singleClick;
  var circle;


/**
   * Set the latitude and longitude values to the input fields
   * And optionaly update the address field
   *
   * @param latLng
   *   a location (latLng) object from google maps api
   * @param i
   *   the index from the maps array we are working on
   * @param op
   *   the op that was performed
   */
  Drupal.searchapilocation.codeLatLng = function(latLng, i, op) {

    // Update the lat and lng input fields
    $('#'  + i + '-lat').val(latLng.lat());
    $('#'  + i + '-lng').val(latLng.lng());
 
    // Update the address field
    if ((op == 'marker' || op == 'geocoder') && geocoder) {

      geocoder.geocode({ 'latLng' : latLng }, function(results, status) {

        if (status == google.maps.GeocoderStatus.OK) {
          $("#" + i + "-address").val(results[0].formatted_address);        
        }
        else {
          $("#" + i + "-address").val('');
          if (status != google.maps.GeocoderStatus.ZERO_RESULTS) {
            alert(Drupal.t('Geocoder failed due to: ') + status);
          }
        }
      });
    }
  }
 
  /**
   * Get the location from the address field
   *
   * @param i
   *   the index from the maps array we are working on
   */
  Drupal.searchapilocation.codeAddress = function(i) {
    var address = $("#" + i + "-address").val();
    
    geocoder.geocode( { 'address': address }, function(results, status) {
      if (status == google.maps.GeocoderStatus.OK) {
        Drupal.searchapilocation.maps[i].setCenter(results[0].geometry.location);
        Drupal.searchapilocation.setMapMarker(results[0].geometry.location, i);
        Drupal.searchapilocation.codeLatLng(results[0].geometry.location, i, 'textinput');      
      } else {
        alert(Drupal.t('Geocode was not successful for the following reason: ') + status);
      }
    });
  }
   
  /**
   * Set/Update a marker on a map
   *
   * @param latLng
   *   a location (latLng) object from google maps api
   * @param i
   *   the index from the maps array we are working on
   */
  Drupal.searchapilocation.setMapMarker = function(latLng, i) {
    // remove old marker and circle    
    if (Drupal.searchapilocation.markers[i]) {
      Drupal.searchapilocation.markers[i].setMap(null);
      Drupal.searchapilocation.circles[i].setMap(null);
    }
    
    // add marker
    Drupal.searchapilocation.markers[i] = new google.maps.Marker({
      map: Drupal.searchapilocation.maps[i],
      draggable: true,
      animation: google.maps.Animation.DROP,
      position: latLng
    });
    
    var measure = 1;

    if(Drupal.settings.searchapilocation[i].radius_measure == "km")
      measure = 1000;
    else if(Drupal.settings.searchapilocation[i].radius_measure == "mi")
      measure = 1609.344;

    
    // add circle
    //TODO : allow other distances than kilometer
    //TODO : allow custom colors
    Drupal.searchapilocation.circles[i] = new google.maps.Circle({
      map: Drupal.searchapilocation.maps[i],
      clickable:false, 
      strokeColor:'#ffcc00', 
      fillColor:'#cc3300', 
      radius: $("#" + i + "-slider").slider( "value" ) * measure, 
      center: latLng
    });

    // fit the map to te circle
    Drupal.searchapilocation.maps[i].fitBounds(Drupal.searchapilocation.circles[i].getBounds()); 
    
    return false; // if called from <a>-Tag
  }

  // Work on each map
  $.each(Drupal.settings.searchapilocation, function(i, searchapilocation) {

      
      $("#"+ i +'-gmap').once('process', function(){
        
        lat = parseFloat(searchapilocation.lat);
        lng = parseFloat(searchapilocation.lng);
                     
        latLng = new google.maps.LatLng(lat, lng);

        // Set map options
        myOptions = {
          zoom: 2,
          center: latLng,
          mapTypeId: google.maps.MapTypeId.ROADMAP,
          scrollwheel: false
        }

        // Create map
        Drupal.searchapilocation.maps[i] = new google.maps.Map(document.getElementById(i + "-gmap"), myOptions);

        // create slider
    		$("#" + i + "-slider").slider({
	        value:$("#" + i + "-radius").val(),
	        min: parseFloat(searchapilocation.radius_min),
	        max: parseFloat(searchapilocation.radius_max),
	        step: parseFloat(searchapilocation.radius_step),
	        slide: function( event, ui ) {
		        $("#"+ i +"-radius").val( ui.value );
		        Drupal.searchapilocation.setMapMarker(Drupal.searchapilocation.markers[i].getPosition(), i);
	        },
	        
	        stop: function( event, ui ) {
	          $("#"+ i +"-radius").val( ui.value );
	        }
	        
	        
        });

	      $("#" + i + "-radius").val($("#" + i + "-slider").slider( "value" ) );


        if (lat && lng) {
          // Set initial marker
          Drupal.searchapilocation.setMapMarker(latLng, i);
          Drupal.searchapilocation.codeLatLng(latLng, i, 'geocoder');
        }
        
        $("#" + i + "-geocode").click(function(e) {
          Drupal.searchapilocation.codeAddress(i);
        });          
        
        // trigger on enter key
        $("#" + i + "-address").keypress(function(ev){
          if(ev.which == 13){
            ev.preventDefault();
            Drupal.searchapilocation.codeAddress(i);
          }
        });
        
        // Listener to click
        google.maps.event.addListener(Drupal.searchapilocation.maps[i], 'click', function(me){
          // Set a timeOut so that it doesn't execute if dbclick is detected
          singleClick = setTimeout(function(){
            Drupal.searchapilocation.codeLatLng(me.latLng, i, 'marker');
            Drupal.searchapilocation.setMapMarker(me.latLng, i);
          }, 500);
        });

        // Detect double click to avoid setting marker
        google.maps.event.addListener(Drupal.searchapilocation.maps[i], 'dblclick', function(me){
          clearTimeout(singleClick);
        });
        
        // Listener to dragend
        google.maps.event.addListener(Drupal.searchapilocation.markers[i], 'dragend', function(me){

            Drupal.searchapilocation.codeLatLng(me.latLng, i, 'marker');
            Drupal.searchapilocation.setMapMarker(me.latLng, i);
        });
        
      })  
    });
}
)(jQuery);

