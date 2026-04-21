/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long n) {
    if (n < 2) return false;
    if (n % 2 == 0) return n == 2;
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b, c, d;
    if (!(cin >> a >> b >> c >> d)) return 0;

    if (isPrime(a) && isPrime(b) && isPrime(c) && isPrime(d)) {
        __int128 prod = (__int128)a * b * c * d;
        long long out = (long long)prod;
        cout << out;
    } else {
        cout << "SEM PRODUTO";
    }
    return 0;
}