/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cctype>

int main() {
    std::string input;
    std::cin >> input;

    if (input.length() != 1) {
        std::cout << "1 caractere, por favor!" << std::endl;
    } else {
        char ch = tolower(input[0]);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            std::cout << "Eh vogal" << std::endl;
        } else {
            std::cout << "Nao eh vogal" << std::endl;
        }
    }
    return 0;
}
