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
    input = input.substr(1, input.size() - 2); // Remove as colchetes

    std::vector<int> numbers;
    std::stringstream ss(input);
    std::string item;

    while (std::getline(ss, item, ',')) {
        numbers.push_back(std::stoi(item));
    }

    bool sorted = true;
    for (size_t i = 1; i < numbers.size(); ++i) {
        if (numbers[i] < numbers[i - 1]) {
            sorted = false;
            break;
        }
    }

    std::cout << (sorted ? "Ordenado" : "Nao ordenado") << std::endl;
    return 0;
}
