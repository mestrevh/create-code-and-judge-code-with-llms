/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    vector<string> grid(N);
    for (int i = 0; i < N; i++) cin >> grid[i];

    vector<vector<int>> compId(N, vector<int>(M, -1));
    int cid = 0;
    vector<int> shipsCount;

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == '#' && compId[i][j] == -1) {
                queue<pair<int,int>> q;
                q.push({i,j});
                compId[i][j] = cid;
                int cnt = 0;

                while (!q.empty()) {
                    auto [r,c] = q.front(); q.pop();
                    cnt++;
                    for (int k = 0; k < 4; k++) {
                        int nr = r + dr[k], nc = c + dc[k];
                        if (nr >= 0 && nr < N && nc >= 0 && nc < M) {
                            if (grid[nr][nc] == '#' && compId[nr][nc] == -1) {
                                compId[nr][nc] = cid;
                                q.push({nr,nc});
                            }
                        }
                    }
                }

                shipsCount.push_back(cnt);
                cid++;
            }
        }
    }

    int K;
    cin >> K;

    vector<int> hitCount(cid, 0);
    for (int t = 0; t < K; t++) {
        int L, C;
        cin >> L >> C;
        int r = L - 1, c = C - 1;
        int id = compId[r][c];
        if (id != -1) hitCount[id]++;
    }

    int destroyed = 0;
    for (int i = 0; i < cid; i++) {
        if (hitCount[i] == shipsCount[i]) destroyed++;
    }

    cout << destroyed << "\n";
    return 0;
}