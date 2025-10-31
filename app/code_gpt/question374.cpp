/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>

int main() {
    double salario;
    std::cin >> salario;

    double bonus = salario * 0.75;
    std::string destino;

    if (bonus < 2000) {
        destino = "ARGENTINA";
    } else if (bonus <= 3000) {
        destino = "ESPANHA";
    } else {
        destino = "ALEMANHA";
    }

    std::cout << destino << std::endl;
    return 0;
}
