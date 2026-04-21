/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    int field = 1;
    const int dr[8] = {-1,-1,-1,0,0,1,1,1};
    const int dc[8] = {-1,0,1,-1,1,-1,0,1};

    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        vector<string> grid(n);
        for (int i = 0; i < n; i++) cin >> grid[i];

        vector<string> ans = grid;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (grid[r][c] == '*') continue;
                int cnt = 0;
                for (int k = 0; k < 8; k++) {
                    int nr = r + dr[k], nc = c + dc[k];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '*') cnt++;
                }
                ans[r][c] = char('0' + cnt);
            }
        }

        if (field == 1) {
            cout << "Field #" << field << ":\n";
        } else {
            cout << "\nField #" << field << ":\n";
        }
        for (int i = 0; i < n; i++) cout << ans[i] << "\n";
        field++;
    }
    return 0;
}