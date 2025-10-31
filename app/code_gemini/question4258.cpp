/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cout << "Digite uma String de números: \n";

    std::string line;
    std::getline(std::cin, line);

    std::stringstream ss(line);
    std::vector<int> numbers;
    int num;
    while (ss >> num) {
        numbers.push_back(num);
    }

    std::cout << "O inverso dos números digitados é: ";

    if (!numbers.empty()) {
        for (int i = numbers.size() - 1; i >= 0; --i) {
            std::cout << numbers[i];
            if (i > 0) {
                std::cout << ", ";
            }
        }
    }

    std::cout << ".\n";

    return 0;
}
