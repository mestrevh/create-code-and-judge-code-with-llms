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
}

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss(input);
    std::vector<int> arr;
    int num;

    while (iss >> num) {
        arr.push_back(num);
    }

    for (size_t i = 0; i < arr.size() - 1; ++i) {
        int minIndex = i;
        for (size_t j = i + 1; j < arr.size(); ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
        std::cout << "Menor elemento neste passo: " << arr[i] << "\n";
        printArray(arr);
        std::cout << "\n\n";
    }

    std::cout << "Resultado Final: ";
    printArray(arr);
    std::cout << "\n";
    return 0;
}
