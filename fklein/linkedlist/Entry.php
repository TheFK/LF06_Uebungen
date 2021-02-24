<?php

// @Herr Kreutzer: Livedemo unter: fklein.bplaced.net
class Entry{
    public $data;
    public $next;

    function __construct($data){
        $this->data = $data;
        $this->next = NULL;
    }

    function getData(){
        return $this->data;
    }
    
    function setData($data){
        $this->data = $data;
    }


}