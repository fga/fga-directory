(function($) {
  Drupal.settings.customFormattersAdmin = {};

  Drupal.behaviors.customFormattersAdmin = {
    attach: function(context) {
      // Set initial states.
      if (typeof Drupal.settings.customFormattersAdmin.fieldsets == 'undefined') {
        Drupal.settings.customFormattersAdmin.fieldsets = {};
        this.storeStates();
      }

      if (context !== document) {
        this.restoreStates();
      }
    },

    detach: function(context) {
      this.storeStates();
    },

    storeStates: function() {
      $('fieldset').each(function() {
        id = $(this).attr('id').indexOf('--') > 0 ? $(this).attr('id').substr(0, $(this).attr('id').indexOf('--')) : $(this).attr('id');
        Drupal.settings.customFormattersAdmin.fieldsets[id] = $(this).hasClass('collapsed');
      });
    },

    restoreStates: function() {
      $('fieldset').each(function() {
        id = $(this).attr('id').indexOf('--') > 0 ? $(this).attr('id').substr(0, $(this).attr('id').indexOf('--')) : $(this).attr('id');
        if (Drupal.settings.customFormattersAdmin.fieldsets[id] == false) {
          $(this).removeClass('collapsed');
        }
      });
    }
  }
})(jQuery);
