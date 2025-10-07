/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

int main() {
    long long T, C;
    std::cin >> T >> C;

    long long ticks_por_dia = 12000;
    long long total_ticks = T * C;
    long long dias = std::ceil(static_cast<double>(total_ticks) / ticks_por_dia);

    std::cout << dias << std::endl;
    return 0;
}
