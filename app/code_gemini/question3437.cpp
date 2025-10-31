/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

std::vector<double> lerVetor(int n) {
    std::vector<double> vetor(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> vetor[i];
    }
    return vetor;
}

std::vector<double> converterParaRadianos(const std::vector<double>& graus) {
    std::vector<double> radianos(graus.size());
    const long double pi = acos(-1.0L);
    for (size_t i = 0; i < graus.size(); ++i) {
        radianos[i] = graus[i] * pi / 180.0;
    }
    return radianos;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<double> vetorGraus = lerVetor(n);
    std::vector<double> vetorRadianos = converterParaRadianos(vetorGraus);

    std::cout << std::fixed << std::setprecision(5);

    for (const double& rad : vetorRadianos) {
        std::cout << rad << std::endl;
    }

    return 0;
}
