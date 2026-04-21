/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

static inline unsigned long long mod_mul(unsigned long long a, unsigned long long b, unsigned long long mod) {
    __uint128_t r = ( __uint128_t )a * b;
    return (unsigned long long)(r % mod);
}

static inline unsigned long long mod_pow(unsigned long long a, unsigned long long d, unsigned long long mod) {
    unsigned long long r = 1;
    while (d) {
        if (d & 1) r = mod_mul(r, a, mod);
        a = mod_mul(a, a, mod);
        d >>= 1;
    }
    return r;
}

static bool isPrimeU64(unsigned long long n) {
    if (n < 2) return false;
    static unsigned long long smallPrimes[] = {2ULL,3ULL,5ULL,7ULL,11ULL,13ULL,17ULL,19ULL,23ULL,29ULL,31ULL,37ULL};
    for (unsigned long long p : smallPrimes) {
        if (n == p) return true;
        if (n % p == 0) return n == p;
    }
    unsigned long long d = n - 1, s = 0;
    while ((d & 1) == 0) { d >>= 1; ++s; }

    auto witness = [&](unsigned long long a) -> bool {
        if (a % n == 0) return false;
        unsigned long long x = mod_pow(a, d, n);
        if (x == 1 || x == n - 1) return false;
        for (unsigned long long i = 1; i < s; i++) {
            x = mod_mul(x, x, n);
            if (x == n - 1) return false;
        }
        return true;
    };

    unsigned long long bases[] = {2ULL, 325ULL, 9375ULL, 28178ULL, 450775ULL, 9780504ULL, 1795265022ULL};
    for (unsigned long long a : bases) {
        if (a == 0) continue;
        if (witness(a)) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    vector<pair<long long,long long>> qs;
    qs.reserve(T);

    long long maxB = 0;
    for (int i = 0; i < T; i++) {
        long long A, B;
        cin >> A >> B;
        qs.push_back({A,B});
        if (B > maxB) maxB = B;
    }

    unsigned long long maxRoot = (unsigned long long)floor(sqrt((long double)maxB));
    unordered_map<unsigned long long, int> cache;
    cache.reserve(1 << 20);

    vector<unsigned long long> primes;
    if (maxRoot <= 3ULL) {
        if (maxRoot >= 2) primes.push_back(2);
    } else {
        unsigned long long limit = maxRoot;
        if (limit <= 5000000ULL) {
            unsigned int n = (unsigned int)limit;
            vector<bool> isP(n + 1, true);
            isP[0] = isP[1] = false;
            for (unsigned int p = 2; (unsigned long long)p * p <= limit; p++) {
                if (isP[p]) {
                    for (unsigned long long x = (unsigned long long)p * p; x <= limit; x += p) isP[(size_t)x] = false;
                }
            }
            for (unsigned int i = 2; i <= n; i++) if (isP[i]) primes.push_back(i);
        }
    }

    auto isPrimeRoot = [&](unsigned long long x) -> bool {
        auto it = cache.find(x);
        if (it != cache.end()) return it->second != 0;
        bool r;
        if (!primes.empty() && x <= primes.back()) {
            r = binary_search(primes.begin(), primes.end(), x);
        } else {
            r = isPrimeU64(x);
        }
        cache.emplace(x, r ? 1 : 0);
        return r;
    };

    auto countHighPrimes = [&](unsigned long long A, unsigned long long B) -> long long {
        unsigned long long rL = (unsigned long long)ceil(sqrt((long double)A));
        while (rL > 0 && rL * rL < A) rL++;
        unsigned long long rR = (unsigned long long)floor(sqrt((long double)B));
        while (rR * rR > B) rR--;
        if (rL > rR) return 0;
        long long cnt = 0;
        for (unsigned long long r = rL; r <= rR; r++) {
            if (isPrimeRoot(r)) cnt++;
        }
        return cnt;
    };

    for (auto [A,B] : qs) {
        unsigned long long uA = (A < 0 ? 0ULL : (unsigned long long)A);
        unsigned long long uB = (unsigned long long)B;
        unsigned long long rL = (unsigned long long)ceil(sqrt((long double)uA));
        while (rL > 0 && rL * rL < uA) rL++;
        unsigned long long rR = (unsigned long long)floor(sqrt((long double)uB));
        while (rR * rR > uB) rR--;
        if (rL > rR) {
            cout << 0 << "\n";
            continue;
        }
        unsigned long long span = rR - rL;
        if (span > 2000000ULL) {
            long long cnt = 0;
            for (unsigned long long r = rL; r <= rR; r++) {
                if (isPrimeRoot(r)) cnt++;
            }
            cout << cnt << "\n";
        } else {
            long long cnt = 0;
            for (unsigned long long r = rL; r <= rR; r++) {
                if (isPrimeRoot(r)) cnt++;
            }
            cout << cnt << "\n";
        }
    }

    return 0;
}