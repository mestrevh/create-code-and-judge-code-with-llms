/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string sabor;
    int quantidade;
    double preco_por_bola = 0.0;

    std::cin >> sabor >> quantidade;

    if (sabor == "Morango" || sabor == "Cereja") {
        preco_por_bola = 4.50;
    } else if (sabor == "Damasco" || sabor == "Siriguela") {
        preco_por_bola = 3.80;
    } else {
        preco_por_bola = 2.75;
    }

    double total = quantidade * preco_por_bola;

    std::cout << std::fixed << std::setprecision(2) << total << std::endl;

    if (quantidade > 2) {
        std::cout << "COM CALDA" << std::endl;
    } else {
        std::cout << "SEM CALDA" << std::endl;
    }

    return 0;
}
