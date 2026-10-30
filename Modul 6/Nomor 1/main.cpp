#include <iostream>
#include "Doublylist.h"

using namespace std;

int main() {
    List L;
    CreateList(L);

    infotype x;
    address P;

    int n;
    cout << "Masukkan jumlah kendaraan yang ingin diinput: ";
    if (!(cin >> n)) return 0;

    for (int i = 0; i < n; i++) {
        cout << "masukkan nomor polisi: ";
        cin >> x.nopol;

        // Cek duplikasi nomor polisi
        if (findElm(L, x.nopol) != nullptr) {
            cout << "nomor polisi sudah terdaftar" << endl;
        } else {
            cout << "masukkan warna kendaraan: ";
            cin >> x.warna;
            cout << "masukkan tahun kendaraan: ";
            cin >> x.thnbuat;

            P = alokasi(x);
            insertFirst(L, P); 
        }
    }

    printInfo(L);

    cout << "\nMasukkan Nomor Polisi yang dicari : ";
    string cariNopol;
    cin >> cariNopol;
    address found = findElm(L, cariNopol);
    if (found != nullptr) {
        cout << "Nomor Polisi : " << found->info.nopol << endl;
        cout << "Warna        : " << found->info.warna << endl;
        cout << "Tahun        : " << found->info.thnbuat << endl;
    } else {
        cout << "Data tidak ditemukan." << endl;
    }

    cout << "\nMasukkan Nomor Polisi yang akan dihapus : ";
    string hapusNopol;
    cin >> hapusNopol;
    address target = findElm(L, hapusNopol);
    
    if (target != nullptr) {
        if (target == L.First) {
            deleteFirst(L, P);
        } else if (target == L.Last) {
            deleteLast(L, P);
        } else {
            deleteAfter(L, target->prev, P);
        }
        dealokasi(P);
        cout << "Data dengan nomor polisi " << hapusNopol << " berhasil dihapus." << endl;
    } else {
        cout << "Data tidak ditemukan." << endl;
    }

    printInfo(L);

    return 0;
}