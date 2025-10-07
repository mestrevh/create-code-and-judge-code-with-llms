/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    for (int j = 0; j < m; ++j) {
        if (j % 2 == 0) {
            for (int i = 0; i < n; ++i) {
                if (matrix[i][j] == 1) {
                    std::cout << "Desliga o farol cidadao ( ._.)\n";
                } else {
                    std::cout << "Queria que todo mundo fosse assim\n";
                }
            }
        } else {
            for (int i = n - 1; i >= 0; --i) {
                if (matrix[i][j] == 1) {
                    std::cout << "Desliga o farol cidadao ( ._.)\n";
                } else {
                    std::cout << "Queria que todo mundo fosse assim\n";
                }
            }
        }
    }

    return 0;
}
