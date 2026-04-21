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

    vector<long double> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    cout << fixed << setprecision(2);
    for (int i = 0; i < n; i++) {
        long double xi = x[i];
        for (int j = 0; j < n; j++) {
            long double val;
            if (j == 0) val = 1.0L;
            else val = powl(xi, j);
            if (j) cout << ' ';
            cout << (double)val;
        }
        if (i + 1 < n) cout << '\n';
    }
    return 0;
}