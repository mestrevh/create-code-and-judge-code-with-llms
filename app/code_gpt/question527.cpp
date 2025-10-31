/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <sstream>

void printArray(const std::vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i];
        if (i < arr.size() - 1) std::cout << " | ";
    }
    std::cout << std::endl;
}

void insertionSort(std::vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        size_t j = i - 1;
        std::cout << "Chave: " << key << std::endl;
        std::cout << "Estado Atual: ";
        printArray(arr);

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            printArray(arr);
        }
        arr[j + 1] = key;
        std::cout << std::endl;
    }
    std::cout << "Resultado Final: ";
    printArray(arr);
}

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss(input);
    std::vector<int> arr;
    int number;
    while (iss >> number) {
        arr.push_back(number);
    }
    insertionSort(arr);
    return 0;
}
