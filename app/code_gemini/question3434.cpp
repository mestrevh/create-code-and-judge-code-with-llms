/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

std::vector<double> lerVetor(int n) {
    std::vector<double> vetor(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> vetor[i];
    }
    return vetor;
}

double menorElemento(const std::vector<double>& vetor) {
    return *std::min_element(vetor.begin(), vetor.end());
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    if (n <= 0) {
        return 0;
    }

    std::vector<double> v = lerVetor(n);
    double menor = menorElemento(v);

    std::cout << std::fixed << std::setprecision(1) << menor << std::endl;

    return 0;
}
