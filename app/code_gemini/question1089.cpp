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

    if (n == 0) {
        std::cout << std::fixed << std::setprecision(2) << 0.0 << std::endl;
    } else {
        for (int i = 1; i <= n; ++i) {
            std::cout << i << "/" << 3 * i;
            if (i < n) {
                std::cout << " + ";
            }
        }
        std::cout << std::endl;

        double sum = static_cast<double>(n) / 3.0;
        std::cout << std::fixed << std::setprecision(2) << sum << std::endl;
    }

    return 0;
}
