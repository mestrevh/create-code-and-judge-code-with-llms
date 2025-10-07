/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int matrix[3][3];
    double total_sum = 0.0;
    int max_val = -2147483648;
    int diag_sum = 0;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cin >> matrix[i][j];
            total_sum += matrix[i][j];
            if (matrix[i][j] > max_val) {
                max_val = matrix[i][j];
            }
            if (i == j) {
                diag_sum += matrix[i][j];
            }
        }
    }

    double average = total_sum / 9.0;
    
    int delta;
    if (max_val > 0) {
        delta = 1;
    } else if (max_val < 0) {
        delta = -1;
    } else {
        delta = 0;
    }

    std::cout << std::fixed << std::setprecision(2) << average << " ";
    std::cout << max_val << " " << delta << " " << diag_sum << std::endl;

    return 0;
}
