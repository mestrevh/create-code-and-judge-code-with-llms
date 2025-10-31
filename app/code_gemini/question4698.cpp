/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

double somar(double a, double b) {
    return a + b;
}

int main() {
    double a, b;
    std::cin >> a >> b;

    double resultado = somar(a, b);

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "O resultado de " << a << " + " << b << " eh ";

    if (resultado == static_cast<long long>(resultado)) {
        std::cout << std::fixed << std::setprecision(0) << resultado << std::endl;
    } else {
        std::cout << std::fixed << std::setprecision(1) << resultado << std::endl;
    }

    return 0;
}
