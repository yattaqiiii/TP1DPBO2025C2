public class PetShop {
    // Atribut untuk menyimpan data produk dalam node
    private int id;
    private String nama;
    private String kategori;
    private double harga;
    private PetShop next;  // Pointer ke node berikutnya

    // Constructor
    public PetShop() {
        this.next = null;
    }

    // Constructor dengan parameter
    public PetShop(int id, String nama, String kategori, double harga) {
        this.id = id;
        this.nama = nama;
        this.kategori = kategori;
        this.harga = harga;
        this.next = null;
    }

    // Method untuk menampilkan semua data
    public void tampilkanData() {
        if (this.next == null) {
            System.out.println("Tidak ada data yang tersedia.");
            return;
        }

        PetShop current = this.next;
        while (current != null) {
            System.out.printf("ID: %d, Nama: %s, Kategori: %s, Harga: %.2f\n",
                    current.id, current.nama, current.kategori, current.harga);
            current = current.next;
        }
    }

    // Method untuk menambah data baru
    public void tambahData(int id, String nama, String kategori, double harga) {
        PetShop newNode = new PetShop(id, nama, kategori, harga);

        // Jika list kosong atau ID baru lebih kecil dari head
        if (this.next == null || id < this.next.id) {
            newNode.next = this.next;
            this.next = newNode;
            System.out.println("Data berhasil ditambahkan.");
            return;
        }

        // Cari posisi yang tepat untuk insert
        PetShop current = this.next;
        while (current.next != null && current.next.id < id) {
            current = current.next;
        }

        // Insert node baru
        newNode.next = current.next;
        current.next = newNode;
        System.out.println("Data berhasil ditambahkan.");
    }

    // Method untuk mengubah data
    public void ubahData(int id, String namaBaru, String kategoriBaru, double hargaBaru) {
        PetShop current = this.next;
        while (current != null) {
            if (current.id == id) {
                current.nama = namaBaru;
                current.kategori = kategoriBaru;
                current.harga = hargaBaru;
                System.out.println("Data berhasil diubah.");
                return;
            }
            current = current.next;
        }
        System.out.println("Data dengan ID " + id + " tidak ditemukan.");
    }

    // Method untuk menghapus data
    public void hapusData(int id) {
        if (this.next == null) {
            System.out.println("Data dengan ID " + id + " tidak ditemukan.");
            return;
        }

        if (this.next.id == id) {
            this.next = this.next.next;
            System.out.println("Data berhasil dihapus.");
            return;
        }

        PetShop current = this.next;
        while (current.next != null) {
            if (current.next.id == id) {
                current.next = current.next.next;
                System.out.println("Data berhasil dihapus.");
                return;
            }
            current = current.next;
        }

        System.out.println("Data dengan ID " + id + " tidak ditemukan.");
    }

    // Method untuk mencari data
    public void cariData(String nama) {
        if (this.next == null) {
            System.out.println("Data dengan nama " + nama + " tidak ditemukan.");
            return;
        }

        boolean ditemukan = false;
        PetShop current = this.next;
        while (current != null) {
            if (current.nama.equals(nama)) {
                System.out.printf("ID: %d, Nama: %s, Kategori: %s, Harga: %.2f\n",
                        current.id, current.nama, current.kategori, current.harga);
                ditemukan = true;
            }
            current = current.next;
        }

        if (!ditemukan) {
            System.out.println("Data dengan nama " + nama + " tidak ditemukan.");
        }
    }

    // Main method
    public static void main(String[] args) {
        PetShop toko = new PetShop();  // Dummy head node
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int pilihan;

        do {
            System.out.println("\nMenu:");
            System.out.println("1. Tampilkan data");
            System.out.println("2. Tambah data");
            System.out.println("3. Ubah data");
            System.out.println("4. Hapus data");
            System.out.println("5. Cari data");
            System.out.println("6. Keluar");
            System.out.print("Pilih: ");

            pilihan = scanner.nextInt();
            scanner.nextLine(); // consume newline

            switch (pilihan) {
                case 1:
                    toko.tampilkanData();
                    break;
                case 2:
                    System.out.print("Masukkan ID: ");
                    int id = scanner.nextInt();
                    scanner.nextLine(); // consume newline
                    System.out.print("Masukkan nama produk: ");
                    String nama = scanner.nextLine();
                    System.out.print("Masukkan kategori produk: ");
                    String kategori = scanner.nextLine();
                    System.out.print("Masukkan harga produk: ");
                    double harga = scanner.nextDouble();
                    toko.tambahData(id, nama, kategori, harga);
                    break;
                case 3:
                    System.out.print("Masukkan ID yang ingin diubah: ");
                    int idUbah = scanner.nextInt();
                    scanner.nextLine(); // consume newline
                    System.out.print("Masukkan nama baru: ");
                    String namaBaru = scanner.nextLine();
                    System.out.print("Masukkan kategori baru: ");
                    String kategoriBaru = scanner.nextLine();
                    System.out.print("Masukkan harga baru: ");
                    double hargaBaru = scanner.nextDouble();
                    toko.ubahData(idUbah, namaBaru, kategoriBaru, hargaBaru);
                    break;
                case 4:
                    System.out.print("Masukkan ID yang ingin dihapus: ");
                    int idHapus = scanner.nextInt();
                    toko.hapusData(idHapus);
                    break;
                case 5:
                    System.out.print("Masukkan nama produk yang ingin dicari: ");
                    String namaCari = scanner.nextLine();
                    toko.cariData(namaCari);
                    break;
                case 6:
                    System.out.println("Keluar dari program.");
                    break;
                default:
                    System.out.println("Pilihan tidak valid.");
            }
        } while (pilihan != 6);

        scanner.close();
    }
}