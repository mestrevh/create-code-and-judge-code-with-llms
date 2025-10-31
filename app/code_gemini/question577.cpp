/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

void print_vector(const std::vector<int>& arr, int size) {
    if (size > 0) {
        std::cout << arr[0];
        for (int i = 1; i < size; ++i) {
            std::cout << " | " << arr[i];
        }
    }
    std::cout << std::endl;
}

void max_heapify(std::vector<int>& arr, int heap_size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

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
    }
}

void heapsort(std::vector<int>& arr) {
    int n = arr.size();

    build_max_heap(arr);
    std::cout << "Estado Atual da Heap: ";
    print_vector(arr, n);

    int heap_size = n;
    for (int i = n - 1; i > 0; --i) {
        std::cout << "Maior elemento neste passo: " << arr[0] << std::endl;
        
        std::swap(arr[0], arr[i]);
        heap_size--;

        max_heapify(arr, heap_size, 0);

        std::cout << "Estado Atual da Heap: ";
        print_vector(arr, heap_size);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string line;
    getline(std::cin, line);
    std::stringstream ss(line);
    int num;
    std::vector<int> arr;
    while (ss >> num) {
        arr.push_back(num);
    }
    
    if (arr.empty()) return 0;

    std::cout << "Estado inicial: ";
    print_vector(arr, arr.size());

    heapsort(arr);

    std::cout << "Resultado Final: ";
    print_vector(arr, arr.size());

    return 0;
}
