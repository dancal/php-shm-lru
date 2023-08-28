--TEST--
test1() Basic test
--EXTENSIONS--
php_boost_ipc
--FILE--
<?php
$ret = test1();

var_dump($ret);
?>
--EXPECT--
The extension php_boost_ipc is loaded and working!
NULL
