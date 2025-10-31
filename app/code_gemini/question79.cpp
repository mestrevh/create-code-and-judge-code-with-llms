/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int k;
    while (std::cin >> k && k != 0) {
        int matrix[4][4];
        for (int j = 0; j < 4; ++j) {
            for (int i = 0; i < 4; ++i) {
                std::cin >> matrix[i][j];
            }
        }

        for (int i = 0; i < 4; ++i) {
            matrix[i][i] *= k;
        }

        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << "\n";
        }
    }
    return 0;
}
