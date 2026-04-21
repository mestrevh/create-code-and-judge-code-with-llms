/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

bool canExitRec(int r, int c, const vector<vector<int>>& a, vector<vector<int>>& vis) {
    int n = 10;
    if (r == n - 1 && c == n - 1) return true;
    vis[r][c] = 1;

    const int dr[4] = {1, 0, -1, 0};
    const int dc[4] = {0, 1, 0, -1};

    for (int k = 0; k < 4; k++) {
        int nr = r + dr[k], nc = c + dc[k];
        if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
        if (a[nr][nc] != 1) continue;
        if (vis[nr][nc]) continue;
        if (canExitRec(nr, nc, a, vis)) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> a(10, vector<int>(10, 0));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (!(cin >> a[i][j])) return 0;
        }
    }

    vector<vector<int>> vis(10, vector<int>(10, 0));
    bool ok = false;
    if (a[0][0] == 1) ok = canExitRec(0, 0, a, vis);

    if (ok) cout << "RUN!";
    else cout << "Welcome to the Upside Down.";
    return 0;
}