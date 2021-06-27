<?php
// PHP code goes here
echo "Turning laser off";
//echo shell_exec("echo 'exit' > /tmp/laserControl");
$person = "exit";
file_put_contents('/tmp/laserControl', $person, FILE_APPEND | LOCK_EX);

?>

