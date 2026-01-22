/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int m, n;
    std::cin >> m >> n;
    std::vector<std::string> grid(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> grid[i];
    }

    for (int r = 0; r < m; ++r) {
        bool changed = true;
        while (changed) {
            changed = false;
            for (int c = 0; c < n; ++c) {
                if (r + 1 < m && grid[r][c] == 'o' && grid[r + 1][c] == '#') {
                    if (c > 0 && grid[r][c - 1] == '.') {
                        grid[r][c - 1] = 'o';
                        changed = true;
                    }
                    if (c < n - 1 && grid[r][c + 1] == '.') {
                        grid[r][c + 1] = 'o';
                        changed = true;
                    }
                }
            }
        }

        if (r + 1 < m) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 'o' && grid[r + 1][c] == '.') {
                    grid[r + 1][c] = 'o';
                }
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        std::cout << grid[i] << '\n';
    }

    return 0;
}
