/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

double combinations(int n, int k) {
    if (k < 0 || k > n) {
        return 0.0;
    }
    if (k == 0 || k == n) {
        return 1.0;
    }
    if (k > n / 2) {
        k = n - k;
    }
    double res = 1.0;
    for (int i = 1; i <= k; ++i) {
        res = res * (n - i + 1) / i;
    }
    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    double B;
    std::cin >> n >> B;

    int best_id = -1;
    double min_prob = 2.0;

    int id;
    double p, d;
    while (std::cin >> id >> p >> d) {
        if (id == -1 && p == 0.0 && d == 0.0) {
            break;
        }

        int k_max = 0;
        if (B > 0) {
            k_max = static_cast<int>(floor(d / B));
        } else {
             k_max = n + 1;
        }

        double current_overload_prob = 0.0;

        for (int k = k_max + 1; k <= n; ++k) {
            double term = combinations(n, k) * pow(p, k) * pow(1.0 - p, n - k);
            current_overload_prob += term;
        }

        if (current_overload_prob < min_prob) {
            min_prob = current_overload_prob;
            best_id = id;
        }
    }

    std::cout << "O roteador escolhido foi o " << best_id
              << ", com probabilidade de " << std::fixed
              << std::setprecision(5) << min_prob << std::endl;

    return 0;
}
