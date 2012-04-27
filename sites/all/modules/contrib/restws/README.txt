
--------------------------------------------------------------------------------
                 RESTful Web Services for Drupal (restws)
--------------------------------------------------------------------------------

Maintainers:
 * Wolfgang Ziegler (fago), wolfgang.ziegler@epiqo.com
 * Klaus Purer (klausi), klaus.purer@epiqo.com

Exposes Drupal resources (e.g. entities) as RESTful web services. The module
makes use of the Entity API and the information about entity properties
(provided via hook_entity_property_info()) to provide resource representations.
It aims to be fully compliant to the REST principles.

Installation
------------

 * Copy the whole restws directory to your modules directory
   (e.g. DRUPAL_ROOT/sites/all/modules) and activate the RESTful Web Services
   module.
 * There is no user interface or such needed.

Usage / Testing
---------------

 * To obtain the JSON representation of an entity use your browser to visit

   http://example.com/node/1.json or
   http://example.com/user/1.json or
   http://example.com/<entity type name>/<entity id>.json

   for an example.
   
 * In order to access entities via this interface, permissions must be granted
   for the desired operation (e.g. "access content" or "create content" for
   nodes). Additionally each resource is protected with a RESTWS permission
   that can be configured at "admin/people/permissions#module-restws".


Design goals and concept
------------------------

 * Create a module that simply exposes Drupal's data (e.g. entities) as web
   resources, thus creating a simple RESTful web service. It aims to be fully
   compliant to the REST principles.

 * The module is strictly resource-oriented. No support for message-oriented or
   RPC-style web services.

 * Plain and simple. No need for endpoint configuration, all resources are
   available on the same path pattern. Access via HTTP only.

 * When the module is enabled all entities should be available at the URL path
   /<entity type name>/<entity id>, e.g. /node/123, /user/1 or /profile/789.

 * Resources are represented and exchanged in different formats, e.g. JSON or
   XML. The format has to be specified in every request.
   
 * The module defines resource for all entity types supported by the entity API
   as well as a JSON format. Modules may provide further resources and formats
   via hooks.

 * The module supports full CRUD (Create, Read, Update, Delete) for resources:
 
     * Create: HTTP PUT /<entity type name> (requires HTTP Content-Type header
       set to the MIME type of <format>)

     * Read: HTTP GET /<entity type name>/<entity id>.<format>
       or    HTTP GET /<entity type name>/<entity id> (requires HTTP Accept
       header set to the MIME type of <format>)

     * Update: HTTP POST /<entity type name>/<entity id>.<format>
       or      HTTP POST /<entity type name>/<entity id> (requires HTTP
       Content-Type header set to the MIME type of the posted format)

     * Delete: HTTP DELETE /<entity type name>/<entity id>

 * The representation <format> can be json, xml etc.

 * The usual Drupal permission system is respected, thus permissions are checked
   for the logged in user account of the received requests. 

 * Authentication can be achieved via separate modules, maybe making use of the
   standard Drupal cookie and session handling. The module comes with an
   optional HTTP Basic Authentication module (restws_auth_basic) that performs
   a user login with the credentials provided via the usual HTTP headers.


Debugging
---------

You can enable a debug logging facility by setting a variable in settings.php
(e.g. in DRUPAL_ROOT/sites/default/settings.php):

$conf['restws_debug_log'] = DRUPAL_ROOT . '/restws_debug.log';

It will write the details of every web service request to the file you have
specified, e.g. to DRUPAL_ROOT/restws_debug.log.
