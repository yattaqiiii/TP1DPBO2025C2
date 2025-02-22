# **Janji**

Saya Yattaqi Ahmad Faza dengan NIM 2311216 mengerjakan soal Latihan Praktikum & Tugas Praktikum 1 dalam mata kuliah Desain Pemrograman Berorientasi Objek untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.

---

## **Desain Program**

Program ini terdiri dari **1 class utama** yaitu `PetShop` yang memiliki **1 atribut private**:
- **`__products`**: Sebuah list yang menyimpan data produk. Atribut ini dibuat private menggunakan Python's name mangling (`self.__products`).

Setiap produk dalam list `__products` direpresentasikan sebagai dictionary dengan **4 key**:
- **`id`**: Identifier unik untuk setiap produk.
- **`nama`**: Nama dari produk yang dijual.
- **`kategori`**: Kategori produk (misalnya: makanan, aksesoris, dll).
- **`harga`**: Harga dari produk.

---

## **Alur Program**

1. **Menu Utama**:
   - Program menampilkan menu dengan 6 pilihan:
     - **1 | Tampilkan data**: Menampilkan semua data produk yang tersimpan.
     - **2 | Tambah data**: Menambahkan data produk baru.
     - **3 | Ubah data**: Mengubah data produk berdasarkan ID.
     - **4 | Hapus data**: Menghapus data produk berdasarkan ID.
     - **5 | Cari data**: Mencari data produk berdasarkan nama.
     - **6 | Keluar**: Keluar dari program.

2. **Interaksi Pengguna**:
   - Pengguna dapat memilih menu dengan memasukkan angka sesuai pilihan yang diinginkan.
   - Program akan memproses input pengguna dan menjalankan operasi yang sesuai.

---

## **Fungsi dan Method**

### **Class `PetShop`**

1. **Constructor `__init__`**:
   - Menginisialisasi atribut private `__products` sebagai list kosong.

2. **Method `tampilkan_data()`**:
   - Menampilkan semua data produk yang tersimpan dalam list `__products`.
   - Jika tidak ada data, akan menampilkan pesan "tidak ada data yang tersedia."

3. **Method `tambah_data(id, nama, kategori, harga)`**:
   - Menambahkan data produk baru ke dalam list `__products`.
   - Data produk disimpan sebagai dictionary dengan key `id`, `nama`, `kategori`, dan `harga`.
   - Setelah data berhasil ditambahkan, program akan menampilkan pesan "data berhasil ditambahkan."

4. **Method `ubah_data(id, nama_baru, kategori_baru, harga_baru)`**:
   - Mengubah data produk berdasarkan ID.
   - Jika ID ditemukan, data akan diubah sesuai dengan input baru.
   - Jika ID tidak ditemukan, akan menampilkan pesan error.

5. **Method `hapus_data(id)`**:
   - Menghapus data produk berdasarkan ID.
   - Jika ID ditemukan, data akan dihapus dari list `__products`.
   - Jika ID tidak ditemukan, akan menampilkan pesan error.

6. **Method `cari_data(nama)`**:
   - Mencari data produk berdasarkan nama.
   - Jika ditemukan, akan menampilkan detail produk.
   - Jika tidak ditemukan, akan menampilkan pesan error.

---

### **Fungsi `main()`**

1. **Inisialisasi Objek `PetShop`**:
   - Membuat objek `toko` dari class `PetShop`.

2. **Loop Menu Utama**:
   - Program akan terus menampilkan menu dan memproses input pengguna sampai pengguna memilih untuk keluar (menu 6).

3. **Pemrosesan Input**:
   - Pengguna dapat memilih menu untuk menampilkan, menambah, mengubah, menghapus, atau mencari data produk.
   - Program akan menangani input yang tidak valid (misalnya, input bukan angka).

---

## **Keterangan Tambahan**

- **Atribut Private (`__products`)**:
  - Atribut `__products` dibuat private menggunakan Python's name mangling untuk mencegah akses langsung dari luar class.
  - Hal ini memastikan bahwa data produk hanya dapat dimodifikasi melalui method yang disediakan oleh class `PetShop`.

- **ID sebagai Acuan**:
  - ID digunakan sebagai acuan utama untuk operasi seperti mengubah, menghapus, dan mencari data.
  - Saat menambah data, ID tidak diperiksa apakah sudah ada atau belum (dalam kode ini, ID bisa duplikat).

- **List sebagai Penyimpanan Data**:
  - Data disimpan dalam bentuk list of dictionaries, di mana setiap dictionary menyimpan informasi tentang satu produk.
  - List memungkinkan penambahan, penghapusan, dan pencarian data dengan mudah.

---

## **Contoh Interaksi**

1. **Menambah Data**:
   - Pengguna memilih menu 2 (Tambah data).
   - Pengguna diminta memasukkan ID, nama, kategori, dan harga produk.
   - Data akan ditambahkan ke dalam list `__products`.

2. **Menampilkan Data**:
   - Pengguna memilih menu 1 (Tampilkan data).
   - Program akan menampilkan semua data produk yang tersimpan.

3. **Mengubah Data**:
   - Pengguna memilih menu 3 (Ubah data).
   - Pengguna diminta memasukkan ID produk yang ingin diubah.
   - Jika ID ditemukan, pengguna dapat memasukkan nama, kategori, dan harga baru.

4. **Menghapus Data**:
   - Pengguna memilih menu 4 (Hapus data).
   - Pengguna diminta memasukkan ID produk yang ingin dihapus.
   - Jika ID ditemukan, data akan dihapus dari list `__products`.

5. **Mencari Data**:
   - Pengguna memilih menu 5 (Cari data).
   - Pengguna diminta memasukkan nama produk yang ingin dicari.
   - Jika ditemukan, program akan menampilkan detail produk.

6. **Keluar**:
   - Pengguna memilih menu 6 (Keluar).
   - Program akan berhenti.

---
