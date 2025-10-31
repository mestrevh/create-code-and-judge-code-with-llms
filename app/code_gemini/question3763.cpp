/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    char dir;
    int R, C;
    std::cin >> dir >> R >> C;

    std::vector<std::vector<int>> matrix(R, std::vector<int>(C));

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    if (dir == 'V') {
        int half_rows = R / 2;
        int half_cols = C / 2;
        for (int i = 0; i < half_rows; ++i) {
            for (int j = half_cols; j < C; ++j) {
                std::swap(matrix[i][j], matrix[R - 1 - i][j]);
            }
        }
    } else {
        int half_rows = R / 2;
        int half_cols = C / 2;
        for (int i = half_rows; i < R; ++i) {
            for (int j = 0; j < half_cols; ++j) {
                std::swap(matrix[i][j], matrix[i][C - 1 - j]);
            }
        }
    }

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            printf("%02d%c", matrix[i][j], (j == C - 1 ? '\n' : ' '));
        }
    }

    return 0;
}
