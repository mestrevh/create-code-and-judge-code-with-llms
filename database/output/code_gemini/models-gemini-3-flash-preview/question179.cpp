/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    vector<string> grid(N);
    for (int i = 0; i < N; ++i) {
        cin >> grid[i];
    }

    vector<vector<bool>> hit(N, vector<bool>(M, false));
    int K;
    cin >> K;
    for (int i = 0; i < K; ++i) {
        int r, c;
        cin >> r >> c;
        hit[r - 1][c - 1] = true;
    }

    vector<vector<bool>> visited(N, vector<bool>(M, false));
    int destroyedCount = 0;

    int dr[] = {0, 0, 1, -1};
    int dc[] = {1, -1, 0, 0};

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (grid[i][j] == '#' && !visited[i][j]) {
                bool shipDestroyed = true;
                queue<pair<int, int>> q;
                
                q.push({i, j});
                visited[i][j] = true;

                while (!q.empty()) {
                    pair<int, int> curr = q.front();
                    q.pop();

                    if (!hit[curr.first][curr.second]) {
                        shipDestroyed = false;
                    }

                    for (int d = 0; d < 4; ++d) {
                        int ni = curr.first + dr[d];
                        int nj = curr.second + dc[d];

                        if (ni >= 0 && ni < N && nj >= 0 && nj < M && 
                            grid[ni][nj] == '#' && !visited[ni][nj]) {
                            visited[ni][nj] = true;
                            q.push({ni, nj});
                        }
                    }
                }

                if (shipDestroyed) {
                    destroyedCount++;
                }
            }
        }
    }

    cout << destroyedCount << endl;

    return 0;
}