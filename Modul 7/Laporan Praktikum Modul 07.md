# <h1 align="center">Laporan Praktikum Modul 7 - Struktur Data</h1>
<p align="center">Dani Wahyu Ramadan - 109082500070</p>

## Dasar Teori
### A. Stack (Tumpukan)
Stack atau tumpukan adalah bentuk struktur data linear di mana prinsip operasi penambahan dan pengambilan data menggunakan sistem LIFO (Last In First Out). Artinya, elemen yang terakhir kali masuk ke dalam stack akan menjadi elemen pertama yang dapat diambil atau dikeluarkan. Akses pada stack hanya dapat dilakukan pada satu ujung saja yang disebut dengan TOP. Representasi stack dapat diimplementasikan menggunakan pointer (linked list) maupun tabel (array). Pada modul ini, implementasi stack menggunakan representasi tabel (array berindeks dengan batas maksimum tertentu).
 
## Guided 

### 1. stack.h

#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include
using namespace std;

struct infotype {
char nim[20];
char nama[20];
};

struct Stack {
infotype info[10];
int Top;
};

void createStack(Stack &S);
int isEmpty(Stack S);
int isFull(Stack S);
void push(Stack &S, infotype X);
void pop(Stack &S, infotype &X);
void viewStack(Stack S);

#endif

penjelasan singkat guided 1 :

File header (stack.h) ini isinya deklarasi struktur data mahasiswa (nim dan nama), struct Stack pakai array ukuran 10 dengan penanda Top, sama daftar nama fungsi dasar stack yang bakal dipakai.

### 2. stack.cpp

#include "stack.h"

void createStack(Stack &S) {
S.Top = 0;
}

int isEmpty(Stack S) {
if (S.Top == 0) {
return 1;
} else {
return 0;
}
}

int isFull(Stack S) {
if (S.Top == 10) {
return 1;
} else {
return 0;
}
}

void push(Stack &S, infotype X) {
if (isFull(S) == 1) {
cout << "Stack penuh!" << endl;
} else {
S.Top = S.Top + 1;
S.info[S.Top] = X;
}
}

void pop(Stack &S, infotype &X) {
if (isEmpty(S) == 1) {
cout << "Stack kosong!" << endl;
} else {
X = S.info[S.Top];
S.Top = S.Top - 1;
}
}

void viewStack(Stack S) {
if (isEmpty(S) == 1) {
cout << "Stack kosong." << endl;
} else {
cout << "Isi Stack (dari TOP ke bawah):" << endl;
for (int i = S.Top; i >= 1; i--) {
cout << i << ". NIM: " << S.info[i].nim
<< " | Nama: " << S.info[i].nama << endl;
}
}
}

penjelasan singkat guided 2 :

Di file stack.cpp ini semua fungsi dari header tadi dijabarkan cara kerjanya, mulai dari bikin stack kosong (Top = 0), ngecek stack penuh atau kosong, masukin data (push), ngambil data paling atas (pop), sampai nampilin semua isi tumpukan dari atas ke bawah.

### 3. main.cpp

#include
#include
#include "stack.h"
using namespace std;

int main() {
Stack S;
createStack(S);

infotype mhs1, mhs2, mhs3, temp;
strcpy(mhs1.nim, "1090825001"); strcpy(mhs1.nama, "Andi");
strcpy(mhs2.nim, "1090825002"); strcpy(mhs2.nama, "Budi");
strcpy(mhs3.nim, "1090825003"); strcpy(mhs3.nama, "Citra");

cout << "=== PUSH DATA MAHASISWA ===" << endl;
push(S, mhs1);
push(S, mhs2);
push(S, mhs3);
viewStack(S);

cout << "\n=== POP DATA TERATAS ===" << endl;
pop(S, temp);
cout << "Data yang di-pop: " << temp.nim << " - " << temp.nama << endl;

cout << "\n=== ISI STACK SETELAH POP ===" << endl;
viewStack(S);

return 0;


}

penjelasan singkat guided 3 :

Ini program utamanya (main.cpp) buat ngetes semua fungsi tadi. Di sini kita coba masukin tiga data mahasiswa ke stack, tampilin isinya, terus hapus satu data paling atas pakai pop, dan lihat sisa datanya.

## Unguided 

### 1. Buatlah ADT Stack menggunakan ARRAY sebagai berikut di dalam file “stack.h”:

stack.h
#ifndef STACK_H
#define STACK_H

#include
using namespace std;

typedef int infotype;

struct Stack {
infotype info[20];
int top;
};

void createStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif

stack.cpp
#include "stack.h"

void createStack(Stack &S) {
S.top = 0;
}

bool isEmpty(Stack S) {
return S.top == 0;
}

bool isFull(Stack S) {
return S.top == 20;
}

void push(Stack &S, infotype x) {
if (!isFull(S)) {
S.top++;
S.info[S.top] = x;
} else {
cout << "Stack penuh!" << endl;
}
}

infotype pop(Stack &S) {
infotype x = -1;
if (!isEmpty(S)) {
x = S.info[S.top];
S.top--;
} else {
cout << "Stack kosong!" << endl;
}
return x;
}

void printInfo(Stack S) {
cout << "[TOP] ";
for (int i = S.top; i >= 1; i--) {
cout << S.info[i] << " ";
}
cout << endl;
}

void balikStack(Stack &S) {
Stack temp1, temp2;
createStack(temp1);
createStack(temp2);

while (!isEmpty(S)) {
    push(temp1, pop(S));
}
while (!isEmpty(temp1)) {
    push(temp2, pop(temp1));
}
while (!isEmpty(temp2)) {
    push(S, pop(temp2));
}



}

main.cpp
#include
#include "stack.h"
using namespace std;

int main() {
cout << "Hello world!" << endl;
Stack S;
createStack(S);
push(S, 3);
push(S, 4);
push(S, 8);
pop(S);
push(S, 2);
push(S, 3);
pop(S);
push(S, 9);
printInfo(S);
cout << "balik stack" << endl;
balikStack(S);
printInfo(S);
return 0;
}

Output Unguided 1 :

<img width="1917" height="1078" alt="Screenshot Nomor 1" src="https://github.com/user-attachments/assets/10131257-c598-4e9e-879a-e1c737a565a5" />


penjelasan unguided 1 :

Program ini bikin stack pakai array maksimal 20 angka. Di main.cpp, angka dimasukin dan dikeluarin bergantian sampai sisa tumpukannya TOP 9 2 4 3. Terus fungsi balikStack dipakai buat muter balik urutan tumpukannya lewat bantuan dua stack sementara (temp1 dan temp2), jadi hasil akhirnya berubah kebalik jadi TOP 3 4 2 9.


### 2. Tambahkan prosedur pushAscending( in/out S : Stack, in x : integer)

stack.h
#ifndef STACK_H
#define STACK_H

#include
using namespace std;

typedef int infotype;

struct Stack {
infotype info[20];
int top;
};

void createStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x);

#endif

stack.cpp
#include "stack.h"

void createStack(Stack &S) {
S.top = 0;
}

bool isEmpty(Stack S) {
return S.top == 0;
}

bool isFull(Stack S) {
return S.top == 20;
}

void push(Stack &S, infotype x) {
if (!isFull(S)) {
S.top++;
S.info[S.top] = x;
}
}

infotype pop(Stack &S) {
infotype x = -1;
if (!isEmpty(S)) {
x = S.info[S.top];
S.top--;
}
return x;
}

void printInfo(Stack S) {
cout << "[TOP] ";
for (int i = S.top; i >= 1; i--) {
cout << S.info[i] << " ";
}
cout << endl;
}

void balikStack(Stack &S) {
Stack temp1, temp2;
createStack(temp1);
createStack(temp2);

while (!isEmpty(S)) {
    push(temp1, pop(S));
}
while (!isEmpty(temp1)) {
    push(temp2, pop(temp1));
}
while (!isEmpty(temp2)) {
    push(S, pop(temp2));
}



}

void pushAscending(Stack &S, infotype x) {
Stack temp;
createStack(temp);

while (!isEmpty(S) && S.info[S.top] > x) {
    push(temp, pop(S));
}
push(S, x);
while (!isEmpty(temp)) {
    push(S, pop(temp));
}



}

main.cpp
#include
#include "stack.h"
using namespace std;

int main() {
cout << "Hello world!" << endl;
Stack S;
createStack(S);
pushAscending(S, 3);
pushAscending(S, 4);
pushAscending(S, 8);
pushAscending(S, 2);
pushAscending(S, 3);
pushAscending(S, 9);
printInfo(S);
cout << "balik stack" << endl;
balikStack(S);
printInfo(S);
return 0;
}

Output Unguided 2 :

<img width="1917" height="1078" alt="Screenshot Nomor 2" src="https://github.com/user-attachments/assets/c83065db-6a15-4dac-b329-1713ff0335bd" />


penjelasan unguided 2 :

Di sini ditambahin prosedur pushAscending supaya angka yang masuk otomatis keurut dari bawah ke atas (dari kecil ke besar menuju TOP). Jadi pas ada angka baru mau masuk, angka-angka di posisi atas yang nilainya lebih besar bakal dipindahin dulu ke stack sementara (temp), baru angka barunya dimasukin, terus isi temp dibalikin lagi. Hasilnya pas dicetak jadi TOP 9 8 4 3 3 2, dan pas dibalik jadi TOP 2 3 3 4 8 9.


### 3.. Tambahkan prosedur getInputStream( in/out S : Stack ). Prosedur akan terus membaca dan menerima input user dan memasukkan setiap input ke dalam stack hingga user menekan  tombol enter. Contoh: gunakan cin.get() untuk mendapatkan inputan user.

stack.h
#ifndef STACK_H
#define STACK_H

#include
using namespace std;

typedef int infotype;

struct Stack {
infotype info[20];
int top;
};

void createStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x);
void getInputStream(Stack &S);

#endif

stack.cpp
#include "stack.h"

void createStack(Stack &S) {
S.top = 0;
}

bool isEmpty(Stack S) {
return S.top == 0;
}

bool isFull(Stack S) {
return S.top == 20;
}

void push(Stack &S, infotype x) {
if (!isFull(S)) {
S.top++;
S.info[S.top] = x;
}
}

infotype pop(Stack &S) {
infotype x = -1;
if (!isEmpty(S)) {
x = S.info[S.top];
S.top--;
}
return x;
}

void printInfo(Stack S) {
cout << "[TOP] ";
for (int i = S.top; i >= 1; i--) {
cout << S.info[i] << " ";
}
cout << endl;
}

void balikStack(Stack &S) {
Stack temp1, temp2;
createStack(temp1);
createStack(temp2);

while (!isEmpty(S)) {
    push(temp1, pop(S));
}
while (!isEmpty(temp1)) {
    push(temp2, pop(temp1));
}
while (!isEmpty(temp2)) {
    push(S, pop(temp2));
}



}

void pushAscending(Stack &S, infotype x) {
Stack temp;
createStack(temp);

while (!isEmpty(S) && S.info[S.top] > x) {
    push(temp, pop(S));
}
push(S, x);
while (!isEmpty(temp)) {
    push(S, pop(temp));
}



}

void getInputStream(Stack &S) {
char ch;
while (cin.get(ch) && ch != '\n') {
if (ch >= '0' && ch <= '9') {
push(S, ch - '0');
}
}
}

main.cpp
#include
#include "stack.h"
using namespace std;

int main() {
cout << "Hello world!" << endl;
Stack S;
createStack(S);
getInputStream(S);
printInfo(S);
cout << "balik stack" << endl;
balikStack(S);
printInfo(S);
return 0;
}

Output Unguided 3 :

<img width="1917" height="1078" alt="Screenshot 2026-11-15 213725" src="https://github.com/user-attachments/assets/cfaef889-2179-4bc8-8886-254961ecdaaa" />


penjelasan unguided 3 :

Prosedur getInputStream pakai cin.get(ch) buat baca ketikan angka dari user satu per satu sampai user pencet tombol Enter (\n). Setiap angka yang diketik langsung diubah dari karakter ke integer (ch - '0') terus dimasukin ke stack pakai push. Karena sifat stack itu LIFO, angka yang terakhir diketik bakal muncul paling depan di TOP, dan pas di-balikStack urutannya balik lagi seperti input awal.

## Kesimpulan

Stack adalah struktur data tumpukan dengan prinsip LIFO (Last In First Out) yang gampang banget dipakai buat ngelola data yang keluar-masuknya cuma lewat satu ujung (TOP). Dengan memakai array, kita nggak perlu ribet ngurusin alokasi memori manual, dan kita juga bisa ngembangin berbagai variasi operasi kayak balikStack, pushAscending, sama getInputStream sesuai kebutuhan progr
