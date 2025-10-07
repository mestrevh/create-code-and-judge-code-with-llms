/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int matrix1[6][6];
    int matrix2[6][6];

    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            std::cin >> matrix1[i][j];
        }
    }

    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            std::cin >> matrix2[i][j];
        }
    }

    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            std::cout << matrix1[i][j] + matrix2[i][j];
            if (j < 5) {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }

    return 0;
}
