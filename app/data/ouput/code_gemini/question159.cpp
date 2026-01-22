/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <functional>

int N, M;
std::vector<std::vector<bool>> grid;
std::vector<std::vector<bool>> visited;

int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int flood_fill(int r, int c) {
    if (r < 1 || r > N || c < 1 || c > M) {
        return 0;
    }
    if (visited[r][c] || grid[r][c]) {
        return 0;
    }

    visited[r][c] = true;
    int count = 1;

    for (int i = 0; i < 8; ++i) {
        count += flood_fill(r + dr[i], c + dc[i]);
    }

    return count;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int X, Y, K;
    std::cin >> N >> M >> X >> Y >> K;

    grid.assign(N + 2, std::vector<bool>(M + 2, false));
    visited.assign(N + 2, std::vector<bool>(M + 2, false));

    for (int i = 0; i < K; ++i) {
        int A, B;
        std::cin >> A >> B;
        grid[A][B] = true;
    }

    std::cout << flood_fill(X, Y) << std::endl;

    return 0;
}
