/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, V, G;
    if (!(cin >> N >> M >> V >> G)) return 0;

    vector<vector<int>> grid(N, vector<int>(M, 0));
    for (int i = 0; i < V; ++i) {
        int y, x;
        if (cin >> y >> x) {
            if (y >= 0 && y < N && x >= 0 && x < M) {
                grid[y][x] = 1;
            }
        }
    }

    auto printGrid = [&]() {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                cout << " " << grid[i][j];
            }
            cout << "\n";
        }
        cout << "\n";
    };

    printGrid();

    for (int g = 1; g <= G; ++g) {
        vector<vector<int>> next_grid(N, vector<int>(M, 0));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                int neighbors = 0;
                for (int di = -1; di <= 1; ++di) {
                    for (int dj = -1; dj <= 1; ++dj) {
                        if (di == 0 && dj == 0) continue;
                        int ni = i + di;
                        int nj = j + dj;
                        if (ni >= 0 && ni < N && nj >= 0 && nj < M) {
                            if (grid[ni][nj]) neighbors++;
                        }
                    }
                }

                if (grid[i][j] == 1) {
                    if (neighbors == 2 || neighbors == 3)
                        next_grid[i][j] = 1;
                    else
                        next_grid[i][j] = 0;
                } else {
                    if (neighbors == 3)
                        next_grid[i][j] = 1;
                    else
                        next_grid[i][j] = 0;
                }
            }
        }
        grid = next_grid;
        printGrid();
    }

    return 0;
}