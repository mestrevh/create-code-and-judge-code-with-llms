/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x, y;
    if (!(cin >> x >> y)) return 0;

    long long a = min(x, y), b = max(x, y);
    for (long long v = a; v <= b; v++) {
        long long r = v % 5;
        if (r < 0) r += 5;
        if (r == 2 || r == 3) cout << v << "\n";
    }
    return 0;
}