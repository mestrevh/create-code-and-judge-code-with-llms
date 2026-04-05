/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (!(std::cin >> n)) return 0;

    std::vector<double> data(n);
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        if (std::cin >> data[i]) {
            sum += data[i];
        }
    }

    double mean = sum / (double)n;
    double sum_sq_diff = 0.0;
    for (int i = 0; i < n; ++i) {
        double diff = data[i] - mean;
        sum_sq_diff += diff * diff;
    }

    double variance = sum_sq_diff / (double)n;
    double std_dev = std::sqrt(variance);

    std::cout << std::fixed << std::setprecision(2) << std_dev << std::endl;

    return 0;
}