<?php

/**
 * @file
 * Include file for revisioning.module; deals with all theming aspects.
 */

/**
 * Implements hook_theme().
 *
 * Register the theme_hooks() available in this module, with their arguments
 * and default values.
 */
function revisioning_theme() {
  $theme = array();
  $theme['revisioning_revisions_summary'] = array(
    'render element' => 'form', // index in the $variables[] array when
    // function theme_revisioning_revisions_summary($variables) gets called
  );
  $theme['revisions_pending_block'] = array(
    'template' => 'revisions-pending-block', // revisions-pending-block.tpl.php
  );
  $theme['revisions_summary'] = array(
    'template' => 'revisions-summary', // revisions-summary.tpl.php
  );
  return $theme;
}

/**
 * Return revisions summary table data. If the Diff modules is enabled, the
 * object returned includes a column of checkboxes allowing the user to select
 * two revisions for side-by-side comparison.
 *
 * @param $form, typically an empty array as passed in by drupal_get_form()
 * @param $form_state
 * @param $extra parametrs, as passed into drupal_get_form(), see _theme_revisions_summary()
 * @return updated form containing all data to be themed
 */
function revisioning_revisions_summary($form, &$form_state, $extra) {

  // #type=>'value' form field values will not appear in the HTML. Used here
  // to pass the node id to theme_revisioning_revisions_summary().
  $nid = $extra; // or: $form_state['build_info']['args'][0];
  $form['nid'] = array('#type' => 'value', '#value' => $nid);

  $show_taxonomy_terms = module_exists('taxonomy') &&
    variable_get('revisioning_show_taxonomy_terms', TRUE) && (count(taxonomy_get_vocabularies()) > 0);

  $revisions = _revisioning_get_all_revisions_for_node($nid, $show_taxonomy_terms);

  $revision_ids = array();
  $published = FALSE;
  foreach ($revisions as $revision) {
    $vid = $revision->vid;
    if ($vid == $revision->current) {
      $title = $revision->title;
      $published = $revision->status;
    }
    $revision_ids[$vid] = ''; // no text next to check boxes (see below)
    $base_url = "node/$nid/revisions/$vid";

    // First column: saved date + author
    $first_cell = t('Saved !date by !username',
      array('!date' => l(format_date($revision->timestamp, 'small'), "$base_url/view"),
            '!username' => theme('username', array('account' => $revision))))
      . (empty($revision->log) ? '' : '<p class="revision-log">' . filter_xss($revision->log) . '</p>');
    $form['info'][$vid] = array(
      '#type' => 'item',
      '#markup' => $first_cell
    );

    // Third & fourth columns: term (2nd column is handled below)
    if (!empty($revision->tags)) {
      $form['tags'][$vid] = array(
        '#type' => 'item',
        '#markup' => $revision->tags
      );
      $has_tags = TRUE;
    }
    if (!empty($revision->term)) {
      $form['term'][$vid] = array(
        '#type' => 'item',
        '#markup' => $revision->term
      );
      $has_terms = TRUE;
    }
    $form['status'][$vid] = array(
      '#type' => 'value',
      '#value' => $revision->status
    );
  } // foreach
  if (empty($has_tags)) {
    unset($form['tags']);
  }
  if (empty($has_terms)) {
    unset($form['term']);
  }
  revisioning_set_status_message(format_plural(count($revisions),
    '%title is @publication_status. It has only one revision',
    '%title is @publication_status. It has @count revisions.',
    array(
     '%title' => $title,
     '@publication_status' => ($published ? t('published') : t('NOT published')),
    )
  ));
  if (count($revisions) >= 2 && module_exists('diff')) {
    // Second column: check-boxes to select two revisions to compare
    // The default selection is the top two check-boxes
    $id1 = key($revision_ids);
    next($revision_ids);
    $id2 = key($revision_ids);
    $form['tickbox'] = array(
      '#type' => 'checkboxes',
      '#options' => $revision_ids,
      '#default_value' => array($id1, $id2),
      '#required' => TRUE,
    );
    // Submit button
    $form['submit'] = array('#value' => t('Compare'), '#type' => 'submit');
  }
  return $form;
}

/**
 * Validation for input form to select two revisions.
 *
 * @param $form
 * @param $form_state
 * @return void
 */
function revisioning_revisions_summary_validate($form, &$form_state) {
  // Strip out all unchecked boxes
  $form_state['values']['tickbox'] = array_filter($form_state['values']['tickbox']);
  $count = count($form_state['values']['tickbox']);
  if ($count != 2) {
    form_set_error('tickbox', t('Please select 2 revisions rather than !count', array('!count' => $count)));
  }
}

/**
 * Submit two selected revisions to Diff module.
 *
 * @param $form
 * @param $form_state
 * @return void
 */
function revisioning_revisions_summary_submit($form, &$form_state) {
  $selected_vids = $form_state['values']['tickbox'];
  $vid1 = key($selected_vids);
  next($selected_vids);
  $vid2 = key($selected_vids);
  drupal_get_messages(); // clear existing msgs
  revisioning_set_status_message(t('Comparing revision #!revision2 against revision #!revision1',
    array('!revision2' => $vid2, '!revision1' => $vid1)));
  $nid = $form_state['values']['nid'];
  $form_state['redirect'] = "node/$nid/revisions/view/$vid2/$vid1";
}

/**
 * Theme the supplied form as a table, then prepend submenu links via
 * revisions-summary.tpl.php
 *
 * Uses the following subthemes:
 * o 'table_revisions', falling back to theme.inc/theme_table() if not defined
 * o 'placeholder' (to display current revision status)
 * o 'username'
 * Uses the following style-classes (see revisioning.css)
 * o 'table-revisions'
 * o 'revision-current' and 'published'
 * o 'revision-pending'
 * @param $form
 * @return unknown_type
 */
function theme_revisioning_revisions_summary($variables) {

  $form = $variables['form'];
  if (!isset($form['nid'])) {
    drupal_set_message(t('theme_revisioning_revisions_summary(): form does not contain nid - aborting.'), 'error');
    return;
  }

  // Need node info, fortunately node_load() employs a cache so is efficient
  $node = node_load($form['nid']['#value']);

  drupal_add_css(drupal_get_path('module', 'revisioning') . '/revisioning.css');

  // Set up the table rows
  $rows = array();
  $revision_ids = element_children($form['info']);

  $show_diff = count($revision_ids) >= 2 && module_exists('diff');

  // Set up the table header
  $header = array(t('Revision'));
  if ($show_diff) {
    $header[] = array('data' => drupal_render($form['submit']), 'class' => 'form-submit');
  }
  if (isset($form['tags'])) {
    $header[] = t('Tags');
  }
  if (isset($form['term'])) {
    $header[] = t('Terms');
  }
  $header[] = t('Status');

  $is_initial_unpublished_draft = !$node->status && (count($revision_ids) == 1);

  // From the $form columns create table $rows
  foreach ($revision_ids as $vid) {
    $row = array();
    // column #1: Revision info
    $row[] = drupal_render($form['info'][$vid]);

    // column #2: Compare checkbox
    if ($show_diff) {
      $row[] = array('data' => drupal_render($form['tickbox'][$vid]));
    }

    // columns #3 & #4: Tags & Terms
    if (isset($form['tags'])) {
      $row[] = drupal_render($form['tags'][$vid]);
    }
    if (isset($form['term'])) {
      $row[] = drupal_render($form['term'][$vid]);
    }

    // column #4: Publication status
    $is_current = ($vid == $node->vid);
    $is_pending = ($vid > $node->vid) || $is_initial_unpublished_draft;
    if ($is_pending) {
      $status = array('data' => t('in draft/pending publication'));
    }
    else {
      $status = array('data' => $is_current && $node->status ? drupal_placeholder(t('current revision (published)')) : t('archived'));
    }
    if (user_access('administer nodes')) {
      $status['data'] .= ' [status=' . $form['status'][$vid]['#value'] . ']';
    }
    $row[] = $status;

    // Apply CSS class
    $row_style = $is_current ? array('revision-current') : ($is_pending ? array('revision-pending') : array());
    if ($is_current && $node->status == NODE_PUBLISHED) {
      $row_style[] = 'published';
    }
    $rows[] = array('data' => $row, 'class' => $row_style);
  }
  // Render $header and $rows as a table
  $table_variables = array(
    'header' => $header,
    'rows' => $rows,
    'attributes' => array('class' => array('table-revisions'))
  );
  $content = theme(array('table_revisions', 'table'), $table_variables);

  // Prepend submenu links
  $submenu_links = _revisioning_generate_node_links_according_to_permissions($node);

  // Combine submenu links and rendered table using a template (.tpl.php) file
  $template_variables = array(
    'submenu_links' => $submenu_links,
    'content' => $content
  );
  $output = theme(array('revisions_summary'), $template_variables);

  return $output . drupal_render_children($form);
}

/**
 * Implement (in your own module) the function below if you want to override
 * the way in which the Revisions table is constructed.
 * If you do, don't forget to register this theme_hook() via <your_module>_theme()
 * in a manner similar to revisioning_theme() in this file.
 *
 * @param $header
 * @param $rows
 * @return themed HTML, see for instance /includes/theme.inc/theme_table() and
 *         diff.module/theme_diff_table()
 *
 * @ingroup themeable
 *
function theme_table_revisions($header, $rows) {
}
 */

/**
 * Theme the revisions summary of the supplied node.
 *
 * @param $node
 *   Node whose revisions to display
 * @return
 *   Render array
 *
 * @ingroup themeable
 */
function _theme_revisions_summary($node) {
  drupal_set_title(t('Revisions for %title', array('%title' => $node->title)), PASS_THROUGH);
  return drupal_get_form('revisioning_revisions_summary', $node->nid);
}


/**
 * Return an array of hyperlinks representing the operations the logged-in user
 * is allowed to perform on the supplied node.
 *
 * @param $node
 * @param $link_type
 *   The type of link, e.g. MENU_IS_LOCAL_TASK, may affect the rendering via
 *   theme('menu_item_link'), if overridden (eg zen_theme_menu_item_link()).
 * @return array of themed hyperlinks
 */
function _revisioning_generate_node_links_according_to_permissions($node, $link_type = 0) {
  $nid = $node->nid;
  $themed_links = array();
  if (!empty($node->revision_moderation)) {
    if (_revisioning_access_node_revision('publish revisions', $node)) {
      $themed_links[] = l(t('Publish'), "node/$nid/revisions/$node->vid/publish");
    }
    elseif (_revisioning_access_node_revision('unpublish current revision', $node)) {
      $themed_links[] = l(t('Unpublish current revision'), "node/$nid/unpublish");
    }
  }
  if (_revisioning_access_node_revision('delete archived revisions', $node)) {
    $num_archived = revisioning_get_number_of_archived_revisions($node);
    if ($num_archived > 0) {
      $themed_links[] = l(t('Delete archived'), "node/$nid/revisions/delete-archived");
    }
  }
  if (_revisioning_access_node_revision('delete node', $node)) {
    $text = // avoiding format_plural [#557050]
      (empty($node->revision_moderation) || $node->num_revisions == 1)
      ? t('Delete')
      : t('Delete all'); // ($node->num_revisions == 2 ? t('Delete both revisions') : t('Delete all @count revisions', array('@count' => $node->num_revisions)));
    $themed_links[] = l($text, "node/$nid/delete");
  }
  return $themed_links;
}
