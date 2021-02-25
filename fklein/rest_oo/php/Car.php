<?php

class Car{
    private ?int $id = null;
    private ?string $brand = null;
    private ?string $model = null;
    private ?string $color = null;
    private ?int $year = null;
    private bool $in_database = false;

    function __construct($id = null, $brand = null, $model = null, $color = null, $year = null){
        $this->id = $id;
        $this->brand = $brand;
        $this->model = $model;
        $this->color = $color;
        $this->year = $year;
        $this->in_database = false;
    }

    public function getId(){
        return $this->id;
    }

    public function getBrand(){
        return $this->brand;
    }

    public function setBrand($brand){
        $this->brand = $brand;
    }

    public function getModel(){
        return $this->model;
    }

    public function setModel($model){
        $this->model = $model;
    }

    public function getColor(){
        return $this->color;
    }

    public function setColor($color){
        $this->color = $color;
    }

    public function getYear(){
        return $this->year;
    }

    public function setYear($year){
        $this->year = $year;
    }

    public function isInDatabse(){
        return $this->in_database;
    }

    public function getRestFields(){
        return [
            "id" => $this->id,
            "brand" => $this->brand,
            "model" => $this->model,
            "color" => $this->color,
            "year" => $this->year,
            "in_database" => $this->in_database
        ];
    }

    public function updateFromRestFields($data){
        $this->brand = $data->brand;
        $this->model = $data->model;
        $this->color = $data->color;
        $this->year = $data->year;
    }

    public function writeToDatabase($mysqli){
        $id = $this->id;
        $brand = $mysqli->real_escape_string($this->brand);
        $model = $mysqli->real_escape_string($this->model);
        $color = $mysqli->real_escape_string($this->color);
        $year = $this->year;

        if($this->in_database){
            $mysqli->query(
                "UPDATE car " .
                "SET brand='" . $brand . "', model='" . $model . "', color='" . $color . "', year=" . $year . " " .
                "WHERE id=" . $id
            );
        }
        else{
            $mysqli->query(
                "INSERT INTO car (brand, model, color, year) " .
                "VALUES ('" . $brand . "', '" . $model . "', '" . $color . "', " . $year . ")"
            );
        }

        $this->in_database = true;
    }
}