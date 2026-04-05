/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static bool isPrime(long long n) {
    if (n < 2) return false;
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n;
    while (cin >> n) {
        if (n == -1) break;
        cout << (isPrime(n) ? 1 : 0) << "\n";
    }
    return 0;
}