/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    double sum = 0.0;
    double sign = 1.0;
    for (int i = 0; i < n; ++i) {
        double denominator = 2.0 * i + 1.0;
        sum += sign / denominator;
        sign *= -1.0;
    }
    double pi_approx = sum * 4.0;
    std::cout << std::fixed << std::setprecision(5) << pi_approx << std::endl;
    return 0;
}
