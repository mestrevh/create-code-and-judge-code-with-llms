/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string mensagem;
    std::getline(std::cin, mensagem);

    std::istringstream iss(mensagem);
    std::string palavra;
    int contador = 0;

    while (iss >> palavra) {
        contador++;
    }

    if (contador % 2 == 0) {
        std::cout << "SIM" << std::endl;
    } else {
        std::cout << "NÃO" << std::endl;
    }

    return 0;
}
