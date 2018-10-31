<?php

function hdmd_rqquote_form_admin($form, &$form_state) {
  if ($options = _webform_rqquote_node_webform_list()) {
    $form['webform'] = array(
      '#type' => 'select',
      '#title' => t('Choose webform'),
      '#options' => $options,
      '#description' => t('Attach the order list into the webform.'),
      '#default_value' => variable_get('_webform_rqquote_node_webform'),
      '#required' => TRUE,
      '#ajax' => array(
        'wrapper' => 'block-system-main > div > form',
        'callback' => 'hdmd_rqquote_form_admin_option_callback'
      )
    );
    
    if (!empty($form_state['values']['webform'])) {
      $nid = $form_state['values']['webform'];
    }
    else {
      $nid = variable_get('_webform_rqquote_node_webform');
    }
    
    $form['webform_component_render'] = array(
      '#type' => 'select',
      '#title' => t('Choose component'),
      '#options' => !empty(_webform_rqquote_node_component_list($nid)) ? _webform_rqquote_node_component_list($nid) : array('' => t('- No available component -')),
      '#description' => t('Select to which component should the display be rendered.'),
      '#default_value' => variable_get('_webform_rqquote_node_webform_component_render'),
      '#required' => TRUE,
    );
    $form['webform_component_help'] = array(
      '#type' => 'markup',
      '#markup' => '<h2>IMPORTANT! Setting up the selected component.</h2>' . theme('item_list', array('items' => array(
        t('Set the default value of the selected component to [current-page:query:orders]'),
        t('Create and set the text format to full html text.'),
        t('Allow the anonymous and authenticated users to use the full html text format.'),
      ))) . '<br />'
    );
    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Save configuration')
    );
  }
  else {
    drupal_set_message(t('Please create a webform content in order to select option.'), 'warning');
    return;
  }
  return $form;
}

function hdmd_rqquote_form_admin_option_callback($form, &$form_state) {
  return $form;
}

function hdmd_rqquote_form_admin_submit($form, &$form_state) {
  variable_set('_webform_rqquote_node_webform', $form_state['values']['webform']);
  variable_set('_webform_rqquote_node_webform_component_render', $form_state['values']['webform_component_render']);
  
  drupal_set_message(t('The configuration options have been saved.'));
}

function _webform_rqquote_node_webform_list() {
  $query = db_select('webform', 'w')
          ->condition('w.status', 1)
          ->fields('w', array('nid'));
  
  if ($results = $query->execute()->fetchAll()) {
    foreach ($results as $result) {
      $node = node_load($result->nid);
      if ($node->status == 0) {
        continue;
      }
      $options[$node->nid] = $node->title;
    }
  }
  return isset($options) ? $options : array();
}

function _webform_rqquote_node_component_list($nid) {
  $query = db_select('webform_component', 'c')
          ->condition('c.nid', $nid)
          ->condition('c.type', array('html_textarea'))
          ->fields('c', array('name', 'form_key'));
          
  if ($results = $query->execute()->fetchAll()) {
    foreach ($results as $result) {
      $options[$result->form_key] = $result->name;
    }
  }
  return isset($options) ? $options : array();
}

