/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<double> multipliers = {0.75, 0.80, 0.82, 0.85, 0.88, 0.90};

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        int d;
        double p;
        std::cin >> d >> p;

        for (int year = 0; year < 3; ++year) {
            if (p > 100.0) {
                p *= multipliers[d];
            } else {
                if (p >= 45.0) {
                    double special_multiplier = (multipliers[d] + 1.0) / 2.0;
                    double new_p = p * special_multiplier;
                    p = std::max(new_p, 45.0);
                }
            }
        }

        std::cout << "Jogo[" << i << "] = R$" << std::fixed << std::setprecision(2) << p << std::endl;
    }

    return 0;
}
