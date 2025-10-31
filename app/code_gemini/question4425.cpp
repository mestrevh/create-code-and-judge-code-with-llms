/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <utility>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<std::string> board(n);
    int x_row = -1, x_col = -1;

    for (int i = 0; i < n; ++i) {
        std::cin >> board[i];
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == 'x') {
                x_row = i;
                x_col = j;
            }
        }
    }

    char move;
    while (std::cin >> move) {
        int new_row = x_row;
        int new_col = x_col;

        if (move == 'U') {
            new_row = (x_row - 1 + n) % n;
        } else if (move == 'D') {
            new_row = (x_row + 1) % n;
        } else if (move == 'L') {
            new_col = (x_col - 1 + n) % n;
        } else if (move == 'R') {
            new_col = (x_col + 1) % n;
        }

        std::swap(board[x_row][x_col], board[new_row][new_col]);
        x_row = new_row;
        x_col = new_col;
    }

    for (int i = 0; i < n; ++i) {
        std::cout << board[i] << std::endl;
    }

    return 0;
}
