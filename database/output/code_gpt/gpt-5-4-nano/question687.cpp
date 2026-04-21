/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<vector<long long>> c(N + 1);
    for (int n = 0; n <= N; n++) {
        c[n].assign(n + 1, 0);
        c[n][0] = 1;
        c[n][n] = 1;
        for (int k = 1; k < n; k++) {
            c[n][k] = c[n - 1][k - 1] + c[n - 1][k];
        }
    }

    for (int n = 0; n <= N; n++) {
        for (int k = 0; k <= n; k++) {
            if (k) cout << ' ';
            cout << c[n][k];
        }
        if (n < N) cout << '\n';
    }
    return 0;
}