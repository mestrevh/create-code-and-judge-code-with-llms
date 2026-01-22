/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

int main() {
    int N, S;
    std::cin >> N >> S;
    int saldo = S, menor_saldo = S;
    
    for (int i = 0; i < N; ++i) {
        int movimentacao;
        std::cin >> movimentacao;
        saldo += movimentacao;
        menor_saldo = std::min(menor_saldo, saldo);
    }
    
    std::cout << menor_saldo << std::endl;
    return 0;
}
