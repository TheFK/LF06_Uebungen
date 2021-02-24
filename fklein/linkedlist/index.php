<?php
include "LinkedList.php";
$list = new LinkedList();
//import old values
$old_values = explode(" ", $_POST["old_values"]);
foreach($old_values as $v){
    $list->add($v);
}

if(isset($_POST["add"])){
    $list->add($_POST["value"]);
}
else if(isset($_POST["remove"])){
    $list->deleteEntry($_POST["value"]);
}

$html = file_get_contents("content.html");
$html = str_replace("%values%", $list->dataAsString(), $html);
echo $html;