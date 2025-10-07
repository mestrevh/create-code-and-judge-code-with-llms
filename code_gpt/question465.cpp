/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double valor, total = 0.0;
    int contador = 0;

    while (true) {
        std::cin >> valor;
        if (valor < 0) break;
        total += valor;
        contador++;
    }

    double media = (contador > 0) ? total / contador : 0.0;

    std::cout << std::fixed << std::setprecision(2) << total << std::endl;
    std::cout << std::fixed << std::setprecision(2) << media << std::endl;

    return 0;
}
