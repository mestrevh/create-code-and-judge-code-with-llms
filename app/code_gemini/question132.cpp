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

    int N, M, S;
    while (std::cin >> N >> M >> S && (N != 0 || M != 0 || S != 0)) {
        std::vector<std::string> grid(N);
        int r = -1, c = -1, dir = -1;

        for (int i = 0; i < N; ++i) {
            std::cin >> grid[i];
            for (int j = 0; j < M; ++j) {
                char cell = grid[i][j];
                if (cell == 'N' || cell == 'S' || cell == 'L' || cell == 'O') {
                    r = i;
                    c = j;
                    if (cell == 'N') dir = 0;
                    else if (cell == 'L') dir = 1;
                    else if (cell == 'S') dir = 2;
                    else if (cell == 'O') dir = 3;
                }
            }
        }

        std::string instructions;
        std::cin >> instructions;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        int stickers_collected = 0;

        for (char instruction : instructions) {
            if (instruction == 'D') {
                dir = (dir + 1) % 4;
            } else if (instruction == 'E') {
                dir = (dir - 1 + 4) % 4;
            } else if (instruction == 'F') {
                int next_r = r + dr[dir];
                int next_c = c + dc[dir];

                if (next_r >= 0 && next_r < N && next_c >= 0 && next_c < M && grid[next_r][next_c] != '#') {
                    r = next_r;
                    c = next_c;
                    if (grid[r][c] == '*') {
                        stickers_collected++;
                        grid[r][c] = '.';
                    }
                }
            }
        }
        std::cout << stickers_collected << std::endl;
    }

    return 0;
}
