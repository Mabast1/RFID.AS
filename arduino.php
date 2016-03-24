<?php
$mysql_host = "Here Host/Server name";
$mysql_database = "Here Database name";
$mysql_username = "Here Username";
$mysql_password = "Here Password";

//$now = date("His");//or date("H:i:s")
//$start = '210000';//or '13:00:00'
//$end = '211500';//or '17:00:00'
//if($now >= $start && $now <= $end){

date_default_timezone_set('America/Chicago');
$Hour = time();
$registrationDate="".date("H:i:s", $Hour);
$value = htmlspecialchars($_GET["v"],ENT_QUOTES);
echo "".$registrationDate."---".$value;

if (($registrationDate!="") and ($value!="")) {
	$conn = mysql_connect($mysql_host,$mysql_username,$mysql_password) or die("Unable to connect to server.");
	mysql_select_db($mysql_database) or die("Unable to open Database.");
	$sql = "UPDATE TableNameHere SET time='$registrationDate' WHERE CardID='$value'";

$result=mysql_query($sql); 
// if successfully updated. 
if($result){ 
echo "Successful"; 
} 
else { 
echo "ERROR"; 
}
} 

//}else{
 //   echo "Time outside constraints";
//}

?>