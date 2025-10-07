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
    std::vector<long long> col_sums(m, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int value;
            std::cin >> value;
            col_sums[j] += value;
        }
    }
    long long min_cost = *std::min_element(col_sums.begin(), col_sums.end());
    std::cout << min_cost << std::endl;
    return 0;
}
