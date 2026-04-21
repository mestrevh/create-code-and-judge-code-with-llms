/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int tc = 1;
    while ( (cin >> n) ) {
        vector<string> g(n);
        for (int i = 0; i < n; i++) cin >> g[i];

        vector<vector<char>> vis(n, vector<char>(n, 0));
        int cnt = 0;

        int dr[8] = {-1,-1,-1,0,0,1,1,1};
        int dc[8] = {-1,0,1,-1,1,-1,0,1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][j] == '1' && !vis[i][j]) {
                    cnt++;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    vis[i][j] = 1;
                    while (!q.empty()) {
                        auto [r,c] = q.front();
                        q.pop();
                        for (int k = 0; k < 8; k++) {
                            int nr = r + dr[k], nc = c + dc[k];
                            if (nr >= 0 && nr < n && nc >= 0 && nc < n && !vis[nr][nc] && g[nr][nc] == '1') {
                                vis[nr][nc] = 1;
                                q.push({nr,nc});
                            }
                        }
                    }
                }
            }
        }

        cout << "Image number " << tc++ << " contains " << cnt << " war eagles.\n";
    }
    return 0;
}