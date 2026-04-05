/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long d, m;
    if (!(cin >> d)) return 0;
    cin >> m;

    while (true) {
        cout << "(antes) " << d << "\n";
        long long pay = min(d, m);
        d -= pay;
        cout << "(depois) " << d << "\n";
        if (d == 0) break;
    }

    return 0;
}