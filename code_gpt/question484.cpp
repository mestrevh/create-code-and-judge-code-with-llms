/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <locale>

int main() {
    std::locale::global(std::locale(""));

    std::string tipo, origem, continuar;
    double peso, pesoTotalTigres = 0.0;
    int contMacacos = 0, contTigres = 0, contCobrasVenezuela = 0;

    while (true) {
        std::getline(std::cin, tipo);
        if (tipo == "PARAR" || tipo == "parar") break;

        std::cin >> peso;
        std::cin.ignore();
        std::getline(std::cin, origem);

        if (tipo == "macaco" || tipo == "Macaco") contMacacos++;
        if (tipo == "tigre" || tipo == "Tigre") {
            pesoTotalTigres += peso;
            contTigres++;
        }
        if (tipo == "cobra" || tipo == "Cobra") {
            if (origem == "Venezuela") contCobrasVenezuela++;
        }

        std::cout << "continuar" << std::endl;
    }

    double pesoMedioTigres = contTigres > 0 ? pesoTotalTigres / contTigres : 0.0;

    std::cout << contMacacos << std::endl;
    std::cout << std::fixed << std::setprecision(2) << pesoMedioTigres << std::endl;
    std::cout << contCobrasVenezuela << std::endl;

    return 0;
}
