<?php

/**
 * Class for handling a view that gets its data not from the database, but from
 * a Solr server.
 */
class apachesolr_views_query extends views_plugin_query {

  /**
   * Array of parameters for Solr query.
   */
  protected $params;

  /**
   * Array of all encountered errors. Each of these is fatal, meaning that a
   * non-empty $errors property will result in an empty result being returned.
   *
   * @var array
   */
  protected $errors;

  /**
   * Store results of apachesolr search.
   */
  protected $apachesolr_results;

  /**
   * Array of where conditions.
   *
   * Neede for grouppin of query conditions.
   */
  protected $where = array();

  public function build(&$view) {
    $view->init_pager();

    // Let the pager modify the query to add limits.
    $this->pager->query();

    // Set aliases of the fields.
    foreach ($view->field as $field_name => &$field) {
      $field->field_alias = $field_name;
      $field->aliases['entity_type'] = 'entity_type';
    }

    // Add fields to the query so they will be shown in solr document.
    $this->params['fl'] = array_keys($view->field);
  }

  /**
   * Executes the query and fills the associated view object with according
   * values.
   *
   * Values to set: $view->result, $view->total_rows, $view->execute_time,
   * $view->pager['current_page'].
   */
  public function execute(&$view) {
    try {
      $start = microtime(TRUE);

      // Execute the search.
      $params = array();
      if (isset($this->params['q'])) {
        $params['q'] =  $this->params['q'];
      }

      $params['rows'] = $this->pager->options['items_per_page'];
      $params['start'] = $this->pager->current_page * $this->pager->options['items_per_page'];

      // If we display all items without pager.
      if ($params['rows'] == 0) {
        $params['rows'] = 100000;
      }

      // Add fields.
      $params['fl'] = array('id', 'entity_id');
      if (isset($this->params['fl'])) {
        $params['fl'] = array_merge($params['fl'], $this->params['fl']);
      }
      $params['fl'] = implode(',', $params['fl']);

      // Add conditions to filter parameter.
      $conditions = array('conditions' => $this->where, 'type' => $this->group_operator);
      $conditions_string = $this->build_where_string($conditions);

      if (!empty($conditions_string)) {
        $params['fq'] = $conditions_string;
      }

      // Load search query.
      // Get the Apache Solr "environment id".
      if (strpos($view->base_table, 'apachesolr__') === 0) {
        $env_id = substr($view->base_table, 12);
      }
      else {
        $env_id = apachesolr_default_environment();
      }

      $solr = apachesolr_get_solr($env_id);
      $query = new ApachesolrViewsSolrBaseQuery('apachesolr', $solr, $params, '', current_path());

      // Add sorting.
      if (isset($this->params['sort'])) {
        $query->setAvailableSort($this->params['sort'][0], $this->params['sort'][1]);
        $query->setSolrsort($this->params['sort'][0], $this->params['sort'][1]);
      }

      $query->page = $this->pager->current_page;

      // Boost parameters if apachesolr_search module is available.
      if (module_exists('apachesolr_search')) {
        apachesolr_search_add_boost_params($query);
      }

      // Execute search.
      list($final_query, $response) = apachesolr_do_query($query);
      apachesolr_has_searched($solr->getId(), TRUE);

      // Store results.
      $view->result = $response->response->docs;

      // Store apachesolr cached response.
      $this->apachesolr_response = $response;

      // Store the results.
      $this->pager->total_items = $view->total_rows = $this->apachesolr_response->response->numFound;
      $this->pager->update_page_info();

      // We shouldn't use $results['performance']['complete'] here, since
      // extracting the results probably takes considerable time as well.
      $view->execute_time = microtime(TRUE) - $start;
    }
    catch (Exception $e) {
      $this->errors[] = $e->getMessage();
    }

    if ($this->errors) {
      foreach ($this->errors as $msg) {
        drupal_set_message($msg, 'error');
      }
      $view->result = array();
      $view->total_rows = 0;
      $view->execute_time = 0;
      return;
    }
  }

  public function add_filter($type, $value, $exclude = FALSE) {
    $exclude_string = ($exclude) ? '-' : '';
    $this->params['filters'][] = $exclude_string . $type . ':(' . $value . ')';
  }

  public function add_filter_string($string) {
    $this->params['q.alt'][] = $string;
  }

  public function add_sort($field, $order) {
    $this->params['sort'] = array($field, $order);
  }

  public function add_parameter($key, $value) {
    $this->params[$key] = $value;
  }

  public function add_field($table_alias, $field, $alias = '', $params = array()) {
    if (isset($table_alias[$field])) {
      return $table_alias[$field];
    }
  }

  public function get_params() {
    return $this->params;
  }

  /**
   *  Build filter string from where array.
   */
  function build_where_string($where) {
    if (!isset($where['conditions'])) {
      return $where['field'] . ':(' . $where['value'] . ')';
    }
    else {
      $condition_strings = array();
      foreach ($where['conditions'] as $condition) {
        $condition_strings[] = $this->build_where_string($condition);
      }
      $condition_strings = array_filter($condition_strings);
      return implode(' ' . $where['type'] . ' ', $condition_strings);
    }
  }

  /**
   * Support for groupping.
   *
   * @see views_plugin_query_default::add_where().
   */
  function add_where($group, $field, $value = NULL, $operator = NULL) {
    // Ensure all variants of 0 are actually 0. Thus '', 0 and NULL are all
    // the default group.
    if (empty($group)) {
      $group = 0;
    }

    // Check for a group.
    if (!isset($this->where[$group])) {
      $this->set_where_group('AND', $group);
    }

    $this->where[$group]['conditions'][] = array(
      'field' => $field,
      'value' => $value,
      'operator' => $operator,
    );
  }

  /**
   * Support for groupping.
   *
   * @see views_plugin_query_default::set_where_group().
   */
  function set_where_group($type = 'AND', $group = NULL, $where = 'where') {
    // Set an alias.
    $groups = &$this->$where;

    if (!isset($group)) {
      $group = empty($groups) ? 1 : max(array_keys($groups)) + 1;
    }

    // Create an empty group
    if (empty($groups[$group])) {
      $groups[$group] = array('conditions' => array(), 'args' => array());
    }

    $groups[$group]['type'] = strtoupper($type);
    return $group;
  }
}
