/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    int k;
    std::cin >> k;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    std::vector<int> row_map(n);
    std::iota(row_map.begin(), row_map.end(), 0);

    std::vector<int> col_map(m);
    std::iota(col_map.begin(), col_map.end(), 0);

    for (int i = 0; i < k; ++i) {
        std::string command;
        int a, b;
        std::cin >> command >> a >> b;
        if (command == "ataque") {
            std::swap(row_map[a], row_map[b]);
        } else {
            std::swap(col_map[a], col_map[b]);
        }
    }

    int final_i, final_j;
    std::cin >> final_i >> final_j;

    int original_row = row_map[final_i];
    int original_col = col_map[final_j];

    std::cout << matrix[original_row][original_col] << std::endl;

    return 0;
}
