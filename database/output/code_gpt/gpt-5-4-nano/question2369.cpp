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
    if (!(cin >> n >> m)) return 0;

    vector<vector<long long>> a(n, vector<long long>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];

    vector<pair<int,int>> ans;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            long long v = a[i][j];
            bool cav = true;
            for (int di = -1; di <= 1 && cav; ++di) {
                for (int dj = -1; dj <= 1 && cav; ++dj) {
                    if (di == 0 && dj == 0) continue;
                    int ni = i + di, nj = j + dj;
                    if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                    if (!(v < a[ni][nj])) cav = false;
                }
            }
            if (cav) ans.push_back({i, j});
        }
    }

    cout << "[";
    for (size_t k = 0; k < ans.size(); ++k) {
        if (k) cout << ", ";
        cout << "(" << ans[k].first << ", " << ans[k].second << ")";
    }
    cout << "]";
    return 0;
}