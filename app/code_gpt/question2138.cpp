/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    int N, M;
    std::cin >> N >> M;
    
    std::vector<int> pares;
    for (int i = 1; pares.size() < N; i++) {
        if (i % 2 == 0) {
            pares.push_back(i);
        }
    }
    
    int linhas = N / M;
    std::vector<std::vector<int>> matriz(linhas, std::vector<int>(M));
    
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < M; ++j) {
            matriz[i][j] = pares[i * M + j];
        }
    }

    for (int j = 0; j < M; ++j) {
        for (int i = 0; i < linhas; ++i) {
            if (i > 0 || j > 0) std::cout << " ";
            std::cout << matriz[i][j];
        }
        std::cout << std::endl;
    }

    return 0;
}
