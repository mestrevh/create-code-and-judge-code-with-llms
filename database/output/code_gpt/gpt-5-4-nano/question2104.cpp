/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int L;
    if (!(cin >> L)) return 0;
    vector<vector<long long>> a(L, vector<long long>(L));
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < L; j++) cin >> a[i][j];
    }

    long long target = 0;
    for (int j = 0; j < L; j++) target += a[0][j];

    bool ok = true;

    for (int i = 0; i < L && ok; i++) {
        long long sum = 0;
        for (int j = 0; j < L; j++) sum += a[i][j];
        if (sum != target) ok = false;
    }

    for (int j = 0; j < L && ok; j++) {
        long long sum = 0;
        for (int i = 0; i < L; i++) sum += a[i][j];
        if (sum != target) ok = false;
    }

    if (ok) {
        long long diag1 = 0, diag2 = 0;
        for (int i = 0; i < L; i++) {
            diag1 += a[i][i];
            diag2 += a[i][L - 1 - i];
        }
        if (diag1 != target || diag2 != target) ok = false;
    }

    cout << (ok ? "A matriz e magica" : "A matriz nao e magica");
    return 0;
}