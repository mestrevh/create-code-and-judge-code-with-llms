/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

long long factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

double calculate_term(int i) {
    double numerator = static_cast<double>(factorial(i));
    double denominator = std::sqrt(2.0 * i + 1.0);
    return numerator / denominator;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<double> terms;
    double sum = 0.0;

    for (int i = 1; i <= N; ++i) {
        double current_term = calculate_term(i);
        sum += current_term;
        terms.push_back(current_term);
    }

    std::cout << std::fixed << std::setprecision(12);
    std::cout << "S: " << sum << '\n';

    for (int i = N - 2; i >= 0; --i) {
        std::cout << terms[i] << '\n';
    }

    return 0;
}
