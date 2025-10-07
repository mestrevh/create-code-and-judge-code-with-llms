/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

float calculaDelta(float a, float b, float c) {
    return (b * b) - (4 * a * c);
}

void calculaRaizes(float a, float b, float c, float *x1, float *x2) {
    float delta = calculaDelta(a, b, c);
    float sqrt_delta = sqrt(delta);
    *x1 = (-b + sqrt_delta) / (2 * a);
    *x2 = (-b - sqrt_delta) / (2 * a);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    float a, b, c;
    std::cin >> a >> b >> c;

    std::cout << "Digite os coeficientes da equacao:" << std::endl;

    float delta = calculaDelta(a, b, c);

    if (a == 0.0 || delta < 0.0) {
        std::cout << "Impossivel calcular" << std::endl;
    } else {
        float x1, x2;
        calculaRaizes(a, b, c, &x1, &x2);
        std::cout << std::fixed << std::setprecision(5);
        std::cout << "X1 = " << x1 << std::endl;
        std::cout << "X2 = " << x2 << std::endl;
    }

    return 0;
}
