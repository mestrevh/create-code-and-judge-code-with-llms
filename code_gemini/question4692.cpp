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

    for (int i = 0; i < arr.size(); ++i) {
        for (int j = 0; j < arr.size(); ++j) {
            cout << arr[j] << (j == arr.size() - 1 ? "" : " ");
        }
        cout << endl;

        int min_idx = i;
        for (int j = i + 1; j < arr.size(); ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(arr[i], arr[min_idx]);
        }
        
        if (is_sorted(arr.begin(), arr.end())) break;


    }
    if (arr.size() > 0 && is_sorted(arr.begin(), arr.end()) == false) {
    for (int j = 0; j < arr.size(); ++j) {
            cout << arr[j] << (j == arr.size() - 1 ? "" : " ");
        }
    cout << endl;
    }

    return 0;
}
