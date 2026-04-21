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
    cout.setf(std::ios::fixed);
    cout << setprecision(2);

    while (cin >> n) {
        vector<vector<long double>> a(n, vector<long double>(n + 1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= n; j++) cin >> a[i][j];
        }

        for (int col = 0, row = 0; col < n && row < n; col++, row++) {
            int pivot = row;
            for (int i = row; i < n; i++) {
                if (fabsl(a[i][col]) > fabsl(a[pivot][col])) pivot = i;
            }
            if (pivot != row) swap(a[pivot], a[row]);

            long double div = a[row][col];
            for (int j = col; j <= n; j++) a[row][j] /= div;

            for (int i = 0; i < n; i++) {
                if (i == row) continue;
                long double factor = a[i][col];
                if (factor == 0) continue;
                for (int j = col; j <= n; j++) a[i][j] -= factor * a[row][j];
            }
        }

        vector<long double> ans(n);
        for (int i = 0; i < n; i++) ans[i] = a[i][n];

        cout << "Case #" << tc++ << ":";
        for (int i = 0; i < n; i++) {
            long double v = ans[i];
            if (fabsl(v) < 0.0005L) v = 0;
            cout << " " << (double)v;
        }
        cout << "\n";
    }

    return 0;
}