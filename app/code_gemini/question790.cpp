/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int n, p;
std::vector<int> valores;
std::vector<int> pesos;

int mochila(int index, int capacidade_restante) {
    if (index == n) {
        return 0;
    }

    int nao_pega = mochila(index + 1, capacidade_restante);

    int pega = 0;
    if (pesos[index] <= capacidade_restante) {
        pega = valores[index] + mochila(index + 1, capacidade_restante - pesos[index]);
    }

    return std::max(nao_pega, pega);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> p;

    valores.resize(n);
    pesos.resize(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> valores[i];
    }

    for (int i = 0; i < n; ++i) {
        std::cin >> pesos[i];
    }

    std::cout << mochila(0, p) << std::endl;

    return 0;
}
