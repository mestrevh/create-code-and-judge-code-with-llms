/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::cout << "Digite as distancias percorridas separadas por ENTER" << std::endl;
    int meta_dias = 0;
    double distancia;

    for (int i = 0; i < 7; ++i) {
        std::cin >> distancia;
        if (distancia >= 8.0) {
            meta_dias++;
        }
    }

    std::cout << "Meta alcancada em " << meta_dias << " dias" << std::endl;

    if (meta_dias >= 5) {
        std::cout << "Desempenho otimo" << std::endl;
    } else if (meta_dias >= 3) {
        std::cout << "Desempenho bom" << std::endl;
    } else {
        std::cout << "Desempenho ruim" << std::endl;
    }

    return 0;
}
