# **Janji**

Saya Yattaqi Ahmad Faza dengan NIM 2311216 mengerjakan soal Latihan Praktikum & Tugas Praktikum 1 dalam mata kuliah Desain Pemrograman Berorientasi Objek untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.

---

## **Desain Program**

Program ini terdiri dari **2 class**:
1. **`Main`**: Class ini berfungsi sebagai entry point program dan menangani interaksi dengan pengguna melalui menu.
2. **`PetShop`**: Class ini bertanggung jawab untuk mengelola data produk menggunakan struktur data **linked list**.

Class `PetShop` memiliki **4 atribut**:
- **ID**: Identifier unik untuk setiap produk.
- **Nama**: Nama dari produk yang dijual.
- **Kategori**: Kategori produk (misalnya: makanan, aksesoris, dll).
- **Harga**: Harga dari produk.
- **next**: Pointer ke node berikutnya dalam linked list.

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

1. **Constructor**:
   - `PetShop()`: Constructor default yang menginisialisasi `next` sebagai `null`.
   - `PetShop(int id, String nama, String kategori, double harga)`: Constructor dengan parameter yang menginisialisasi atribut `id`, `nama`, `kategori`, dan `harga`.

2. **Method `tampilkanData()`**:
   - Menampilkan semua data produk yang tersimpan dalam linked list.
   - Jika tidak ada data, akan menampilkan pesan "Tidak ada data yang tersedia."

3. **Method `tambahData(int id, String nama, String kategori, double harga)`**:
   - Menambahkan data produk baru ke dalam linked list.
   - Data akan disimpan secara terurut berdasarkan ID.
   - Jika ID sudah ada, data tidak akan ditambahkan.

4. **Method `ubahData(int id, String namaBaru, String kategoriBaru, double hargaBaru)`**:
   - Mengubah data produk berdasarkan ID.
   - Jika ID ditemukan, data akan diubah sesuai dengan input baru.
   - Jika ID tidak ditemukan, akan menampilkan pesan error.

5. **Method `hapusData(int id)`**:
   - Menghapus data produk berdasarkan ID.
   - Jika ID ditemukan, data akan dihapus dari linked list.
   - Jika ID tidak ditemukan, akan menampilkan pesan error.

6. **Method `cariData(String nama)`**:
   - Mencari data produk berdasarkan nama.
   - Jika ditemukan, akan menampilkan detail produk.
   - Jika tidak ditemukan, akan menampilkan pesan error.

---

### **Class `Main`**

1. **Method `main(String[] args)`**:
   - Method utama yang menjalankan program.
   - Menampilkan menu dan memproses input pengguna.
   - Menggunakan objek `PetShop` untuk mengelola data produk.

2. **Interaksi Menu**:
   - Pengguna dapat memilih menu untuk menampilkan, menambah, mengubah, menghapus, atau mencari data produk.
   - Program akan terus berjalan sampai pengguna memilih untuk keluar (menu 6).

---

## **Keterangan Tambahan**

- **ID sebagai Acuan**:
  - ID digunakan sebagai acuan utama untuk operasi seperti menambah, mengubah, menghapus, dan mencari data.
  - Saat menambah data, ID tidak boleh sama dengan ID yang sudah ada.
  - Saat mengubah, menghapus, atau mencari data, ID harus tersedia di dalam linked list.

- **Linked List**:
  - Data disimpan dalam bentuk linked list, di mana setiap node menyimpan informasi tentang satu produk.
  - Linked list memungkinkan penambahan, penghapusan, dan pencarian data dengan efisien.

---

## **Contoh Interaksi**

1. **Menambah Data**:
   - Pengguna memilih menu 2 (Tambah data).
   - Pengguna diminta memasukkan ID, nama, kategori, dan harga produk.
   - Data akan ditambahkan ke dalam linked list jika ID belum ada.

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
   - Jika ID ditemukan, data akan dihapus dari linked list.

5. **Mencari Data**:
   - Pengguna memilih menu 5 (Cari data).
   - Pengguna diminta memasukkan nama produk yang ingin dicari.
   - Jika ditemukan, program akan menampilkan detail produk.

6. **Keluar**:
   - Pengguna memilih menu 6 (Keluar).
   - Program akan berhenti.

---
