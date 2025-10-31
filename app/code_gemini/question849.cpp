/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

double VolumeEsfera(double raio) {
    const double PI = 3.1416;
    return (4.0 * PI * raio * raio * raio) / 3.0;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cout << std::fixed << std::setprecision(2);

    double raio;
    for (int i = 0; i < 3; ++i) {
        std::cin >> raio;
        std::cout << VolumeEsfera(raio) << std::endl;
    }

    return 0;
}
