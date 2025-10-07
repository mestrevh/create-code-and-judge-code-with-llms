/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <sstream>

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss(input);
    std::vector<int> numbers;
    int number;

    while (iss >> number) {
        numbers.push_back(number);
    }

    std::vector<int> invert(numbers.rbegin(), numbers.rend());
    std::vector<int> parImp;

    for (size_t i = 0; i < numbers.size(); ++i) {
        if (i % 2 == 0) {
            parImp.push_back(numbers[i]);
        }
    }
    for (size_t i = 0; i < numbers.size(); ++i) {
        if (i % 2 != 0) {
            parImp.push_back(numbers[i]);
        }
    }

    std::vector<int> soma;
    for (size_t i = 0; i < invert.size(); ++i) {
        soma.push_back(invert[i] + parImp[i]);
    }

    std::cout << "Invert:";
    for (const auto& num : invert) {
        std::cout << " " << num;
    }
    std::cout << "\nParImp:";
    for (const auto& num : parImp) {
        std::cout << " " << num;
    }
    std::cout << "\nSoma:";
    for (const auto& num : soma) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    return 0;
}
