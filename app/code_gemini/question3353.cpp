/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int R, C;
    std::cin >> R >> C;

    int matrix[100][100];

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    for (int j = 0; j < C; ++j) {
        for (int i = 0; i < R; ++i) {
            std::cout << matrix[i][j];
            if (i < R - 1) {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }

    return 0;
}
