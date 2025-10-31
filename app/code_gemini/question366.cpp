/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    int s;
    std::cin >> n >> s;
    int saldo_atual = s;
    int menor_saldo = 0;
    int movimentacao;

    for (int i = 0; i < n; ++i) {
        std::cin >> movimentacao;
        saldo_atual += movimentacao;
        if (i == 0) {
            menor_saldo = saldo_atual;
        } else {
            menor_saldo = std::min(menor_saldo, saldo_atual);
        }
    }

    std::cout << menor_saldo << std::endl;

    return 0;
}
