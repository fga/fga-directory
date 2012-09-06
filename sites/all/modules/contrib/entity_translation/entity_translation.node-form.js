
(function ($) {

Drupal.behaviors.translationNodeFieldsetSummaries = {
  attach: function (context) {
    $('fieldset#edit-translation', context).drupalSetSummary(function (context) {
      return $('#edit-translation-retranslate', context).is(':checked') ?
        Drupal.t('Flag translations as outdated') :
        Drupal.t('Don\'t flag translations as outdated');
    });
  }
};

})(jQuery);
