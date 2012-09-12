<?php

/**
 * @file
 * The entity translation user interface.
 */

/**
 * The entity translation settings form.
 */
function entity_translation_admin_form($form, $form_state) {
  $options = array();

  $form['locale_field_language_fallback'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable language fallback'),
    '#description' => t('When language fallback is enabled, if a translation is not available for the requested language an existing one will be displayed.'),
    '#default_value' => variable_get('locale_field_language_fallback', TRUE),
  );

  foreach (entity_get_info() as $entity_type => $info) {
    if ($info['fieldable']) {
      $options[$entity_type] = $info['label'];
    }
  }

  $form['entity_translation_entity_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Translatable entity types'),
    '#description' => t('Select which entities can be translated.'),
    '#options' => $options,
    '#default_value' => variable_get('entity_translation_entity_types', array()),
  );

  $form = system_settings_form($form);

  // Menu rebuilding needs to be performed after the system settings are saved.
  $form['#submit'][] = 'entity_translation_admin_form_submit';

  return $form;
}

/**
 * Submit handler for the entity translation settings form.
 */
function entity_translation_admin_form_submit($form, $form_state) {
  // Clear the entity info cache for the new entity translation settings.
  entity_info_cache_clear();
  menu_rebuild();
}

/**
 * Translations overview menu callback.
 */
function entity_translation_overview($entity_type, $entity, $callback = NULL) {
  // Entity translation and node translation share the same system path.
  if ($callback && entity_translation_node($entity_type, $entity)) {
    return entity_translation_overview_callback($callback, $entity);
  }

  $handler = entity_translation_get_handler($entity_type, $entity);

  // Initialize translations if they are empty.
  $translations = $handler->getTranslations();
  if (empty($translations->original)) {
    $handler->initTranslations();
    $handler->saveTranslations();
  }

  // Ensure that we have a coherent status between entity language and field
  // languages.
  if ($handler->initOriginalTranslation()) {
    // FIXME!
    field_attach_presave($entity_type, $entity);
    field_attach_update($entity_type, $entity);
  }

  $header = array(t('Language'), t('Source language'), t('Translation'), t('Status'), t('Operations'));
  // @todo: Do we want only enabled languages here?
  $languages = language_list();
  $source = isset($_SESSION['entity_translation_source_language']) ? $_SESSION['entity_translation_source_language'] :  $translations->original;
  $base_path = $handler->getBasePath();
  $path = $handler->getViewPath();

  if ($path) {
    // If we have a view path defined for the current entity get the switch
    // links based on it.
    $links = language_negotiation_get_switch_links(LANGUAGE_TYPE_CONTENT, $path);
  }

  foreach ($languages as $language) {
    $options = array();
    $language_name = $language->name;
    $langcode = $language->language;

    if (isset($translations->data[$langcode])) {
      list($id, $vid, $bundle) = entity_extract_ids($entity_type, $entity);

      // Existing translation in the translation set: display status.
      $is_original = $langcode == $translations->original;
      $translation = $translations->data[$langcode];
      $label = _entity_translation_label($entity_type, $entity, $langcode);
      $link = isset($links->links[$langcode]['href']) ? $links->links[$langcode] : array('href' => $path, 'language' => $language);
      $row_title = l($label, $link['href'], $link);

      if (empty($link['href'])) {
        $row_title = $is_original ? $label : t('n/a');
      }

      $edit_path = $is_original ? $handler->getEditPath() : $base_path . '/translate/edit/' . $langcode;
      if ($edit_path && $handler->getAccess('update')) {
        $options[] = l($is_original ? t('edit') : t('edit translation'), $edit_path);
      }

      $status = $translation['status'] ? t('Published') : t('Not published');
      $status .= isset($translation['translate']) && $translation['translate'] ? ' - <span class="marker">' . t('outdated') . '</span>' : '';

      if ($is_original) {
        $language_name = t('<strong>@language_name</strong>', array('@language_name' => $language_name));
        $source_name = t('(original content)');
      }
      else {
        $source_name = $languages[$translation['source']]->name;
      }
    }
    else {
      // No such translation in the set yet: help user to create it.
      $row_title = $source_name = t('n/a');
      $add_path = "$base_path/translate/add/$langcode/$source";

      if ($source != $langcode && $handler->getAccess('update')) {
        list(, , $bundle) = entity_extract_ids($entity_type, $entity);
        $translatable = FALSE;

        foreach (field_info_instances($entity_type, $bundle) as $instance) {
          $field_name = $instance['field_name'];
          $field = field_info_field($field_name);
          if ($field['translatable']) {
            $translatable = TRUE;
            break;
          }
        }

        $options[] = $translatable ? l(t('add translation'), $add_path) : t('No translatable fields');
      }
      $status = t('Not translated');
    }
    $rows[] = array($language_name, $source_name, $row_title, $status, implode(" | ", $options));
  }

  drupal_set_title(t('Translations of %label', array('%label' => $handler->getLabel())), PASS_THROUGH);

  // Add metadata to the build render allow to let other modules know about
  // which entity this is.
  $build['#entity_type'] = $entity_type;
  $build['#entity'] = $entity;
  $build['entity_translation_overview'] = array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $rows,
  );

  return $build;
}

/**
 * Call the appropriate translation overview callback.
 */
function entity_translation_overview_callback($callback, $entity) {
  if (module_exists($callback['module'])) {
    if (isset($callback['file'])) {
      $path = isset($callback['file path']) ? $callback['file path'] : drupal_get_path('module', $callback['module']);
      require_once DRUPAL_ROOT . '/' . $path . '/' . $callback['file'];
    }
    return $callback['page callback']($entity);
  }
}

/**
 * Return the appropriate entity label for the given language.
 */
function _entity_translation_label($entity_type, $entity, $langcode = NULL) {
  if (function_exists('title_entity_label')) {
    list (, , $bundle) = entity_extract_ids($entity_type, $entity);
    $entity_info = entity_get_info($entity_type);
    $legacy_field = $entity_info['entity keys']['label'];
    if (title_field_replacement_enabled($entity_type, $bundle, $legacy_field)) {
      return title_entity_label($entity, $entity_type, $langcode);
    }
  }
  return t('view');
}

/**
 * Translation adding/editing form.
 */
function entity_translation_edit_form($form, $form_state, $entity_type, $entity, $langcode, $source = NULL) {
  if (entity_translation_node($entity_type, $entity)) {
    drupal_goto("node/$entity->nid/translate");
  }

  $handler = entity_translation_get_handler($entity_type, $entity);

  $languages = language_list();
  $args = array('@label' => $handler->getLabel(), '@language' => t($languages[$langcode]->name));
  drupal_set_title(t('@label [@language translation]', $args));

  $translations = $handler->getTranslations();
  $new_translation = !isset($translations->data[$langcode]);

  $form = array(
    '#handler' => $handler,
    '#entity_type' => $entity_type,
    '#entity' => $entity,
    '#source' => $new_translation ? $source : $translations->data[$langcode]['source'],
    '#language' => $langcode,
  );

  // Display source language selector only if we are creating a new translation
  // and there are at least two translations available.
  if ($new_translation && count($translations->data) > 1) {
    $form['source_language'] = array(
      '#type' => 'fieldset',
      '#title' => t('Source language'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#tree' => TRUE,
      '#weight' => -22,
      'language' => array(
        '#type' => 'select',
        '#default_value' => $source,
        '#options' => array(),
      ),
      'submit' => array(
        '#type' => 'submit',
        '#value' => t('Change'),
        '#submit' => array('entity_translation_edit_form_source_language_submit'),
      ),
    );
    foreach (language_list() as $language) {
      if (isset($translations->data[$language->language])) {
        $form['source_language']['language']['#options'][$language->language] = t($language->name);
      }
    }
  }

  $translate = intval(isset($translations->data[$langcode]) && $translations->data[$langcode]['translate']);

  $form['translation'] = array(
    '#type' => 'fieldset',
    '#title' => t('Translation settings'),
    '#collapsible' => TRUE,
    '#collapsed' => !$translate,
    '#tree' => TRUE,
    '#weight' => -24,
  );
  $form['translation']['status'] = array(
    '#type' => 'checkbox',
    '#title' => t('This translation is published'),
    '#default_value' => !isset($translations->data[$langcode]) || $translations->data[$langcode]['status'],
    '#description' => t('When this option is unchecked, this translation will not be visible for non-administrators.'),
  );
  $form['translation']['translate'] = array(
    '#type' => 'checkbox',
    '#title' => t('This translation needs to be updated'),
    '#default_value' => $translate,
    '#description' => t('When this option is checked, this translation needs to be updated because the source post has changed. Uncheck when the translation is up to date again.'),
    '#disabled' => !$translate,
  );

  // If we are creating a new translation we need to retrieve form elements
  // populated with the source language values, but only if form is not being
  // rebuilt. In this case source values have already been populated, so we need
  // to preserve possible changes.
  $prepare_fields = $new_translation && !$form_state['rebuild'];
  if ($prepare_fields) {
    $source_form = array();
    $source_form_state = $form_state;
    field_attach_form($entity_type, $entity, $source_form, $source_form_state, $source);
  }
  field_attach_form($entity_type, $entity, $form, $form_state, $langcode);

  list(, , $bundle) = entity_extract_ids($entity_type, $entity);
  foreach (field_info_instances($entity_type, $bundle) as $instance) {
    $field_name = $instance['field_name'];
    $field = field_info_field($field_name);
    // If a field is not translatable remove it from the translation form.
    if (!$field['translatable']) {
      $form[$field_name]['#access'] = FALSE;
    }
    // If we are creating a new translation we have to change the form item
    // language information from source to target language, this way the
    // user can find the form items already populated with the source values
    // while the field form element holds the correct language information.
    elseif ($prepare_fields && !isset($entity->{$field_name}[$langcode]) && isset($source_form[$field_name][$source])) {
      $form[$field_name][$langcode] = $source_form[$field_name][$source];
      // Update #language keys in the field form subtree.
      _entity_translation_form_language($form[$field_name][$langcode], $source, $langcode);
    }
  }

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save translation'),
    '#validate' => array('entity_translation_edit_form_save_validate'),
    '#submit' => array('entity_translation_edit_form_save_submit'),
  );
  if (!$new_translation) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete translation'),
      '#submit' => array('entity_translation_edit_form_delete_submit'),
    );
  }

  // URL alias widget.
  if (_entity_translation_path_enabled($handler)) {
    $alias = db_select('url_alias')
      ->fields('url_alias', array('alias'))
      ->condition('source', $handler->getViewPath())
      ->condition('language', $langcode)
      ->execute()
      ->fetchField();

    $form['path'] = array(
      '#type' => 'fieldset',
      '#title' => t('URL path settings'),
      '#tree' => TRUE,
    );

    $form['path']['alias'] = array(
      '#type' => 'textfield',
      '#title' => t('URL alias'),
      '#default_value' => $alias,
      '#maxlength' => 255,
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#description' => t('Optionally specify an alternative URL by which this entity can be accessed. For example, type "about" when writing an about page. Use a relative path and don\'t add a trailing slash or the URL alias won\'t work.'),
      '#access' => user_access('create url aliases'),
      '#weight' => 0,
    );

    $form['path']['source'] = array(
      '#type' => 'value',
      '#value' => $handler->getViewPath(),
    );
    $form['path']['language'] = array(
      '#type' => 'value',
      '#value' => $langcode,
    );

    if (!empty($alias)) {
      $pid = db_select('url_alias')
        ->fields('url_alias', array('pid'))
        ->condition('alias', $alias)
        ->condition('language', $langcode)
        ->execute()
        ->fetchField();

      $form['path']['pid'] = array(
        '#type' => 'value',
        '#value' => $pid,
      );
    }

    // Load special form settings if applicable.
    if ($entity_type == 'node') {
      // Create temporary, decoupled stuff to avoid side effects.
      $form_state_dummy = $form_state;
      $form_state_dummy['node'] = clone($form['#entity']);
      $form_state_dummy['node']->language = $langcode;
      if (!isset($translations->data[$langcode])) {
        // If this is a new translation simulate a new node for pathauto.
        unset($form_state_dummy['node']->nid);
      }

      // The following part recycles code from other modules, what means that
      // this module doesn't have control about essential functional parts.
      // Thus this section has to be considered as fragile as changes in the
      // other modules can easily break it.
      if (module_exists('pathauto')) {
        // Reuse code parts from pathauto.
        module_load_include('module', 'pathauto');
        pathauto_form_node_form_alter($form, $form_state_dummy);
      }
      if (module_exists('redirect')) {
        // Reuse code parts from redirect.
        module_load_include('module', 'redirect');
        redirect_form_node_form_alter($form, $form_state);
      }
      // Remove the temporary stuff.
      unset($form_state_dummy);
    }
  }

  return $form;
}

/**
 * Helper function: recursively replace the source language with the given one.
 */
function _entity_translation_form_language(&$element, $source, $langcode) {
  // Iterate through the form structure recursively.
  foreach (element_children($element) as $key) {
    _entity_translation_form_language($element[$key], $source, $langcode);
  }

  // Replace specific occurrences of the source language with the target
  // language.
  foreach (element_properties($element) as $key) {
    if ($key === '#language') {
      $element[$key] = $langcode;
    }

    if ($key === '#parents' || $key === '#field_parents') {
      foreach ($element[$key] as $delta => $value) {
        if ($value === $source) {
          $element[$key][$delta] = $langcode;
        }
      }
    }
  }
}

/**
 * Submit handler for the source language selector.
 */
function entity_translation_edit_form_source_language_submit($form, &$form_state) {
  $handler = $form['#handler'];
  $langcode = $form_state['values']['source_language']['language'];
  $path = "{$handler->getBasePath()}/translate/add/{$form['#language']}/$langcode";
  $form_state['redirect'] = array('path' => $path);
  $languages = language_list();
  drupal_set_message(t('Source translation set to: %language', array('%language' => t($languages[$langcode]->name))));
}

/**
 * Validation handler for the translation saving.
 */
function entity_translation_edit_form_save_validate($form, &$form_state) {
  field_attach_form_validate($form['#entity_type'], $form['#entity'], $form, $form_state);
}

/**
 * Submit handler for the translation saving.
 */
function entity_translation_edit_form_save_submit($form, &$form_state) {
  $handler = $form['#handler'];

  $translation = array(
    'translate' => $form_state['values']['translation']['translate'],
    'status' => $form_state['values']['translation']['status'],
    'language' => $form['#language'],
    'source' => $form['#source'],
  );

  $handler->setTranslation($translation, $form_state['values']);

  $form['#entity'] = (object) $form['#entity'];
  entity_form_submit_build_entity($form['#entity_type'], $form['#entity'], $form, $form_state);
  field_attach_presave($form['#entity_type'], $form['#entity']);
  field_attach_update($form['#entity_type'], $form['#entity']);


  $entity_info = entity_get_info($form['#entity_type']);
  $id_key = $entity_info['entity keys']['id'];
  entity_get_controller($form['#entity_type'])->resetCache(array($form['#entity']->{$id_key}));

  module_invoke_all('entity_translation_save', $form['#entity_type'], $form['#entity'], $form['#language']);
  $form_state['redirect'] = "{$handler->getBasePath()}/translate";
}

/**
 * Helper function to check if the path support is enabled.
 */
function _entity_translation_path_enabled(EntityTranslationHandlerInterface $handler) {
  return $handler->isAliasEnabled() && module_exists('path');
}

/**
 * Submit handler for the translation deletion.
 */
function entity_translation_edit_form_delete_submit($form, &$form_state) {
  $form_state['redirect'] = "{$form['#handler']->getBasePath()}/translate/delete/{$form['#language']}";
}

/**
 * Translation deletion confirmation form.
 */
function entity_translation_delete_confirm($form, $form_state, $entity_type, $entity, $langcode) {
  $handler = entity_translation_get_handler($entity_type, $entity);
  $languages = language_list();

  $form = array(
    '#handler' => $handler,
    '#entity_type' => $entity_type,
    '#entity' => $entity,
    '#language' => $langcode,
  );

  return confirm_form(
    $form,
    t('Are you sure you want to delete the @language translation of %label?', array('@language' => $languages[$langcode]->name, '%label' => $handler->getLabel())),
    "{$handler->getBasePath()}/translate/edit/$langcode",
    t('This action cannot be undone.'),
    t('Delete'),
    t('Cancel')
  );
}

/**
 * Submit handler for the translation deletion confirmation.
 */
function entity_translation_delete_confirm_submit($form, &$form_state) {
  $handler = $form['#handler'];

  $handler->removeTranslation($form['#language']);
  field_attach_update($form['#entity_type'], $form['#entity']);

  if (isset($_SESSION['entity_translation_source_language']) && $form['#language'] == $_SESSION['entity_translation_source_language']) {
    unset($_SESSION['entity_translation_source_language']);
  }

  $form_state['redirect'] = "{$handler->getBasePath()}/translate";
}

/*
 * Confirm form for changing field translatability.
 */
function entity_translation_translatable_form($form, &$form_state, $field_name) {
  $field = field_info_field($field_name);
  $t_args = array('%name' => $field_name);

  $warning = t('By submitting this form you will trigger a batch operation.');
  if ($field['translatable']) {
    $title = t('Are you sure you want to disable translation for the %name field?', $t_args);
    $warning .= "<br>" . t("<strong>All the existing translations of this field will be deleted.</strong><br>This action cannot be undone.");
  }
  else {
    $title = t('Are you sure you want to enable translation for the %name field?', $t_args);
  }

  // We need to keep some information for later processing.
  $form_state['field'] = $field;

  // Store the 'translatable' status on the client side to prevent outdated form
  // submits from toggling translatability.
  $form['translatable'] = array(
    '#type' => 'hidden',
    '#default_value' => $field['translatable'],
  );

  return confirm_form($form, $title, '', $warning);
}

/**
 * Submit handler for the field settings form.
 *
 * This submit handler maintains consistency between the translatability of an
 * entity and the language under which the field data is stored. When a field is
 * marked as translatable, all the data in $entity->{field_name}[LANGUAGE_NONE]
 * is moved to $entity->{field_name}[$entity_language]. When a field is marked
 * as untranslatable the opposite process occurs. Note that marking a field as
 * untranslatable will cause all of its translations to be permanently removed,
 * with the exception of the one corresponding to the entity language.
 */
function entity_translation_translatable_form_submit($form, $form_state) {
  // This is the current state that we want to reverse.
  $translatable = $form_state['values']['translatable'];
  $field_name = $form_state['field']['field_name'];
  $field = field_info_field($field_name);

  if ($field['translatable'] !== $translatable) {
    // Field translatability has changed since form creation, abort.
    $t_args = array('%field_name' => $field_name, '!translatable' => $translatable ? t('untranslatable') : t('translatable'));
    drupal_set_message(t('The field %field_name is already !translatable. No change was performed.', $t_args), 'warning');
    return;
  }

  // If a field is untranslatable, it can have no data except under
  // LANGUAGE_NONE. Thus we need a field to be translatable before we convert
  // data to the entity language. Conversely we need to switch data back to
  // LANGUAGE_NONE before making a field untranslatable lest we lose
  // information.
  $operations = array(
    array('entity_translation_translatable_batch', array(!$translatable, $field_name)),
    array('entity_translation_translatable_switch', array(!$translatable, $field_name)),
  );
  $operations = $translatable ? $operations : array_reverse($operations);

  $t_args = array('%field' => $field_name);
  $title = !$translatable ? t('Enabling translation for the %field field', $t_args) : t('Disabling translation for the %field field', $t_args);

  $batch = array(
    'title' => $title,
    'operations' => $operations,
    'finished' => 'entity_translation_translatable_batch_done',
    'file' => drupal_get_path('module', 'entity_translation') . '/entity_translation.admin.inc',
  );

  batch_set($batch);
}

/*
 * Toggle translatability of the given field.
 *
 * This is called from a batch operation, but should only run once per field.
 */
function entity_translation_translatable_switch($translatable, $field_name) {
  $field = field_info_field($field_name);

  if ($field['translatable'] === $translatable) {
    return;
  }

  $field['translatable'] = $translatable;
  field_update_field($field);

  // This is needed for versions of Drupal core 7.10 and lower.
  // See http://drupal.org/node/1380660 for details.
  drupal_static_reset('field_available_languages');
}

/**
 * Batch operation. Convert field data to or from LANGUAGE_NONE.
 */
function entity_translation_translatable_batch($translatable, $field_name, &$context) {
  if (empty($context['sandbox'])) {
    $context['sandbox']['progress'] = 0;

    // How many entities will need processing?
    $query = new EntityFieldQuery();
    $count = $query
      ->fieldCondition($field_name)
      ->count()
      ->execute();

    if (intval($count) === 0) {
      // Nothing to do.
      $context['finished'] = 1;
      return;
    }
    $context['sandbox']['max'] = $count;
  }

  // Number of entities to be processed for each step.
  $limit = variable_get('entity_translation_translatable_batch_limit', 10);

  $offset = $context['sandbox']['progress'];
  $query = new EntityFieldQuery();
  $result = $query
    ->fieldCondition($field_name)
    ->entityOrderBy('entity_id')
    ->range($offset, $limit)
    ->execute();

  foreach ($result as $entity_type => $entities) {
    foreach (entity_load($entity_type, array_keys($entities)) as $id => $entity) {
      $context['sandbox']['progress']++;
      $handler = entity_translation_get_handler($entity_type, $entity);
      $langcode = $handler->getLanguage();

      // Skip process for language neutral entities.
      if ($langcode == LANGUAGE_NONE) {
        continue;
      }

      // We need a two-steps approach while updating field translations: given
      // that field-specific update functions might rely on the stored values to
      // perform their processing, see for instance file_field_update(), first
      // we need to store the new translations and only after we can remove the
      // old ones. Otherwise we might have data loss, since the removal of the
      // old translations might occur before the new ones are stored.
      if ($translatable && isset($entity->{$field_name}[LANGUAGE_NONE])) {
        // If the field is being switched to translatable and has data for
        // LANGUAGE_NONE then we need to move the data to the right language.
        $entity->{$field_name}[$langcode] = $entity->{$field_name}[LANGUAGE_NONE];
        // Store the original value.
        _entity_translation_update_field($entity_type, $entity, $field_name);
        $entity->{$field_name}[LANGUAGE_NONE] = array();
        // Remove the language neutral value.
        _entity_translation_update_field($entity_type, $entity, $field_name);
      }
      elseif (!$translatable && isset($entity->{$field_name}[$langcode])) {
        // The field has been marked untranslatable and has data in the entity
        // language: we need to move it to LANGUAGE_NONE and drop the other
        // translations.
        $entity->{$field_name}[LANGUAGE_NONE] = $entity->{$field_name}[$langcode];
        // Store the original value.
        _entity_translation_update_field($entity_type, $entity, $field_name);
        // Remove translations.
        foreach ($entity->{$field_name} as $langcode => $items) {
          if ($langcode != LANGUAGE_NONE) {
            $entity->{$field_name}[$langcode] = array();
          }
        }
        _entity_translation_update_field($entity_type, $entity, $field_name);
      }
      else {
        // No need to save unchanged entities.
        continue;
      }
    }
  }

  $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
}

/**
 * Stores the given field translations.
 */
function _entity_translation_update_field($entity_type, $entity, $field_name) {
  $empty = 0;
  $field = field_info_field($field_name);

  // Ensure that we are trying to store only valid data.
  foreach ($entity->{$field_name} as $langcode => $items) {
    $entity->{$field_name}[$langcode] = _field_filter_items($field, $entity->{$field_name}[$langcode]);
    $empty += empty($entity->{$field_name}[$langcode]);
  }

  // Save the field value only if there is at least one item available,
  // otherwise any stored empty field value would be deleted. If this happens
  // the range queries would be messed up.
  if ($empty < count($entity->{$field_name})) {
    field_attach_presave($entity_type, $entity);
    field_attach_update($entity_type, $entity);
  }
}

/**
 * Check the exit status of the batch operation.
 */
function entity_translation_translatable_batch_done($success, $results, $operations) {
  if ($success) {
    drupal_set_message(t("Data successfully processed."));
  }
  else {
    // @todo: Do something about this case.
    drupal_set_message(t("Something went wrong while processing data. Some nodes may appear to have lost fields."));
  }
}
