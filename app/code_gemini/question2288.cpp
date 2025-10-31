/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int m, n;
    std::cin >> m >> n;

    std::vector<std::vector<int>> matrix(m, std::vector<int>(m));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    bool bomb_found = false;
    for (int k = 0; k < n; ++k) {
        int x, y;
        std::cin >> x >> y;

        if (matrix[x][y] == -1) {
            std::cout << "Essa casa ja foi selecionada.\n";
            continue;
        }

        long long sum_right = 0;
        for (int j = y; j < m; ++j) {
            if (matrix[x][j] != -1) {
                sum_right += matrix[x][j];
            }
        }

        long long sum_down = 0;
        for (int i = x; i < m; ++i) {
            if (matrix[i][y] != -1) {
                sum_down += matrix[i][y];
            }
        }

        long long sum_diag = 0;
        for (int i = x, j = y; i < m && j < m; ++i, ++j) {
            if (matrix[i][j] != -1) {
                sum_diag += matrix[i][j];
            }
        }

        if (sum_right == sum_down && sum_down == sum_diag) {
            std::cout << "Bomba encontrada.\n";
            std::cout << "Voce perdeu.\n";
            bomb_found = true;
            break;
        } else {
            std::cout << "Boa jogada, a casa (" << x << "," << y << ") nao tinha bomba.\n";
            matrix[x][y] = -1;
        }
    }

    if (!bomb_found) {
        std::cout << "Voce e uma pessoa de sorte.\n";
    }

    return 0;
}
