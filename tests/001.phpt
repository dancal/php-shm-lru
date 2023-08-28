--TEST--
Check if php_boost_ipc is loaded
--EXTENSIONS--
php_boost_ipc
--FILE--
<?php
echo 'The extension "php_boost_ipc" is available';
?>
--EXPECT--
The extension "php_boost_ipc" is available
