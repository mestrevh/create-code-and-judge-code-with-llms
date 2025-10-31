/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::string input;
    while (true) {
        std::getline(std::cin, input);
        if (input.length() >= 1 && input.length() <= 20) {
            break;
        }
        std::cout << "Entrada invalida" << std::endl;
    }
    for (size_t i = 0; i < input.length(); ++i) {
        char ch = std::toupper(input[i]);
        for (size_t j = 0; j <= i; ++j) {
            std::cout << ch;
        }
        std::cout << std::endl;
    }
    return 0;
}
