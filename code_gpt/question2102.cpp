/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    int M, N;
    std::cin >> M >> N;
    std::vector<std::vector<int>> matriz(M, std::vector<int>(N));

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> matriz[i][j];
        }
    }

    for (int j = 0; j < N; ++j) {
        for (int i = 0; i < M; ++i) {
            std::cout << matriz[i][j];
            if (i != M - 1) std::cout << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
