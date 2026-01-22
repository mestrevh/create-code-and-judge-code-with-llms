/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

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
        maxHeapify(arr, n, largest);
    }
}

void buildMaxHeap(std::vector<int>& arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}

void heapsort(std::vector<int>& arr) {
    int n = arr.size();
    buildMaxHeap(arr, n);
    
    std::cout << "Estado inicial: ";
    for (int num : arr) std::cout << num << " | "; 
    std::cout << std::endl;

    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        n--;
        maxHeapify(arr, n, 0);
        
        std::cout << "Maior elemento neste passo: " << arr[i] << std::endl;
        std::cout << "Estado Atual da Heap: ";
        for (int j = 0; j < n; j++) std::cout << arr[j] << " | "; 
        std::cout << std::endl;
    }

    std::cout << "Resultado Final: ";
    for (int num : arr) std::cout << num << " | ";
    std::cout << std::endl;
}

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::stringstream ss(input);
    std::vector<int> arr;
    int num;

    while (ss >> num) {
        arr.push_back(num);
    }

    heapsort(arr);
    return 0;
}
