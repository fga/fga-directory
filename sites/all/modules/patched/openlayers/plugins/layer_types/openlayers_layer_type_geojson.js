/**
 * @file
 * Layer handler for GeoJSON layers
 */

/**
 * Openlayer layer handler for KML layer
 */
(function($) {

Drupal.openlayers.layer.geojson = function(title, map, options) {
  var features = null;
  options.projection = 'EPSG:' + options.projection;
  options.styleMap = Drupal.openlayers.getStyleMap(map, options.drupalID);

  // GeoJSON Projection handling
  var geojson_options = {
    'internalProjection': new OpenLayers.Projection('EPSG:' + map.projection),
    'externalProjection': new OpenLayers.Projection(options.projection)
  };

  // If GeoJSON data is provided with the layer, use that.  Otherwise
  // check if BBOX, then finally use AJAX method.
  if (options.geojson_data) {
    var layer = new OpenLayers.Layer.Vector(title, options);
  
    // Read data in.
    features = new OpenLayers.Format.GeoJSON(geojson_options).read(options.geojson_data);
    if (features) {
      // If not array (ie only one feature)
      if (features.constructor != Array) {
        features = [features];
      }
    }

    // Add features, if needed
    if (features) {
      layer.addFeatures(features);
    }
  }
  else if (options.useBBOX) {
    options.strategies = [ new OpenLayers.Strategy.BBOX() ];
    options.protocol = new OpenLayers.Protocol.HTTP({
      url: options.url,
      format: new OpenLayers.Format.GeoJSON(),
    });
    var layer = new OpenLayers.Layer.Vector(title, options);
  }
  else {
    var layer = new OpenLayers.Layer.Vector(title, options);
  
    // Use an AJAX like call to get data from URL
    OpenLayers.loadURL(options.url, {}, null, function (response) {
      var format = new OpenLayers.Format.GeoJSON(geojson_options);
      var features = format.read(response.responseText);
      // Add features, if needed
      if (features) {
        layer.addFeatures(features);
      }
    });
  }

  return layer;
};

})(jQuery);



