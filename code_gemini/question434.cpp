/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int creditos_pagos;
    std::cin >> creditos_pagos;

    const int TOTAL_CREDITOS = 260;
    const int MAX_POR_SEMESTRE = 24;

    int creditos_restantes = TOTAL_CREDITOS - creditos_pagos;

    if (creditos_restantes <= 0) {
        std::cout << 0 << std::endl;
    } else {
        int semestres_restantes = (creditos_restantes + MAX_POR_SEMESTRE - 1) / MAX_POR_SEMESTRE;
        std::cout << semestres_restantes << std::endl;
    }

    return 0;
}
