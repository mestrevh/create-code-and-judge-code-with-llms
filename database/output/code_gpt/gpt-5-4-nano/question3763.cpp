/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    char dir;
    int n, m;
    if (!(cin >> dir >> n >> m)) return 0;

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> a[i][j];
    }

    if (dir == 'V') {
        int mid = m / 2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < mid; j++) {
                int left = a[i][j];
                int right = a[i][m - 1 - j];
                a[i][j] = left;
                a[i][m - 1 - j] = right;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = mid; j < m; j++) {
                a[i][j] = a[i][m - 1 - j + mid];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < mid; j++) {
                int tmp = a[i][j];
                a[i][j] = a[i][mid + (mid - 1 - j)];
                a[i][mid + (mid - 1 - j)] = tmp;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = mid; j < m; j++) {
                a[i][j] = a[i][m - 1 - j];
            }
        }
    } else if (dir == 'H') {
        int mid = n / 2;
        for (int i = 0; i < mid; i++) {
            for (int j = 0; j < m; j++) {
                int tmp = a[i][j];
                a[i][j] = a[n - 1 - i][j];
                a[n - 1 - i][j] = tmp;
            }
        }
    }

    if (dir == 'V') {
        int mid = m / 2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < mid; j++) {
                int tmp = a[i][j];
                a[i][j] = a[i][mid + (mid - 1 - j)];
                a[i][mid + (mid - 1 - j)] = tmp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j) cout << ' ';
            cout << setw(2) << setfill('0') << a[i][j];
        }
        if (i + 1 < n) cout << '\n';
    }

    return 0;
}