# <h1 align="center">Laporan Praktikum Modul 1 - Struktur Data</h1>
<p align="center">Dani Wahyu Ramadan - 109082500070</p>

## Dasar Teori

Dalam pemrograman C++, pemahaman mengenai struktur data dasar serta kontrol alur memegang peranan yang sangat penting. Dua konsep esensial yang dipakai untuk berbagai kasus pemrograman yaitu Array serta Perulangan For (For Loop).

### A. Array
Array merupakan himpunan dari beberapa variabel bertipe data serupa yang tertata rapi dalam ruang memori berurutan. Setiap elemen di dalam array dapat dipanggil lewat indeks angka, di mana urutan pertama pada bahasa C++ dimulai dari titik 0. Array membantu kita untuk menampung dan mengatur banyak data sekaligus tanpa perlu mendeklarasikan variabel satu persatu secara terpisah.

### B. For Loop
Perulangan for adalah salah satu mekanismemyang difungsikan untuk menjalankan sekumpulan baris perintah secara berulang dan syarat tertentu terpenuhi. Bentuk perulangan ini untuk diterapkan total pengulangan atau literasi telah diketahui secara pasti sebelum program mulai dieksekusi.

## Unguided 

### 1. Buatlah program yang menerima input-an dua buah bilangan betipe float, kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut.

#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

int main() {
    float a, b;
    
    cout << "Masukkan bilangan pertama: ";
    cin >> a;
    cout << "Masukkan bilangan kedua: ";
    cin >> b;

    cout << "\nHasil:" << endl;
    cout << "Penjumlahan : " << a + b << endl;
    cout << "Pengurangan : " << a - b << endl;
    cout << "Perkalian   : " << a * b << endl;
    
    if (b != 0) {
        cout << "Pembagian   : " << a / b << endl;
    } else {
        cout << "Pembagian   : Tidak bisa dibagi dengan nol" << endl;
    }

    return 0;
}

### Output Unguided 1 :

<img width="1917" height="1078" alt="no1" src="https://github.com/user-attachments/assets/3cae8e06-4174-4a42-87be-291a7ae12ae5" />


penjelasan unguided 1 :

Kode program di atas dirancang untuk menjalankan operasi aritmatika tambah, kurang, kali, dan bagi terhadap dua buah angka berformat float. Aplikasi akan meminta user menginputkan dua nilai desimal yang nantinya ditampung dalam variabel a dan b. Berikutnya, sistem langsung memproses kalkulasi matematika tersebut di dalam perintah



### 2. Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di-input-kan user adalah bilangan bulat positif mulai dari 0 s.d 100.

#include <iostream>
#include <string>
using namespace std;

string satuan[] = {"", "Satu", "Dua", "Tiga", "Empat", "Lima", "Enam", "Tujuh", "Delapan", "Sembilan", "Sepuluh", "Sebelas"};

string terbilang(int n) {
    if (n < 12) {
        return satuan[n];
    } else if (n < 20) {
        return satuan[n % 10] + " Belas";
    } else if (n < 100) {
        return satuan[n / 10] + " Puluh " + satuan[n % 10];
    } else if (n == 100) {
        return "Seratus";
    }
    return "";
}

int main() {
    int n;
    cout << "Masukkan angka (0-100): ";
    cin >> n;

    if (n < 0 || n > 100) {
        cout << "Angka di luar jangkauan!" << endl;
    } else if (n == 0) {
        cout << n << " : nol" << endl;
    } else {
        cout << n << " : " << terbilang(n) << endl;
    }

    return 0;
}

### Output Unguided 2 :

![Output Unguided 2](Struktur%20Data%20no2.png)

penjelasan unguided 2 :

## Penjelasan Kodingan Unguided 2

Aplikasi ini dibuat untuk mengubah masukan angka berbentuk numerik dan mulai dari rentang 0 sampai dengan 100 menjadi format kata-kata (huruf).


### 3. Buatlah program yang dapat memberikan input dan output sbb pola piramida berulang dengan angka dan karakter

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "input: ";
    cin >> n;

    cout << "output:" << endl;

    for (int i = n; i >= 1; i--) {
        for (int s = 0; s < n - i; s++) {
            cout << "  ";
        }
        
        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }
        
        cout << "* ";
        
        for (int j = 1; j <= i; j++) {
            cout << j << (j == i ? "" : " ");
        }
        cout << endl;
    }

    for (int s = 0; s < n; s++) {
        cout << "  ";
    }
    cout << "*" << endl;

    return 0;
}

### Output Unguided 3 :

![Output Unguided 3](Struktur%20Data%20no3.png)

penjelasan unguided 3 :

## Penjelasan Kodingan Unguided 3

Sistem ini dirancang untuk mengolah angka masukan "n" untuk merancang sebuah bentuk piramida terbalik yang tersusun secara rapi dan simetris menggunakan kombinasi karakter angka serta simbol bintang. 

## Kesimpulan

Berdasarkan praktikum Modul 1 ini, dapat disimpulkan bahwa:
1. Bahasa C++ untuk mengeksekusi berbagai kalkulasi aritmatika dasar menggunakan data berformat desimal (*float*).
2. Pengubahan angka numerik ke dalam bentuk tulisan kata berhasil diwujudkan melalui penggabungan *array* sebagai penyimpan daftar kata serta logika if-else untuk menentukan aturan satuan, belasan, hingga puluhan.
3. Perancangan bentuk piramida di layar konsol dapat dikuasai melalui penerapan perulangan bersarang nested loop yang berfungsi menata letak spasi, urutan angka, dan karakter simbol secara rapi dan simetris.
