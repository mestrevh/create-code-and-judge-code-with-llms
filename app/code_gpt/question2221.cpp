/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    std::string canos[3] = {"Esquerda", "Meio", "Direita"};
    std::string letras[3];
    std::string target = "bowser";

    for (int i = 0; i < 3; ++i) {
        std::cin >> letras[i];
    }

    for (int i = 0; i < 3; ++i) {
        std::unordered_map<char, int> letter_count;
        for (char c : letras[i]) {
            letter_count[c]++;
        }

        bool can_form = true;
        for (char c : target) {
            if (letter_count[c] == 0) {
                can_form = false;
                break;
            }
            letter_count[c]--;
        }

        if (can_form) {
            std::cout << canos[i] << std::endl;
            break;
        }
    }
    
    std::cout << "Siga" << std::endl;
    return 0;
}
