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
    if (!(cin >> n)) return 0;

    vector<vector<long double>> a(n, vector<long double>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> a[i][j];
    }

    vector<long double> alpha(n, 0.0L);
    for (int i = 0; i < n; i++) {
        long double diag = fabsl(a[i][i]);
        long double sum = 0.0L;
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            if (j < i) sum += fabsl(a[i][j]) * alpha[j];
            else sum += fabsl(a[i][j]);
        }
        if (diag == 0.0L) {
            alpha[i] = 0.0L;
        } else {
            alpha[i] = sum / diag;
        }
    }

    long double mx = 0.0L;
    for (int i = 0; i < n; i++) mx = max(mx, alpha[i]);

    cout << (mx < 1.0L ? "SIM" : "NAO") << "\n";
    cout.setf(std::ios::fixed);
    cout << setprecision(2);
    for (int i = 0; i < n; i++) {
        if (i) cout << ' ';
        cout << (double)alpha[i];
    }
    cout << "\n";
    return 0;
}