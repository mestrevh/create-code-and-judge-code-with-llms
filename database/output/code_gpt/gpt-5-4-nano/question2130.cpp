/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N;
    if (!(cin >> M >> N)) return 0;

    vector<vector<int>> a(M, vector<int>(N));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) cin >> a[i][j];
    }

    const int INF = 1e9;
    vector<vector<int>> dist(M, vector<int>(N, INF));
    vector<vector<int>> bestDir(M, vector<int>(N, -1));

    deque<pair<int,int>> q;
    vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

    if (a[0][0] != 1) {
        cout << "Welcome to the Upside Down.";
        return 0;
    }

    dist[0][0] = 0;
    bestDir[0][0] = -1;
    q.push_back({0,0});

    auto inb = [&](int x, int y) {
        return x >= 0 && x < M && y >= 0 && y < N;
    };

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop_front();

        int curD = dist[x][y];
        int curDir = bestDir[x][y];

        for (int nd = 0; nd < 4; nd++) {
            int nx = x + (nd == 0 ? 1 : nd == 1 ? -1 : 0);
            int ny = y + (nd == 2 ? 1 : nd == 3 ? -1 : 0);
            if (!inb(nx, ny)) continue;
            if (a[nx][ny] != 1) continue;

            int add = 0;
            if (curDir != -1 && curDir != nd) add = 1;
            int ndist = curD + add;

            if (ndist < dist[nx][ny]) {
                dist[nx][ny] = ndist;
                bestDir[nx][ny] = nd;
                q.push_back({nx, ny});
            } else if (ndist == dist[nx][ny]) {
                if (bestDir[nx][ny] == -1 || curDir == -1 || bestDir[nx][ny] == nd) {
                    bestDir[nx][ny] = nd;
                } else {
                    int curBest = bestDir[nx][ny];
                    if (curBest != nd) {
                        if (curDir == -1) bestDir[nx][ny] = nd;
                    } else {
                        bestDir[nx][ny] = nd;
                    }
                }
            }
        }
    }

    int ans = INF;
    for (int i = 0; i < M; i++) {
        if (a[i][N-1] == 1) ans = min(ans, dist[i][N-1]);
    }
    for (int j = 0; j < N; j++) {
        if (a[M-1][j] == 1) ans = min(ans, dist[M-1][j]);
    }
    if (a[M-1][N-1] == 1) ans = min(ans, dist[M-1][N-1]);

    if (ans == INF) {
        cout << "Welcome to the Upside Down.";
    } else {
        cout << "O caminho tem complexidade: " << ans;
    }

    return 0;
}