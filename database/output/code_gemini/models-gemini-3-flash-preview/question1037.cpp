/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

double mat[1005][1005];
double* r[1005];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    int caseNum = 1;
    while (std::cin >> n) {
        for (int i = 0; i < n; ++i) {
            r[i] = mat[i];
            for (int j = 0; j <= n; ++j) {
                std::cin >> r[i][j];
            }
        }

        for (int i = 0; i < n; ++i) {
            int pivot = i;
            double max_val = std::abs(r[i][i]);
            for (int j = i + 1; j < n; ++j) {
                double current_val = std::abs(r[j][i]);
                if (current_val > max_val) {
                    max_val = current_val;
                    pivot = j;
                }
            }
            std::swap(r[i], r[pivot]);

            double diag = r[i][i];
            for (int j = i + 1; j < n; ++j) {
                if (r[j][i] == 0.0) continue;
                double factor = r[j][i] / diag;
                double* rj = r[j];
                double* ri = r[i];
                for (int k = i + 1; k <= n; ++k) {
                    rj[k] -= factor * ri[k];
                }
            }
        }

        std::vector<double> res(n);
        for (int i = n - 1; i >= 0; --i) {
            double val = r[i][n];
            for (int j = i + 1; j < n; ++j) {
                val -= r[i][j] * res[j];
            }
            res[i] = val / r[i][i];
        }

        std::cout << "Case #" << caseNum++ << ":";
        for (int i = 0; i < n; ++i) {
            if (std::abs(res[i]) < 1e-9) res[i] = 0.0;
            std::cout << " " << std::fixed << std::setprecision(2) << res[i];
        }
        std::cout << "\n";
    }

    return 0;
}