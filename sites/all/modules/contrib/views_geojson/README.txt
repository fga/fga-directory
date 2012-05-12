CONTENTS OF THIS FILE
---------------------

* Summary
* Requirements
* Installation
* Usage
* To Do
* Credits
* Current Maintainers


SUMMARY
-------

Views GeoJSON is a style plugin for Views to deliver location-specific data in GeoJSON format, (see GeoJSON spec: http://geojson.org/geojson-spec.html).

Content is output as GeoJSON "Point" features; each row a point including geospatial coordinates (longitude,latitude) and optional metadata. All features are wrapped in a "Feature Collection" object.


REQUIREMENTS
------------

Drupal modules:
* Views - http://drupal.org/project/views
* Libraries - http://drupal.org/project/libraries

3rd-party libraries:
* GeoPHP - https://github.com/phayes/geoPHP

INSTALLATION
------------

Install the module as usual. See http://drupal.org/documentation/install/modules-themes/modules-7 for help.

Views GeoJSON depends on the geoPHP library for converting WKT format data.
Download geoPHP from https://github.com/downloads/phayes/geoPHP/geoPHP.tar.gz
and unpack it into your sites/all/libraries directory.

USAGE
-----

1. Create a View with a Page display on content with geospatial data.
2. Add fields for longitude and latitude data.
3. Optionally add fields for name and description.
4. Set Format for the display to "GeoJSON Feed".
5. In the "Style options" for this format:
  * Choose Map Data Source (Set to Other: Lat/Lon Point.)
  * Assign the fields that represent Latitude and Longitude.
  * Optionally choose fields representing name and description for each point.
  * Optionally set a JSONP prefix, (see http://en.wikipedia.org/wiki/JSONP).
  * Set the Content-type header to be sent. The default is "application/json",
    the standard MIME type for JSON, per http://www.ietf.org/rfc/rfc4627.txt.
  * Optionally enable "Views API mode". By default the plugins stop Drupal from
    doing any additional processing when a view is rendered, allowing the
    content to be output without normal page markup. If you are calling a view
    programatically, enable "Views API mode" to avoid early termination of
    Drupal execution.


TO DO
-----
* Sort out BoundingBox and OpenLayers WKT support.
* Support addditional GeoJSON feature types like LineString.
* Support an optional altitude coordinate for Point positions.
* Support additional coordinate systems.


CREDITS
-------

This module was originally born from a patch by tmcw to the OpenLayers module (http://drupal.org/node/889190#comment-3376628) and adapted to model the Views Datasource module (http://drupal.org/project/views_datasource).

Much of the code is drawn directly from these sources.


CURRENT MAINTAINERS
-------------------

* jeffschuler - http://drupal.org/user/239714