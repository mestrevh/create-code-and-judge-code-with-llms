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
    if (!(cin >> M)) return 0;
    cin >> N;

    vector<string> grid(M);
    for (int i = 0; i < M; i++) {
        cin >> grid[i];
    }

    int sr = -1, sc = -1;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 'E') {
                sr = i; sc = j;
            }
        }
    }

    vector<vector<int>> vis(M, vector<int>(N, 0));

    auto isBlocked = [&](int r, int c) {
        char ch = grid[r][c];
        return ch == '#';
    };

    function<bool(int,int)> dfs = [&](int r, int c) -> bool {
        if (grid[r][c] == 'S') return true;
        vis[r][c] = 1;
        const int dr[4] = {-1, 0, 1, 0};
        const int dc[4] = {0, 1, 0, -1};
        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k], nc = c + dc[k];
            if (nr < 0 || nr >= M || nc < 0 || nc >= N) continue;
            if (vis[nr][nc]) continue;
            if (isBlocked(nr, nc)) continue;
            if (dfs(nr, nc)) return true;
        }
        return false;
    };

    bool ok = dfs(sr, sc);

    if (ok) {
        cout << "Esse Yordle é confiável, vamos por esse atalho.";
    } else {
        cout << "Não tem saída, deve ser a LeBlanc tentando me enganar, melhor dar o fora daqui.";
    }
    return 0;
}