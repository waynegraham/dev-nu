<?php

define('DEV-NU_PLUGIN_DIR', dirname(__FILE__));

// {{{ hooks
add_plugin_hook('install', 'install');
add_plugin_hook('uninstall', 'uninstall');
// }}}

function install()
{
  set_option('dev-nu-plugin-version', '1.1');
}

function uninstall()
{
  delete_option('dev-nu-plugin-version', '1.1');
}



