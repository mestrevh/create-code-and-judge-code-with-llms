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
    char x_char;
    std::cin >> m >> x_char >> n;

    int k;
    std::cin >> k;

    if (k >= m * n) {
        std::cout << "BANDECLAY OVERLOAD!\n";
        return 0;
    }

    std::vector<std::pair<int, int>> bombs;
    for (int i = 0; i < k; ++i) {
        std::string coord;
        std::cin >> coord;
        int row = coord[0] - 'a';
        int col = coord[1] - '1';
        bombs.push_back({row, col});
    }

    std::vector<std::vector<int>> grid(m, std::vector<int>(n, 0));

    int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (const auto& bomb : bombs) {
        int br = bomb.first;
        int bc = bomb.second;
        for (int i = 0; i < 8; ++i) {
            int nr = br + dr[i];
            int nc = bc + dc[i];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                grid[nr][nc]++;
            }
        }
    }

    for (const auto& bomb : bombs) {
        grid[bomb.first][bomb.second] = 9;
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
