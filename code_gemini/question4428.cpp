/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, exit_i, exit_j;
vector<vector<int>> grid;
vector<vector<int>> dp;

int solve(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= n) {
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    int max_steps = 0;
    int current_val = grid[i][j];

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    for (int k = 0; k < 4; ++k) {
        int next_i = i + dx[k];
        int next_j = j + dy[k];

        if (next_i >= 0 && next_i < n && next_j >= 0 && next_j < n && grid[next_i][next_j] == current_val + 1) {
            max_steps = max(max_steps, 1 + solve(next_i, next_j));
        }
    }
    
    if (i == exit_i && j == exit_j && max_steps == 0)
        return dp[i][j] = 1;


    return dp[i][j] = max_steps;
}

int main() {
    cin >> n >> exit_i >> exit_j;
    grid.resize(n, vector<int>(n));
    dp.resize(n, vector<int>(n, -1));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    int max_path = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
             max_path = max(max_path, solve(i, j));
        }
    }

    printf("Numero de passos do maior caminho: %d\n", max_path);

    return 0;
}
