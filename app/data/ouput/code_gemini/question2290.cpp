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

    int M;
    std::cin >> M;

    int N;
    std::cin >> N;

    std::vector<std::vector<char>> map(M, std::vector<char>(M));
    int snake_row = -1, snake_col = -1;

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cin >> map[i][j];
            if (map[i][j] == '#') {
                snake_row = i;
                snake_col = j;
            }
        }
    }

    bool game_over = false;

    for (int k = 0; k < N; ++k) {
        char move;
        std::cin >> move;

        int next_row = snake_row;
        int next_col = snake_col;

        if (move == 'D') {
            next_col++;
        } else if (move == 'E') {
            next_col--;
        } else if (move == 'C') {
            next_row--;
        } else if (move == 'B') {
            next_row++;
        }

        next_row = (next_row % M + M) % M;
        next_col = (next_col % M + M) % M;

        if (map[next_row][next_col] == '@') {
            game_over = true;
            break;
        }

        map[snake_row][snake_col] = '*';
        snake_row = next_row;
        snake_col = next_col;
        map[snake_row][snake_col] = '#';
    }

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cout << map[i][j] << (j == M - 1 ? "" : " ");
        }
        std::cout << '\n';
    }

    if (game_over) {
        std::cout << "Game over.\n";
    }

    return 0;
}
