/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::string senha;
    std::cout << "Digite a senha numerica:\n";
    std::cin >> senha;

    if (senha == "1234") {
        std::cout << "ACESSO PERMITIDO\n";
    } else {
        std::cout << "ACESSO NEGADO\n";
    }

    return 0;
}
