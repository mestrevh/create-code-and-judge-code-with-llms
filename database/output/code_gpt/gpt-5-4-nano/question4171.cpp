/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    if (!(cin >> k)) return 0;

    vector<vector<long long>> a(k + 1, vector<long long>(k + 1, 0));
    for (int n = 1; n <= k; n++) {
        a[n][1] = 1;
        a[n][n] = 1;
        for (int i = 2; i <= n - 1; i++) {
            a[n][i] = a[n - 1][i - 1] + a[n - 1][i];
        }
    }

    for (int n = 1; n <= k; n++) {
        for (int i = 1; i <= n; i++) {
            if (i > 1) cout << ' ';
            cout << a[n][i];
        }
        if (n < k) cout << '\n';
    }
    return 0;
}