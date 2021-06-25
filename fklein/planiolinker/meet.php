<?php

start();

function start(){
    $response = [];
    $response["response_type"] = "in_channel";
    $text = $_POST["text"];
    if(!$text){
        $text = random_bytes(10);
        $text = bin2hex($text);
    }
    $response["text"] = "https://meet.google.com/lookup/" . $text;
    $response = json_encode($response);
    header('Content-Type: application/json');
    echo $response;
}