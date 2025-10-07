/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::string codigo;
    std::cin >> codigo;

    if (codigo.length() != 10) {
        std::cout << "Codigo Invalido" << std::endl;
        return 0;
    }

    char pokemon = codigo[6];
    
    if (pokemon == 'b') {
        std::cout << "Bulbassauro" << std::endl;
    } else if (pokemon == 'c') {
        std::cout << "Charmander" << std::endl;
    } else if (pokemon == 's') {
        std::cout << "Squirtle" << std::endl;
    } else {
        std::cout << "Codigo Invalido" << std::endl;
    }

    return 0;
}
