/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <sstream>

void insertionSort(std::vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        for (int k = 0; k < arr.size(); k++) {
            std::cout << arr[k] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::istringstream stream(input);
    std::vector<int> arr;
    int number;

    while (stream >> number) {
        arr.push_back(number);
    }

    for (const int& n : arr) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    insertionSort(arr);
    return 0;
}
