<?php

/**
 * Build simple  form.
 */
function terra_form($form, $form_state) {
  $countryes = ['ukraine' => 'Ukraine', 'germany' => 'Germany'];
  $form = [];
  $form['promo'] = [
    '#type' => 'item',
    '#markup' => t('Register for a 14-day Free Trial'),
  ];
  $form['domain'] = [
    '#type' => 'textfield',
    '#title' => 'domain',
    '#required' => TRUE,
    '#attributes' => ['placeholder' => t('Domain*')],
  ];
  $form['domain_suffix'] = [
    '#type' => 'textfield',
    '#default_value' => '.bpmonline.com',
    '#disabled' => TRUE,
  ];
  $form['login'] = [
    '#type' => 'textfield',
    '#title' => 'login',
    '#required' => TRUE,
    '#attributes' => ['placeholder' => t('Login*')],
  ];
  $form['country'] = [
    '#type' => 'select',
    '#title' => 'country',
    '#options' => $countryes,
    '#empty_option' => t('Countryes*'),
    '#required' => TRUE,
  ];
  $form['city'] = [
    '#type' => 'textfield',
    '#title' => 'city',
    '#attributes' => ['placeholder' => t('City')],
  ];
  $form['code'] = [
    '#type' => 'textfield',
    '#title' => 'code',
    '#required' => TRUE,
    '#attributes' => ['placeholder' => t('Code*')],
  ];
  $form['phone'] = [
    '#type' => 'textfield',
    '#title' => 'phone',
    '#required' => TRUE,
    '#attributes' => ['placeholder' => t('Phone*')],
  ];
  $form['submit'] = [
    '#type' => 'submit',
    '#value' => t('Register'),
    '#ajax' => [
      'callback' => 'terra_ajax_callback',
      'wrapper' => 'terra-form',
      'event' => 'click',
    ],
  ];
  return $form;
}

/**
 * Callback submit.
 * Implements hook_form_submit.
 */
function terra_form_submit($form, &$form_state) {
  db_insert('terra_data')
    ->fields([
      'terra_domain' => $form_state['values']['domain'] . $form_state['values']['domain_suffix'],
      'terra_login' => $form_state['values']['login'],
      'terra_country' => $form_state['values']['country'],
      'terra_city' => $form_state['values']['city'],
      'terra_phone' => $form_state['values']['code'] . $form_state['values']['phone'],
    ])
    ->execute();
  drupal_mail('terrasoft_drak', 'terra_mail', variable_get('terra_email'), language_default(), ['data' => $form_state['values']]);
  drupal_set_message('You message send');
}

/**
 * Implements hook_form_validate.
 */
function terra_form_validate($form, &$form_state) {
  $domain_arr = ['test1', 'test2', 'test3'];
  if (in_array($form_state['values']['domain'], $domain_arr)) {
    form_set_error('domain', t('Domain is busy'));
  }
  if (empty($form_state['values']['domain'])) {
    form_set_error($form_state['values']['domain'], t('Required field'));
  }
  if (empty($form_state['values']['login'])) {
    form_set_error($form_state['values']['login'], t('Required field'));
  }
  if (empty($form_state['values']['country'])) {
    form_set_error($form_state['values']['country'], t('Required field'));
  }
  if (empty($form_state['values']['code'])) {
    form_set_error($form_state['values']['code'], t('Required field'));
  }
  if (empty($form_state['values']['phone'])) {
    form_set_error($form_state['values']['phone'], t('Required field'));
  }
  if (!filter_var($form_state['values']['code'], FILTER_SANITIZE_NUMBER_INT)) {
    form_set_error('code', t('Enter valid code'));
  }
  if (!filter_var($form_state['values']['phone'], FILTER_SANITIZE_NUMBER_INT)) {
    form_set_error('phone', t('Enter valid phone number'));
  }
  if (preg_match("~[^\w\s]+~siu", $form_state['values']['city'])) {
    form_set_error('city', t('Enter valid City'));
  }
}
/**
 * Callback ajax form.
 */
function terra_ajax_callback($form, &$form_state) {
  return $form;
}