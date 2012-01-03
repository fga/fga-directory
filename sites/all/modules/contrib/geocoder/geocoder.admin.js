jQuery(document).ready(function(){
	geocoder_admin_handler_filter();
});

function geocoder_admin_handler_filter() {
  var field = jQuery('#edit-instance-widget-settings-geocoder-field').val();
  var field_type = Drupal.settings.geocoder_widget_settings.types[field];
  var valid_handlers = Drupal.settings.geocoder_widget_settings.handlers[field_type];
  
  // Filter the options list to ones that are valid for this field
  jQuery('#edit-instance-widget-settings-geocoder-handler option').each(function() {
  	handler_type = jQuery(this).val();
  	if (geocoder_admin_handler_in_array(handler_type,valid_handlers)) {
  	  jQuery(this).css('display','inline');
  	}
  	else {
  		jQuery(this).css('display','none');
  	}
  });
  
  // If the currently selected handler is not valid, set it to the first valid handler
  if (!geocoder_admin_handler_in_array(jQuery('#edit-instance-widget-settings-geocoder-handler').val(),valid_handlers)) {
  	jQuery('#edit-instance-widget-settings-geocoder-handler').val(valid_handlers[0]);
  }
}

function geocoder_admin_handler_in_array(needle, haystack) {
  var length = haystack.length;
  for(var i = 0; i < length; i++) {
    if(haystack[i] == needle) return true;
  }
  return false;
}
