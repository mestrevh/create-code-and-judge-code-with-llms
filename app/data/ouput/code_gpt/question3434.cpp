/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <limits>

void lerVetor(std::vector<double>& vetor, int n) {
    double valor;
    for (int i = 0; i < n; ++i) {
        std::cin >> valor;
        vetor.push_back(valor);
    }
}

double menorElemento(const std::vector<double>& vetor) {
    double menor = std::numeric_limits<double>::max();
    for (const auto& num : vetor) {
        if (num < menor) {
            menor = num;
        }
    }
    return menor;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<double> vetor;
    lerVetor(vetor, n);
    std::cout << menorElemento(vetor) << std::endl;
    return 0;
}
