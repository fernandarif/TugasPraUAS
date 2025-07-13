#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i) L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int> &arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    cout << "Nama  : Fernanda Rifky Syahrial" << endl;
    cout << "NIM   : 23533738" << endl;
    cout << "Kelas : 4-B Teknik Informatika" << endl;
    cout << "=== UNIVERSITAS MUHHAMMADIYAH PONOROGO ===" << endl;   
 
 
 int n;
    cout << "Masukkan jumlah elemen: ";
    cin >> n;

    vector<int> data(n);
    cout << "Masukkan " << n << " angka:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Data ke-" << i+1 << ": ";
        cin >> data[i];
    }

    cout << "\nData sebelum diurutkan: ";
    for (int num : data) cout << num << " ";
    cout << endl;

    mergeSort(data, 0, n - 1);

    cout << "Data setelah merge sort: ";
    for (int num : data) cout << num << " ";
    cout << endl;

    return 0;
}
