/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int totalPaginas, pagAtual, paginasLidas = 0, maxDiarias = 0;
    std::cin >> totalPaginas;
    pagAtual = 0;

    for (int i = 0; i < 7; ++i) {
        int pagParada;
        std::cin >> pagParada;
        if (pagParada > pagAtual) {
            int lidasHoje = pagParada - pagAtual;
            paginasLidas += lidasHoje;
            maxDiarias = std::max(maxDiarias, lidasHoje);
            pagAtual = pagParada;
        }
    }

    std::cout << paginasLidas << "\n" << maxDiarias << "\n";
    return 0;
}
