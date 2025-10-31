/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

void bubbleSort(std::vector<int>& arr) {
    bool swapped;
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        for (int k = 0; k < n; k++) std::cout << arr[k] << (k < n - 1 ? " " : "");
        std::cout << std::endl;
        if (!swapped) break;
    }
}

int main() {
    std::vector<int> arr;
    int num;
    while (std::cin >> num) {
        arr.push_back(num);
    }
    bubbleSort(arr);
    return 0;
}
