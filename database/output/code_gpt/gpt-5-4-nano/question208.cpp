/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned long long N;
    if (!(cin >> N)) return 0;

    auto isPrime = [&](unsigned long long x) -> bool {
        if (x < 2) return false;
        if (x % 2 == 0) return x == 2;
        if (x % 3 == 0) return x == 3;
        unsigned long long d = 5;
        while (d * d <= x) {
            if (x % d == 0) return false;
            if (x % (d + 2) == 0) return false;
            d += 6;
        }
        return true;
    };

    if (N <= 3) {
        cout << 'N' << '\n';
        return 0;
    }

    if (isPrime(N)) {
        cout << 'N' << '\n';
        return 0;
    }

    cout << 'S' << '\n';
    return 0;
}