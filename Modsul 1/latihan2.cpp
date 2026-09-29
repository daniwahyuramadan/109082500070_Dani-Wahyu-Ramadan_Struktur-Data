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