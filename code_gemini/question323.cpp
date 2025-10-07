/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    while (std::cin >> n && n != 0) {
        std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int val = std::min({i, j, n - 1 - i, n - 1 - j}) + 1;
                matrix[i][j] = val;
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                std::cout << std::setw(3) << matrix[i][j];
                if (j < n - 1) {
                    std::cout << " ";
                }
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    return 0;
}
