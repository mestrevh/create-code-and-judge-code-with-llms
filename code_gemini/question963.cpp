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

    int n;
    std::cin >> n;

    std::vector<std::vector<double>> matrix(n, std::vector<double>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    int idx1, idx2;
    std::cin >> idx1 >> idx2;

    int min_idx = std::min(idx1, idx2) - 1;
    int max_idx = std::max(idx1, idx2) - 1;

    std::cout << std::fixed << std::setprecision(2);

    std::cout << matrix[min_idx][min_idx] << " " << matrix[min_idx][max_idx] << std::endl;
    std::cout << matrix[max_idx][min_idx] << " " << matrix[max_idx][max_idx] << std::endl;

    return 0;
}
