/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (!(std::cin >> n)) {
        return 0;
    }

    if (n <= 0) {
        std::cout << "SIM\n";
        return 0;
    }

    bool satisfied = true;
    for (int i = 0; i < n; ++i) {
        double diag_val = 0;
        double off_diag_sum = 0;
        for (int j = 0; j < n; ++j) {
            double val;
            std::cin >> val;
            if (i == j) {
                diag_val = std::abs(val);
            } else {
                off_diag_sum += std::abs(val);
            }
        }
        
        // Criterion: alpha_i = off_diag_sum / diag_val
        // Convergence is guaranteed if max(alpha_i) < 1.
        // This is equivalent to off_diag_sum < diag_val for all i.
        // If diag_val is 0, the criterion is not satisfied.
        if (diag_val == 0 || off_diag_sum >= diag_val) {
            satisfied = false;
        }
    }

    if (satisfied) {
        std::cout << "SIM\n";
    } else {
        std::cout << "NAO\n";
    }

    return 0;
}