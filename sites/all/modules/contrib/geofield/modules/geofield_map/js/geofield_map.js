(function ($) {
  Drupal.behaviors.geofieldMap = {
    attach: function(context) {
      var settings = Drupal.settings.geofieldMap;

      $('.geofieldMap:not(.processed)').each(function(index, element) {
        var data = undefined;
        var map_settings = [];
        var pointCount = 0;
        for (var i in settings) {
          if (settings[i].map_id == $(element).attr('id')) {
            data = settings[i].data;
            map_settings = settings[i].map_settings;
            break;
          }
        }

        if (data != undefined) {
          var markers = [];

          // controltype
          var controltype = map_settings.controltype;
          if (controltype == 'default') { controltype = google.maps.ZoomControlStyle.DEFAULT; }
          else if (controltype == 'small') { controltype = google.maps.ZoomControlStyle.SMALL; }
          else if (controltype == 'large') { controltype = google.maps.ZoomControlStyle.LARGE; }
          else { controltype = false }

          // map type
          var maptype = map_settings.maptype;
          if (maptype) {
            if (maptype == 'map' && map_settings.baselayers_map) { maptype = google.maps.MapTypeId.ROADMAP; }
            if (maptype == 'satellite' && map_settings.baselayers_satellite) { maptype = google.maps.MapTypeId.SATELLITE; }
            if (maptype == 'hybrid' && map_settings.baselayers_hybrid) { maptype = google.maps.MapTypeId.HYBRID; }
            if (maptype == 'physical' && map_settings.baselayers_physical) { maptype = google.maps.MapTypeId.TERRAIN; }
          }
          else { maptype = google.maps.MapTypeId.ROADMAP; }

          // menu type
          var mtc = map_settings.mtc;
          if (mtc == 'standard') { mtc = google.maps.MapTypeControlStyle.HORIZONTAL_BAR; }
          else if (mtc == 'menu' ) { mtc = google.maps.MapTypeControlStyle.DROPDOWN_MENU; }
          else { mtc = false; }

          var myOptions = {
            zoom: parseInt(map_settings.zoom),
            mapTypeId: maptype,
            mapTypeControl: (mtc ? true : false),
            mapTypeControlOptions: {style: mtc},
            zoomControl: ((controltype !== false) ? true : false),
            zoomControlOptions: {style: controltype},
            panControl: (map_settings.pancontrol ? true : false),
            scrollwheel: (map_settings.scrollwheel ? true : false),
            draggable: (map_settings.draggable ? true : false),
            overviewMapControl: (map_settings.overview ? true : false),
            overviewMapControlOptions: {opened: (map_settings.overview_opened ? true : false)},
            streetViewControl: (map_settings.streetview_show ? true : false),
            scaleControl: (map_settings.scale ? true : false),
            scaleControlOptions: {style: google.maps.ScaleControlStyle.DEFAULT}
          };

          var map = new google.maps.Map(document.getElementById($(element).attr('id')), myOptions);

          var range = new google.maps.LatLngBounds();

          var infowindow = new google.maps.InfoWindow({
            content: ''
          });

          for (var i in data) {
            switch (data[i].type) {
              case 'point':
                var point = new google.maps.LatLng(data[i].points[0]['lat'], data[i].points[0]['lon']);
                range.extend(point);
                pointCount++;

                var marker = new google.maps.Marker({
                  position: point,
                  map: map,
                  title: "test"
                });

                if (data[i].icon != undefined) {
                  marker.setIcon(data[i].icon);
                }
                marker.setValues({'data_id': i});

                if (data[i].points[0]['text'] !== '') {
                  google.maps.event.addListener(marker, 'click', function() {
                    if (data[this.data_id].points[0].text) {
                      infowindow.setContent(data[this.data_id].points[0].text);
                      infowindow.open(map, this);
                    }
                  });
                }

              break;
              case 'linestring':
                var linestring = [];
                for (var j in data[i].points) {
                  var point = new google.maps.LatLng(data[i].points[j]['lat'], data[i].points[j]['lon']);
                  range.extend(point);
                  pointCount++;
                  linestring.push(point);
                }
                var linestringObject = new google.maps.Polyline({
                  path: linestring
                });

                linestringObject.setMap(map);
              break;
              case 'polygon':
                var polygon = [];
                for (var j in data[i].points) {
                  var point = new google.maps.LatLng(data[i].points[j]['lat'], data[i].points[j]['lon']);
                  range.extend(point);
                  pointCount++;
                  polygon.push(point);
                }
                var polygonObject = new google.maps.Polygon({
                  paths: polygon
                });

                polygonObject.setMap(map);
              break;
            }
          }

          if (pointCount == 0) {

          }
          else if (pointCount > 1) {
            map.fitBounds(range);
          } else {
            map.setCenter(range.getCenter());
          }
        }

        $(element).addClass('processed');
      });
    }
  }
})(jQuery);
