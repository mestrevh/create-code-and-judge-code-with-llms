/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, startX, startY;
vector<vector<int>> grid;
vector<vector<int>> dp;

int dfs(int x, int y) {
    if (dp[x][y] != -1) return dp[x][y];

    int maxSteps = 0;
    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    for (auto& d : directions) {
        int newX = x + d.first, newY = y + d.second;
        if (newX >= 0 && newX < N && newY >= 0 && newY < N && grid[newX][newY] == grid[x][y] + 1) {
            maxSteps = max(maxSteps, dfs(newX, newY));
        }
    }
    
    return dp[x][y] = maxSteps + 1;
}

int main() {
    cin >> N >> startX >> startY;
    grid.resize(N, vector<int>(N));
    dp.resize(N, vector<int>(N, -1));

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> grid[i][j];

    int maxPath = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (grid[i][j] == grid[startX][startY])
                maxPath = max(maxPath, dfs(i, j));

    cout << "Numero de passos do maior caminho: " << maxPath - 1 << endl;
    return 0;
}
