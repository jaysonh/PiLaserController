<?php
// PHP code goes here
//echo "Turning laser off";
//echo shell_exec("echo 'exit' > /tmp/laserControl");
//$blankState = $_GET['name'];
//echo "blankState: ";
//echo $blankState; 

if(isset($_GET['UNBLANK'])){
	echo "unblanking";
	file_put_contents('/tmp/laserControl', "blank,0", FILE_APPEND | LOCK_EX);

}
 if(isset($_GET['BLANK'])){
	echo "blanking"; 
	file_put_contents('/tmp/laserControl', "blank,1", FILE_APPEND | LOCK_EX);
}

//$cmd = "blank 1";
//file_put_contents('/tmp/laserControl', $cmd, FILE_APPEND | LOCK_EX);

?>

