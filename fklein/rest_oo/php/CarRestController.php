<?php
include "Car.php";
ajax();

//Start
function ajax(){
    if(isset($_POST["action"])){
        $action = $_POST["action"];

        switch($action){
            case 'add':
                echo addCar();
                break;
            case 'getAll':
                echo getAllCars();
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

function getAllCars(){
    $mysqli = getMysqlConnection();
    $query = "SELECT * FROM car;";

    $result = $mysqli->query($query);
    $cars = $result->fetch_all(MYSQLI_ASSOC);
    $mysqli->close();

    $car_array = [];

    if($cars != false){
        foreach($cars as $car){
            $car_obj = new Car($car["id"], $car["brand"], $car["model"], $car["color"], $car["year"]);
            $car_array[] = $car_obj->getRestFields();
        }
    }

    return json_encode($car_array);
}