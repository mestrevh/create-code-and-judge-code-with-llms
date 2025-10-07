/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int N, M;
std::vector<std::vector<int>> grid;
std::vector<std::vector<bool>> visited;
int min_complexity = INT_MAX;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void solve(int r, int c, int last_dir, int complexity) {
    if (complexity >= min_complexity) {
        return;
    }

    if (r < 0 || r >= N || c < 0 || c >= M || grid[r][c] == 0 || visited[r][c]) {
        return;
    }

    if (r == N - 1 && c == M - 1) {
        min_complexity = std::min(min_complexity, complexity);
        return;
    }

    visited[r][c] = true;

    for (int i = 0; i < 4; ++i) {
        int new_r = r + dr[i];
        int new_c = c + dc[i];
        int new_complexity = complexity;

        if (last_dir != -1 && i != last_dir) {
            new_complexity++;
        }

        solve(new_r, new_c, i, new_complexity);
    }

    visited[r][c] = false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> N >> M;

    grid.assign(N, std::vector<int>(M));
    visited.assign(N, std::vector<bool>(M, false));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cin >> grid[i][j];
        }
    }

    if (grid[0][0] == 0 || grid[N - 1][M - 1] == 0) {
        std::cout << "Continuem cavando!" << std::endl;
        return 0;
    }

    solve(0, 0, -1, 0);

    if (min_complexity == INT_MAX) {
        std::cout << "Continuem cavando!" << std::endl;
    } else {
        std::cout << "O caminho tem complexidade: " << min_complexity << std::endl;
    }

    return 0;
}
