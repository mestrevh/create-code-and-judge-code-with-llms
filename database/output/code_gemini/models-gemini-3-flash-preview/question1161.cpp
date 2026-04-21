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

    long long da = a * h;
    long long dl = l * h;
    long long dp = p * h;

    long long m1 = (da + dl + std::abs(da - dl)) / 2;
    long long m2 = (m1 + dp + std::abs(m1 - dp)) / 2;

    std::cout << m2 << std::endl;

    return 0;
}