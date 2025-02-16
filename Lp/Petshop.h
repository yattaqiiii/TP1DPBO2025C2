#ifndef petshop_h
#define petshop_h

#include <iostream>
#include <string>
using namespace std;

class petshop {
private:
    // struct untuk node linked list
    struct produk {
        int id;
        string nama;
        string kategori;
        double harga;
        produk* next; // pointer ke node selanjutnya

        // constructor untuk inisialisasi node
        produk(int id, const string& nama, const string& kategori, double harga)
            : id(id), nama(nama), kategori(kategori), harga(harga), next(nullptr) {}
    };

    produk* head; // pointer ke node pertama

    // getter untuk id
    int get_id(produk* node) const {
        return node->id;
    }

    // setter untuk id
    void set_id(produk* node, int new_id) {
        node->id = new_id;
    }

    // getter untuk nama
    string get_nama(produk* node) const {
        return node->nama;
    }

    // setter untuk nama
    void set_nama(produk* node, const string& new_nama) {
        node->nama = new_nama;
    }

    // getter untuk kategori
    string get_kategori(produk* node) const {
        return node->kategori;
    }

    // setter untuk kategori
    void set_kategori(produk* node, const string& new_kategori) {
        node->kategori = new_kategori;
    }

    // getter untuk harga
    double get_harga(produk* node) const {
        return node->harga;
    }

    // setter untuk harga
    void set_harga(produk* node, double new_harga) {
        node->harga = new_harga;
    }

public:
    // constructor untuk inisialisasi
    petshop() : head(nullptr) {}

    // destructor untuk menghapus semua data
    ~petshop() {
        while (head != nullptr) {
            produk* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // method untuk menampilkan semua data produk
    void tampilkan_data() const {
        if (head == nullptr) {
            cout << "tidak ada data yang tersedia.\n";
            return;
        }
        produk* current = head;
        while (current != nullptr) {
            cout << "id: " << get_id(current) << ", nama: " << get_nama(current)
                 << ", kategori: " << get_kategori(current) << ", harga: " << get_harga(current) << "\n";
            current = current->next;
        }
    }

    // method untuk menambahkan data produk baru
    void tambah_data(int id, const string& nama, const string& kategori, double harga) {
        produk* new_produk = new produk(id, nama, kategori, harga);
        if (head == nullptr) {
            head = new_produk; // jika linked list kosong, tambahkan sebagai head
        } else {
            produk* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new_produk; // tambahkan di akhir linked list
        }
        cout << "data berhasil ditambahkan.\n";
    }

    // method untuk mengubah data produk berdasarkan id
    void ubah_data(int id, const string& nama_baru, const string& kategori_baru, double harga_baru) {
        produk* current = head;
        while (current != nullptr) {
            if (get_id(current) == id) {
                set_nama(current, nama_baru);          // ubah nama produk
                set_kategori(current, kategori_baru); // ubah kategori produk
                set_harga(current, harga_baru);       // ubah harga produk
                cout << "data berhasil diubah.\n";
                return;
            }
            current = current->next;
        }
        cout << "data dengan id " << id << " tidak ditemukan.\n";
    }

    // method untuk menghapus data produk berdasarkan id
    void hapus_data(int id) {
        if (head == nullptr) {
            cout << "tidak ada data yang tersedia.\n";
            return;
        }
        if (get_id(head) == id) {
            produk* temp = head;
            head = head->next;
            delete temp;
            cout << "data berhasil dihapus.\n";
            return;
        }
        produk* current = head;
        while (current->next != nullptr) {
            if (get_id(current->next) == id) {
                produk* temp = current->next;
                current->next = current->next->next;
                delete temp;
                cout << "data berhasil dihapus.\n";
                return;
            }
            current = current->next;
        }
        cout << "data dengan id " << id << " tidak ditemukan.\n";
    }

    // method untuk mencari data produk berdasarkan nama
    void cari_data(const string& nama) const {
        produk* current = head;
        bool ditemukan = false;
        while (current != nullptr) {
            if (get_nama(current) == nama) {
                cout << "id: " << get_id(current) << ", nama: " << get_nama(current)
                     << ", kategori: " << get_kategori(current) << ", harga: " << get_harga(current) << "\n";
                ditemukan = true;
            }
            current = current->next;
        }
        if (!ditemukan) {
            cout << "data dengan nama " << nama << " tidak ditemukan.\n";
        }
    }
};

#endif