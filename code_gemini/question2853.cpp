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

    std::cout << "Digite as dimensoes da matriz:" << std::endl;
    int L, C;
    std::cin >> L >> C;

    std::vector<std::vector<int>> matrix(L, std::vector<int>(C));

    std::cout << "Digite os elementos da matriz:" << std::endl;
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < C; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    std::cout << "Matriz transposta:" << std::endl;

    for (int j = 0; j < C; ++j) {
        for (int i = 0; i < L; ++i) {
            std::cout << std::left << std::setw(6) << matrix[i][j];
        }
        std::cout << std::endl;
    }

    return 0;
}
