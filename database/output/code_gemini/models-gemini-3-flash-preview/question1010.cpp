/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    // Optimization for fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n;
    // Reading input N
    if (!(std::cin >> n)) return 0;

    // Handle N < 1 though constraints say N >= 1
    if (n < 1) return 0;

    double pi_over_4 = 0.0;

    // Iterating through the first N terms of the Leibniz series
    // Series: 1/1 - 1/3 + 1/5 - 1/7 + 1/9 - ...
    // General term: (-1)^i / (2*i + 1)
    for (long long i = 0; i < n; ++i) {
        double denominator = 2.0 * i + 1.0;
        if (i % 2 == 0) {
            pi_over_4 += 1.0 / denominator;
        } else {
            pi_over_4 -= 1.0 / denominator;
        }
    }

    // Multiply the result by 4 to get Pi
    double pi = 4.0 * pi_over_4;

    // Output formatted with exactly 5 digits after the decimal point
    std::cout << std::fixed << std::setprecision(5) << pi << std::endl;

    return 0;
}