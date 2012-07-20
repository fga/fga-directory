<?php

/**
 * Displays a search page.
 *
 * @param $id
 *   The search page's machine name.
 * @param $keys
 *   The keys to search for.
 */
function search_api_page_view($id, $keys = NULL) {
  $page = search_api_page_load($id);
  if (!$page) {
    return MENU_NOT_FOUND;
  }

  // Override per_page setting with GET parameter.
  if (!empty($_GET['per_page']) && !empty($page->options['get_per_page']) && ((int) $_GET['per_page']) > 0) {
    // Remember and later restore the true setting value so we don't
    // accidentally permanently save the altered one.
    $page->options['original_per_page'] = $page->options['per_page'];
    $page->options['per_page'] = (int) $_GET['per_page'];
  }

  $ret['form'] = drupal_get_form('search_api_page_search_form', $page, $keys);

  if ($keys) {
    try {
      $results = search_api_page_search_execute($page, $keys);
    }
    catch (SearchApiException $e) {
      $ret['message'] = t('An error occurred while executing the search. Please try again or contact the site administrator if the problem persists.');
      watchdog('search_api_page', 'An error occurred while executing a search: !msg.', array('!msg' => $e->getMessage()), WATCHDOG_ERROR, l(t('search page'), $_GET['q']));
    }

    // If spellcheck results are returned then add them to the render array.
    if (isset($results['search_api_spellcheck'])) {
      $ret['search_api_spellcheck']['#theme'] = 'search_api_spellcheck';
      $ret['search_api_spellcheck']['#spellcheck'] = $results['search_api_spellcheck'];
      // Let the theme function know where the key is stored by passing its arg
      // number. We can work this out from the number of args in the page path.
      $ret['search_api_spellcheck']['#options'] = array(
        'arg' => array(count(arg(NULL, $page->path))),
      );
    }

    $ret['results']['#theme'] = 'search_api_page_results';
    $ret['results']['#index'] = search_api_index_load($page->index_id);
    $ret['results']['#results'] = $results;
    $ret['results']['#view_mode'] = isset($page->options['view_mode']) ? $page->options['view_mode'] : 'search_api_page_result';
    $ret['results']['#keys'] = $keys;

    if ($results['result count'] > $page->options['per_page']) {
      pager_default_initialize($results['result count'], $page->options['per_page']);
      $ret['pager']['#theme'] = 'pager';
      $ret['pager']['#quantity'] = 9;
    }

    if (!empty($results['ignored'])) {
      drupal_set_message(t('The following search keys are too short or too common and were therefore ignored: "@list".', array('@list' => implode(t('", "'), $results['ignored']))), 'warning');
    }
    if (!empty($results['warnings'])) {
      foreach ($results['warnings'] as $warning) {
        drupal_set_message($warning, 'warning');
      }
    }
  }

  if (isset($page->options['original_per_page'])) {
    $page->options['per_page'] = $page->options['original_per_page'];
    unset($page->options['original_per_page']);
  }

  return $ret;
}

/**
 * Executes a search.
 *
 * @param Entity $page
 *   The page for which a search should be executed.
 * @param $keys
 *   The keywords to search for.
 *
 * @return array
 *   The search results as returned by SearchApiQueryInterface::execute().
 */
function search_api_page_search_execute(Entity $page, $keys) {
  $limit = $page->options['per_page'];
  $offset = pager_find_page() * $limit;
  $options = array(
    'search id' => 'search_api_page:' . $page->path,
    'parse mode' => $page->options['mode'],
  );

  if (!empty($page->options['search_api_spellcheck'])) {
    $options['search_api_spellcheck'] = TRUE;
  }

  $query = search_api_query($page->index_id, $options)
    ->keys($keys)
    ->range($offset, $limit);
  if (!empty($page->options['fields'])) {
    $query->fields($page->options['fields']);
  }
  return $query->execute();
}

/**
 * Function for preprocessing the variables for the search_api_page_results
 * theme.
 *
 * @param array $variables
 *   An associative array containing:
 *   - index: The index this search was executed on.
 *   - results: An array of search results, as returned by
 *     SearchApiQueryInterface::execute().
 *   - keys: The keywords of the executed search.
 */
function template_preprocess_search_api_page_results(array &$variables) {
  if (!empty($variables['results']['results'])) {
    $variables['items'] = $variables['index']->loadItems(array_keys($variables['results']['results']));
  }
}

/**
 * Theme function for displaying search results.
 *
 * @param array $variables
 *   An associative array containing:
 *   - index: The index this search was executed on.
 *   - results: An array of search results, as returned by
 *     SearchApiQueryInterface::execute().
 *   - items: The loaded items for all results, in an array keyed by ID.
 *   - view_mode: The view mode to use for displaying the individual results,
 *     or the special mode "search_api_page_result" to use the theme function
 *     of the same name.
 *   - keys: The keywords of the executed search.
 */
function theme_search_api_page_results(array $variables) {
  drupal_add_css(drupal_get_path('module', 'search_api_page') . '/search_api_page.css');

  $index = $variables['index'];
  $results = $variables['results'];
  $items = $variables['items'];
  $keys = $variables['keys'];

  $output = '<p class="search-performance">' . format_plural($results['result count'],
      'The search found 1 result in @sec seconds.',
      'The search found @count results in @sec seconds.',
      array('@sec' => round($results['performance']['complete'], 3))) . '</p>';

  if (!$results['result count']) {
    $output .= "\n<h2>" . t('Your search yielded no results') . "</h2>\n";
    return $output;
  }

  $output .= "\n<h2>" . t('Search results') . "</h2>\n";

  if ($variables['view_mode'] == 'search_api_page_result') {
    $output .= '<ol class="search-results">';
    foreach ($results['results'] as $item) {
      $output .= '<li class="search-result">' . theme('search_api_page_result', array('index' => $index, 'result' => $item, 'item' => isset($items[$item['id']]) ? $items[$item['id']] : NULL, 'keys' => $keys)) . '</li>';
    }
    $output .= '</ol>';
  }
  else {
    // This option can only be set when the items are entities.
    $output .= '<div class="search-results">';
    $render = entity_view($index->item_type, $items, $variables['view_mode']);
    $output .= render($render);
    $output .= '</div>';
  }

  return $output;
}

/**
 * Theme function for displaying search results.
 *
 * @param array $variables
 *   An associative array containing:
 *   - index: The index this search was executed on.
 *   - result: One item of the search results, an array containing the keys
 *     'id' and 'score'.
 *   - item: The loaded item corresponding to the result.
 *   - keys: The keywords of the executed search.
 */
function theme_search_api_page_result(array $variables) {
  $index = $variables['index'];
  $id = $variables['result']['id'];
  $item = $variables['item'];

  $wrapper = $index->entityWrapper($item, FALSE);

  $url = $index->datasource()->getItemUrl($item);
  $name = $index->datasource()->getItemLabel($item);

  if (!empty($variables['result']['excerpt'])) {
    $text = $variables['result']['excerpt'];
  }
  else {
    $fields = $index->options['fields'];
    $fields = array_intersect_key($fields, drupal_map_assoc($index->getFulltextFields()));
    $fields = search_api_extract_fields($wrapper, $fields);
    $text = '';
    $length = 0;
    foreach ($fields as $field_name => $field) {
      if (search_api_is_list_type($field['type']) || !isset($field['value'])) {
        continue;
      }
      $val_length = drupal_strlen($field['value']);
      if ($val_length > $length) {
        $text = $field['value'];
        $length = $val_length;

        $format = NULL;
        if (($pos = strrpos($field_name, ':')) && substr($field_name, $pos + 1) == 'value') {
          $tmp = $wrapper;
          try {
            foreach (explode(':', substr($field_name, 0, $pos)) as $part) {
              if (!isset($tmp->$part)) {
                $tmp = NULL;
              }
              $tmp = $tmp->$part;
            }
          }
          catch (EntityMetadataWrapperException $e) {
            $tmp = NULL;
          }
          if ($tmp && $tmp->type() == 'text_formatted' && isset($tmp->format)) {
            $format = $tmp->format->value();
          }
        }
      }
    }
    if ($text && function_exists('text_summary')) {
      $text = text_summary($text, $format);
    }
  }

  $output = '<h3>' . ($url ? l($name, $url['path'], $url['options']) : check_plain($name)) . "</h3>\n";
  if ($text) {
    $output .= $text;
  }

  return $output;
}
