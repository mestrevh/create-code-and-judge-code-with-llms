/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (!(cin >> a[i][j])) return 0;
        }
    }

    long long sum = 0;
    long long mx = a[0][0];
    long long diag = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sum += a[i][j];
            mx = max(mx, a[i][j]);
        }
        diag += a[i][i];
    }

    double media = sum / 9.0;
    int delta = (mx > 0) ? 1 : (mx < 0 ? -1 : 0);

    cout.setf(std::ios::fixed);
    cout << setprecision(2) << media << ' ' << mx << ' ' << delta << ' ' << diag;
    return 0;
}