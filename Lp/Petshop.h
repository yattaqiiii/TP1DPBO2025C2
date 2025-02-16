#ifndef petshop_h
#define petshop_h

#include <iostream>
#include <string>
using namespace std;

class petshop {
private:
    // konstanta untuk ukuran maksimum array
    static const int MAX_PRODUK = 100;

    // atribut untuk menyimpan data produk
    int id_produk[MAX_PRODUK];          // array untuk menyimpan id produk
    string nama_produk[MAX_PRODUK];     // array untuk menyimpan nama produk
    string kategori_produk[MAX_PRODUK]; // array untuk menyimpan kategori produk
    double harga_produk[MAX_PRODUK];    // array untuk menyimpan harga produk
    int jumlah_produk;                  // variabel untuk menyimpan jumlah produk yang ada

public:
    // constructor untuk inisialisasi
    petshop() : jumlah_produk(0) {}

    // method untuk menampilkan semua data produk
    void tampilkan_data() const {
        if (jumlah_produk == 0) {
            cout << "tidak ada data yang tersedia.\n";
            return;
        }
        for (int i = 0; i < jumlah_produk; i++) {
            cout << "id: " << id_produk[i] << ", nama: " << nama_produk[i]
                 << ", kategori: " << kategori_produk[i] << ", harga: " << harga_produk[i] << "\n";
        }
    }

    // method untuk menambahkan data produk baru
    void tambah_data(int id, const string& nama, const string& kategori, double harga) {
        if (jumlah_produk >= MAX_PRODUK) {
            cout << "data sudah penuh, tidak bisa menambahkan data baru.\n";
            return;
        }
        id_produk[jumlah_produk] = id;          // simpan id produk
        nama_produk[jumlah_produk] = nama;      // simpan nama produk
        kategori_produk[jumlah_produk] = kategori; // simpan kategori produk
        harga_produk[jumlah_produk] = harga;    // simpan harga produk
        jumlah_produk++;                        // tambah jumlah produk
        cout << "data berhasil ditambahkan.\n";
    }

    // method untuk mengubah data produk berdasarkan id
    void ubah_data(int id, const string& nama_baru, const string& kategori_baru, double harga_baru) {
        for (int i = 0; i < jumlah_produk; i++) {
            if (id_produk[i] == id) {
                nama_produk[i] = nama_baru;          // ubah nama produk
                kategori_produk[i] = kategori_baru;  // ubah kategori produk
                harga_produk[i] = harga_baru;        // ubah harga produk
                cout << "data berhasil diubah.\n";
                return;
            }
        }
        cout << "data dengan id " << id << " tidak ditemukan.\n";
    }

    // method untuk menghapus data produk berdasarkan id
    void hapus_data(int id) {
        for (int i = 0; i < jumlah_produk; i++) {
            if (id_produk[i] == id) {
                // geser semua data setelah indeks ke-i ke kiri
                for (int j = i; j < jumlah_produk - 1; j++) {
                    id_produk[j] = id_produk[j + 1];
                    nama_produk[j] = nama_produk[j + 1];
                    kategori_produk[j] = kategori_produk[j + 1];
                    harga_produk[j] = harga_produk[j + 1];
                }
                jumlah_produk--; // kurangi jumlah produk
                cout << "data berhasil dihapus.\n";
                return;
            }
        }
        cout << "data dengan id " << id << " tidak ditemukan.\n";
    }

    // method untuk mencari data produk berdasarkan nama
    void cari_data(const string& nama) const {
        bool ditemukan = false;
        for (int i = 0; i < jumlah_produk; i++) {
            if (nama_produk[i] == nama) {
                cout << "id: " << id_produk[i] << ", nama: " << nama_produk[i]
                     << ", kategori: " << kategori_produk[i] << ", harga: " << harga_produk[i] << "\n";
                ditemukan = true;
            }
        }
        if (!ditemukan) {
            cout << "data dengan nama " << nama << " tidak ditemukan.\n";
        }
    }
};

#endif