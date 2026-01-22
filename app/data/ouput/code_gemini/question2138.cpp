/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N, M;
    std::cin >> N >> M;
    if (M == 0) {
        return 0;
    }
    int rows = N / M;
    if (rows == 0) {
        return 0;
    }
    std::vector<std::vector<int>> matrix(rows, std::vector<int>(M));
    int current_even = 2;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < M; ++j) {
            matrix[i][j] = current_even;
            current_even += 2;
        }
    }
    for (int j = 0; j < M; ++j) {
        for (int i = 0; i < rows; ++i) {
            std::cout << matrix[i][j];
            if (i < rows - 1) {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }
    return 0;
}
