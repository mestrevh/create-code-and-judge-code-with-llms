/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

void print_vector(const std::vector<int>& arr, const std::string& prefix) {
    std::cout << prefix;
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << (i == arr.size() - 1 ? "" : " | ");
    }
    std::cout << std::endl;
}

void max_heapify(std::vector<int>& arr, int heap_size, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    if (left < heap_size && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < heap_size && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        max_heapify(arr, heap_size, largest);
    }
}

void build_max_heap(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; --i) {
        max_heapify(arr, n, i);
        print_vector(arr, "Estado Atual: ");
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string line;
    std::getline(std::cin, line);

    std::stringstream ss(line);
    std::vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }

    if (arr.empty()) {
        return 0;
    }

    print_vector(arr, "Estado inicial: ");

    build_max_heap(arr);

    print_vector(arr, "Resultado Final: ");

    return 0;
}
