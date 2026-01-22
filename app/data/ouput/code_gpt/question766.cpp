/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>

int main() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    std::unordered_map<int, int> frequency;
    int number;

    while (iss >> number) {
        frequency[number]++;
    }

    int mode = 0, max_count = 0;
    for (const auto& pair : frequency) {
        if (pair.second > max_count) {
            max_count = pair.second;
            mode = pair.first;
        }
    }

    std::cout << "Moda = " << mode << std::endl;
    return 0;
}
