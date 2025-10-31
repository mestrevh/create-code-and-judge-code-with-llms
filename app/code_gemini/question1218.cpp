/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cstdio>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, q;
    std::cin >> n >> q;

    double vendas[101] = {0.0};

    for (int i = 0; i < q; ++i) {
        int v;
        double p;
        std::cin >> v >> p;
        vendas[v] += p;
    }

    int vagao_mais_lucrativo = 1;
    double maior_venda = -1.0;

    for (int i = 1; i <= n; ++i) {
        if (vendas[i] > maior_venda) {
            maior_venda = vendas[i];
            vagao_mais_lucrativo = i;
        }
    }

    printf("%d %.1f\n", vagao_mais_lucrativo, maior_venda);

    return 0;
}
