<?php
class Product {
    private $products;
    private $last_id;
    
    public function __construct() {
        if (!isset($_SESSION['products'])) {
            $_SESSION['products'] = [];
            $_SESSION['last_id'] = 0;
        }
        $this->products = &$_SESSION['products'];
        $this->last_id = &$_SESSION['last_id'];
    }
    
    public function getAll() {
        return $this->products;
    }
    
    public function getById($id) {
        foreach ($this->products as $product) {
            if ($product['id'] == $id) {
                return $product;
            }
        }
        return null;
    }
    
    public function create($data) {
        $this->last_id++;
        $data['id'] = $this->last_id;
        $data['created_at'] = date('Y-m-d H:i:s');
        $this->products[] = $data;
        return $this->last_id;
    }
    
    public function update($id, $data) {
        foreach ($this->products as $key => $product) {
            if ($product['id'] == $id) {
                $data['id'] = $id;
                $data['created_at'] = $product['created_at'];
                $this->products[$key] = $data;
                return true;
            }
        }
        return false;
    }
    
    public function delete($id) {
        foreach ($this->products as $key => $product) {
            if ($product['id'] == $id) {
                if (file_exists('uploads/' . $product['image'])) {
                    unlink('uploads/' . $product['image']);
                }
                unset($this->products[$key]);
                $this->products = array_values($this->products);
                return true;
            }
        }
        return false;
    }
    
    public function search($keyword) {
        $results = [];
        foreach ($this->products as $product) {
            if (stripos($product['name'], $keyword) !== false) {
                $results[] = $product;
            }
        }
        return $results;
    }
}