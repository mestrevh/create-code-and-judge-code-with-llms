/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>

std::vector<double> lerVetor(int n) {
    std::vector<double> vetor(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> vetor[i];
    }
    return vetor;
}

double produtoInterno(const std::vector<double>& v1, const std::vector<double>& v2, int n) {
    double resultado = 0.0;
    for (int i = 0; i < n; ++i) {
        resultado += v1[i] * v2[i];
    }
    return resultado;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<double> vetor1 = lerVetor(n);
    std::vector<double> vetor2 = lerVetor(n);

    double resultado = produtoInterno(vetor1, vetor2, n);

    std::cout << std::fixed << std::setprecision(1) << resultado << std::endl;

    return 0;
}
