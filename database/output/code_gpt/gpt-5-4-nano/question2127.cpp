/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static const int N = 10;

bool dfs(const vector<vector<int>>& g, int r, int c, vector<vector<char>>& vis) {
    if (r < 0 || r >= N || c < 0 || c >= N) return false;
    if (g[r][c] == 0) return false;
    if (vis[r][c]) return false;
    vis[r][c] = 1;
    if (r == N - 1 && c == N - 1) return true;
    if (dfs(g, r + 1, c, vis)) return true;
    if (dfs(g, r - 1, c, vis)) return true;
    if (dfs(g, r, c + 1, vis)) return true;
    if (dfs(g, r, c - 1, vis)) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> g(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!(cin >> g[i][j])) return 0;
        }
    }

    vector<vector<char>> vis(N, vector<char>(N, 0));
    bool ok = dfs(g, 0, 0, vis);

    if (ok) cout << "RUN!";
    else cout << "Welcome to the Upside Down.";
    return 0;
}