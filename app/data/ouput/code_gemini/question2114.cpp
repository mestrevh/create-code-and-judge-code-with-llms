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

    std::vector<double> x_values(n);
    double y_dummy;

    for (int i = 0; i < n; ++i) {
        std::cin >> x_values[i] >> y_dummy;
    }

    std::cout << std::fixed << std::setprecision(2);

    for (int i = 0; i < n; ++i) {
        double current_power = 1.0;
        for (int j = 0; j < n; ++j) {
            if (j > 0) {
                std::cout << " ";
            }
            std::cout << current_power;
            current_power *= x_values[i];
        }
        std::cout << "\n";
    }

    return 0;
}
