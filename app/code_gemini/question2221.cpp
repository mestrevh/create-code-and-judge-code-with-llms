/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

bool can_form_bowser(const std::string& s) {
    std::string target = "bowser";
    for (char c : target) {
        if (s.find(c) == std::string::npos) {
            return false;
        }
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string esquerda, meio, direita;

    std::cin >> esquerda;
    std::cin >> meio;
    std::cin >> direita;

    if (can_form_bowser(esquerda)) {
        std::cout << "Esquerda\n";
    } else if (can_form_bowser(meio)) {
        std::cout << "Meio\n";
    } else {
        std::cout << "Direita\n";
    }

    return 0;
}
