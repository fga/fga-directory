
This module is useful for feature development using the Features module[1].
Occasionally the Features module auto detects components that you do not want
exported to features. You can use this module to remove those auto-detected
components from any and all features you choose. The Features Plumber UI module
adds checkboxes to the feature create form, and unchecking these detected
components will cause them to be removed from the actual generated export.

The Features Plumber module itself is light weight, but still is really only
needed in development environments if you so choose (see admin/structure/
features/settings). Also included are some drush command for removing components
from features:

drush features-component-list Examples:

drush fcl example_feature                 List the available components to
                                           remove from example_feature.
drush fcl example_feature dependencies    List the available dependencies to
                                           remove from example_feature.

drush features-component-remove Examples:

drush fcr example_feature views frontpage	Do not export the frontpage view
 						to the example_feature.
drush fcr all views frontpage			Ensure that the frontpage view 
						is never autodetected for any 
						feature.


Please be careful with this module. It is powerful, and needs testing.

[1] http://drupal.org/project/features