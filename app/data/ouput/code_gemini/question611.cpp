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

    int R, C;
    std::cin >> R >> C;

    std::vector<std::vector<long long>> H(R + 2, std::vector<long long>(C + 2, 0));
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            std::cin >> H[i][j];
        }
    }

    long long surface_area = 0;

    // Top and bottom faces contribution
    surface_area += 2LL * R * C;

    // Side faces contribution
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            surface_area += std::abs(H[i][j] - H[i - 1][j]); // Difference with top neighbor
            surface_area += std::abs(H[i][j] - H[i + 1][j]); // Difference with bottom neighbor
            surface_area += std::abs(H[i][j] - H[i][j - 1]); // Difference with left neighbor
            surface_area += std::abs(H[i][j] - H[i][j + 1]); // Difference with right neighbor
        }
    }

    std::cout << surface_area / 2 << std::endl;

    return 0;
}
