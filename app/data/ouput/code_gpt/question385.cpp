/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>

int main() {
    std::string matricula;
    float cre, menorCRE = 10.0, somaCRE = 0.0;
    int contador = 0;
    std::string matriculaMenorCRE;

    while (true) {
        std::cin >> matricula;
        if (matricula == "999") break;
        std::cin >> cre;

        if (cre < menorCRE) {
            menorCRE = cre;
            matriculaMenorCRE = matricula;
        }
        somaCRE += cre;
        contador++;
    }

    std::cout << matriculaMenorCRE << std::endl;
    std::cout << std::fixed << std::setprecision(2) << (somaCRE / contador) << std::endl;

    return 0;
}
