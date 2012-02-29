
(function ($) {

  Drupal.behaviors.suppressPublishedForModeratedContent = {
    attach: function (context) {

      var publishedDiv = $('.form-item-status', context);
      var firstSummaryTab = $('.vertical-tabs span.summary:first', context)
      var lastSummaryTab  = $('.vertical-tabs span.summary:last', context);
      var textNewRevision = Drupal.t('New revision');
      var textNoRevision = Drupal.t('No revision');
      var textPublished = Drupal.t('Published');
      var textNotPublished =  Drupal.t('Not published');
      var checked = $('.form-item-revision-operation .form-radio:checked').val();

      if (checked == 0) { // NO_REVISION
        firstSummaryTab.text(firstSummaryTab.text().replace(textNewRevision, textNoRevision));
      }
      else if (checked == 2) { // NEW_REVISION_WITH_MODERATION
        // Hide the "Published" check-box, as it does not apply in this mode
        // because the new revision will always be unpublished. 
        publishedDiv.hide();
        lastSummaryTab.text(lastSummaryTab.text().replace(textPublished, textNotPublished));
      }

      $('.form-radio').click(function() {
        checked = $('.form-item-revision-operation .form-radio:checked').val();

        if (checked == 2) { // NEW_REVISION_WITH_MODERATION
          publishedDiv.hide();
          lastSummaryTab.text(lastSummaryTab.text().replace(textPublished, textNotPublished));
        }
        else { // NO_REVISION or NEW_REVISION_NO_MODERATTION
          publishedDiv.show();
          if (checked == 0) { // NO_REVISION
            firstSummaryTab.text(firstSummaryTab.text().replace(textNewRevision, textNoRevision));
          }
          if ($('.form-item-status input').is(':checked')) {
            updatedText = lastSummaryTab.text().replace(textNotPublished, textPublished);
          }
          else {
            updatedText = lastSummaryTab.text().replace(textPublished, textNotPublished);
          }
          lastSummaryTab.text(updatedText);
        }

      });
    }
  };

})(jQuery);

