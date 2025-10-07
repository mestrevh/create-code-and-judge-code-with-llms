/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> matriz(N, std::vector<int>(M));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            std::cin >> matriz[i][j];

    if (N != M) {
        std::cout << "A matriz nao possui traco" << std::endl;
    } else {
        int traco = 0, diagonalSecundaria = 0;
        for (int i = 0; i < N; ++i) {
            traco += matriz[i][i];
            diagonalSecundaria += matriz[i][N - 1 - i];
        }
        std::cout << traco << std::endl << diagonalSecundaria << std::endl;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cout << matriz[i][j];
            if (j < M - 1) std::cout << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
