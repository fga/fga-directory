// preferred method is to attach jQuery to Drupal.behaviors, that way it can be run anytime new DOM elements are inserted. 
// Since we are using AJAX in Views, each time a section of the page reloads, it will reload/run jQuery.
// see http://drupal.org/node/171213 for more info

(function($) {
Drupal.behaviors.myBehavior = {
  attach: function (context, settings) {

    //code goes here
    
  }
};
})(jQuery);