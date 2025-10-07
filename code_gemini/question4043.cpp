/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

double fatorial(int n) {
    if (n <= 1) {
        return 1.0;
    }
    return n * fatorial(n - 1);
}

double potencia(double base, int exp) {
    if (exp == 0) {
        return 1.0;
    }
    return base * potencia(base, exp - 1);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double x;
    std::cin >> x;

    double valor_real = exp(x);
    double soma_aproximada = 0.0;
    int i = 0;

    while (true) {
        double termo = potencia(x, i) / fatorial(i);
        soma_aproximada += termo;

        std::cout << "e^" << std::fixed << std::setprecision(1) << x
                  << " com " << i << " iteracoes -> "
                  << std::fixed << std::setprecision(5) << soma_aproximada
                  << std::endl;

        if (std::abs(valor_real - soma_aproximada) <= 0.0001) {
            break;
        }

        i++;
    }

    std::cout << std::endl << std::endl;
    std::cout << "Numero de iteracoes -> " << i << std::endl;

    return 0;
}
