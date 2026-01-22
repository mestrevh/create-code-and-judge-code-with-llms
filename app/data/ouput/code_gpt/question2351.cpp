/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>

double calcularMedia(const std::vector<int>& L, int n) {
    double soma = 0;
    for (int i = 0; i < n; ++i) {
        soma += L[i];
    }
    return soma / n;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> L(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> L[i];
    }
    double media = calcularMedia(L, n);
    std::cout << std::fixed << std::setprecision(2) << media << std::endl;
    return 0;
}
