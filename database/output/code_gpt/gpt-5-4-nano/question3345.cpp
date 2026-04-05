/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<long long> mn(n, (long long)4e18), mx(n, (long long)-4e18);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            long long x;
            cin >> x;
            mn[j] = min(mn[j], x);
            mx[j] = max(mx[j], x);
        }
    }

    vector<long long> cur(n);
    for (int j = 0; j < n; j++) cin >> cur[j];

    vector<long long> norm(n), invnorm(n);
    for (int j = 0; j < n; j++) {
        long long a = mx[j];
        long long b = mn[j];
        long long val = cur[j];
        long long out;
        if (a == b) {
            out = 0;
        } else {
            long long num = (val - b) * 1000LL;
            long long den = (a - b);
            if (den < 0) { den = -den; num = -num; }
            if (num <= 0) out = 0;
            else out = (num + den - 1) / den;
            if (out < 0) out = 0;
            if (out > 1000) out = 1000;
        }
        norm[j] = out;
        invnorm[j] = 1000 - norm[j];
    }

    long long pos = 0;
    long long den = 0;
    for (int j = 0; j < n; j++) {
        long long w = invnorm[j];
        den += w;
        pos += w * (j * 3000LL / (n - 1));
    }
    if (den == 0) pos = 1500;
    else pos = pos / den;

    for (int j = 0; j < n; j++) {
        if (j) cout << ' ';
        cout << mx[j];
    }
    cout << "\n";
    for (int j = 0; j < n; j++) {
        if (j) cout << ' ';
        cout << mn[j];
    }
    cout << "\n";
    for (int j = 0; j < n; j++) {
        if (j) cout << ' ';
        cout << norm[j] << (j + 1 == n ? "" : "");
    }
    cout << "\n";
    cout << pos << "\n";

    return 0;
}