/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> row_sums(n, 0);
    std::vector<int> col_sums(m, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int value;
            std::cin >> value;
            row_sums[i] += value;
            col_sums[j] += value;
        }
    }

    int max_sum = 0;

    for (int i = 0; i < n; ++i) {
        if (row_sums[i] > max_sum) {
            max_sum = row_sums[i];
        }
    }

    for (int j = 0; j < m; ++j) {
        if (col_sums[j] > max_sum) {
            max_sum = col_sums[j];
        }
    }

    std::cout << max_sum << std::endl;

    return 0;
}
