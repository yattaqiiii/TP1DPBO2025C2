#include "petshop.h"

int main() {
    petshop toko; // membuat objek petshop
    int pilihan, id;
    string nama, kategori;
    double harga;

    do {
        // menampilkan menu
        cout << "\nmenu:\n";
        cout << "1. tampilkan data\n";
        cout << "2. tambah data\n";
        cout << "3. ubah data\n";
        cout << "4. hapus data\n";
        cout << "5. cari data\n";
        cout << "6. keluar\n";
        cout << "pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                toko.tampilkan_data();
                break;
            case 2:
                cout << "masukkan id: ";
                cin >> id;
                cin.ignore(); // mengabaikan newline character
                cout << "masukkan nama produk: ";
                getline(cin, nama);
                cout << "masukkan kategori produk: ";
                getline(cin, kategori);
                cout << "masukkan harga produk: ";
                cin >> harga;
                toko.tambah_data(id, nama, kategori, harga);
                break;
            case 3:
                cout << "masukkan id yang ingin diubah: ";
                cin >> id;
                cin.ignore();
                cout << "masukkan nama baru: ";
                getline(cin, nama);
                cout << "masukkan kategori baru: ";
                getline(cin, kategori);
                cout << "masukkan harga baru: ";
                cin >> harga;
                toko.ubah_data(id, nama, kategori, harga);
                break;
            case 4:
                cout << "masukkan id yang ingin dihapus: ";
                cin >> id;
                toko.hapus_data(id);
                break;
            case 5:
                cin.ignore();
                cout << "masukkan nama produk yang ingin dicari: ";
                getline(cin, nama);
                toko.cari_data(nama);
                break;
            case 6:
                cout << "keluar dari program.\n";
                break;
            default:
                cout << "pilihan tidak valid.\n";
        }
    } while (pilihan != 6);

    return 0;
}