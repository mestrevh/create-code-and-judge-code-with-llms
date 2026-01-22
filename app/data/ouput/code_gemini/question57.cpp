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

    std::vector<double> numbers;
    double num;

    while (std::cin >> num && num != -1.0) {
        numbers.push_back(num);
    }

    if (numbers.empty()) {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << 0.00 << '\n';
        std::cout << 0.00 << '\n';
        std::cout << 0 << '\n';
        return 0;
    }

    if (numbers.size() == 1) {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << numbers[0] << '\n';
        std::cout << 0.00 << '\n';
        std::cout << 0 << '\n';
        return 0;
    }

    const int n = numbers.size();
    
    double sum = 0.0;
    for (const auto& val : numbers) {
        sum += val;
    }

    double mean = sum / n;

    double sum_sq_diff = 0.0;
    for (const auto& val : numbers) {
        sum_sq_diff += (val - mean) * (val - mean);
    }
    
    double std_dev = std::sqrt(sum_sq_diff / (n - 1));

    int count_greater = 0;
    for (const auto& val : numbers) {
        if (val > mean) {
            count_greater++;
        }
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << mean << '\n';
    std::cout << std_dev << '\n';
    std::cout << count_greater << '\n';

    return 0;
}
