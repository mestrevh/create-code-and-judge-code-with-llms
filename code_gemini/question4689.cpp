/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> arr;
    int num;
    while (cin >> num) {
        arr.push_back(num);
    }

    int n = arr.size();
    bool swapped;

    do {
        swapped = false;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        for (int i = 0; i < n; i++) {
            cout << arr[i] << (i == n - 1 ? "" : " ");
        }
        cout << endl;
    } while (swapped);

    return 0;
}
