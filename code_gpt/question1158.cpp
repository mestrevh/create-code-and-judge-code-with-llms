/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    int D, C;
    std::cin >> D >> C;

    int ticksPorDia = 12000; // Ticks durante o dia
    int totalTicks = D * ticksPorDia;
    int ticksPorCasa = totalTicks / C;

    std::cout << ticksPorCasa << std::endl;

    return 0;
}
