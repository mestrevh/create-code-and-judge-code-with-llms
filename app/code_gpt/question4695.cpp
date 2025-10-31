/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int pivotIndex = i + 1;

        cout << "Subarray: ";
        for (int k = low; k <= high; k++) {
            cout << arr[k] << " ";
        }
        cout << "\nPivo: " << pivot << endl;

        cout << "Array: ";
        for (int k = 0; k < arr.size(); k++) {
            cout << arr[k] << " ";
        }
        cout << endl;

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    string input;
    getline(cin, input);
    istringstream iss(input);
    vector<int> arr;
    int number;
    while (iss >> number) {
        arr.push_back(number);
    }

    quickSort(arr, 0, arr.size() - 1);
    return 0;
}
