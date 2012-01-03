/**
 * @file
 * JS Implementation of OpenLayers behavior.
 */
(function($) {
  /**
   * Geofield Behavior
   */
  Drupal.behaviors.openlayers_behavior_geofield = {
    'attach': function(context, settings) {
      var data = $(context).data('openlayers'),
          behavior = data && data.map.behaviors['openlayers_behavior_geofield'],
          dataProjection = new OpenLayers.Projection('EPSG:4326'),
          features, wktFormat;

      // helper to create a WKT format object with the right projections
      function initWktFormat (inp, outp) {
        var WktWriter = new OpenLayers.Format.WKT();
        WktWriter.internalProjection = inp;
        WktWriter.externalProjection = outp || dataProjection;
        return WktWriter;
      }

      // populate our wkt input field
      function updateWKTField (features) {
        var WktWriter = initWktFormat(features.object.map.projection);
        // limits are to be checked server-side, not here.
        // for a single shape avoid GEOMETRYCOLLECTION
        var toSerialize = features.object.features;
        // don't serialize empty feature
        if (toSerialize.length) {
          if (toSerialize.length === 1) { toSerialize = toSerialize[0]; }
          this.val(WktWriter.write(toSerialize));
        }
        // but clear the value
        else {
          this.val('');
        }
      }

      if (behavior && !$(context).hasClass('geofield-processed')) {
        // we get the .form-item wrapper which is a slibling of our hidden input
        var $wkt = $(context).closest('.form-item').parent().find('input.geofield_wkt');
        var dataLayer = new OpenLayers.Layer.Vector(Drupal.t('Feature Layer'), {
              projection: dataProjection,
              drupalID: 'openlayers_behavior_geofield'
            });

        dataLayer.styleMap = Drupal.openlayers.getStyleMap(data.map, 'openlayers_behavior_geofield');
        data.openlayers.addLayer(dataLayer);

        if ($wkt.val() != '') {
          wktFormat = initWktFormat(data.openlayers.projection);
          features = wktFormat.read($wkt.val());
          dataLayer.addFeatures(features);
        }

        // registering events late, because adding data
        // would result in a reprojection loop
        dataLayer.events.register('featureadded', $wkt, updateWKTField);
        dataLayer.events.register('featureremoved', $wkt, updateWKTField);
        dataLayer.events.register('featuremodified', $wkt, updateWKTField);

        // create toolbar
        var control = new OpenLayers.Control.EditingToolbar(dataLayer);
        data.openlayers.addControl(control);
        control.activate();

        // Add modify feature tool
        control.addControls(new OpenLayers.Control.ModifyFeature(
          dataLayer, {
            displayClass: 'olControlModifyFeature',
            deleteCodes: [46, 68, 100],
            handleKeypress: function(evt) {
              if (this.feature && $.inArray(evt.keyCode, this.deleteCodes) > -1) {
                // We must unselect the feature before we delete it
                var feature_to_delete = this.feature;
                this.selectControl.unselectAll();
                this.layer.removeFeatures([feature_to_delete]);
              }
            }
          }));

        // on submit recalculate everything to be up to date
        var formData = {
          'control': control, 
          'dataLayer': dataLayer
        };
        function handleSubmit (e) {
          $.map(e.data.control.controls, function(c) { c.deactivate(); });
          dataLayer.events.triggerEvent('featuremodified');
        }
        $(context).parents('form').bind('submit', formData, handleSubmit);

        $(context).addClass('geofield-processed');
      } // if
    }
  };
})(jQuery);
