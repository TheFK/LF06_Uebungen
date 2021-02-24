<?php

ajax();

//Start
function ajax(){
    if(isset($_POST["action"])){
        $action = $_POST["action"];

        switch($action){
            case 'add':
                return addCar();
            case 'delete':
                return deleteCar();
        }
    }
    else{
        $error = [];
        $error["msg"] = "Unknown Action";
        $error["code"] = 500;
        return json_encode($error);
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

function addCar(){
    $mysqli = getMysqlConnection();

    $data = json_decode($_POST["data"]);

    $car = new Car();
    $car->updateFromRestFields($data);
    $car->writeToDatabase($mysqli);

    $mysqli->close();

    $response = [];
    $response["code"] = 200;
    $response["msg"] = "OK";

    return json_encode($response);
}





























































function getDataBaseCredentials(){
    return [
        "user" => "fklein",
        "password" => "U1l2i345",
        "name" => "fklein"
    ];
}