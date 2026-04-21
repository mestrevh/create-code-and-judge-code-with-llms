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

    vector<string> g(M);
    for (int i = 0; i < M; i++) cin >> g[i];

    vector<vector<unsigned char>> vis(M, vector<unsigned char>(N, 0));
    queue<pair<int,int>> q;

    for (int r = 0; r < M; r++) {
        for (int c = 0; c < N; c++) {
            if (g[r][c] == '.' && !vis[r][c]) {
                vis[r][c] = 1;
                q.push({r, c});
                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();
                    const int dx[4] = {-1, 1, 0, 0};
                    const int dy[4] = {0, 0, -1, 1};
                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k], ny = y + dy[k];
                        if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
                            if (!vis[nx][ny] && g[nx][ny] == '.') {
                                vis[nx][ny] = 1;
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }
    }

    long long ans = 0;
    for (int r = 0; r < M; r++) {
        for (int c = 0; c < N; c++) {
            if (g[r][c] == '#') {
                bool isCoast = false;
                if (r > 0 && g[r-1][c] == '.' && vis[r-1][c]) isCoast = true;
                else if (r+1 < M && g[r+1][c] == '.' && vis[r+1][c]) isCoast = true;
                else if (c > 0 && g[r][c-1] == '.' && vis[r][c-1]) isCoast = true;
                else if (c+1 < N && g[r][c+1] == '.' && vis[r][c+1]) isCoast = true;
                if (isCoast) ans++;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}