/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long X;
    if (!(cin >> X)) return 0;

    long long Z;
    while (cin >> Z) {
        if (Z > X) break;
    }

    long long diff = Z - X;
    long long a = 1 + diff / 2;
    long long b = 1 + diff;
    long long ans = min(a, b);

    cout << ans << "\n";
    return 0;
}