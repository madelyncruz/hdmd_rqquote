<?php
/**
 * @file
 * hdmd_rqquote_content.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hdmd_rqquote_content_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function hdmd_rqquote_content_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function hdmd_rqquote_content_image_default_styles() {
  $styles = array();

  // Exported image style: product_large.
  $styles['product_large'] = array(
    'label' => 'Product Large',
    'effects' => array(
      4 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 559,
          'height' => 514,
        ),
        'weight' => 1,
      ),
      5 => array(
        'name' => 'canvasactions_interlace',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: product_medium.
  $styles['product_medium'] = array(
    'label' => 'Product Medium',
    'effects' => array(
      12 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 254,
          'height' => 234,
        ),
        'weight' => 1,
      ),
      13 => array(
        'name' => 'canvasactions_interlace',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: product_thumbnail.
  $styles['product_thumbnail'] = array(
    'label' => 'Product Thumbnail',
    'effects' => array(
      6 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 169,
          'height' => 156,
        ),
        'weight' => 1,
      ),
      7 => array(
        'name' => 'canvasactions_interlace',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  return $styles;
}

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
