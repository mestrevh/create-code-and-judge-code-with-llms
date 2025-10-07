/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    if (n == 0) {
        std::cout << std::fixed << std::setprecision(2) << 0.0 << std::endl;
        return 0;
    }

    double sum = 0.0;
    for (int i = 1; i <= n; ++i) {
        if (i % 2 != 0) { // Ímpar
            double numerator = static_cast<double>(i);
            double denominator = static_cast<double>(2 * (i + 1));
            sum += numerator / denominator;
        } else { // Par
            sum += 1.0;
        }
    }

    std::cout << std::fixed << std::setprecision(2) << sum << std::endl;

    for (int i = 1; i <= n; ++i) {
        if (i > 1) {
            std::cout << " + ";
        }
        if (i % 2 != 0) { // Ímpar
            int numerator = i;
            int denominator = 2 * (i + 1);
            std::cout << numerator << "/" << denominator;
        } else { // Par
            std::cout << "1";
        }
    }
    std::cout << std::endl;

    return 0;
}
