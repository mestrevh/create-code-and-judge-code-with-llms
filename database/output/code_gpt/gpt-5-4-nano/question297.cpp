/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static bool isLeap(int y) {
    if (y % 400 == 0) return true;
    if (y % 100 == 0) return false;
    return y % 4 == 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b;
    if (!(cin >> a >> b)) return 0;
    if (a > b) swap(a, b);

    bool any = false;
    for (long long y = a; y <= b; y++) {
        if (isLeap((int)y)) {
            cout << y << "\n";
            any = true;
        }
    }
    if (!any) cout << "-1\n";
    return 0;
}