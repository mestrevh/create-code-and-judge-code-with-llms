/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>

int contarOcorrencias(int x, const std::vector<int>& L, int n) {
    int contador = 0;
    for (int i = 0; i < n; ++i) {
        if (L[i] == x) {
            contador++;
        }
    }
    return contador;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int x;
    std::cin >> x;

    int n;
    std::cin >> n;

    std::vector<int> L(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> L[i];
    }

    int resultado = contarOcorrencias(x, L, n);

    std::cout << resultado << std::endl;

    return 0;
}
