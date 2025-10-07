/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<char>> grid;
vector<vector<bool>> visited;
int maxCoins = 0;
bool canReachEnd = false;

void backtrack(int x, int y, int coins) {
    if (x < 0 || x >= N || y < 0 || y >= M || visited[x][y] || grid[x][y] == '|') return;
    
    if (grid[x][y] == 'o') coins++;
    if (grid[x][y] == '8') coins += 2;

    if (x == N - 1 && y == M - 1) {
        canReachEnd = true;
        maxCoins = max(maxCoins, coins);
        return;
    }

    visited[x][y] = true;

    backtrack(x + 1, y, coins);
    backtrack(x, y + 1, coins);

    visited[x][y] = false;
}

int main() {
    cin >> N >> M;
    grid.resize(N, vector<char>(M));
    visited.resize(N, vector<bool>(M, false));

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> grid[i][j];

    backtrack(0, 0, 0);

    cout << (canReachEnd ? "SIM" : "NAO") << endl;
    cout << "Valor maximo de moedas: " << maxCoins << endl;

    return 0;
}
