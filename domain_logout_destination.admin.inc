<?php

/**
 * @file
 * Menu callback for admin pages.
 */

/**
 * Page callback for admin settings form.
 */
function domain_logout_destination_settings_form($form, &$form_state) {
  $domains = domain_logout_destinations_get_domain_options();
  $destinations = variable_get('domain_logout_destinations', array());

  $form['domain_logout_destinations'] = array(
    '#tree' => TRUE,
  );
  foreach ($domains as $domain_id => $domain_name) {
    $form['domain_logout_destinations'][$domain_id] = array(
      '#title' => $domain_name,
      '#type' => 'textfield',
      '#description' => t('Logout destination for %domain_name.', array(
        '%domain_name' => $domain_name,
      )),
      '#default_value' => isset($destinations[$domain_id]) ? $destinations[$domain_id] : '',
    );
  }

  return system_settings_form($form);
}
