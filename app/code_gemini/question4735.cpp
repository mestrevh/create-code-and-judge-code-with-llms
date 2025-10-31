/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

void minHeapify(std::vector<int>& arr, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest]) {
        smallest = left;
    }

    if (right < n && arr[right] < arr[smallest]) {
        smallest = right;
    }

    if (smallest != i) {
        std::swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    if (n <= 1) return;

    for (int i = n / 2 - 1; i >= 0; i--) {
        minHeapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        minHeapify(arr, i, 0);
    }
}

void printArray(const std::vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << (i == arr.size() - 1 ? "" : " ");
    }
    std::cout << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string line;
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        std::vector<int> original_arr;
        int number;
        while (ss >> number) {
            original_arr.push_back(number);
        }

        if (!original_arr.empty()) {
            std::vector<int> sorted_arr = original_arr;

            std::cout << "Array original:" << std::endl;
            printArray(original_arr);

            heapSort(sorted_arr);

            std::cout << "Array ordenado" << std::endl;
            printArray(sorted_arr);
        }
    }

    return 0;
}
