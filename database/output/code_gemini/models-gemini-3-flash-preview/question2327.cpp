/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <algorithm>

double encontrar_menor(double x, double y, double z) {
    double menor = x;
    if (y < menor) menor = y;
    if (z < menor) menor = z;
    return menor;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double a, b, c;
    if (std::cin >> a >> b >> c) {
        std::cout << std::fixed << std::setprecision(2) << encontrar_menor(a, b, c) << "\n";
    }

    return 0;
}