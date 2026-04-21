/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

float calculaDelta(float a, float b, float c) {
    return (b * b) - (4.0f * a * c);
}

void calculaRaizes(float a, float b, float c, float *x1, float *x2) {
    float delta = calculaDelta(a, b, c);
    float sqrtDelta = std::sqrt(delta);
    *x1 = (-b + sqrtDelta) / (2.0f * a);
    *x2 = (-b - sqrtDelta) / (2.0f * a);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    float a, b, c;
    if (!(std::cin >> a >> b >> c)) return 0;

    std::cout << "Digite os coeficientes da equacao:" << std::endl;

    float delta = calculaDelta(a, b, c);

    if (a == 0.0f || delta < 0.0f) {
        std::cout << "Impossivel calcular" << std::endl;
    } else {
        float r1, r2;
        calculaRaizes(a, b, c, &r1, &r2);
        std::cout << std::fixed << std::setprecision(5);
        std::cout << "X1 = " << r1 << "\n";
        std::cout << "X2 = " << r2 << "\n";
    }

    return 0;
}