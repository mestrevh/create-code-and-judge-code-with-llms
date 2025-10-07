/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    int menor_valor;
    int posicao = 0;
    for (int i = 0; i < n; ++i) {
        int valor_atual;
        std::cin >> valor_atual;
        if (i == 0) {
            menor_valor = valor_atual;
            posicao = 0;
        } else {
            if (valor_atual < menor_valor) {
                menor_valor = valor_atual;
                posicao = i;
            }
        }
    }
    std::cout << "Menor valor: " << menor_valor << "\n";
    std::cout << "Posicao: " << posicao << "\n";
    return 0;
}
