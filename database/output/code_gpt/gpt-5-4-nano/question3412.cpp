/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b;
    if (!(cin >> a >> b)) return 0;

    long long x = llabs(a), y = llabs(b);
    while (y != 0) {
        long long r = x % y;
        x = y;
        y = r;
    }
    cout << "MDC=" << x << "\n";
    return 0;
}