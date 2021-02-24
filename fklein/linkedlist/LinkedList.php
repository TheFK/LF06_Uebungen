<?php
include "Entry.php";

// @Herr Kreutzer: Livedemo unter: fklein.bplaced.net
class LinkedList
{
    private $firstEntry;
    private $lastEntry;
    private $count;

    function __construct(){
        $this->firstEntry = NULL;
        $this->lastEntry = NULL;
        $this->count = 0;
    }

    public function insertAsFirst($data){
        $entry = new Entry($data);
        $entry->next = $this->firstEntry;
        $this->firstEntry = &$entry;

        if($this->lastEntry == NULL){
            $this->lastEntry = &$entry;
        }

        $this->count++;
    }

    public function add($data){
        $entry = new Entry($data);
        $entry->next = NULL;
        if($this->firstEntry == NULL){
            $this->firstEntry = &$entry;
        }
        if($this->lastEntry != NULL){
            $this->lastEntry->next = $entry;
        }
        
        $this->lastEntry = &$entry;

        $this->count++;
    }

    public function dataAsString(){
        $listData = array();
        $current = $this->firstEntry;
        while($current != NULL){
            array_push($listData, $current->getData());
            $current = $current->next;
        }
        $string = "";
        foreach($listData as $v){
            $string .= $v . " ";
        }
        return $string;
    }

    public function dataAsArray(){
        $listData = array();
        $current = $this->firstEntry;
        while($current != NULL){
            array_push($listData, $current->getData());
            $current = $current->next;
        }
        return $listData;
    }

    public function deleteEntry($key){
        $current = $this->firstEntry;
        $previous = $this->firstEntry;

        while($current->data != $key){
            if($current->next == NULL){
                return NULL;
            }
            else{
                $previous = $current;
                $current = $current->next;
            }
        }

        if($current == $this->firstEntry){
            if($this->count == 1){
                $this->lastEntry = $this->firstEntry;
            }
            $this->firstEntry = $this->firstEntry->next;
        }
        else{
            if($this->lastEntry == $current){
                $this->lastEntry = $previous;
            }
            $previous->next = $current->next;
        }
        $this->count--;  
    }

    public function emptyList(){
        $this->firstEntry == NULL;
    }
 
}