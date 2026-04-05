/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, k, c;
    if (!(cin >> n >> k >> c)) return 0;

    for (long long x = c; x <= n; x += k) {
        cout << x << "\n";
    }
    return 0;
}