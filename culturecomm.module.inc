<?php

// hook_init
function culturecomm_init() {
  drupal_add_css(drupal_get_path('module', 'culturecomm') . '/css/culturecomm.css');
}

// hook_form_alter
function culturecomm_form_alter(&$form, &$form_state, $form_id) {
	global $user;
	
	if($form_id == 'page_node_form') {

		// Hide the media field in page for now
		if($user->name == 'mcinnisd') {
			// Because he need to control a web page, but we don't allow him to upload video
			$form['field_shared_video']['#attributes']['class'][] = 'hide';
		}
		else if ($user->name == 'test-user') {
			// test-user is used for testing only	
			$form['field_shared_video']['#attributes']['class'][] = 'hide';
		}
			
	}
}

