<?php

start();

function start(){
    $response = [];
    $response["response_type"] = "in_channel";
    $text = $_POST["text"];
    $text = str_replace("#", "", $text);
    $response["text"] = "Ticket in plan.io: https://ibelsa.planio.com/issues/" . $text;
    $response = json_encode($response);
    header('Content-Type: application/json');
    echo $response;
}