/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    int linhas, colunas;
    std::cout << "Digite as dimensoes da matriz:" << std::endl;
    std::cin >> linhas >> colunas;

    std::vector<std::vector<int>> matriz(linhas, std::vector<int>(colunas));
    std::cout << "Digite os elementos da matriz:" << std::endl;
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            std::cin >> matriz[i][j];
        }
    }

    std::cout << "Matriz transposta:" << std::endl;
    for (int j = 0; j < colunas; ++j) {
        for (int i = 0; i < linhas; ++i) {
            std::cout << std::left << std::setw(6) << matriz[i][j];
        }
        std::cout << std::endl;
    }

    return 0;
}
