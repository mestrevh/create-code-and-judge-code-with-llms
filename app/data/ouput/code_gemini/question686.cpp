/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
    }

    long long moves = 0;

    for (int i = 0; i < n - 1; ++i) {
        int diff = m - p[i];
        p[i + 1] += diff;
        moves += std::abs(diff);
    }

    std::cout << moves << std::endl;

    return 0;
}
