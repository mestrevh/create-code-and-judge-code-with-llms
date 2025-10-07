/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double d;
    std::cin >> d;

    double vi_kmh = 400.0;
    double vi_ms = vi_kmh / 3.6;
    double vf_ms = 0.0;

    double a = (pow(vf_ms, 2) - pow(vi_ms, 2)) / (2.0 * d);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "A desaceleracao desse veiculo foi de aproximadamente: " << a << " m/s^2" << std::endl;

    return 0;
}
