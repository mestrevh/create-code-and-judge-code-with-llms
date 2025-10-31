/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int L1, C1, L2, C2;
    std::cin >> L1 >> C1;
    std::cin >> L2 >> C2;

    if (C1 != L2) {
        std::cout << "impossivel multiplicar\n";
        return 0;
    }

    int matA[25][25];
    int matB[25][25];
    int matRes[25][25];

    for (int i = 0; i < L1; ++i) {
        for (int j = 0; j < C1; ++j) {
            std::cin >> matA[i][j];
        }
    }

    for (int i = 0; i < L2; ++i) {
        for (int j = 0; j < C2; ++j) {
            std::cin >> matB[i][j];
        }
    }

    for (int i = 0; i < L1; ++i) {
        for (int j = 0; j < C2; ++j) {
            matRes[i][j] = 0;
            for (int k = 0; k < C1; ++k) {
                matRes[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }

    for (int i = 0; i < L1; ++i) {
        for (int j = 0; j < C2; ++j) {
            std::cout << matRes[i][j];
            if (j < C2 - 1) {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }

    return 0;
}
