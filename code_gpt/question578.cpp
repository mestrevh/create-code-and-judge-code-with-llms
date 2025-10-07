/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <sstream>

void maxHeapify(std::vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        std::cout << "Estado Atual: ";
        for (int j = 0; j < n; j++) {
            std::cout << arr[j];
            if (j < n - 1) std::cout << " | ";
        }
        std::cout << std::endl;
        maxHeapify(arr, n, largest);
    }
}

void buildMaxHeap(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

int main() {
    std::string line;
    std::getline(std::cin, line);
    std::stringstream ss(line);
    std::vector<int> arr;
    int num;

    while (ss >> num) {
        arr.push_back(num);
    }

    std::cout << "Estado inicial: ";
    for (int j = 0; j < arr.size(); j++) {
        std::cout << arr[j];
        if (j < arr.size() - 1) std::cout << " | ";
    }
    std::cout << std::endl;

    buildMaxHeap(arr);

    std::cout << "Resultado Final: ";
    for (int j = 0; j < arr.size(); j++) {
        std::cout << arr[j];
        if (j < arr.size() - 1) std::cout << " | ";
    }
    std::cout << std::endl;

    return 0;
}
