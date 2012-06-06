
/**
 * @file
 * Layer handler for XYZ layers
 */

/**
 * Openlayer layer handler for XYZ layer
 */
Drupal.openlayers.layer.xyz = function(title, map, options) {
  var styleMap = Drupal.openlayers.getStyleMap(map, options.drupalID);
  if (options.maxExtent !== undefined) {
    options.maxExtent = new OpenLayers.Bounds.fromArray(options.maxExtent) || new OpenLayers.Bounds(-20037508.34, -20037508.34, 20037508.34, 20037508.34);
  }
  options.projection = 'EPSG:' + options.projection;

  // Legacy goodnes
  if (typeof options.base_url == 'string' && typeof options.url == 'undefined') {
    options.url = options.base_url;
  }

  // Server resolutions are very particular in OL 2.11
  var r = options.serverResolutions;
  if (r == null || typeof r == 'undefined' || r.length == 0) {
    options.serverResolutions = null;
  }

  // Wrap Date Line does not seem to work for 2.10.  This may
  // have something to do with our extent definitions.
  if (OpenLayers.VERSION_NUMBER.indexOf('2.10') >= 0) {
    options.wrapDateLine = null;
  }

  options.getURL = function (bounds) {
    var xyz = this.getXYZ(bounds);

    // Fixed the -1 zoom level error in openlayers 2.11.
    var res = this.map.getResolution();
    var resolutions = this.serverResolutions || this.resolutions;
    var z = this.zoomOffset == 0 ?
            (OpenLayers.Util.indexOf(resolutions, res) != -1 ? OpenLayers.Util.indexOf(resolutions, res) : this.map.getZoom() + this.zoomOffset) :
            this.map.getZoom() + this.zoomOffset;
    xyz.z = z;

    var url = this.url;
    if (OpenLayers.Util.isArray(url)) {
        var s = '' + xyz.x + xyz.y + xyz.z;
        url = this.selectUrl(s, url);
    }

    return OpenLayers.String.format(url, xyz);
  }

  var layer = new OpenLayers.Layer.XYZ(title, options.url, options);
  layer.styleMap = styleMap;
  return layer;
};