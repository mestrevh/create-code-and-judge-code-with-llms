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

    std::string s;

    while (true) {
        std::getline(std::cin, s);
        if (s.length() >= 1 && s.length() <= 20) {
            break;
        } else {
            std::cout << "Entrada invalida\n";
        }
    }

    for (size_t i = 0; i < s.length(); ++i) {
        char upper_char = static_cast<char>(std::toupper(static_cast<unsigned char>(s[i])));
        for (size_t j = 0; j <= i; ++j) {
            std::cout << upper_char;
        }
        std::cout << '\n';
    }

    return 0;
}
