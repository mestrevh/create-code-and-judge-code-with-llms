/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::string input;
    std::cin >> input;

    if (input == "F") {
        std::cout << "Feminino" << std::endl;
    } else if (input == "M") {
        std::cout << "Masculino" << std::endl;
    } else {
        std::cout << "Sexo nao definido" << std::endl;
    }

    return 0;
}
