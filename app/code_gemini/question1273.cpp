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

    std::vector<std::vector<int>> matriz(n, std::vector<int>(n));
    int contador = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matriz[i][j] = contador++;
        }
    }

    std::cout << "Matriz:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << std::setw(3) << matriz[i][j];
        }
        std::cout << "\n";
    }

    std::cout << "\n";

    std::cout << "Diagonal Principal:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            std::cout << "   ";
        }
        std::cout << std::setw(3) << matriz[i][i] << "\n";
    }

    std::cout << "\n";

    std::cout << "Diagonal Secundaria:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            std::cout << "   ";
        }
        std::cout << std::setw(3) << matriz[i][n - 1 - i] << "\n";
    }

    return 0;
}
