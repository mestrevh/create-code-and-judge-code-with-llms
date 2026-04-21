/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int m, n;
    if (!(cin >> m >> n)) return 0;
    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) cin >> a[i][j];
    }

    vector<vector<int>> up(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!a[i][j]) continue;
            if (i == 0 || j == 0) up[i][j] = 1;
            else up[i][j] = min({up[i-1][j-1], up[i-1][j]}) + 1;
        }
    }

    vector<vector<int>> down(m, vector<int>(n, 0));
    for (int i = m - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            if (!a[i][j]) continue;
            if (i == m - 1 || j == 0) down[i][j] = 1;
            else down[i][j] = min({down[i+1][j-1], down[i+1][j]}) + 1;
        }
    }

    int ans = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!a[i][j]) continue;
            int h = up[i][j];
            for (int k = 2; k <= h; k++) {
                int left = j - (k - 1);
                int right = j + (k - 1);
                if (left < 0 || right >= n) break;
                int area = k * (k + 1) / 2;
                ans = max(ans, area);
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!a[i][j]) continue;
            int h = down[i][j];
            for (int k = 2; k <= h; k++) {
                int left = j - (k - 1);
                int right = j + (k - 1);
                int top = i - (k - 1);
                if (top < 0 || left < 0 || right >= n) break;
                int area = k * (k + 1) / 2;
                ans = max(ans, area);
            }
        }
    }

    cout << ans << "\n";
    return 0;
}