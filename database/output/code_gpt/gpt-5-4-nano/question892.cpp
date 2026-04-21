/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int H, C;
    if (!(cin >> H >> C)) return 0;
    vector<string> g(H);
    for (int i = 0; i < H; i++) cin >> g[i];

    vector<vector<int>> vis(H, vector<int>(C, 0));
    int enemies = 0;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < C; j++) {
            if (g[i][j] == '*') enemies++;
        }
    }

    queue<pair<int,int>> q;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < C; j++) {
            if (g[i][j] == '&') {
                vis[i][j] = 1;
                q.push({i, j});
            }
        }
    }

    int killed = 0;
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k], nc = c + dc[k];
            if (nr < 0 || nr >= H || nc < 0 || nc >= C) continue;
            if (g[nr][nc] == '*') killed++;
        }
    }

    cout << (killed == enemies ? "S" : "N");
    return 0;
}