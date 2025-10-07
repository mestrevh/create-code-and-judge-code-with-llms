/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

double somar(double a, double b) {
    return a + b;
}

int main() {
    double a, b;
    std::cin >> a >> b;
    double c = somar(a, b);
    std::cout << std::fixed << std::setprecision(1) << "O resultado de " << a << " + " << b << " eh " << c << std::endl;
    return 0;
}
