/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int N;
std::vector<std::vector<int>> grid;
std::vector<std::vector<int>> dp;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

bool isValid(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < N;
}

int solve(int r, int c) {
    if (dp[r][c] != -1) {
        return dp[r][c];
    }

    int max_len = 1;

    for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (isValid(nr, nc) && grid[r][c] == grid[nr][nc] + 1) {
            max_len = std::max(max_len, 1 + solve(nr, nc));
        }
    }

    return dp[r][c] = max_len;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int exit_i, exit_j;
    
    std::cin >> N >> exit_i >> exit_j;

    exit_i--;
    exit_j--;

    grid.resize(N, std::vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> grid[i][j];
        }
    }

    dp.assign(N, std::vector<int>(N, -1));

    int path_length = solve(exit_i, exit_j);
    int steps = path_length - 1;

    std::cout << "Numero de passos do maior caminho: " << steps << std::endl;

    return 0;
}
