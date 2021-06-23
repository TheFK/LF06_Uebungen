<?php
ajax();

//Start
function ajax(){
    if(isset($_POST["action"])){
        $action = $_POST["action"];

        switch($action){
            case 'read':
                echo read();
                break;
            case 'write':
                echo write();
                break;
            // case 'delete':
            //     return deleteCar();
        }
    }
    else{
        $error = [];
        $error["msg"] = "Unknown Action";
        $error["code"] = 500;
        echo json_encode($error);
    }
}

//DB Connection
function getMysqlConnection(){
    $credentials = getDataBaseCredentials();

    $mysqli = new mysqli("localhost", $credentials["user"], $credentials["password"], $credentials["name"]);
    if ($mysqli->connect_error) {
        die("SQL-Connection failed!");
    }

    mysqli_set_charset($mysqli, "utf8");
    return $mysqli;
}

function getDataBaseCredentials(){
    $credentials = json_decode(file_get_contents("credentials.json"), true);

    return $credentials;
}

function read(){
    $mysqli = getMysqlConnection();

    $last_time = $_POST["last_time"];

    $result = $mysqli->query("SELECT * FROM chat_log WHERE time > '" . $last_time . "'");
    $messages = $result->fetch_all(MYSQLI_ASSOC);
    
    $mysqli->close();

    $response = [];
    $response["code"] = 200;
    $response["msg"] = "OK";

    return json_encode($messages);
}

function write(){
    $mysqli = getMysqlConnection();

    $sender = $_POST["sender"];
    $message = $_POST["message"];

    $mysqli->query(
        "INSERT INTO chat_log (sender, text) " .
        "VALUES ('" . $sender . "', '" . $message . "')"
    );

    $mysqli->close();

    $response = [];
    $response["code"] = 200;
    $response["msg"] = "OK";

    return json_encode($response);
}