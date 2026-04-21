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
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            cin >> a[i][j];

    vector<string> names = {"Sul", "Leste", "Norte", "Oeste"};
    vector<int> dr = {1, 0, -1, 0};
    vector<int> dc = {0, 1, 0, -1};

    int sr = 0, sc = 0;
    vector<vector<int>> vis(M, vector<int>(N, 0));
    vector<string> path;
    bool found = false;

    function<void(int,int)> dfs = [&](int r, int c) {
        if (found) return;
        if (r < 0 || r >= M || c < 0 || c >= N) return;
        if (a[r][c] == 0) return;

        if (r == M - 1 && c == N - 1) {
            found = true;
            return;
        }

        vis[r][c] = 1;
        for (int k = 0; k < 4 && !found; k++) {
            int nr = r + dr[k], nc = c + dc[k];
            if (nr < 0 || nr >= M || nc < 0 || nc >= N) continue;
            if (a[nr][nc] == 1 && !vis[nr][nc]) {
                path.push_back(names[k]);
                dfs(nr, nc);
                if (!found) path.pop_back();
            }
        }
        vis[r][c] = 0;
    };

    dfs(sr, sc);

    if (!found) {
        cout << "Welcome to the Upside Down.";
        return 0;
    }

    for (size_t i = 0; i < path.size(); i++) {
        if (i) cout << ", ";
        cout << path[i];
    }
    return 0;
}