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

    int x_int, num_terms;
    std::cin >> x_int >> num_terms;

    double x = static_cast<double>(x_int);
    double approximation_sum = 0.0;
    double term = 1.0;

    for (int i = 0; i < num_terms; ++i) {
        approximation_sum += term;
        term = term * x / (i + 1.0);
    }

    double true_value = exp(x);
    double diff = std::fabs(true_value - approximation_sum);

    std::cout << std::fixed << std::setprecision(3) << approximation_sum << std::endl;

    if (diff > 0.10 * true_value) {
        std::cout << "A aproximacao foi pouco precisa" << std::endl;
    } else if (diff > 0.01 * true_value) {
        std::cout << "A aproximacao foi muito precisa" << std::endl;
    } else {
        std::cout << "Os valores sao praticamente iguais" << std::endl;
    }

    return 0;
}
