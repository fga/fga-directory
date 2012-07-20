-- SUMMARY --

The Search API location module adds the possibility of location based searching 
to the Search API module.
Currently only Apache Solr is supported as server.

-- REQUIREMENTS --

- a content type /entity with a latlng field (currently geofield is supported,
  Location fields probably work, bu I haven't tested it yet)
- apache solr server 3.1+ (I only tested with 3.3 en 3.4, but location search is
  included since 3.1)
- latest dev of search_api, search_api_solr and search_api_page

-- INSTALLATION --

- put the module in sites/all/modules folder.
- apply search_api_solr-compatibility-with-search_api_location.patch to the
  search_api_solr module. 
- update the schema.xml of solr with the version from the module
- enable the module
- add/modify a Search API index
  - add a latitude/longitude field on the 'fields' tab of the index. The field
    must return a latlng pair separated with a comma
  - enable the location search processor and select the field it has to run on
    on the 'workflow' tab of the index
- add a new search page and select the index with the enabled location search
  processor
  - select the default settings (default point, min/max radius, stepping and
    unit of measurement). The slider doesn't change automatically to the new
    values (yet). So you have to edit the search page twice if you want to
    select a radius that fits the min/max radius, stepping and unit of
    measurement)
- go to your search page a search with location based abilities :)
 
-- CONTACT --

Current maintainers:
* Mollux - http://drupal.org/user/785804
