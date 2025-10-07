/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int matrix[3][3];
    int sum = 0, max_value = INT_MIN, diagonal_sum = 0;

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j) {
            std::cin >> matrix[i][j];
            sum += matrix[i][j];
            if (matrix[i][j] > max_value) max_value = matrix[i][j];
            if (i == j) diagonal_sum += matrix[i][j];
        }

    float average = sum / 9.0;
    int delta = (max_value > 0) ? 1 : (max_value < 0) ? -1 : 0;

    std::cout << std::fixed << std::setprecision(2) << average << " " 
              << max_value << " " << delta << " " << diagonal_sum << std::endl;

    return 0;
}
