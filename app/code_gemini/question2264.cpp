/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<std::vector<int>> board(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> board[i][j];
        }
    }

    int max_score = 0;

    int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            if (board[r][c] == 0) {
                int current_score = 0;
                for (int i = 0; i < 8; ++i) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    while (nr >= 0 && nr < n && nc >= 0 && nc < n && board[nr][nc] == 0) {
                        current_score++;
                        nr += dr[i];
                        nc += dc[i];
                    }
                }
                if (current_score > max_score) {
                    max_score = current_score;
                }
            }
        }
    }

    std::cout << max_score << std::endl;

    return 0;
}
