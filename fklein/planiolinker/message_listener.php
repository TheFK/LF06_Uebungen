<?php

start();

function start(){
    $response = [];

    $body = file_get_contents('php://input');
    $request = json_decode($body, 1);

    $text = $request["event"]["text"];
    error_log('request=' . print_r($request, 1) . "\n", 3, 'listener.log');
    error_log('text=' . print_r($text, 1) . "\n", 3, 'listener.log');

    $ids = [];
    if(preg_match('/#[0-9]*/', $text, $ids) == 1){
        error_log('found' . "\n", 3, 'listener.log');


        $id = $ids[0];
        error_log('id=' . print_r($id, 1) . "\n", 3, 'listener.log');
        $id = str_replace("#", "", $id);
        $response["text"] .= "https://ibelsa.planio.com/issues/" . $id;

        $response["channel"] = $request["event"]["channel"];

        error_log('response=' . print_r($response, 1) . "\n", 3, 'listener.log');

        // $ch = curl_init("https://slack.com/api/chat.postMessage");
        // curl_setopt($ch, CURLOPT_POST, 1);
        // curl_setopt( $ch, CURLOPT_HTTPHEADER, array('Content-Type:application/json'));
        // curl_setopt( $ch, CURLOPT_POSTFIELDS, json_encode($response));
        // curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
        // $output = curl_exec($ch);
        // error_log('output=' . print_r($output, 1) . "\n", 3, 'listener.log');
        // curl_close($ch);
        $options = array(
            'http' => array(
              'header'  => "Content-Type:application/json\r\n",
              'method'  => 'POST',
              'content' => http_build_query($response),
            ),
        );
        $context  = stream_context_create($options);
        $result = file_get_contents("https://slack.com/api/chat.postMessage", false, $context);
    }

    // $text = str_replace("#", "", $text);
    // $response["text"] = "Ticket in plan.io: https://ibelsa.planio.com/issues/" . $text;
    // $response = json_encode($response);

    // header('Content-Type: application/json');
    // echo $response;
}