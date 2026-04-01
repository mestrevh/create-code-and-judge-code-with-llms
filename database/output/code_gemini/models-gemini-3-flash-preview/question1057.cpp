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

    double a, b;
    if (!(std::cin >> a >> b)) return 0;

    double hipotenusa = std::sqrt(a * a + b * b);

    std::cout << std::fixed << std::setprecision(2) << hipotenusa << std::endl;

    return 0;
}