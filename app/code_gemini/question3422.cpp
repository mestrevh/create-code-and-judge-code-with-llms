/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    double s = 0.0;
    double sign = 1.0;
    for (int i = 0; i < n; ++i) {
        double denominator_base = 2 * i + 1;
        double term = sign / pow(denominator_base, 3);
        s += term;
        sign *= -1;
    }
    double pi = cbrt(s * 32.0);
    std::cout << std::fixed << std::setprecision(5) << pi << std::endl;
    return 0;
}
