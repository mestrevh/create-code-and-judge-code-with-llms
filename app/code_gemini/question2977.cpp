/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cstring>
#include <vector>

bool grid[501][501];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    while (std::cin >> n && n != 0) {
        memset(grid, false, sizeof(grid));

        for (int k = 0; k < n; ++k) {
            int a, b, c, d;
            std::cin >> a >> b >> c >> d;
            for (int i = a; i < c; ++i) {
                for (int j = b; j < d; ++j) {
                    grid[i][j] = true;
                }
            }
        }

        int total_area = 0;
        for (int i = 0; i < 501; ++i) {
            for (int j = 0; j < 501; ++j) {
                if (grid[i][j]) {
                    total_area++;
                }
            }
        }
        std::cout << total_area << '\n';
    }

    return 0;
}
