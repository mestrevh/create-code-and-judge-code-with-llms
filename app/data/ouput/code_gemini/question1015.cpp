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

    long double sum_x = 0.0;
    long double sum_y = 0.0;
    long double sum_xy = 0.0;
    long double sum_x_sq = 0.0;
    long double n_ld = n;

    for (int i = 0; i < n; ++i) {
        long double x, y;
        std::cin >> x >> y;
        sum_x += x;
        sum_y += y;
        sum_xy += x * y;
        sum_x_sq += x * x;
    }

    long double denominator = n_ld * sum_x_sq - sum_x * sum_x;

    long double a = (n_ld * sum_xy - sum_x * sum_y) / denominator;
    long double b = (sum_y * sum_x_sq - sum_x * sum_xy) / denominator;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "A: " << a << std::endl;
    std::cout << "B: " << b << std::endl;

    return 0;
}
