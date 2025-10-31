/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>

int count_swaps(int n, const std::vector<int>& p) {
    if (n == 0) {
        return 0;
    }
    std::vector<bool> visited(n, false);
    int cycles = 0;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            cycles++;
            int current = i;
            while (!visited[current]) {
                visited[current] = true;
                current = p[current];
            }
        }
    }
    return n - cycles;
}

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

    int total_swaps = 0;

    std::vector<int> row_perm(L);
    for (int i = 0; i < L; ++i) {
        row_perm[i] = (grid[i][0] - 1) / C;
    }
    total_swaps += count_swaps(L, row_perm);

    std::vector<int> col_perm(C);
    for (int j = 0; j < C; ++j) {
        col_perm[j] = (grid[0][j] - 1) % C;
    }
    total_swaps += count_swaps(C, col_perm);

    std::cout << total_swaps << std::endl;

    return 0;
}
