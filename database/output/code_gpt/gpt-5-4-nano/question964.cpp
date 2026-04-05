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
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    long double maxAlpha = 0;
    for (int i = 0; i < n; i++) {
        long double diagAbs = fabsl(a[i][i]);
        long double sumAbsOffDiag = 0;
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            sumAbsOffDiag += fabsl(a[i][j]);
        }

        long double alpha;
        if (diagAbs == 0) alpha = numeric_limits<long double>::infinity();
        else alpha = sumAbsOffDiag / diagAbs;

        if (alpha > maxAlpha) maxAlpha = alpha;
    }

    const long double EPS = 1e-18L;
    if (maxAlpha < 1.0L - EPS) cout << "SIM\n";
    else cout << "NAO\n";
    return 0;
}