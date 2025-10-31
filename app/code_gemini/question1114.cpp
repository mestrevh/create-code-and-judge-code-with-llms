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

    int n;
    std::cin >> n;

    if (n == 0) {
        std::cout << "S: 0.00" << std::endl;
        return 0;
    }

    long double sum = 0.0;
    long double power_of_2 = 1.0;

    for (int i = 1; i <= n; ++i) {
        if (i % 2 != 0) {
            sum += static_cast<long double>(i) / power_of_2;
        } else {
            sum += power_of_2 / (3.0L * (i / 2));
        }
        power_of_2 *= 2.0L;
    }

    std::cout << "S: " << std::fixed << std::setprecision(2) << sum << std::endl;

    return 0;
}
