/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            std::cin >> matrix[i][j];
    
    double max_alpha = 0.0;
    
    for (int i = 0; i < n; ++i) {
        double sum = 0.0;
        for (int j = 0; j < n; ++j) {
            if (j != i) {
                sum += std::abs(matrix[i][j]);
            }
        }
        double alpha = sum / std::abs(matrix[i][i]);
        max_alpha = std::max(max_alpha, alpha);
    }
    
    std::cout << (max_alpha < 1.0 ? "SIM" : "NAO") << std::endl;
    return 0;
}
