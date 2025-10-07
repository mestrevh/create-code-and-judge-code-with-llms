/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }
    bool is_upper_triangular = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (matrix[i][j] != 0) {
                is_upper_triangular = false;
                break;
            }
        }
        if (!is_upper_triangular) {
            break;
        }
    }
    std::cout << std::boolalpha << is_upper_triangular << std::endl;
    return 0;
}
