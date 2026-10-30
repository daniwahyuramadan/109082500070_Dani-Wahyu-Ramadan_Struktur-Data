# <h1 align="center">Laporan Praktikum Modul 6 - Struktur Data</h1>
<p align="center">Dani Wahyu Ramadan - 109082500070</p>

## Dasar Teori
### A.  Doubly Linked List

Doubly Linked List adalah struktur data linier berkait yang setiap elemennya (node) memiliki dua buah pointer/successor, yaitu prev yang menunjuk ke elemen sebelumnya dan next yang menunjuk ke elemen sesudahnya. Struktur ini mempermudah traversal atau penelusuran data secara dua arah (maju dan mundur).

## Guided 

### 1. Doublylist.h

#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <string>
using namespace std;

struct kendaraan {
    string nopol;
    string warna;
    int thnbuat;
};

typedef kendaraan infotype;
struct elmlist;
typedef elmlist* address;

struct elmlist {
    infotype info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

// Prototipe Fungsi dan Prosedur
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(const List &L);
void insertLast(List &L, address P);
void insertFirst(List &L, address P);
address findElm(const List &L, string nopol);
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);

#endif


penjelasan singkat guided 1 :

 Doublylist.h berfungsi untuk mendefinisikan tipe data bentukan kendaraan (berisi nomor polisi, warna, dan tahun pembuatan), pointer node address, struktur elmlist, serta struktur List yang memiliki penunjuk First dan Last. File ini juga mendeklarasikan seluruh prototipe fungsi dan prosedur primitif Doubly Linked List.


### 2. Doublylist.cpp

#include <iostream>
#include "Doublylist.h"

using namespace std;

void CreateList(List &L) {
    L.First = nullptr;
    L.Last = nullptr;
}

address alokasi(infotype x) {
    address P = new elmlist;
    P->info = x;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = nullptr;
}

void printInfo(const List &L) {
    address P = L.First;
    if (P == nullptr) {
        cout << "List kosong." << endl;
    } else {
        cout << "\nDATA LIST 1" << endl;
        while (P != nullptr) {
            cout << "no polisi : " << P->info.nopol << endl;
            cout << "warna     : " << P->info.warna << endl;
            cout << "tahun     : " << P->info.thnbuat << endl;
            P = P->next;
        }
    }
}

void insertLast(List &L, address P) {
    if (L.First == nullptr) {
        L.First = P;
        L.Last = P;
    } else {
        L.Last->next = P;
        P->prev = L.Last;
        L.Last = P;
    }
}

void insertFirst(List &L, address P) {
    if (L.First == nullptr) {
        L.First = P;
        L.Last = P;
    } else {
        P->next = L.First;
        L.First->prev = P;
        L.First = P;
    }
}

address findElm(const List &L, string nopol) {
    address P = L.First;
    while (P != nullptr) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

void deleteFirst(List &L, address &P) {
    if (L.First == nullptr) {
        P = nullptr;
    } else if (L.First == L.Last) {
        P = L.First;
        L.First = nullptr;
        L.Last = nullptr;
    } else {
        P = L.First;
        L.First = L.First->next;
        L.First->prev = nullptr;
        P->next = nullptr;
    }
}

void deleteLast(List &L, address &P) {
    if (L.First == nullptr) {
        P = nullptr;
    } else if (L.First == L.Last) {
        P = L.First;
        L.First = nullptr;
        L.Last = nullptr;
    } else {
        P = L.Last;
        L.Last = L.Last->prev;
        L.Last->next = nullptr;
        P->prev = nullptr;
    }
}

void deleteAfter(List &L, address Prec, address &P) {
    if (Prec != nullptr && Prec->next != nullptr) {
        P = Prec->next;
        Prec->next = P->next;
        if (P->next != nullptr) {
            P->next->prev = Prec;
        } else {
            L.Last = Prec;
        }
        P->next = nullptr;
        P->prev = nullptr;
    } else {
        P = nullptr;
    }
}


penjelasan singkat guided 2 :

 berisi logika implementasi dari seluruh prosedur dan fungsi primitif Doubly Linked List, meliputi pengalokasian/idealokasi memori, penambahan node (insertFirst, insertLast), pencarian node (findElm), serta penghapusan node (deleteFirst, deleteLast, deleteAfter).


### 3. main.cpp

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


penjelasan singkat guided 3 :

engeksekusi alur program utama untuk memasukkan data kendaraan secara dinamis, melakukan pengecekan duplikasi nopol, menampilkan seluruh isi list, melakukan pencarian data kendaraan berdasarkan nopol, serta menghapus data kendaraan dari list.


## Unguided 

### 1. Buatlah ADT Doubly Linked list sebagai berikut di dalam file “Doublylist.h”:

Doublylist.h

#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <string>
using namespace std;

struct kendaraan {
    string nopol;
    string warna;
    int thnbuat;
};

typedef kendaraan infotype;
struct elmlist;
typedef elmlist* address;

struct elmlist {
    infotype info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(const List &L);
void insertFirst(List &L, address P);
void insertLast(List &L, address P);

#endif


Doublylist.cpp

#include <iostream>
#include "Doublylist.h"

using namespace std;

void CreateList(List &L) {
    L.First = nullptr;
    L.Last = nullptr;
}

address alokasi(infotype x) {
    address P = new elmlist;
    P->info = x;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = nullptr;
}

void printInfo(const List &L) {
    address P = L.First;
    if (P == nullptr) {
        cout << "List kosong." << endl;
    } else {
        cout << "\nDATA LIST 1" << endl;
        while (P != nullptr) {
            cout << "no polisi : " << P->info.nopol << endl;
            cout << "warna     : " << P->info.warna << endl;
            cout << "tahun     : " << P->info.thnbuat << endl;
            P = P->next;
        }
    }
}

void insertFirst(List &L, address P) {
    if (L.First == nullptr) {
        L.First = P;
        L.Last = P;
    } else {
        P->next = L.First;
        L.First->prev = P;
        L.First = P;
    }
}

void insertLast(List &L, address P) {
    if (L.First == nullptr) {
        L.First = P;
        L.Last = P;
    } else {
        L.Last->next = P;
        P->prev = L.Last;
        L.Last = P;
    }
}

main.cpp

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




### Output Unguided 1 :


<img width="1920" height="1080" alt="Nomer 1" src="https://github.com/user-attachments/assets/d6f856b8-c3a1-4be2-83ab-56d718c5348a" />






penjelasan unguided 1 :

Pada penambahan elemen kendaraan, digunakan insertFirst sehingga data yang baru dimasukkan akan berada di posisi paling depan (head). Dan ditemukan nomor polisi yang sama, sistem memberi peringatan "nomor polisi sudah terdaftar" dan mengabaikan masukan tersebut.




## Kesimpulan
Praktikum Modul 6 mengenai Doubly Linked List memberikan pemahaman mendalam tentang struktur data berkait dua arah. Keberadaan dua pointer (next dan prev) serta penunjuk First dan Last mempermudah pengaksesan, pemrosesan, dan penghapusan data secara fleksibel dibanding Singly Linked List.
