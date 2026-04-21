/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; (long long)i * i <= n; i += 2)
        if (n % i == 0) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;
    if (!(cin >> a >> b >> c)) return 0;

    int cnt = (isPrime(a) ? 1 : 0) + (isPrime(b) ? 1 : 0) + (isPrime(c) ? 1 : 0);

    if (cnt == 0) cout << "Seguro\n";
    else if (cnt == 1) cout << "Possível Risco\n";
    else cout << "Perigo\n";

    return 0;
}