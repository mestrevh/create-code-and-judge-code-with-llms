/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long A, B;
    if (!(cin >> A >> B)) return 0;
    if (A > B) swap(A, B);

    int n = (int)(B - A + 1);
    vector<int> spf(n, 0);
    vector<long long> val(n);
    for (int i = 0; i < n; i++) val[i] = A + i;

    long long limit = (long long)floor(sqrt((long double)B));
    vector<int> primes;
    vector<bool> isComp(limit + 1, false);
    for (long long i = 2; i <= limit; i++) {
        if (!isComp[(size_t)i]) {
            primes.push_back((int)i);
            if (i * i <= limit) {
                for (long long j = i * i; j <= limit; j += i) isComp[(size_t)j] = true;
            }
        }
    }

    for (long long p : primes) {
        long long start = (A + p - 1) / p * p;
        for (long long x = start; x <= B; x += p) {
            int idx = (int)(x - A);
            if (spf[idx] == 0) spf[idx] = (int)p;
            while (val[idx] % p == 0) val[idx] /= p;
        }
    }

    vector<long long> remaining(n);
    for (int i = 0; i < n; i++) remaining[i] = val[i];

    vector<long long> primesUsed(n, 0);
    vector<long long> divisors(n, 1);

    for (int i = 0; i < n; i++) {
        long long xorig = A + i;
        long long x = xorig;
        long long dCount = 1;

        long long t = x;
        for (long long p : primes) {
            if (p * p > t) break;
            if (t % p == 0) {
                long long e = 0;
                while (t % p == 0) {
                    t /= p;
                    e++;
                }
                dCount *= (e + 1);
            }
        }
        if (t > 1) dCount *= 2;

        primesUsed[i] = xorig;
        divisors[i] = dCount;
    }

    long long bestNum = A;
    long long bestDiv = divisors[0];
    for (int i = 1; i < n; i++) {
        long long d = divisors[i];
        if (d > bestDiv) {
            bestDiv = d;
            bestNum = A + i;
        }
    }

    cout << bestNum << " " << bestDiv << "\n";
    return 0;
}