<?php 
$myArray =  $_REQUEST['pointList']; 

file_put_contents('/tmp/laserControl', $myArray, FILE_APPEND | LOCK_EX);
?>
