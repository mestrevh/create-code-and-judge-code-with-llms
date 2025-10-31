/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

std::vector<double> lerVetor(int n) {
    std::vector<double> vetor(n);
    for (int i = 0; i < n; i++) {
        std::cin >> vetor[i];
    }
    return vetor;
}

double produtoInterno(const std::vector<double>& v1, const std::vector<double>& v2, int n) {
    double produto = 0.0;
    for (int i = 0; i < n; i++) {
        produto += v1[i] * v2[i];
    }
    return produto;
}

int main() {
    int n;
    std::cin >> n;
    auto vetor1 = lerVetor(n);
    auto vetor2 = lerVetor(n);
    double resultado = produtoInterno(vetor1, vetor2, n);
    std::cout << resultado << std::endl;
    return 0;
}
