/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string cpf;
    std::getline(std::cin, cpf);
    
    std::replace(cpf.begin(), cpf.end(), '.', ' ');
    std::replace(cpf.begin(), cpf.end(), '-', ' ');

    std::istringstream iss(cpf);
    std::string part;
    while (iss >> part) {
        std::cout << part << std::endl;
    }
    
    return 0;
}
