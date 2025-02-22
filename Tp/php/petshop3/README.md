# **Janji**

Saya Yattaqi Ahmad Faza dengan NIM 2311216 mengerjakan soal Latihan Praktikum & Tugas Praktikum 1 dalam mata kuliah Desain Pemrograman Berorientasi Objek untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.

---

## **Desain Program**

Program ini dirancang untuk mengelola produk di toko hewan peliharaan dengan fitur-fitur seperti:
- Menambah produk baru.
- Menampilkan daftar produk.
- Mengedit produk yang sudah ada.
- Menghapus produk.
- Mencari produk berdasarkan nama.

Program menggunakan **session** untuk menyimpan data produk dan **file upload** untuk menyimpan gambar produk. Data produk disimpan dalam session PHP, sehingga data akan hilang saat session berakhir.

---

## **Struktur File**

1. **`class/Product.php`**:
   - Berisi class `Product` yang bertanggung jawab untuk mengelola data produk.
   - Data produk disimpan dalam session PHP (`$_SESSION['products']`).

2. **`index.php`**:
   - File utama yang menampilkan antarmuka pengguna (UI) untuk menambah, mencari, dan menampilkan produk.
   - Menampilkan form untuk menambah produk dan form pencarian.

3. **`process.php`**:
   - File yang menangani proses CRUD (Create, Update, Delete) dan upload gambar.
   - Menggunakan method dari class `Product` untuk memproses data.

4. **`edit.php`**:
   - File yang menampilkan form untuk mengedit produk yang sudah ada.
   - Mengambil data produk berdasarkan ID dan menampilkannya dalam form.

---

## **Class `Product`**

Class ini memiliki beberapa method untuk mengelola data produk:

### **Atribut**
- **`$products`**: Menyimpan daftar produk dalam bentuk array.
- **`$last_id`**: Menyimpan ID terakhir yang digunakan untuk produk baru.

### **Method**
1. **`__construct()`**:
   - Constructor yang menginisialisasi session untuk menyimpan data produk jika belum ada.
   - Mengambil data produk dan ID terakhir dari session.

2. **`getAll()`**:
   - Mengembalikan semua produk yang tersimpan.

3. **`getById($id)`**:
   - Mencari produk berdasarkan ID dan mengembalikan data produk jika ditemukan.

4. **`create($data)`**:
   - Menambahkan produk baru ke dalam daftar produk.
   - Menghasilkan ID baru dan menyimpan waktu pembuatan produk.

5. **`update($id, $data)`**:
   - Mengupdate data produk berdasarkan ID.
   - Mempertahankan waktu pembuatan produk.

6. **`delete($id)`**:
   - Menghapus produk berdasarkan ID.
   - Menghapus gambar produk dari direktori upload jika ada.

7. **`search($keyword)`**:
   - Mencari produk berdasarkan nama menggunakan pencarian case-insensitive.

---

## **Alur Program**

1. **Inisialisasi Session**:
   - Program memulai session untuk menyimpan data produk.
   - Jika session belum ada, program akan menginisialisasi array kosong untuk produk dan ID terakhir.

2. **Menu Utama (`index.php`)**:
   - Program menampilkan antarmuka pengguna dengan fitur:
     - **Tambah Produk**: Form untuk menambahkan produk baru.
     - **Cari Produk**: Form untuk mencari produk berdasarkan nama.
     - **Daftar Produk**: Menampilkan semua produk yang tersimpan.

3. **Proses CRUD (`process.php`)**:
   - Program menangani permintaan CRUD (Create, Update, Delete) dari form.
   - Untuk operasi Create dan Update, program juga menangani upload gambar produk.

4. **Edit Produk (`edit.php`)**:
   - Program menampilkan form untuk mengedit produk yang sudah ada.
   - Form ini diisi dengan data produk yang diambil berdasarkan ID.

---

## **Fungsi dan Method**

### **Class `Product`**

1. **Constructor `__construct()`**:
   - Menginisialisasi session untuk menyimpan data produk jika belum ada.
   - Mengambil data produk dan ID terakhir dari session.

2. **Method `getAll()`**:
   - Mengembalikan semua produk yang tersimpan.

3. **Method `getById($id)`**:
   - Mencari produk berdasarkan ID dan mengembalikan data produk jika ditemukan.

4. **Method `create($data)`**:
   - Menambahkan produk baru ke dalam daftar produk.
   - Menghasilkan ID baru dan menyimpan waktu pembuatan produk.

5. **Method `update($id, $data)`**:
   - Mengupdate data produk berdasarkan ID.
   - Mempertahankan waktu pembuatan produk.

6. **Method `delete($id)`**:
   - Menghapus produk berdasarkan ID.
   - Menghapus gambar produk dari direktori upload jika ada.

7. **Method `search($keyword)`**:
   - Mencari produk berdasarkan nama menggunakan pencarian case-insensitive.

---

## **Keterangan Tambahan**

- **Session untuk Penyimpanan Data**:
  - Data produk disimpan dalam session PHP, sehingga data akan hilang saat session berakhir.
  - Session digunakan untuk menyimpan daftar produk dan ID terakhir.

- **Upload Gambar**:
  - Program menyediakan fitur upload gambar untuk setiap produk.
  - Gambar disimpan dalam direktori `uploads/` dengan nama file yang unik.

- **Pencarian Produk**:
  - Program menyediakan fitur pencarian produk berdasarkan nama.
  - Pencarian dilakukan dengan menggunakan fungsi `stripos` untuk pencarian case-insensitive.

---

## **Contoh Interaksi**

1. **Menambah Produk**:
   - Pengguna mengisi form tambah produk dengan nama, kategori, harga, dan gambar.
   - Program akan menyimpan data produk dan gambar ke dalam session dan direktori upload.

2. **Menampilkan Daftar Produk**:
   - Program menampilkan semua produk yang tersimpan dalam session.

3. **Mengedit Produk**:
   - Pengguna memilih produk yang ingin diubah.
   - Program menampilkan form edit dengan data produk yang sudah ada.
   - Pengguna dapat mengubah nama, kategori, harga, dan gambar produk.

4. **Menghapus Produk**:
   - Pengguna memilih produk yang ingin dihapus.
   - Program akan menghapus data produk dari session dan gambar dari direktori upload.

5. **Mencari Produk**:
   - Pengguna memasukkan kata kunci pencarian.
   - Program menampilkan produk yang namanya mengandung kata kunci tersebut.

---
