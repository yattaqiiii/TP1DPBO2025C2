import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        PetShop toko = new PetShop();
        Scanner scanner = new Scanner(System.in);
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