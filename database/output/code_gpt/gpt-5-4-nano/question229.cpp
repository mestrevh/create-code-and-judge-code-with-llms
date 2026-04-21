/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, V, G;
    if (!(cin >> N >> M >> V >> G)) return 0;

    vector<vector<int>> grid(N, vector<int>(M, 0));
    for (int i = 0; i < V; i++) {
        int Y, X;
        cin >> Y >> X;
        if (0 <= Y && Y < N && 0 <= X && X < M) grid[Y][X] = 1;
    }

    auto printGrid = [&](const vector<vector<int>>& a) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cout << " " << a[i][j];
            }
            cout << "\n";
        }
        cout << "\n";
    };

    printGrid(grid);

    vector<vector<int>> nextGrid(N, vector<int>(M, 0));
    int dx[8] = {-1,-1,-1,0,0,1,1,1};
    int dy[8] = {-1,0,1,-1,1,-1,0,1};

    for (int gen = 1; gen <= G; gen++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int cnt = 0;
                for (int k = 0; k < 8; k++) {
                    int ni = i + dx[k], nj = j + dy[k];
                    if (ni >= 0 && ni < N && nj >= 0 && nj < M) cnt += grid[ni][nj];
                }
                if (grid[i][j] == 1) {
                    nextGrid[i][j] = (cnt == 2 || cnt == 3) ? 1 : 0;
                } else {
                    nextGrid[i][j] = (cnt == 3) ? 1 : 0;
                }
            }
        }
        grid.swap(nextGrid);
        printGrid(grid);
    }

    return 0;
}