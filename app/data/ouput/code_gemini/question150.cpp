/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int h;
    std::cin >> h;

    long long total_nodes = (1LL << h) - 1;

    std::vector<long long> p(total_nodes + 1);
    for (int i = 1; i <= total_nodes; ++i) {
        std::cin >> p[i];
    }

    for (int i = (1LL << (h - 1)) - 1; i >= 1; --i) {
        long long p_left = p[2 * i];
        long long p_right = p[2 * i + 1];
        p[i] = std::max(p[i] * p_left, p[i] * p_right);
    }

    std::cout << p[1] << std::endl;

    return 0;
}
