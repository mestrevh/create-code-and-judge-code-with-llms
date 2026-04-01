/*
Código criado pelo gpt-4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<int> casas(N);
    std::vector<int> encomendas(M);

    for (int i = 0; i < N; i++) {
        std::cin >> casas[i];
    }

    for (int i = 0; i < M; i++) {
        std::cin >> encomendas[i];
    }

    int tempo = 0;
    int pos_atual = casas[0];

    for (int i = 0; i < M; i++) {
        int pos_entrega = encomendas[i];
        auto it = std::lower_bound(casas.begin(), casas.end(), pos_entrega);
        if (it != casas.end()) {
            tempo += std::abs(pos_atual - pos_entrega);
            pos_atual = pos_entrega;
        }
    }

    std::cout << tempo << std::endl;
    return 0;
}