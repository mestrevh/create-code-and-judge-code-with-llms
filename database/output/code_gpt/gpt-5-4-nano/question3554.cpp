/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    if (!(cin >> N)) return 0;

    auto isPrime = [](long long x) -> bool {
        if (x < 2) return false;
        if (x % 2 == 0) return x == 2;
        for (long long d = 3; d * d <= x; d += 2) {
            if (x % d == 0) return false;
        }
        return true;
    };

    vector<long long> fib;
    fib.push_back(1);
    fib.push_back(1);
    while (true) {
        long long a = fib[fib.size() - 2];
        long long b = fib[fib.size() - 1];
        long long c = a + b;
        if (c > N) break;
        fib.push_back(c);
    }

    long long lastFib = fib.back();
    long long i = (long long)fib.size();

    long long p = 1;
    for (long long x = 2;; x++) {
        if (isPrime(x)) {
            p = x;
            if (--i == 0) break;
        }
    }

    cout << p << "\n";
    return 0;
}