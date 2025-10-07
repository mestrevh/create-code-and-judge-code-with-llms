/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_subarray(const vector<int>& arr, int start, int end) {
    cout << "Subarray: ";
    for (int i = start; i <= end; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void print_array(const vector<int>& arr) {
    cout << "Array: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quick_sort(vector<int>& arr, int low, int high) {
    if (low < high) {
        print_subarray(arr, low, high);
        cout << "Pivo: " << arr[high] << endl;
        int pi = partition(arr, low, high);
        print_array(arr);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

int main() {
    vector<int> arr;
    int num;
    while (cin >> num) {
        arr.push_back(num);
    }

    quick_sort(arr, 0, arr.size() - 1);

    return 0;
}
