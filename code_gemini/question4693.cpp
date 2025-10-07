/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_range(const vector<int>& arr, int l, int r) {
    for (int i = l; i <= r; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(vector<int>& arr, int l, int m, int r) {
    vector<int> temp(r - l + 1);
    int i = l, j = m + 1, k = 0;

    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= m) {
        temp[k++] = arr[i++];
    }

    while (j <= r) {
        temp[k++] = arr[j++];
    }

    for (int i = 0; i < k; ++i) {
        arr[l + i] = temp[i];
    }
    print_range(arr, l, r);
}

void merge_sort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    vector<int> arr;
    int num;
    while (cin >> num) {
        arr.push_back(num);
    }

    print_range(arr, 0, arr.size() - 1);
    merge_sort(arr, 0, arr.size() - 1);

    return 0;
}
