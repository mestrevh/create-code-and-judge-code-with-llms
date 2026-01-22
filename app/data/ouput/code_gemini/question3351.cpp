/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int matA[3][3];
    int matB[3][3];
    int matC[3][3];

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cin >> matA[i][j];
        }
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cin >> matB[i][j];
        }
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            matC[i][j] = 0;
            for (int k = 0; k < 3; ++k) {
                matC[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }

    for (int i = 0; i < 3; ++i) {
        std::cout << matC[i][0] << " " << matC[i][1] << " " << matC[i][2] << "\n";
    }

    return 0;
}
