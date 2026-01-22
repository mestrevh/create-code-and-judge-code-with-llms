/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m, x;
    std::cin >> n >> m >> x;

    std::vector<std::vector<std::string>> original_matrix(n, std::vector<std::string>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> original_matrix[i][j];
        }
    }

    int rotations = x % 4;
    std::vector<std::vector<std::string>> final_matrix;

    if (rotations == 0) {
        final_matrix = original_matrix;
    } else if (rotations == 1) {
        final_matrix.assign(m, std::vector<std::string>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                final_matrix[j][n - 1 - i] = original_matrix[i][j];
            }
        }
    } else if (rotations == 2) {
        final_matrix.assign(n, std::vector<std::string>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                final_matrix[n - 1 - i][m - 1 - j] = original_matrix[i][j];
            }
        }
    } else {
        final_matrix.assign(m, std::vector<std::string>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                final_matrix[m - 1 - j][i] = original_matrix[i][j];
            }
        }
    }

    int target_row = x % n;

    int cols_in_final_matrix = 0;
    if (!final_matrix.empty()) {
        cols_in_final_matrix = final_matrix[0].size();
    }

    for (int j = 0; j < m; ++j) {
        if (target_row < final_matrix.size() && j < cols_in_final_matrix) {
            std::cout << final_matrix[target_row][j];
        } else {
            std::cout << "Qualquer";
        }
        if (j < m - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
