/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> a;
int best = INT_MAX;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void dfs(int r, int c, int dir, int turns, vector<vector<char>>& vis) {
    if (turns >= best) return;
    if (r == N - 1 && c == M - 1) {
        best = min(best, turns);
        return;
    }
    for (int k = 0; k < 4; k++) {
        int nr = r + dr[k];
        int nc = c + dc[k];
        if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
        if (a[nr][nc] == 0) continue;
        if (vis[nr][nc]) continue;
        int nt = turns;
        if (dir == -1) nt = turns;
        else if (k != dir) nt = turns + 1;
        vis[nr][nc] = 1;
        dfs(nr, nc, k, nt, vis);
        vis[nr][nc] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> N >> M)) return 0;
    a.assign(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) cin >> a[i][j];
    }

    if (a[0][0] == 0 || a[N-1][M-1] == 0) {
        cout << "Continuem cavando!" << "\n";
        return 0;
    }

    vector<vector<char>> vis(N, vector<char>(M, 0));
    vis[0][0] = 1;
    dfs(0, 0, -1, 0, vis);

    if (best == INT_MAX) cout << "Continuem cavando!" << "\n";
    else cout << "O caminho tem complexidade: " << best << "\n";
    return 0;
}