<?php

/**
 * @file
 * Implementation form in the block.
 */

/**
 * Implements hook_block_info().
 */
function terrasoft_drak_block_info() {
  $blocks['terra-block'] = [
    'info' => t('Terrasoft'),
  ];
  return $blocks;
}

/**
 * Implements hook_block_view().
 */
function terrasoft_drak_block_view($delta = '') {
  $block = [];
  if ($delta == 'terra-block') {
    $block['subject'] = t('Terrasoft');
    $block['content'] = drupal_get_form('terra_form');
  }
  return $block;
}

/**
 * Implements hook_block_configure().
 */
function terrasoft_drak_block_configure($delta = '') {
  $form = [];
  $valiad = [0 => 'No', 1 => 'Yes'];
  if ($delta == 'terra-block') {
    $form['email'] = [
      '#type' => 'textfield',
      '#title' => t('Enter an email to send letters to'),
      '#default_value' => variable_get('terra_email'),
    ];
    $form['valid'] = [
      '#title' => t('Chose front validation'),
      '#type' => 'select',
      '#options' => $valiad,
      '#required' => TRUE,
      '#default_value' => variable_get('terra_valid'),
    ];
  }
  return $form;
}

/**
 * Implements hook_block_save().
 */
function terrasoft_drak_block_save($delta = '', $edit = []) {
  if ($delta == 'terra-block') {
    variable_set('terra_email', $edit['email']);
    variable_set('terra_valid', $edit['valid']);
  }
}

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Adds validation of block configuration custom fields.
 */
function terrasoft_drak_form_block_admin_configure_alter(&$form, &$form_state, $form_id) {
  if ($form['module']['#value'] == 'terrasoft_drak') {
    $form['#validate'][] = 'terra_admin_block_validate';
  }
}

/**
 * Form validation callback of block configuration.
 */
function terra_admin_block_validate(&$form, $form_state) {
  $delta = $form['delta']['#value'];
  if ($delta == 'terra-block') {
    if (!filter_var($form_state['values']['email'], FILTER_VALIDATE_EMAIL)) {
      form_set_error('email', t('Enter valid email please'));
    }
  }
}