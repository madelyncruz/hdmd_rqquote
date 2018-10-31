<?php
/**
 * @file
 * request_quote_feature.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function request_quote_feature_filter_default_formats() {
  $formats = array();

  // Exported format: Full HTML Text.
  $formats['full_html_text'] = array(
    'format' => 'full_html_text',
    'name' => 'Full HTML Text',
    'cache' => 1,
    'status' => 1,
    'weight' => 0,
    'filters' => array(
      'filter_url' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
    ),
  );

  return $formats;
}
