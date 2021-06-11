<?php
// PHP code goes here
echo "Turning laser off";
echo shell_exec("echo 'dogshit' > /tmp/dogshit.txt");
echo shell_exec("echo 'exit\n' > /tmp/laserControl");
echo "done";
//echo "exit" > /tmp/laserControl;

?>

