<?php 
$myArray = $_REQUEST['activitiesArray']; 

file_put_contents('/tmp/laserPoints', $myArray, FILE_APPEND | LOCK_EX);
?>
