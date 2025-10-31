/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int dfs(vector<vector<int>>& grid, int x, int y, int prev_dir, int complexity) {
    int m = grid.size(), n = grid[0].size();
    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0) return INT_MAX;
    if (x == m - 1 && y == n - 1) return complexity; 

    int temp = grid[x][y];
    grid[x][y] = 0; // Desmarcar

    int min_complexity = INT_MAX;
    if (prev_dir != -1) min_complexity = min(min_complexity, dfs(grid, x + 1, y, 0, complexity)); // Baixo
    if (prev_dir != 1) min_complexity = min(min_complexity, dfs(grid, x, y + 1, 1, complexity + (prev_dir != 1))); // Direita
    if (prev_dir != 0) min_complexity = min(min_complexity, dfs(grid, x - 1, y, 2, complexity + (prev_dir != 2))); // Cima
    if (prev_dir != 2) min_complexity = min(min_complexity, dfs(grid, x, y - 1, 3, complexity + (prev_dir != 3))); // Esquerda

    grid[x][y] = temp; // Restaurar
    return min_complexity;
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; ++i) 
        for (int j = 0; j < n; ++j)
            cin >> grid[i][j];

    int complexity = dfs(grid, 0, 0, -1, 0);
    if (complexity == INT_MAX)
        cout << "\"Welcome to the Upside Down.\"" << endl;
    else
        cout << "O caminho tem complexidade: " << complexity << endl;

    return 0;
}
