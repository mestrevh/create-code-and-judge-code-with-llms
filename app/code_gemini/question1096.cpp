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

    int n;
    std::cin >> n;

    const double PI = 3.14;
    double sum = 0.0;
    long double current_factorial = 1.0;

    for (int i = 1; i <= n; ++i) {
        current_factorial *= i;
        double numerator = pow(i, i);
        double term = numerator / current_factorial;

        if (i % 2 != 0) {
            sum += term * PI;
        } else {
            sum += term;
        }
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Valor de S : " << sum << std::endl;

    return 0;
}
