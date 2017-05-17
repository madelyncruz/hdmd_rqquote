<?php
/**
 * @file
 * hdmd_rqquote_content.features.inc
 */

/**
 * Implements hook_node_info().
 */
function hdmd_rqquote_content_node_info() {
  $items = array(
    'product' => array(
      'name' => t('Product'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Product title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
