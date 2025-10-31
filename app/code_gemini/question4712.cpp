/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

void calculadora(double a, double b) {
    std::cout << std::fixed << std::setprecision(1);

    std::cout << a << " + " << b << " = " << (a + b) << std::endl;
    std::cout << b << " - " << a << " = " << (b - a) << std::endl;
    std::cout << a << " * " << b << " = " << (a * b) << std::endl;

    std::cout << b << " / " << a << " = ";
    if (a == 0.0) {
        std::cout << "Indeterminado" << std::endl;
    } else {
        std::cout << std::fixed << std::setprecision(16) << (b / a) << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double a, b;
    std::cin >> a >> b;

    calculadora(a, b);

    return 0;
}
