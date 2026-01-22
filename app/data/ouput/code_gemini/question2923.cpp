/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int m, n;
    std::cin >> m >> n;

    std::vector<std::vector<int>> matrix(m, std::vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    int max_h = 0;
    std::vector<int> dp_prev(n, 0);

    for (int i = 0; i < m; ++i) {
        std::vector<int> R(n, 0);
        for (int j = n - 1; j >= 0; --j) {
            if (matrix[i][j] == 1) {
                R[j] = (j < n - 1 ? R[j + 1] : 0) + 1;
            }
        }

        std::vector<int> dp_curr(n, 0);
        int current_L = 0;
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 1) {
                current_L++;
                int rad = std::min(current_L, R[j]);
                dp_curr[j] = std::min(rad, dp_prev[j] + 1);
                max_h = std::max(max_h, dp_curr[j]);
            } else {
                current_L = 0;
            }
        }
        dp_prev = dp_curr;
    }

    if (max_h < 2) {
        std::cout << 0 << std::endl;
    } else {
        long long result = (long long)max_h * max_h;
        std::cout << result << std::endl;
    }

    return 0;
}
