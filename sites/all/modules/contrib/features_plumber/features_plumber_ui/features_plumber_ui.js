/**
 * @file
 * Features Plumber js.
 */

(function ($) {

Drupal.behaviors.featuresPlumberUi = {
  attach: function(context) {
    var form = $('#features-export-contents', context);

    $('.features-plumber-ui-plumbable', form).each(function () {
      var item = $(this);
      var component = item.attr('component');
      var componentVal = item.attr('component_val');
      $('input[component="' + component + '"][component_val="' + componentVal + '"]', form).prependTo(item);
    });
  }
}

})(jQuery);
