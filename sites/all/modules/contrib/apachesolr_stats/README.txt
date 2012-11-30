README.txt
Apache Solr Statistics module for Drupal.

-- SUMMARY --

Logs user queries submitted to the Solr service configured under Apache Solr
Search Integration module.

For a full description of the module, visit the project page:
  http://drupal.org/project/apachesolr_stats

To submit bug reports and feature suggestions, or to track changes:
  http://drupal.org/project/issues/apachesolr_stats


-- REQUIREMENTS --

Apache Solr Search Integration module.
See http://drupal.org/project/apachesolr


-- INSTALLATION --

* Install as usual, see http://drupal.org/node/70151 for further information.


-- CONFIGURATION AND USAGE --

After enabling the module, all searches done through Apache Solr Search are
automatically logged. You can see the report at:

  Administration >> Reports >> Apache Solr >> Statistics

You can also view the report as a Google Gadget.

You can configure the module at:

 * Administer >> Site Configurarion >> Apache Solr >> Statistics

Where you can configure:

 * Days to mantain in the query log.
   If your site receives heavy use, you should probably keep an eye on your
   database size. More data also means calculations take longer.

 * IP addresses to ignore.
   You can optionally enter a listing of IP addresses you can ignore logging for.
   You could use this to specify IPs for web crawlers or monitoring scripts that
   make sure your site is working.

 * Google Gadget Settings.
   You can configure a secret key to give access to your access report through
   a Google Gadget.

--