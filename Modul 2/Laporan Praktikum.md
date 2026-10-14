# <h1 align="center">Laporan Praktikum Modul 2 - Struktur Data</h1>
<p align="center"> Dani Wahyu Ramadan- 109082500070 </p>

## Dasar Teori
Dalam menyusun program C++, pemahaman mengenai tata cara tempat memori serta struktur data dasar adalah hal yang krusial. Beberapa konsep esensial yang diaplikasikan mencakup Pointer, Function, serta Procedure.

### A. Pointer
Pointer merupakan sebuah variabel khusus yang berfungsi untuk menampung alamat memori dari variabel lain, bukan menyimpan nilai datanya secara langsung. Pemanfaatan pointer memungkinkan kita untuk memodifikasi isi data secara langsung pada sektor memorinya, sekaligus mempermudah perpindahan variabel di dalam program.

### B. Function
Function adalah blok instruksi mandiri yang bertugas menerima data masukan parameter, menjalankan komputasi tertentu, lalu mengirimkan kembali hasil akhirnya nilai return kepada bagian pemanggilnya.

### C. Procedure
Secara mendasar, Procedure memiliki kesamaan dengan fungsi, hanya saja prosedur tidak menghasilkan atau mengembalikan nilai balik (memakai tipe data void). Prosedur biasanya diandalkan untuk menjalankan sekumpulan perintah, contohnya mencetak keluaran ke layar ataupun memodifikasi nilai variabel global.

## Guided 

### 1. Array 1

#include <iostream>
using namespace std;

int main() {
    int nilai[5];

    nilai[0] = 80;
    nilai[1] = 75;
    nilai[2] = 90;
    nilai[3] = 85;
    nilai[4] = 95;

    for (int i = 0; i < 5; i++) {
        cout << "Nilai ke-" << i + 1 << " = " << nilai[i] << endl;
    }

    return 0;
}

penjelasan singkat guided 1 :

Program ini mendemonstrasikan penerapan Array 1 Dimensi yang berisi 5 slot data bertipe integer, kemudian menampilkan tiap elemennya menggunakan teknik perulangan for.

### 2. Array 2

#include <iostream>
using namespace std;

int main() {
    int nilai[3][3] = {
        {80, 75, 90},
        {85, 90, 88},
        {70, 80, 85}
    };

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << nilai[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << nilai[1][2] << endl;
    return 0;
}

penjelasan singkat guided 2 :

Program mengaplikasikan bentuk Array 2 Dimensi (berupa matriks berukuran 3x3). Seluruh isi matriks dicetak lewat bantuan nested loop (perulangan bersarang), di mana program juga mampu mengambil data pada titik spesifik, yakni baris indeks ke-1 dan kolom indeks ke-2.

### 3. Array 3

#include <iostream>
using namespace std;

int main() {
    int data[2][2][3] = {
        {
            {10, 20, 30},
            {40, 50, 60}
        },
        {
            {70, 80, 90},
            {100, 110, 120}
        }
    };

    cout << data[0][1][2] << endl;

    return 0;
}

penjelasan singkat guided 3 :

Program ini memperlihatkan contoh penggunaan Array 3 Dimensi berdimensi 2 x 2 x 3, yang kemudian mencetak isi data pada titik koordinat indeks [0][1][2], yaitu angka 60.

### 4. Alamat

#include <iostream>
using namespace std;

int main() {
    int angka = 100;

    cout << "Nilai Angka : " << angka << endl;
    cout << "Alamat Angka : " << &angka << endl;

    return 0;
}

penjelasan singkat guided 4 :

Program ini memperlihatkan cara menampilkan isi dari suatu variabel angka (yaitu 100) serta melacak letak alamat memori variabel tersebut di dalam RAM menggunakan operator address of (&angka).

### 5. Pointer 1 dan 2
//Pointer 1
#include <iostream>
using namespace std;

int main() {
    char arr[6];

    arr[0] = 'a';
    arr[1] = 'b';
    arr[2] = 'c';
    arr[3] = 'b';
    arr[4] = 'd';
    arr[5] = 'e';

    cout << arr[3] << endl;
    cout << &(arr[4]) << endl;

}

// Pointer 2
#include <iostream>
using namespace std;

int main() {
    int angka = 100;

    int *pointer;

    pointer = &angka;

    cout << "Nilai angka       :" << angka << endl;
    cout << "Alamat angka      :" << &angka << endl;
    cout << "Isi pointer       :" << pointer << endl;
    cout << "Nilai dari pointer:" << *pointer << endl;


    return 0;

}

penjelasan singkat guided 5 :

Program pertama mencetak karakter tertentu dari array karakter pada indeks ke-3 ('b') serta menampilkan letak memori elemen indeks ke-4 (&(arr[4])) memakai operator &.

Program kedua memperlihatkan fondasi dasar variabel pointer, di mana variabel pointer merekam alamat dari suatu angka, sementara operator dereference (*pointer) dipakai guna membaca nilai yang tersimpan pada alamat tersebut (100).

### 6. Function

#include <iostream>
using namespace std;

int maks3(int a, int b, int c){
    int temp_max = a;

    if (b > temp_max){
        temp_max = b;
    }

    if (c > temp_max){
        temp_max = c;
    }

    return temp_max;
}

int main() {
    int x, y, z;

    cout << "Masukkan nilai 1: ";
    cin >> x;

    cout << "Masukkan nilai 2: ";
    cin >> y;

    cout << "Masukkan nilai 3: ";
    cin >> z;

    cout << "Nilai maksimum = " << maks3(x, y, z);

    return 0;

}

penjelasan singkat guided 6 :

Program ini mengandalkan fungsi maks3() yang dirancang untuk menerima tiga buah parameter integer dan menyeleksi serta mengembalikan nilai yang paling besar di antara ketiganya.

### 7. Procedure

#include <iostream>
using namespace std;

void sapa() {
    cout << "Selamat datang di Telkom University Purwokero" << endl;
}

int main() {
    sapa();
    return 0;
}

penjelasan singkat guided 7 :

Program menerapkan prosedur sapa() dengan tipe data void guna memunculkan teks sambutan ke layar tanpa perlu mengembalikan nilai apa pun.

### 8. callby Value/Pointer/Reference
//Value
#include <iostream>
using namespace std;

void tukar(int x, int y) {
    int temp;

    temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 4;
    int b = 6;

    cout << "Sebelum ditukar:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    tukar(a, b);

    cout << "\nSetelah ditukar:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}
//Pointer
#include <iostream>
using namespace std;

void tukar(int *x, int *y) {
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a = 4;
    int b = 6;

    cout << "Sebelum ditukar:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    tukar(&a, &b);

    cout << "\nSetelah ditukar:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}
// Reference
#include <iostream>

using namespace std;

void tukar(int &x, int &y);

int main () {
    int a, b;
    a=4;  b=6;
    cout << "kondisi sebelum ditukar \n";
    cout << " a = "<<a<<" b = "<<b<<endl;
    tukar(a,b);
    cout<<"kondisi setelah ditukar \n";
    cout << " a = "<<a<<" b = "<<b<<endl;
    return 0;
}

void tukar (int &x, int &y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
    cout<< "nilai akhir pada fungsi tukar \n";
    cout << " x = "<<x<<" y="<<y<<endl;
}

penjelasan singkat guided 8 :

Program membandingkan 3 metode pemanggilan parameter:
Call by Value: Modifikasi nilai di dalam fungsi tidak berdampak pada nilai asli variabel di fungsi main().
Call by Pointer: Mengirimkan alamat memori (&a), sehingga perubahan yang terjadi lewat pointer turut mengubah nilai variabel utama di main().
Call by Reference: Memanfaatkan alias variabel (&x), sehingga setiap perubahan akan langsung memengaruhi variabel aslinya secara langsung di main().


## Unguided 

### 1. Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3  

#include <iostream>
using namespace std;

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int Hasil[3][3];

    cout << "=== HASIL PENJUMLAHAN (A + B) ===" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            Hasil[i][j] = A[i][j] + B[i][j];
            cout << Hasil[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    cout << "=== HASIL PENGURANGAN (A - B) ===" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            Hasil[i][j] = A[i][j] - B[i][j];
            cout << Hasil[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    cout << "=== HASIL PERKALIAN (A x B) ===" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            
            Hasil[i][j] = 0;

            for (int k = 0; k < 3; k++) {
                Hasil[i][j] += A[i][k] * B[k][j];
            }

            cout << Hasil[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}

### Output Unguided 1 :





<img width="1920" height="1080" alt="Soalno 1" src="https://github.com/user-attachments/assets/6c958011-a051-4d18-97d9-b34dc6a39158" />





penjelasan unguided 1 :

Program memanfaatkan Array 2D guna menyelesaikan operasi hitung matriks 3x3. Penjumlahan dan pengurangan dikalkulasikan per elemen, sementara proses perkalian matriks menerapkan tiga lapis perulangan bersarang untuk mengalikan baris matriks A dengan kolom matriks B.

### 2. Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel  

//Pointer
#include <iostream>
using namespace std;

void tukar(int *x, int *y, int *z) {
    int temp = *x; 
    *x = *z;       
    *z = *y;       
    *y = temp;    
}

int main() {
    int a = 4;
    int b = 6;
    int c = 8;

    cout << "Sebelum ditukar:" << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    tukar(&a, &b, &c);

    cout << "\nSetelah ditukar:" << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    return 0;
}

//Reference
#include <iostream>
using namespace std;

void tukar(int &x, int &y, int &z);

int main() {
    int a = 4, b = 6, c = 8;

    cout << "kondisi sebelum ditukar \n";
    cout << " a = " << a << " b = " << b << " c = " << c << endl;

    tukar(a, b, c);

    cout << "\nkondisi setelah ditukar \n";
    cout << " a = " << a << " b = " << b << " c = " << c << endl;

    return 0;
}

void tukar(int &x, int &y, int &z) {
    int temp = x; 
    x = z;        
    z = y;      
    y = temp;     

    cout << "\nnilai akhir pada fungsi tukar \n";
    cout << " x = " << x << " y = " << y << " z = " << z << endl;
}

### Output Unguided 2 :


<img width="1920" height="1080" alt="Soalno 2 Pointer" src="https://github.com/user-attachments/assets/d01c64f5-df94-4b81-accf-c05e9b6991f6" />



<img width="1920" height="1080" alt="Soalno2 Reference" src="https://github.com/user-attachments/assets/7cd5618f-dc57-4802-8242-4e01507d93fc" />



penjelasan unguided 2 :

Program ini dirancang untuk menukar posisi nilai dari tiga variabel sekaligus (a, b, dan c) secara berputar menggunakan fungsi berpenengah pointer (*) dan reference (&), sehingga nilai variabel penampung di dalam main() ikut berubah secara nyata.


### 3. Diketahui sebuah array 1 dimensi sebagai berikut :  arrA = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55} Buatlah program yang dapat mencari nilai minimum, maksimum, dan rata – rata dari array tersebut! Gunakan function cariMinimum() untuk mencari nilai minimum dan function cariMaksimum() untuk mencari nilai maksimum, serta gunakan prosedur hitungRataRata() untuk menghitung nilai rata – rata! Buat program menggunakan menu switch-case seperti berikut ini : --- Menu Program Array ---  • Tampilkan isi array  • cari nilai maksimum • cari nilai minimum  • Hitung nilai rata - rata 

#include <iostream>
using namespace std;

int cariMinimum(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int cariMaksimum(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void hitungRataRata(int arr[], int n) {
    double total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    double rataRata = total / n;
    cout << "Nilai rata-rata dari array: " << rataRata << endl;
}

void tampilkanArray(int arr[], int n) {
    cout << "Isi array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Inisialisasi array sesuai soal
    int arrA[] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int n = sizeof(arrA) / sizeof(arrA[0]); // Menghitung jumlah elemen array (10 elemen)
    int pilihan;

    do {
        cout << "\n--- Menu Program Array ---" << endl;
        cout << "1. Tampilkan isi array" << endl;
        cout << "2. Cari nilai maksimum" << endl;
        cout << "3. Cari nilai minimum" << endl;
        cout << "4. Hitung nilai rata - rata" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;
        cout << endl;

        switch (pilihan) {
            case 1:
                tampilkanArray(arrA, n);
                break;
            case 2:
                cout << "Nilai maksimum: " << cariMaksimum(arrA, n) << endl;
                break;
            case 3:
                cout << "Nilai minimum: " << cariMinimum(arrA, n) << endl;
                break;
            case 4:
                hitungRataRata(arrA, n);
                break;
            case 5:
                cout << "Terima kasih, program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid! Silakan masukkan angka 1-5." << endl;
                break;
        }

    } while (pilihan != 5);

    return 0;
}

### Output Unguided 3 :


<img width="1920" height="1080" alt="Soalno 3" src="https://github.com/user-attachments/assets/cb598750-c028-4231-a698-3942a712e335" />



penjelasan unguided 3 :

Program ini mengelola sekumpulan data array 1 dimensi menggunakan sistem menu interaktif berbasis switch-case. Pencarian nilai terendah dan tertinggi diselesaikan lewat fungsi cariMinimum() dan cariMaksimum(), sedangkan tugas mencetak array serta mengkalkulasi rata-rata ditangani oleh prosedur tersendiri.

## Kesimpulan

Berdasarkan praktikum Modul 2 ini, dapat disimpulkan bahwa:

1.Penggunaan struktur Array (baik 1D, 2D, maupun 3D) sangat memudahkan pengorganisasian sekumpulan data yang sejenis ke dalam blok memori yang tersusun secara berurutan.

2.Mekanisme Pointer dan Reference memberikan kemudahan untuk mengakses serta mengontrol letak memori variabel secara langsung, yang amat krusial ketika melakukan pengiriman parameter (Call by Pointer/Reference).

3.Penerapan Function dan Procedure menjadikan struktur penulisan kode program C++ jauh lebih rapi, terstruktur, serta mudah dipelihara.