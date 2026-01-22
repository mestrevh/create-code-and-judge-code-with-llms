/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

int raizes(float A, float B, float C, float *x1, float *x2) {
    float delta = (B * B) - (4 * A * C);

    if (delta < 0) {
        return 0;
    }

    float sqrt_delta = sqrt(delta);

    if (delta == 0) {
        *x1 = -B / (2 * A);
        return 1;
    } else { // delta > 0
        *x1 = (-B + sqrt_delta) / (2 * A);
        *x2 = (-B - sqrt_delta) / (2 * A);
        return 2;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    float a, b, c;
    std::cin >> a >> b >> c;

    float r1, r2;
    int num_solucoes = raizes(a, b, c, &r1, &r2);

    std::cout << std::fixed << std::setprecision(2);

    if (num_solucoes == 2) {
        std::cout << r1 << " " << r2 << std::endl;
        std::cout << 2 << std::endl;
    } else if (num_solucoes == 1) {
        std::cout << r1 << std::endl;
        std::cout << 1 << std::endl;
    } else {
        std::cout << 0 << std::endl;
    }

    return 0;
}
