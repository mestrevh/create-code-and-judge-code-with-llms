/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> grid(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> grid[i][j];
        }
    }

    int p;
    std::cin >> p;

    long long total_points = 0;
    for (int i = 0; i < p; ++i) {
        int r, c;
        std::cin >> r >> c;
        total_points += grid[r - 1][c - 1];
    }

    int t;
    std::cin >> t;

    double score = static_cast<double>(total_points) / t;

    std::cout << std::fixed << std::setprecision(2) << score << std::endl;

    return 0;
}
