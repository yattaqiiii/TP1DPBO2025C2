<?php
session_start();
require_once 'class/Product.php';

// Handle image uploads folder
$upload_dir = 'uploads/';
if (!file_exists($upload_dir)) {
    mkdir($upload_dir, 0777, true);
}

$product = new Product();

// Get products based on search or show all
$products = isset($_GET['search']) ? 
    $product->search($_GET['search']) : 
    $product->getAll();
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>PetShop Management System</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css" rel="stylesheet">
</head>
<body>
    <div class="container mt-4">
        <h1>PetShop Product Management</h1>
        
        <?php if (isset($_SESSION['message'])): ?>
            <div class="alert alert-success">
                <?php 
                    echo $_SESSION['message']; 
                    unset($_SESSION['message']);
                ?>
            </div>
        <?php endif; ?>

        <!-- Add Product Form -->
        <div class="card mb-4">
            <div class="card-header">Add New Product</div>
            <div class="card-body">
                <form action="process.php" method="POST" enctype="multipart/form-data">
                    <input type="hidden" name="action" value="create">
                    <div class="mb-3">
                        <label>Name:</label>
                        <input type="text" name="name" class="form-control" required>
                    </div>
                    <div class="mb-3">
                        <label>Category:</label>
                        <input type="text" name="category" class="form-control" required>
                    </div>
                    <div class="mb-3">
                        <label>Price:</label>
                        <input type="number" name="price" class="form-control" required>
                    </div>
                    <div class="mb-3">
                        <label>Image:</label>
                        <input type="file" name="image" class="form-control" required accept="image/*">
                    </div>
                    <button type="submit" class="btn btn-primary">Add Product</button>
                </form>
            </div>
        </div>

        <!-- Search Form -->
        <div class="card mb-4">
            <div class="card-header">Search Products</div>
            <div class="card-body">
                <form method="GET">
                    <div class="input-group">
                        <input type="text" name="search" class="form-control" placeholder="Search by product name" value="<?php echo isset($_GET['search']) ? htmlspecialchars($_GET['search']) : ''; ?>">
                        <button type="submit" class="btn btn-primary">Search</button>
                        <?php if (isset($_GET['search'])): ?>
                            <a href="index.php" class="btn btn-secondary">Clear</a>
                        <?php endif; ?>
                    </div>
                </form>
            </div>
        </div>

        <!-- Products List -->
        <div class="card">
            <div class="card-header">Products List</div>
            <div class="card-body">
                <?php if (empty($products)): ?>
                    <p class="text-center">No products found.</p>
                <?php else: ?>
                    <table class="table">
                        <thead>
                            <tr>
                                <th>ID</th>
                                <th>Image</th>
                                <th>Name</th>
                                <th>Category</th>
                                <th>Price</th>
                                <th>Actions</th>
                            </tr>
                        </thead>
                        <tbody>
                            <?php foreach ($products as $item): ?>
                            <tr>
                                <td><?php echo $item['id']; ?></td>
                                <td><img src="uploads/<?php echo $item['image']; ?>" width="50" height="50" style="object-fit: cover;"></td>
                                <td><?php echo htmlspecialchars($item['name']); ?></td>
                                <td><?php echo htmlspecialchars($item['category']); ?></td>
                                <td>Rp <?php echo number_format($item['price'], 0, ',', '.'); ?></td>
                                <td>
                                    <a href="edit.php?id=<?php echo $item['id']; ?>" class="btn btn-sm btn-warning">Edit</a>
                                    <form action="process.php" method="POST" style="display:inline;">
                                        <input type="hidden" name="action" value="delete">
                                        <input type="hidden" name="id" value="<?php echo $item['id']; ?>">
                                        <button type="submit" class="btn btn-sm btn-danger" onclick="return confirm('Are you sure?')">Delete</button>
                                    </form>
                                </td>
                            </tr>
                            <?php endforeach; ?>
                        </tbody>
                    </table>
                <?php endif; ?>
            </div>
        </div>
    </div>
</body>
</html>