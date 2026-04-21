/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x;
    bool first = true;
    bool ok = true;
    long long prev = 0;

    while (cin >> x) {
        if (x == 0) break;
        if (first) {
            prev = x;
            first = false;
        } else {
            if (x <= prev) ok = false;
            prev = x;
        }
    }

    cout << (ok ? "EM ORDEM" : "FORA DE ORDEM");
    return 0;
}