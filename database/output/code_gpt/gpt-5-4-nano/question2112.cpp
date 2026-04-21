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
    vector<vector<double>> a(n, vector<double>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    double mx = 0.0;
    const double EPS = 1e-12;

    for (int j = 0; j < n; j++) {
        double sum = 0.0;
        for (int i = 0; i < n; i++) {
            if (i == j) continue;
            sum += fabs(a[i][j]);
        }
        double diag = fabs(a[j][j]);
        double alpha;
        if (diag == 0.0) alpha = numeric_limits<double>::infinity();
        else alpha = sum / diag;
        if (alpha > mx) mx = alpha;
    }

    if (mx + EPS < 1.0) cout << "SIM\n";
    else cout << "NAO\n";

    return 0;
}