<?php
session_start();
require_once 'class/Product.php';

$product = new Product();

if (!isset($_GET['id'])) {
    header("Location: index.php");
    exit;
}

$productData = $product->getById($_GET['id']);
if (!$productData) {
    $_SESSION['message'] = "Product not found!";
    header("Location: index.php");
    exit;
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Edit Product - PetShop Management System</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css" rel="stylesheet">
</head>
<body>
    <div class="container mt-4">
        <h1>Edit Product</h1>
        <div class="card">
            <div class="card-body">
                <form action="process.php" method="POST" enctype="multipart/form-data">
                    <input type="hidden" name="action" value="update">
                    <input type="hidden" name="id" value="<?php echo $productData['id']; ?>">
                    <input type="hidden" name="current_image" value="<?php echo $productData['image']; ?>">
                    
                    <div class="mb-3">
                        <label>Name:</label>
                        <input type="text" name="name" class="form-control" value="<?php echo htmlspecialchars($productData['name']); ?>" required>
                    </div>
                    <div class="mb-3">
                        <label>Category:</label>
                        <input type="text" name="category" class="form-control" value="<?php echo htmlspecialchars($productData['category']); ?>" required>
                    </div>
                    <div class="mb-3">
                        <label>Price:</label>
                        <input type="number" name="price" class="form-control" value="<?php echo $productData['price']; ?>" required>
                    </div>
                    <div class="mb-3">
                        <label>Current Image:</label><br>
                        <img src="uploads/<?php echo $productData['image']; ?>" width="100" class="mb-2">
                        <input type="file" name="image" class="form-control" accept="image/*">
                        <small class="text-muted">Leave empty to keep current image</small>
                    </div>
                    <button type="submit" class="btn btn-primary">Update Product</button>
                    <a href="index.php" class="btn btn-secondary">Cancel</a>
                </form>
            </div>
        </div>
    </div>
</body>
</html>