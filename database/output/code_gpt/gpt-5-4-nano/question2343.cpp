/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

void exibeMultipos(long long i, long long f, long long x) {
    if (x == 0) return;
    if (i > f) swap(i, f);
    long long start = (i + x - 1) / x;
    long long val = start * x;
    while (val <= f) {
        cout << val;
        if (val + x <= f) cout << "\n";
        val += x;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long i, f, x;
    if (!(cin >> i >> f >> x)) return 0;
    exibeMultipos(i, f, x);
    return 0;
}