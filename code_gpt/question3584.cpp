/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bubbleSort(vector<int>& arr, int n) {
    int size = arr.size();
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
        cout << "[";
        for (int k = 0; k < size; k++) {
            cout << arr[k];
            if (k < size - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<int> arr(m);
    for (int i = 0; i < m; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end(), greater<int>());
    arr.resize(n);
    bubbleSort(arr, n);

    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
