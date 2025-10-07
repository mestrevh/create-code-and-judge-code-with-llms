/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<std::vector<int>> campo(N, std::vector<int>(M));
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cin >> campo[i][j];
        }
    }

    int max_produtividade = 0;

    for (int i = 0; i < N; ++i) {
        int soma_linha = 0;
        for (int j = 0; j < M; ++j) {
            soma_linha += campo[i][j];
        }
        max_produtividade = std::max(max_produtividade, soma_linha);
    }

    for (int j = 0; j < M; ++j) {
        int soma_coluna = 0;
        for (int i = 0; i < N; ++i) {
            soma_coluna += campo[i][j];
        }
        max_produtividade = std::max(max_produtividade, soma_coluna);
    }

    std::cout << max_produtividade << std::endl;
    return 0;
}
