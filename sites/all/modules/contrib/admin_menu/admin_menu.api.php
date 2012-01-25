<?php

/**
 * @file
 * API documentation for Administration menu.
 */

/**
 * Provide expansion arguments for dynamic menu items.
 *
 * The map items must be keyed by the dynamic path to expand, i.e. a menu path
 * containing one or more '%' placeholders. Each map item may have the following
 * properties:
 * - parent: The parent menu path to link the expanded items to.
 * - arguments: An array of argument sets that will be used in the expansion.
 *   Each set consists of an array of one or more placeholders, which again is
 *   an array of possible expansion values. Upon expansion, each argument is
 *   combined with every other argument from the set (technically, the cartesian
 *   product of all arguments). The expansion values may be empty; that is, you
 *   do not need to insert logic to skip map items for which no values exist,
 *   since Administration menu will take care of that.
 * - hide: (optional) Used to hide another menu path, usually a superfluous
 *   "List" item.
 *
 * @see admin_menu.map.inc
 */
function hook_admin_menu_map() {
  // Expand content types below Structure > Content types.
  // The key denotes the dynamic path to expand to multiple menu items.
  $map['admin/structure/types/manage/%node_type'] = array(
    // Link generated items directly to the "Content types" item.
    'parent' => 'admin/structure/types',
    // Hide the "List" item, as this expansion will expose all available
    // options.
    'hide' => 'admin/structure/types/list',
    // Create expansion arguments for the '%node_type' placeholder.
    'arguments' => array(
      array(
        '%node_type' => array_keys(node_type_get_types()),
      ),
    ),
  );
  return $map;
}

/**
 * Add to the administration menu content before it is rendered.
 *
 * @param array $content
 *   A structured array suitable for drupal_render(), containing:
 *   - menu: The administrative menu of links below the path 'admin/*'.
 *   - icon: The icon menu.
 *   - user: The user items and links.
 *   Passed by reference.
 *
 * @see hook_admin_menu_output_alter()
 * @see admin_menu_links_menu()
 * @see admin_menu_links_icon()
 * @see admin_menu_links_user()
 * @see theme_admin_menu_links()
 */
function hook_admin_menu_output_build(&$content) {
}

/**
 * Change the administration menu content before it is rendered.
 *
 * @param array $content
 *   A structured array suitable for drupal_render(), containing:
 *   - menu: The administrative menu of links below the path 'admin/*'.
 *   - icon: The icon menu.
 *   - user: The user items and links.
 *   Passed by reference.
 *
 * @see hook_admin_menu_output_build()
 * @see admin_menu_links_menu()
 * @see admin_menu_links_icon()
 * @see admin_menu_links_user()
 * @see theme_admin_menu_links()
 */
function hook_admin_menu_output_alter(&$content) {
  // Add new top-level item.
  $content['menu']['myitem'] = array(
    '#title' => t('My item'),
    // #attributes are used for list items (LI).
    '#attributes' => array('class' => array('mymodule-myitem')),
    '#href' => 'mymodule/path',
    // #options are passed to l(). Note that you can apply 'attributes' for
    // links (A) here.
    '#options' => array(
      'query' => drupal_get_destination(),
    ),
    // #weight controls the order of links in the resulting item list.
    '#weight' => 50,
  );
  // Add link to manually run cron.
  $content['menu']['myitem']['cron'] = array(
    '#title' => t('Run cron'),
    '#access' => user_access('administer site configuration'),
    '#href' => 'admin/reports/status/run-cron',
  );
}

