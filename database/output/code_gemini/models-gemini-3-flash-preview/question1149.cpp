/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long a, l, p, h;
    std::cin >> a >> l >> p >> h;

    long long vA = a * h;
    long long vL = l * h;
    long long vP = p * h;

    long long m1 = (vA + vL + std::abs(vA - vL)) / 2;
    long long m2 = (m1 + vP + std::abs(m1 - vP)) / 2;

    std::cout << m2 << std::endl;

    return 0;
}