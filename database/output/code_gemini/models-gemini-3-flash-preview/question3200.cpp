/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long double raio, altura;
    if (std::cin >> raio >> altura) {
        long double pi = std::acos(-1.0L);
        long double volume = pi * (raio * raio) * altura;
        std::cout << std::setprecision(16) << volume << "\n";
    }

    return 0;
}