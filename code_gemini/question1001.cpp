/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <utility>

void print_grid(const std::vector<std::vector<int>>& grid, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << grid[i][j] << (j == m - 1 ? "" : " ");
        }
        std::cout << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> grid(n, std::vector<int>(m, 0));

    int k;
    std::cin >> k;
    for (int i = 0; i < k; ++i) {
        int x, y;
        std::cin >> x >> y;
        grid[x][y] = 1;
    }

    print_grid(grid, n, m);

    int h, b_count;
    std::cin >> h >> b_count;

    for (int i = 0; i < h; ++i) {
        std::cout << std::endl;

        std::vector<std::vector<bool>> destroyed(n, std::vector<bool>(m, false));
        for (int j = 0; j < b_count; ++j) {
            int bx, by;
            std::cin >> bx >> by;

            destroyed[(bx % n + n) % n][(by % m + m) % m] = true;
            destroyed[((bx + 1) % n + n) % n][((by + 1) % m + m) % m] = true;
            destroyed[((bx + 1) % n + n) % n][((by - 1) % m + m) % m] = true;
            destroyed[((bx - 1) % n + n) % n][((by - 1) % m + m) % m] = true;
            destroyed[((bx - 1) % n + n) % n][((by + 1) % m + m) % m] = true;
        }

        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < m; ++col) {
                if (destroyed[row][col]) {
                    grid[row][col] = 0;
                }
            }
        }

        std::vector<std::vector<int>> new_grid(n, std::vector<int>(m, 0));
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < m; ++col) {
                if (grid[row][col] == 1) {
                    int new_x = ((row - 1) % n + n) % n;
                    int new_y = ((col + 1) % m + m) % m;
                    new_grid[new_x][new_y] = 1;
                }
            }
        }
        grid = new_grid;

        print_grid(grid, n, m);
    }

    return 0;
}
