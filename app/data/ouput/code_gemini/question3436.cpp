/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

long double calcularArea(long double raio) {
    return M_PI * raio * raio;
}

long double calcularPerimetro(long double raio) {
    return 2 * M_PI * raio;
}

int main() {
    long double raio;
    std::cin >> raio;

    std::cout << std::fixed << std::setprecision(5);
    std::cout << calcularArea(raio) << std::endl;
    std::cout << calcularPerimetro(raio) << std::endl;

    return 0;
}
