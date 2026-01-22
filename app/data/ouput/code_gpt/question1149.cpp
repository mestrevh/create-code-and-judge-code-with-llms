/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

int main() {
    int A, L, P, H;
    std::cin >> A >> L >> P >> H;

    int maxAL = (A + L + std::abs(A - L)) / 2;
    int maxAP = (maxAL + P + std::abs(maxAL - P)) / 2;
    int maxDiamonds = maxAP * H;

    std::cout << maxDiamonds << std::endl;
    return 0;
}
