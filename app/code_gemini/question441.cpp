/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

int N;
std::vector<std::string> grid;
std::vector<std::vector<bool>> visited;

int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void flood_fill(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= N) {
        return;
    }
    if (visited[r][c] || grid[r][c] == '0') {
        return;
    }

    visited[r][c] = true;

    for (int i = 0; i < 8; ++i) {
        flood_fill(r + dr[i], c + dc[i]);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int image_num = 1;
    while (std::cin >> N) {
        grid.assign(N, std::string(N, ' '));
        for (int i = 0; i < N; ++i) {
            std::cin >> grid[i];
        }

        visited.assign(N, std::vector<bool>(N, false));
        int count = 0;

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    count++;
                    flood_fill(i, j);
                }
            }
        }

        std::cout << "Image number " << image_num++ << " contains " << count << " war eagles.\n";
    }

    return 0;
}
