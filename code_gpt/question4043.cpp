/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

double calcularExpoRecursivo(double x, int n, double termo) {
    if (n == 0) return 1;
    return termo + calcularExpoRecursivo(x, n - 1, termo * x / n);
}

int main() {
    double x;
    std::cin >> x;

    double valorReal = exp(x);
    double aproximacao = 0;
    int iteracoes;

    for (iteracoes = 0; ; ++iteracoes) {
        double termo = pow(x, iteracoes) / (iteracoes == 0 ? 1 : iteracoes);
        aproximacao += termo;

        std::cout << "e^" << x << " com " << iteracoes << " iteracoes -> "
                  << std::fixed << std::setprecision(5) << aproximacao << std::endl;

        if (iteracoes > 0 && fabs(valorReal - aproximacao) <= 0.0001) {
            break;
        }
    }

    std::cout << "\nNumero de iteracoes -> " << iteracoes << std::endl;
    return 0;
}
