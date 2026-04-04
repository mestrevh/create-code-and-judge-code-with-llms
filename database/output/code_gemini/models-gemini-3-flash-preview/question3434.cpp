/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<double> lerVetor(int n) {
    std::vector<double> vetor(n);
    for (int i = 0; i < n; ++i) {
        if (!(std::cin >> vetor[i])) break;
    }
    return vetor;
}

double encontrarMenor(const std::vector<double>& vetor) {
    if (vetor.empty()) return 0.0;
    double menor = vetor[0];
    for (size_t i = 1; i < vetor.size(); ++i) {
        if (vetor[i] < menor) {
            menor = vetor[i];
        }
    }
    return menor;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (std::cin >> n && n > 0) {
        std::vector<double> vetor = lerVetor(n);
        double menor = encontrarMenor(vetor);
        std::cout << menor << std::endl;
    }

    return 0;
}