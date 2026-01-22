/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    double total_sum = 0.0;

    for (int j = 0; j <= m; ++j) {
        total_sum += (std::min(j, n) + 1) * (sin(static_cast<double>(j)) + cos(static_cast<double>(j)));
    }

    std::cout << std::fixed << std::setprecision(6) << total_sum << std::endl;

    return 0;
}
