/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

long long fact(int n) {
    if (n <= 1) return 1;
    return 1LL * n * fact(n - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b, c;
    if (!(cin >> a >> b >> c)) return 0;

    cout << fact((int)a) + fact((int)b) + fact((int)c);
    return 0;
}