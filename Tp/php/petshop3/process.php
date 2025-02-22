<?php
session_start();
require_once 'class/Product.php';

$product = new Product();

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $action = $_POST['action'] ?? '';
    
    switch ($action) {
        case 'create':
            if (isset($_FILES['image'])) {
                $image = time() . '_' . $_FILES['image']['name'];
                move_uploaded_file($_FILES['image']['tmp_name'], "uploads/" . $image);
                
                $data = [
                    'name' => $_POST['name'],
                    'category' => $_POST['category'],
                    'price' => $_POST['price'],
                    'image' => $image
                ];
                
                $product->create($data);
                $_SESSION['message'] = "Product added successfully!";
            }
            break;

        case 'update':
            if (isset($_POST['id'])) {
                $data = [
                    'name' => $_POST['name'],
                    'category' => $_POST['category'],
                    'price' => $_POST['price'],
                    'image' => $_POST['current_image']
                ];

                if (isset($_FILES['image']) && $_FILES['image']['size'] > 0) {
                    if (file_exists('uploads/' . $_POST['current_image'])) {
                        unlink('uploads/' . $_POST['current_image']);
                    }
                    
                    $image = time() . '_' . $_FILES['image']['name'];
                    move_uploaded_file($_FILES['image']['tmp_name'], "uploads/" . $image);
                    $data['image'] = $image;
                }
                
                $product->update($_POST['id'], $data);
                $_SESSION['message'] = "Product updated successfully!";
            }
            break;

        case 'delete':
            if (isset($_POST['id'])) {
                $product->delete($_POST['id']);
                $_SESSION['message'] = "Product deleted successfully!";
            }
            break;
    }
    
    header("Location: index.php");
    exit;
}