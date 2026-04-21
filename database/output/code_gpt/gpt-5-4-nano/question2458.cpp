/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

static vector<int64> primes;
static void sieve(int limit) {
    vector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; 1LL * i * i <= limit; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= limit; j += i) isPrime[j] = false;
        }
    }
    for (int i = 2; i <= limit; i++) if (isPrime[i]) primes.push_back(i);
}

static long long mul_mod(long long a, long long b, long long mod) {
    return (long long)((__int128)a * b % mod);
}

static long long pow_mod(long long a, long long d, long long mod) {
    long long r = 1 % mod;
    while (d > 0) {
        if (d & 1) r = mul_mod(r, a, mod);
        a = mul_mod(a, a, mod);
        d >>= 1;
    }
    return r;
}

static bool isPrimeDet(long long n) {
    if (n < 2) return false;
    for (long long p : {2LL,3LL,5LL,7LL,11LL,13LL,17LL,19LL,23LL,29LL,31LL,37LL}) {
        if (n == p) return true;
        if (n % p == 0) return false;
    }
    long long d = n - 1, s = 0;
    while ((d & 1) == 0) { d >>= 1; s++; }

    auto witness = [&](long long a)->bool{
        if (a % n == 0) return false;
        long long x = pow_mod(a, d, n);
        if (x == 1 || x == n - 1) return false;
        for (long long r = 1; r < s; r++) {
            x = mul_mod(x, x, n);
            if (x == n - 1) return false;
        }
        return true;
    };

    for (long long a : {2LL, 325LL, 9375LL, 28178LL, 450775LL, 9780504LL, 1795265022LL}) {
        if (witness(a)) return false;
    }
    return true;
}

static long long pollard_f(long long x, long long c, long long mod) {
    return (mul_mod(x, x, mod) + c) % mod;
}

static long long pollard_rho(long long n) {
    if (n % 2 == 0) return 2;
    if (n % 3 == 0) return 3;

    static std::mt19937_64 rng((uint64_t)chrono::high_resolution_clock::now().time_since_epoch().count());
    while (true) {
        long long c = uniform_int_distribution<long long>(1, n - 1)(rng);
        long long x = uniform_int_distribution<long long>(0, n - 1)(rng);
        long long y = x;
        long long d = 1;
        while (d == 1) {
            x = pollard_f(x, c, n);
            y = pollard_f(pollard_f(y, c, n), c, n);
            long long diff = x > y ? x - y : y - x;
            d = std::gcd(diff, n);
        }
        if (d != n) return d;
    }
}

static void factor_rec(long long n, vector<long long>& fac) {
    if (n == 1) return;
    if (isPrimeDet(n)) {
        fac.push_back(n);
        return;
    }
    long long d = pollard_rho(n);
    factor_rec(d, fac);
    factor_rec(n / d, fac);
}

static unsigned long long num_divisors(long long n) {
    if (n == 1) return 1;
    vector<long long> fac;
    vector<long long> trialFactors;
    long long tmp = n;

    for (int64 p : primes) {
        if (p * p > tmp) break;
        if (tmp % p == 0) {
            while (tmp % p == 0) {
                fac.push_back(p);
                tmp /= p;
            }
        }
    }
    if (tmp > 1) {
        if (isPrimeDet(tmp)) fac.push_back(tmp);
        else factor_rec(tmp, fac);
    }

    sort(fac.begin(), fac.end());
    unsigned long long ans = 1;
    for (size_t i = 0; i < fac.size();) {
        size_t j = i;
        while (j < fac.size() && fac[j] == fac[i]) j++;
        unsigned long long e = (unsigned long long)(j - i);
        ans *= (e + 1);
        i = j;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x;
    vector<long long> nums;
    while (cin >> x) nums.push_back(x);

    sieve(1000000);

    for (size_t i = 0; i < nums.size(); i++) {
        unsigned long long ans = num_divisors(nums[i]);
        cout << ans << "\n";
    }
    return 0;
}