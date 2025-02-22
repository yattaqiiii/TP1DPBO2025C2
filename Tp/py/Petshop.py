class PetShop:
    def __init__(self):
        # Private attributes using Python's name mangling
        self.__products = []
    
    # Method to display all products
    def tampilkan_data(self):
        if not self.__products:
            print("tidak ada data yang tersedia.")
            return
        
        for product in self.__products:
            print(f"id: {product['id']}, nama: {product['nama']}, kategori: {product['kategori']}, harga: {product['harga']}")

    # Method to add new product
    def tambah_data(self, id, nama, kategori, harga):
        product = {
            'id': id,
            'nama': nama,
            'kategori': kategori,
            'harga': harga
        }
        self.__products.append(product)
        print("data berhasil ditambahkan.")

    # Method to update existing product
    def ubah_data(self, id, nama_baru, kategori_baru, harga_baru):
        for product in self.__products:
            if product['id'] == id:
                product['nama'] = nama_baru
                product['kategori'] = kategori_baru
                product['harga'] = harga_baru
                print("data berhasil diubah.")
                return
        print(f"data dengan id {id} tidak ditemukan.")

    # Method to delete product
    def hapus_data(self, id):
        for i, product in enumerate(self.__products):
            if product['id'] == id:
                self.__products.pop(i)
                print("data berhasil dihapus.")
                return
        print(f"data dengan id {id} tidak ditemukan.")

    # Method to search product by name
    def cari_data(self, nama):
        found = False
        for product in self.__products:
            if product['nama'] == nama:
                print(f"id: {product['id']}, nama: {product['nama']}, kategori: {product['kategori']}, harga: {product['harga']}")
                found = True
        
        if not found:
            print(f"data dengan nama {nama} tidak ditemukan.")

def main():
    toko = PetShop()
    
    while True:
        print("\nmenu:")
        print("1. tampilkan data")
        print("2. tambah data")
        print("3. ubah data")
        print("4. hapus data")
        print("5. cari data")
        print("6. keluar")
        
        try:
            pilihan = int(input("pilih: "))
            
            if pilihan == 1:
                toko.tampilkan_data()
            
            elif pilihan == 2:
                id = int(input("masukkan id: "))
                nama = input("masukkan nama produk: ")
                kategori = input("masukkan kategori produk: ")
                harga = float(input("masukkan harga produk: "))
                toko.tambah_data(id, nama, kategori, harga)
            
            elif pilihan == 3:
                id = int(input("masukkan id yang ingin diubah: "))
                nama = input("masukkan nama baru: ")
                kategori = input("masukkan kategori baru: ")
                harga = float(input("masukkan harga baru: "))
                toko.ubah_data(id, nama, kategori, harga)
            
            elif pilihan == 4:
                id = int(input("masukkan id yang ingin dihapus: "))
                toko.hapus_data(id)
            
            elif pilihan == 5:
                nama = input("masukkan nama produk yang ingin dicari: ")
                toko.cari_data(nama)
            
            elif pilihan == 6:
                print("keluar dari program.")
                break
            
            else:
                print("pilihan tidak valid.")
                
        except ValueError:
            print("input tidak valid. masukkan angka untuk pilihan menu.")

if __name__ == "__main__":
    main()