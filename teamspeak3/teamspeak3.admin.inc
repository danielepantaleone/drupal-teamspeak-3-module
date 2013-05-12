<?php

/**
 * @file
 * Module configuration menu.
 */


/**
 * Implements hook_admin().
 */
function teamspeak3_admin() {

  $form = array();

  $form['server_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Server'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#group' => 'settings',
  );

  $form['server_settings']['teamspeak3_address'] = array(
    '#type' => 'textfield',
    '#title' => t('Address'),
    '#default_value' => variable_get('teamspeak3_address', ''),
    '#size' => 40,
    '#required' => TRUE,
    '#description' => t("Server query address/domain"),
  );

  $form['server_settings']['teamspeak3_port'] = array(
    '#type' => 'textfield',
    '#title' => t('Port'),
    '#default_value' => variable_get('teamspeak3_port', 10011),
    '#size' => 6,
    '#maxlength' => 5,
    '#required' => TRUE,
    '#description' => t("Server query port (default = 10011)"),
  );

  $form['server_settings']['teamspeak3_server_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Server ID'),
    '#default_value' => variable_get('teamspeak3_server_id', 1),
    '#required' => TRUE,
    '#size' => 6,
    '#maxlength' => 5,
    '#description' => t("Virtual server id (default = 1)"),
  );

  $form['auth_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Authentication'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#group' => 'settings',
  );

  $form['auth_settings']['teamspeak3_username'] = array(
    '#type' => 'textfield',
    '#title' => t('Username'),
    '#default_value' => variable_get('teamspeak3_username', ''),
    '#size' => 40,
    '#required' => TRUE,
    '#description' => t("Username"),
  );

  $form['auth_settings']['teamspeak3_password'] = array(
    '#type' => 'textfield',
    '#title' => t('Password'),
    '#default_value' => variable_get('teamspeak3_password', ''),
    '#size' => 40,
    '#required' => TRUE,
    '#description' => t("Server query password"),
  );

  $form['advanced_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Advanced'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#group' => 'settings',
  );

  $form['advanced_settings']['teamspeak3_timeout'] = array(
    '#type' => 'select',
    '#title' => t('Timeout'),
    '#default_value' => variable_get('teamspeak3_timeout', 3),
    '#description' => t("Seconds before the socket connection times out"),
    '#options' => drupal_map_assoc(array(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)),
  );

  $form['advanced_settings']['teamspeak3_cache_time'] = array(
    '#type' => 'select',
    '#title' => t('Cache time'),
    '#default_value' => variable_get('teamspeak3_cache_time', 30),
    '#description' => t("How many seconds you want to keep the data cache (0 = no cache)"),
    '#options' => drupal_map_assoc(array(0,
                                         10,
                                         20,
                                         30,
                                         60,
                                         120,
                                         300,
                                         600,
                                         1800,
                                         3600)),
  );

  return system_settings_form($form);

}

/**
 * Implements hook_admin_validate().
 */
function teamspeak3_admin_validate($form, &$form_state) {

  if (!is_numeric($form_state['values']['teamspeak3_port'])) {
    form_set_error('teamspeak3_port', t('Server query port must be numeric'));
  }

  if (((int) $form_state['values']['teamspeak3_port'] < 1) || ((int) $form_state['values']['teamspeak3_port'] > 65535)) {
    form_set_error('teamspeak3_port', t('Server query port must be in range 1-65535'));
  }

  if (!is_numeric($form_state['values']['teamspeak3_server_id'])) {
    form_set_error('teamspeak3_server_id', t('Virtual server id must be numeric'));
  }

  if (!is_numeric($form_state['values']['teamspeak3_timeout'])) {
    form_set_error('teamspeak3_timeout', t('Socket connection timeout must be numeric'));
  }

  if (!is_numeric($form_state['values']['teamspeak3_cache_time'])) {
    form_set_error('teamspeak3_cache_time', t('Data cache time must be numeric'));
  }

}
