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
    while (cin >> N >> M) {
        if (N == 0 && M == 0) break;

        int K = (N * M) / 2;
        vector<int> a(K + 1);
        for (int i = 1; i <= K; i++) cin >> a[i];

        vector<int> id(N, vector<int>(M, -1));
        vector<pair<int,int>> pos(K + 1);
        int idx = 1;
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < M; c++) {
                if ( (r + c) % 2 == 0 ) {
                    id[r][c] = idx;
                    pos[idx] = {r, c};
                    idx++;
                }
            }
        }

        vector<vector<int>> dirs = {
            {-1,-1}, {-1, 1},
            { 1,-1}, { 1, 1}
        };

        int best = 0;
        for (int s = 1; s <= K; s++) {
            if (a[s] != 1) continue;
            auto [sr, sc] = pos[s];

            vector<int> visited(K + 1, 0);
            function<int(int,int,int,int)> dfs = [&](int r, int c, int curPiece, int capturedCount) -> int {
                int localBest = capturedCount;
                for (auto &d : dirs) {
                    int mr = r + d[0], mc = c + d[1];
                    int nr = r + 2*d[0], nc = c + 2*d[1];
                    if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
                    int midId = (mr>=0 && mr<N && mc>=0 && mc<M) ? id[mr][mc] : -1;
                    int nid = id[nr][nc];
                    if (midId == -1 || nid == -1) continue;
                    if (a[midId] != 2) continue;
                    if (visited[midId]) continue;
                    if (a[nid] != 0) continue;

                    visited[midId] = 1;
                    int after = dfs(nr, nc, curPiece, capturedCount + 1);
                    localBest = max(localBest, after);
                    visited[midId] = 0;
                }
                return localBest;
            };

            int res = dfs(sr, sc, s, 0);
            best = max(best, res);
        }

        cout << best << "\n";
    }
    return 0;
}