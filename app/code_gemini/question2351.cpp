/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>

long long calcula_soma(const std::vector<int>& L, int n) {
    long long soma = 0;
    for (int i = 0; i < n; ++i) {
        soma += L[i];
    }
    return soma;
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

    long long soma = calcula_soma(L, n);

    double media = 0.0;
    if (n > 0) {
        media = static_cast<double>(soma) / n;
    }
    
    std::cout << std::fixed << std::setprecision(2) << media << std::endl;

    return 0;
}
