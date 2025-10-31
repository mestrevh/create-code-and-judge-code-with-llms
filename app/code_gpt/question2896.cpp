/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

double calcularRamen(int X, int C) {
    double V = X;
    for (int n = 1; n <= (C - 1); n++) {
        int expoente = 2 * n;
        double fatorial = 1;
        for (int i = 1; i <= (2 * n + 1); i++) {
            fatorial *= i;
        }
        V += (n % 2 == 0 ? 1 : -1) * pow(X, expoente) / fatorial;
    }
    return V;
}

int main() {
    int X, C;
    std::cin >> X >> C;
    double resultado = calcularRamen(X, C);
    std::cout << std::fixed << std::setprecision(3) << fabs(resultado) << std::endl;
    return 0;
}
