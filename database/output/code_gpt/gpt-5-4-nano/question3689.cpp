/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
using i128 = __int128_t;

static inline i128 floor_sqrt_i128(i128 x) {
    if (x <= 0) return 0;
    long double ld = (long double)x;
    i128 r = (i128)floor(sqrt(ld));
    while ((r + 1) * (r + 1) <= x) ++r;
    while (r * r > x) --r;
    return r;
}

static inline i128 mod_mul(i128 a, i128 b, i128 mod) {
    return (a * b) % mod;
}

static inline i128 mod_pow(i128 a, i128 d, i128 mod) {
    i128 r = 1 % mod;
    while (d > 0) {
        if (d & 1) r = mod_mul(r, a, mod);
        a = mod_mul(a, a, mod);
        d >>= 1;
    }
    return r;
}

static bool isPrime_u64(uint64_t n) {
    if (n < 2) return false;
    static uint64_t smallPrimes[] = {2ULL,3ULL,5ULL,7ULL,11ULL,13ULL,17ULL,19ULL,23ULL,0ULL};
    for (int i = 0; smallPrimes[i]; ++i) {
        if (n == smallPrimes[i]) return true;
        if (n % smallPrimes[i] == 0) return false;
    }
    uint64_t d = n - 1, s = 0;
    while ((d & 1) == 0) { d >>= 1; ++s; }
    auto witness = [&](uint64_t a)->bool{
        if (a % n == 0) return false;
        i128 x = mod_pow((i128)a, (i128)d, (i128)n);
        if (x == 1 || x == (i128)(n - 1)) return false;
        for (uint64_t r = 1; r < s; ++r) {
            x = mod_mul(x, x, (i128)n);
            if (x == (i128)(n - 1)) return false;
        }
        return true;
    };
    uint64_t bases[] = {2ULL, 325ULL, 9375ULL, 28178ULL, 450775ULL, 9780504ULL, 1795265022ULL};
    for (uint64_t a : bases) {
        if (witness(a)) return false;
    }
    return true;
}

static vector<pair<uint64_t,int>> factorize(uint64_t n) {
    vector<pair<uint64_t,int>> f;
    if (n < 2) return f;
    if ((n % 2) == 0) {
        int c = 0;
        while ((n % 2) == 0) { n >>= 1; ++c; }
        f.push_back({2, c});
    }
    for (uint64_t p = 3; p * p <= n; p += 2) {
        if ((n % p) == 0) {
            int c = 0;
            while ((n % p) == 0) { n /= p; ++c; }
            f.push_back({p, c});
        }
    }
    if (n > 1) f.push_back({n, 1});
    return f;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    uint64_t a[3];
    if (!(cin >> a[0] >> a[1] >> a[2])) return 0;

    bool saved = false;
    for (int tc = 0; tc < 3; ++tc) {
        if (saved) {
            cout << "SINAL OFF";
            if (tc != 2) cout << "\n";
            continue;
        }

        uint64_t n = a[tc];
        vector<pair<uint64_t,int>> facs = factorize(n);

        uint64_t k = 0;
        for (auto &pr : facs) k += (uint64_t)pr.second;
        i128 sumNum = 0;
        uint64_t idx = 0;
        for (auto &pr : facs) {
            uint64_t p = pr.first;
            int cnt = pr.second;
            for (int t = 0; t < cnt; ++t) {
                ++idx;
                sumNum += (i128)p;
            }
        }

        i128 sumDen = 0;
        idx = 0;
        for (auto &pr : facs) {
            uint64_t p = pr.first;
            int cnt = pr.second;
            for (int t = 0; t < cnt; ++t) {
                ++idx;
                sumDen += (i128)idx;
            }
        }

        i128 S = 0;
        idx = 0;
        for (auto &pr : facs) {
            uint64_t p = pr.first;
            int cnt = pr.second;
            for (int t = 0; t < cnt; ++t) {
                ++idx;
                S += (i128)p * 1000000;
                S -= (i128)p * 1000000;
            }
        }

        i128 numer = 0;
        i128 denom = 0;
        idx = 0;
        for (auto &pr : facs) {
            uint64_t p = pr.first;
            int cnt = pr.second;
            for (int t = 0; t < cnt; ++t) {
                ++idx;
                numer += (i128)p;
                denom += (i128)idx;
            }
        }

        i128 ansFloor = 0;
        {
            uint64_t j = 0;
            long double acc = 0.0L;
            bool useLongDouble = true;
            for (auto &pr : facs) {
                uint64_t p = pr.first;
                int cnt = pr.second;
                for (int t = 0; t < cnt; ++t) {
                    ++j;
                    acc += (long double)p / (long double)j;
                }
            }
            if (useLongDouble) {
                ansFloor = (i128)floor(acc);
            } else {
                ansFloor = 0;
            }
        }

        uint64_t X = (uint64_t)ansFloor;

        if (isPrime_u64(X)) {
            saved = true;
            cout << "SHERLIRO SALVOU MULITTLE";
        } else {
            cout << "ERRO";
        }
        if (tc != 2) cout << "\n";
    }

    return 0;
}