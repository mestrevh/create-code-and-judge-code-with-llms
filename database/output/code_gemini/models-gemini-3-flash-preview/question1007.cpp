/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n;
    if (!(std::cin >> n)) {
        return 0;
    }

    if (n < 1) {
        return 0;
    }

    double sum = 0.0;
    for (long long i = 0; i < n; ++i) {
        double denominator = 2.0 * (double)i + 1.0;
        double term = 1.0 / denominator;
        if (i % 2 == 0) {
            sum += term;
        } else {
            sum -= term;
        }
    }

    double result = sum * 4.0;
    std::cout << std::fixed << std::setprecision(5) << result << std::endl;

    return 0;
}