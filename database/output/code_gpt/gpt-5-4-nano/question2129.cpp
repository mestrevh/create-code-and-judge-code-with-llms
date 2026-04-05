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

    int si = 0, sj = 0;
    int di = M - 1, dj = N - 1;

    if (M == 1 && N == 1) {
        cout << "Welcome to the Upside Down.";
        return 0;
    }

    vector<vector<int>> vis(M, vector<int>(N, 0));
    vector<pair<int,int>> path;
    vector<char> dirs;

    const int dr[4] = {1, 0, -1, 0};
    const int dc[4] = {0, 1, 0, -1};
    const char name[4] = {'S', 'L', 'N', 'O'};

    function<bool(int,int)> dfs = [&](int r, int c) -> bool {
        if (r == di && c == dj) return true;
        vis[r][c] = 1;

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k], nc = c + dc[k];
            if (nr < 0 || nr >= M || nc < 0 || nc >= N) continue;
            if (a[nr][nc] == 0) continue;
            if (vis[nr][nc]) continue;

            dirs.push_back(name[k]);
            if (dfs(nr, nc)) return true;
            dirs.pop_back();
        }
        return false;
    };

    if (!dfs(si, sj)) {
        cout << "Welcome to the Upside Down.";
        return 0;
    }

    vector<pair<char,int>> comp;
    for (char ch : dirs) {
        if (comp.empty() || comp.back().first != ch) comp.push_back({ch, 1});
        else comp.back().second++;
    }

    for (int i = 0; i < (int)comp.size(); i++) {
        if (i) cout << ", ";
        long long cnt = comp[i].second;
        cout << cnt << "*" << comp[i].first;
    }
    return 0;
}