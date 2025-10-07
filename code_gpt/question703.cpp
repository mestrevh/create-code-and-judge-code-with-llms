/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

int main() {
    int n;
    std::cin >> n;
    std::vector<double> numbers(n);
    double sum = 0.0;

    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
        sum += numbers[i];
    }

    double mean = sum / n;
    double variance_sum = 0.0;

    for (double num : numbers) {
        variance_sum += (num - mean) * (num - mean);
    }

    double stddev = std::sqrt(variance_sum / n);
    std::cout << std::fixed << std::setprecision(2) << stddev << std::endl;

    return 0;
}
