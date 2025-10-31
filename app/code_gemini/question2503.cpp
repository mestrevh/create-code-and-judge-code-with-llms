/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>

int grid[10][10];
bool visited[10][10];

bool solve_maze(int r, int c) {
    if (r < 0 || r >= 10 || c < 0 || c >= 10) {
        return false;
    }
    if (grid[r][c] == 0 || visited[r][c]) {
        return false;
    }
    if (r == 9 && c == 9) {
        return true;
    }

    visited[r][c] = true;

    if (solve_maze(r + 1, c)) return true;
    if (solve_maze(r - 1, c)) return true;
    if (solve_maze(r, c + 1)) return true;
    if (solve_maze(r, c - 1)) return true;

    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> counts(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        if (x >= 0 && x <= n) {
            counts[x]++;
        }
    }

    bool consistent = false;
    for (int t = 0; t <= n; ++t) {
        if (counts[t] == t) {
            consistent = true;
            break;
        }
    }

    if (consistent) {
        std::cout << "Vamo nessa, temos que sair rapido...\n";

        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                std::cin >> grid[i][j];
                visited[i][j] = false;
            }
        }

        if (solve_maze(0, 0)) {
            std::cout << "Tudo nosso.\n";
        } else {
            std::cout << "Continuem cavando!\n";
        }
    } else {
        std::cout << "Ja nao se pode confiar nos refens como antigamente...\n";
    }

    return 0;
}
