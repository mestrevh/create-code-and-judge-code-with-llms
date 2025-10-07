/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    const double rate = 5.08;
    double val;

    for (int i = 0; i < 3; ++i) {
        std::cin >> val;
        double result = val * rate;
        long long result_times_100 = round(result * 100.0);

        if (result_times_100 % 10 == 0) {
            std::cout << std::fixed << std::setprecision(1) << result << std::endl;
        } else {
            std::cout << std::fixed << std::setprecision(2) << result << std::endl;
        }
    }

    return 0;
}
