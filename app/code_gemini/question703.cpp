/*
Código criado pelo Gemini Pro 2.5
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
    std::cin >> n;

    double sum = 0.0;
    double sum_of_squares = 0.0;
    
    for (int i = 0; i < n; ++i) {
        double x;
        std::cin >> x;
        sum += x;
        sum_of_squares += x * x;
    }

    double mean = sum / n;
    double variance = (sum_of_squares / n) - (mean * mean);
    double std_dev = std::sqrt(variance);

    std::cout << std::fixed << std::setprecision(2) << std_dev << std::endl;

    return 0;
}
