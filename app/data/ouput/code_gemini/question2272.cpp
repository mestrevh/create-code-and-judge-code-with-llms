/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int L, C;
    std::cin >> L >> C;

    std::vector<std::vector<int>> grid(L, std::vector<int>(C));
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < C; ++j) {
            std::cin >> grid[i][j];
        }
    }

    int D;
    std::cin >> D;

    if (L % 2 == 0) {
        for (int i = 0; i < L; ++i) {
            for (int j = 0; j < C; ++j) {
                if (D > 0 && grid[i][j] == 1) {
                    grid[i][j] = 0;
                    D--;
                }
            }
        }
    } else {
        for (int j = 0; j < C; ++j) {
            for (int i = 0; i < L; ++i) {
                if (D > 0 && grid[i][j] == 1) {
                    grid[i][j] = 0;
                    D--;
                }
            }
        }
    }

    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < C; ++j) {
            std::cout << grid[i][j] << (j == C - 1 ? "" : " ");
        }
        std::cout << "\n";
    }

    int remaining_live_cells = 0;
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < C; ++j) {
            if (grid[i][j] == 1) {
                remaining_live_cells++;
            }
        }
    }

    std::cout << D << " " << remaining_live_cells << "\n";

    return 0;
}
