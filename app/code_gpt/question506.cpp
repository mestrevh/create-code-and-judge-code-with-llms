/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

int main() {
    std::string passeio, residente;
    int mergulhos = 0;
    double total = 0.0;
    const double precoMergulho = 50.0;
    const double precoBarco = 65.0;
    const double precoBuggy = 90.0;
    const double desconto = 0.4;

    while (true) {
        std::getline(std::cin, passeio);
        std::transform(passeio.begin(), passeio.end(), passeio.begin(), ::tolower);
        if (passeio != "mergulho" && passeio != "barco" && passeio != "buggy") break;

        std::getline(std::cin, residente);
        std::transform(residente.begin(), residente.end(), residente.begin(), ::tolower);

        double preco = 0.0;
        if (passeio == "mergulho") {
            preco = precoMergulho;
            mergulhos++;
        } else if (passeio == "barco") {
            preco = precoBarco;
        } else if (passeio == "buggy") {
            preco = precoBuggy;
        }

        if (residente == "sim") {
            preco *= (1 - desconto);
        }

        total += preco;
    }

    std::cout << mergulhos << std::endl;
    std::cout << std::fixed << std::setprecision(2) << total << std::endl;

    return 0;
}
