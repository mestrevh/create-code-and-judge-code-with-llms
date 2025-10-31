/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;
    std::cin.ignore(); 

    for (int i = 0; i < N; ++i) {
        std::string line;
        std::getline(std::cin, line);

        std::stringstream ss(line);
        std::vector<int> numbers;
        int num;
        while (ss >> num) {
            numbers.push_back(num);
        }

        if (!numbers.empty()) {
            quickSort(numbers, 0, numbers.size() - 1);
        }

        for (size_t j = 0; j < numbers.size(); ++j) {
            std::cout << numbers[j] << (j == numbers.size() - 1 ? "" : " ");
        }
        std::cout << "\n";
    }

    return 0;
}
