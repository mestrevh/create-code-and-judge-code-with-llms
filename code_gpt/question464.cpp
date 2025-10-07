/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>

int main() {
    int totalPessoas = 0, familiares;
    std::string continuar;

    while (true) {
        std::cin >> familiares;
        totalPessoas += familiares;
        std::cin >> continuar;
        if (continuar == "sair" || continuar == "SAIR") break;
    }

    double orcamento = totalPessoas * 14.0;
    std::cout << totalPessoas << std::endl;
    std::cout << std::fixed << std::setprecision(2) << orcamento << std::endl;

    return 0;
}
