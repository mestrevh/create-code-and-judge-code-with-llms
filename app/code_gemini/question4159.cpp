/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cstdio>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;

    if (scanf("%dx%d", &n, &m) != 2) {
        return 1;
    }

    if (m % 2 == 0) {
        std::cout << "Nao posso construir nessas proporcoes" << std::endl;
        return 0;
    }

    int center_col = m / 2 + 1;

    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= m; ++j) {
            char to_print;
            if (i <= 2) {
                to_print = (j == center_col) ? 'H' : '=';
            } else {
                if (i % 2 != 0) {
                    to_print = (j % 2 != 0) ? '=' : 'o';
                } else {
                    to_print = '=';
                }
            }
            std::cout << to_print << (j == m ? "" : " ");
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < (2 * m - 1); ++i) {
        std::cout << "-";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    int totalCost = 0;

    if (n >= 2) {
        totalCost += 500;
    }

    totalCost += (2 * m - 1) * 133;

    for (int i = 1; i <= n; ++i) {
        if (i <= 2) {
            totalCost += (m - 1) * 85;
        } else {
            if (i % 2 != 0) {
                int num_windows = m / 2;
                int num_walls = m / 2 + 1;
                totalCost += num_windows * 250;
                totalCost += num_walls * 85;
            } else {
                totalCost += m * 85;
            }
        }
    }

    std::cout << "E o valor total eh " << totalCost << std::endl;

    return 0;
}
