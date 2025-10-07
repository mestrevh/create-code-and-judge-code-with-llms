/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    if (n == 0) {
        return 0;
    }

    std::vector<double> notas(n);
    double soma = 0.0;

    for (int i = 0; i < n; ++i) {
        std::cin >> notas[i];
        soma += notas[i];
    }

    double media = soma / n;

    double maisProximo = notas[0];
    double menorDiferenca = std::fabs(notas[0] - media);

    for (int i = 1; i < n; ++i) {
        double diferencaAtual = std::fabs(notas[i] - media);
        if (diferencaAtual < menorDiferenca) {
            menorDiferenca = diferencaAtual;
            maisProximo = notas[i];
        }
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "MEDIA: " << media << std::endl;
    std::cout << "MAIS PROXIMO: " << maisProximo << std::endl;
    std::cout << "DIFERENCA: " << menorDiferenca << std::endl;

    return 0;
}
