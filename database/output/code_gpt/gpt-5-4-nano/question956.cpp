/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    bool first = true;
    int mn = 0, mx = 0;

    while (cin >> x) {
        if (x == 0) break;
        if (first) {
            mn = mx = x;
            first = false;
        } else {
            mn = min(mn, x);
            mx = max(mx, x);
        }
    }

    if (!first) cout << mn << ' ' << mx;
    return 0;
}