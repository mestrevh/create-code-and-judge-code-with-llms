/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int L, C;
    std::cin >> L >> C;
    int matrix1[25][25];
    int matrix2[25][25];
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < C; ++j) {
            std::cin >> matrix1[i][j];
        }
    }
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < C; ++j) {
            std::cin >> matrix2[i][j];
        }
    }
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < C; ++j) {
            std::cout << matrix1[i][j] + matrix2[i][j];
            if (j < C - 1) {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }
    return 0;
}
