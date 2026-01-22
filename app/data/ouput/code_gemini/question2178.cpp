/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<double> v(n);
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
        sum += v[i];
    }

    if (n <= 1) {
        std::cout << std::fixed << std::setprecision(2) << 0.0 << std::endl;
        return 0;
    }

    double mean = sum / n;

    double sum_sq_diff = 0.0;
    for (int i = 0; i < n; ++i) {
        sum_sq_diff += (v[i] - mean) * (v[i] - mean);
    }

    double std_dev = std::sqrt(sum_sq_diff / (n - 1));

    std::cout << std::fixed << std::setprecision(2) << std_dev << std::endl;

    return 0;
}
