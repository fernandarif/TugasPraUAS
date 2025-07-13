#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int knapsack(int W, vector<int> weight, vector<int> profit, int n, vector<int> &itemsTaken) {
    vector<vector<int>> K(n + 1, vector<int>(W + 1, 0));

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (weight[i - 1] <= w)
                K[i][w] = max(profit[i - 1] + K[i - 1][w - weight[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    int res = K[n][W];
    int w = W;
    for (int i = n; i > 0 && res > 0; i--) {
        if (res != K[i - 1][w]) {

            itemsTaken.push_back(i - 1); 
            res -= profit[i - 1];
            w -= weight[i - 1];
        }
    }

    return K[n][W];
}

int main() {
     cout << "Nama  : Fernanda Rifky Syahrial" << endl;
    cout << "NIM   : 23533738" << endl;
    cout << "Kelas : 4-B Teknik Informatika" << endl;
    cout << "=== UNIVERSITAS MUHHAMMADIYAH PONOROGO ===" << endl;
    cout << endl;
    vector<int> weight = {2, 3, 5, 3, 3, 7, 3, 8};
    vector<int> profit = {21, 35, 70, 42, 80, 20, 10, 5};
    int n = weight.size();

    int capacity;
    cout << "Masukkan kapasitas maksimum knapsack: ";
    cin >> capacity;

    vector<int> itemsTaken;
    int maxProfit = knapsack(capacity, weight, profit, n, itemsTaken);

    cout << "\n===== HASIL PEMILIHAN KNAPSACK 0/1 =====\n";
    cout << "| Objek | Berat | Profit |\n";
    cout << "----------------------------\n";

    int totalWeight = 0;
    for (int idx : itemsTaken) {
        cout << "|   " << setw(3) << (idx + 1)
             << " |  " << setw(5) << weight[idx]
             << " |  " << setw(6) << profit[idx] << " |\n";
        totalWeight += weight[idx];
    }

    cout << "----------------------------\n";
    cout << "Total Berat  : " << totalWeight << endl;
    cout << "Total Profit : " << maxProfit << endl;

    return 0;
}
