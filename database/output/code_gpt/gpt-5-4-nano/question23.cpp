/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n, m;
    if (!(cin >> n >> m)) return 0;

    long long start = ((n + 4) / 5) * 5;
    if (start < n) start += 5;

    bool first = true;
    for (long long x = start; x <= m; x += 5) {
        if (!first) cout << '|';
        cout << x;
        first = false;
    }
    return 0;
}