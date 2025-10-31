/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <utility>

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        std::cout << "Subarray: ";
        for (int i = low; i <= high; ++i) {
            std::cout << arr[i] << (i == high ? "" : " ");
        }
        std::cout << std::endl;

        std::cout << "Pivo: " << arr[high] << std::endl;

        int pi = partition(arr, low, high);

        std::cout << "Array: ";
        for (size_t i = 0; i < arr.size(); ++i) {
            std::cout << arr[i] << (i == arr.size() - 1 ? "" : " ");
        }
        std::cout << std::endl;

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<int> numbers;
    int num;
    while (std::cin >> num) {
        numbers.push_back(num);
    }

    if (!numbers.empty()) {
        quickSort(numbers, 0, numbers.size() - 1);
    }

    return 0;
}
