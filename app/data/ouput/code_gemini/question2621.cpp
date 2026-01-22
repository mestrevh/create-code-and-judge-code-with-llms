/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    std::vector<std::vector<int>> original_matrix(t, std::vector<int>(t));
    for (int i = 0; i < t; ++i) {
        for (int j = 0; j < t; ++j) {
            std::cin >> original_matrix[i][j];
        }
    }
    std::vector<std::vector<int>> result_matrix(t, std::vector<int>(t));
    for (int i = 0; i < t; ++i) {
        for (int j = 0; j < t; ++j) {
            int val = original_matrix[i][j];
            if (val < 0) {
                val *= 2;
            }
            result_matrix[j][i] = val;
        }
    }
    for (int i = 0; i < t; ++i) {
        for (int j = 0; j < t; ++j) {
            std::cout << result_matrix[i][j];
            if (j < t - 1) {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }
    return 0;
}
