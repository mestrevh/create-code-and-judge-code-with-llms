/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>

void printVector(const std::vector<int>& arr) {
    if (arr.empty()) {
        return;
    }
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << (i == arr.size() - 1 ? "" : " ");
    }
    std::cout << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string line;
    while (std::getline(std::cin, line)) {
        if (line.empty()) {
            continue;
        }

        std::stringstream ss(line);
        std::vector<int> numbers;
        int num;
        while (ss >> num) {
            numbers.push_back(num);
        }

        if (numbers.empty()) {
            continue;
        }

        printVector(numbers);

        int n = numbers.size();
        if (n <= 1) {
            continue;
        }
        
        bool swapped;
        do {
            swapped = false;
            for (int i = 0; i < n - 1; ++i) {
                if (numbers[i] > numbers[i + 1]) {
                    std::swap(numbers[i], numbers[i + 1]);
                    swapped = true;
                }
            }
            printVector(numbers);
        } while (swapped);
    }

    return 0;
}
