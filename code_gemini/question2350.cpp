/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int encontrarMaximo(const std::vector<int>& L, int n) {
    if (n < 1) {
        return 0; 
    }
    int max_valor = L[0];
    for (int i = 1; i < n; ++i) {
        if (L[i] > max_valor) {
            max_valor = L[i];
        }
    }
    return max_valor;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    std::vector<int> L(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> L[i];
    }
    int resultado = encontrarMaximo(L, n);
    std::cout << resultado << std::endl;
    return 0;
}
