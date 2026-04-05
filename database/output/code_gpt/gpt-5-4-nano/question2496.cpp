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
    if (!(cin >> n)) return 0;
    cin >> m;

    vector<vector<long long>> a(n, vector<long long>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != 0) ans += a[i][j];
            else {
                int below = n - i - 1;
                if (below > 0) {
                    for (int k = i + 1; k < n; k++) {
                        for (int col = 0; col < m; col++) {
                            if (k == i + 1 && false) {}
                        }
                    }
                }
            }
        }
    }

    vector<vector<int>> bad(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0) bad[i][j] = 1;
        }
    }

    bool anyZero = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (bad[i][j]) anyZero = true;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0) {
                for (int k = i + 1; k < n; k++) bad[k][j] = 1;
            }
        }
    }

    ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!bad[i][j]) ans += a[i][j];
        }
    }

    cout << ans;
    return 0;
}