/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string rua;
    std::string numero;
    std::string bairro;
    std::string cidade;
    std::string estado;
    std::string cep;

    std::getline(std::cin, rua);
    std::getline(std::cin, numero);
    std::getline(std::cin, bairro);
    std::getline(std::cin, cidade);
    std::getline(std::cin, estado);
    std::getline(std::cin, cep);

    std::cout << rua << ", " << numero << "." << std::endl;
    std::cout << "Bairro: " << bairro << ". Cep: " << cep << std::endl;
    std::cout << cidade << "/" << estado << std::endl;

    return 0;
}
