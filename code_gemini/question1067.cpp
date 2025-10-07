/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string line;
    std::getline(std::cin, line);
    if (line.length() != 1) {
        std::cout << "1 caractere, por favor!" << std::endl;
    } else {
        char c = line[0];
        c = tolower(c);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            std::cout << "Eh vogal" << std::endl;
        } else {
            std::cout << "Nao eh vogal" << std::endl;
        }
    }
    return 0;
}
