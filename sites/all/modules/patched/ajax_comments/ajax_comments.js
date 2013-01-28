(function ($) {

Drupal.behaviors.ajaxComments = {
  attach: function(context, settings) {

    // Responds to submission of new comment by the user.
    if ($(context).hasClass('ajax-comment-wrapper')) {
      commentNumber = $(context).attr("id").split('-');
      // Scroll to the comment reply inserted by ajax_command.
      ajaxCommentsScrollReply(commentNumber[2])
    }

    // Scroll to the comment reply form when reply is clicked.
    $("a.ajax-comment-reply:not(clicked)").click(function() {
      commentNumber = $(this).attr("id").split('-');
      ajaxCommentsScrollForm(commentNumber[1]);

      // Don't let people reply over and over.
      $(this).hide();

    });

    // Hide comment form if cancel is clicked.
    $("a.ajax-comments-reply-cancel").click(function(e) {
      commentForm = $(this).attr("href");
      // Hide comment form.
      $(commentForm).hide();

      ajaxCommentsScrollReply(commentNumber[1])

      e.preventDefault();

      commentNumber = $(this).attr("id").split('-');
      // This needs to be unbound because the ajax_command callback is still
      // attached to it. We want to show the form that is already hidden
      // instead of calling for a new one.
      $('a#reply-' + commentNumber[3]).addClass('clicked').unbind().attr("href", "#").show().bind({
        click: function(e) {
          commentNumber = $(this).attr("id").split('-');
          // Reshow the form.
          $('[about="/comment/' + commentNumber[1] + '#comment-' + commentNumber[1] + '"]').next().show();

          // Don't let people reply over and over.
          $(this).hide();

          ajaxCommentsScrollForm(commentNumber[1]);
          e.preventDefault();
        },
      });

    });

  }
};

/**
 * Scrolls user to comment reply form.
 */
function ajaxCommentsScrollForm(commentNumber) {
  pos = $('#comment-wrapper-' + commentNumber).offset();
  height = $('#comment-wrapper-' + commentNumber + ' .comment').attr("scrollHeight");

  // Scroll to comment reply form.
  $('html, body').animate({ scrollTop: pos.top + height}, 'fast');
}

/**
 * Scrolls user to comment that has been added to page.
 */
function ajaxCommentsScrollReply(commentNumber) {
  formSize = $('.comment-form').attr("scrollHeight");
  pos = $('#comment-wrapper-' + commentNumber).offset();

  // Scroll to comment reply.
  $('html, body').animate({ scrollTop: pos.top - formSize}, 'slow');
}

}(jQuery));
