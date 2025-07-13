#include <iostream>
#include <cstring>
using namespace std;
#define size 99

void sort(int[], int);
int main() {
    int x[size], i, koin, n, hasil[size];
    cout << endl;
    cout << "Nama  : Fernanda Rifky Syahrial" << endl;
    cout << "NIM   : 23533738" << endl;
    cout << "Kelas : 4-B Teknik Informatika" << endl;
    cout << "=== UNIVERSITAS MUHHAMMADIYAH PONOROGO ===" << endl;
    cout << endl;
    cout << "===== Penukaran Koin dengan Algoritma Greedy =====" << endl;
    cout << endl;
    cout << "Tuliskan Banyaknya Koin : ";
    cin >> n;
    cout << "\nMasukkan Jenis kepingan Koin : \n";
    for (i = 0; i < n; i++) {
        cin >> x[i];
    }

    sort(x, n);
    cout << "\nMasukkan Nilai yang Ditukarkan : ";
    cin >> koin;
    cout << "\n";

    memset(hasil, 0, sizeof(hasil));
    for (i = 0; i < n; i++) {
        hasil[i] = koin / x[i];
        koin = koin % x[i];
    }

    for (i = 0; i < n; i++) {
        cout << "Jumlah Keping " << x[i] << "-an sebanyak: " << hasil[i] << endl;
    }

    return 0;
}

void sort(int a[], int siz) {
    int pass, hold, j;
    for (pass = 0; pass < siz - 1; pass++) {
        for (j = 0; j < siz - pass - 1; j++) {
            if (a[j] < a[j + 1]) {
                hold = a[j];
                a[j] = a[j + 1];
                a[j + 1] = hold;
            }
        }
    }
}
