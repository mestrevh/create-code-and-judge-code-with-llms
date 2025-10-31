/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::string code;
    std::cin >> code;

    char identifier = code[6];

    if (identifier == 'b') {
        std::cout << "Bulbassauro\n";
    } else if (identifier == 'c') {
        std::cout << "Charmander\n";
    } else if (identifier == 's') {
        std::cout << "Squirtle\n";
    } else {
        std::cout << "Codigo Invalido\n";
    }

    return 0;
}
