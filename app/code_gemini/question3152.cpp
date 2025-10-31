/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double ax, ay, bx, by, cx, cy;
    std::cin >> ax >> ay >> bx >> by >> cx >> cy;

    double dist_ab_sq = (ax - bx) * (ax - bx) + (ay - by) * (ay - by);
    double dist_ac_sq = (ax - cx) * (ax - cx) + (ay - cy) * (ay - cy);
    double dist_bc_sq = (bx - cx) * (bx - cx) + (by - cy) * (by - cy);

    if (dist_ab_sq >= 4.0 && dist_ac_sq >= 4.0 && dist_bc_sq >= 4.0) {
        std::cout << "POSICAO VALIDA\n";
    } else {
        std::cout << "POSICAO INVALIDA\n";
    }

    return 0;
}
