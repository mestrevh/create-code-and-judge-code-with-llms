/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <limits>

int main() {
    int N;
    std::cin >> N;
    std::vector<double> notas(N);
    double soma = 0.0;

    for (int i = 0; i < N; ++i) {
        std::cin >> notas[i];
        soma += notas[i];
    }

    double media = soma / N;
    double mais_proximo = notas[0];
    double menor_diferenca = std::abs(notas[0] - media);

    for (int i = 1; i < N; ++i) {
        double diferenca = std::abs(notas[i] - media);
        if (diferenca < menor_diferenca) {
            menor_diferenca = diferenca;
            mais_proximo = notas[i];
        }
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "MEDIA: " << media << std::endl;
    std::cout << "MAIS PROXIMO: " << mais_proximo << std::endl;
    std::cout << "DIFERENCA: " << menor_diferenca << std::endl;

    return 0;
}
