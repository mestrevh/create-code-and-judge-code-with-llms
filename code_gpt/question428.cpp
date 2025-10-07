/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::string rua, numero, bairro, cidade, estado, cep;

    std::getline(std::cin, rua);
    std::getline(std::cin, numero);
    std::getline(std::cin, bairro);
    std::getline(std::cin, cidade);
    std::getline(std::cin, estado);
    std::getline(std::cin, cep);

    std::cout << rua << ", " << numero << ".\n";
    std::cout << "Bairro: " << bairro << ". Cep: " << cep << "\n";
    std::cout << cidade << "/" << estado << "\n";

    return 0;
}
