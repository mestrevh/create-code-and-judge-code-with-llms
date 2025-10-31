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
    std::cin >> s;
    if (s.length() == 10) {
        char key = s[6];
        if (key == 'b') {
            std::cout << "Bulbassauro\n";
        } else if (key == 'c') {
            std::cout << "Charmander\n";
        } else if (key == 's') {
            std::cout << "Squirtle\n";
        } else {
            std::cout << "Codigo Invalido\n";
        }
    } else {
        std::cout << "Codigo Invalido\n";
    }
    return 0;
}
