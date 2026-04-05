/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    if (!(cin >> n)) return 0;

    for (long long i = 0; i < n; i++) {
        cout << 2 * i + 1;
        if (i + 1 < n) cout << (n == 0 ? '\n' : '\n');
    }
    return 0;
}