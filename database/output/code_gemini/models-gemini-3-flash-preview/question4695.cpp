/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        cout << "Subarray: ";
        for (int k = low; k <= high; ++k) {
            cout << arr[k] << " ";
        }
        cout << "\n";

        int pivot = arr[high];
        cout << "Pivo: " << pivot << "\n";

        int i = low - 1;
        for (int j = low; j < high; ++j) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int pi = i + 1;

        cout << "Array: ";
        for (int k = 0; k < (int)arr.size(); ++k) {
            cout << arr[k] << " ";
        }
        cout << "\n";

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> arr;
    int val;
    while (cin >> val) {
        arr.push_back(val);
    }

    if (!arr.empty()) {
        quickSort(arr, 0, (int)arr.size() - 1);
    }

    return 0;
}