/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s;
    while (std::cin >> s && s != "sair") {
        size_t at_pos = s.find('@');
        if (at_pos == std::string::npos || s.rfind('@') != at_pos) {
            std::cout << "errado\n";
            continue;
        }

        size_t dot1_pos = s.find('.');
        if (dot1_pos == std::string::npos) {
            std::cout << "errado\n";
            continue;
        }

        size_t dot2_pos = s.find('.', dot1_pos + 1);
        if (dot2_pos == std::string::npos) {
            std::cout << "errado\n";
            continue;
        }

        if (s.find('.', dot2_pos + 1) != std::string::npos) {
            std::cout << "errado\n";
            continue;
        }

        bool is_valid = true;
        if (at_pos < 1) { // Pelo menos 1 caractere antes do @
            is_valid = false;
        } else if (!(at_pos < dot1_pos && dot1_pos < dot2_pos)) { // Estrutura @ . .
            is_valid = false;
        } else if (dot1_pos - at_pos <= 1) { // Pelo menos 1 caractere entre @ e .
            is_valid = false;
        } else if (dot2_pos - dot1_pos <= 1) { // Pelo menos 1 caractere entre . e .
            is_valid = false;
        } else if (s.length() - dot2_pos <= 1) { // Pelo menos 1 caractere depois do ultimo .
            is_valid = false;
        }

        if (is_valid) {
            std::cout << "certo\n";
        } else {
            std::cout << "errado\n";
        }
    }

    return 0;
}
