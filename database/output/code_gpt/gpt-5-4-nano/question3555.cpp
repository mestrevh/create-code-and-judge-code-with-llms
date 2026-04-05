/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
using i128 = __int128_t;

static long long mul_mod(long long a, long long b, long long mod) {
    return (long long)((i128)a * b % mod);
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

static bool isPrime64(long long n) {
    if (n < 2) return false;
    for (long long p : {2LL,3LL,5LL,7LL,11LL,13LL,17LL,19LL,23LL,29LL,31LL,37LL}) {
        if (n == p) return true;
        if (n % p == 0) return false;
    }
    long long d = n - 1, s = 0;
    while ((d & 1) == 0) { d >>= 1; ++s; }
    auto witness = [&](long long a) -> bool {
        if (a % n == 0) return false;
        long long x = pow_mod(a, d, n);
        if (x == 1 || x == n - 1) return false;
        for (long long i = 1; i < s; i++) {
            x = mul_mod(x, x, n);
            if (x == n - 1) return false;
        }
        return true;
    };
    vector<long long> bases;
    if (n < 341550071728321LL) bases = {2,3,5,7,11,13,17};
    else bases = {2,3,5,7,11,13,17,19,23,29,31,37};
    for (long long a : bases) {
        if (witness(a)) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    while (cin >> N) {
        if (N == -1) break;

        string ans;
        if (N < 16) {
            if (N == 16) ans = "eh um primo de 4";
            else ans = "eu nunca duvidei";
        } else {
            long long cnt = 0;
            long long x = N;
            for (long long p : {2LL, 3LL, 5LL, 7LL, 11LL, 13LL}) {
                if (x == 1) break;
                while (x % p == 0) {
                    x /= p;
                    cnt++;
                    if (cnt > 4) break;
                }
                if (cnt > 4) break;
            }

            if (cnt > 4) {
                ans = "eu nunca duvidei";
            } else {
                if (N == 1) {
                    ans = "eu nunca duvidei";
                } else if (cnt == 4) {
                    ans = (x == 1) ? "eh um primo de 4" : "eu nunca duvidei";
                } else {
                    long long a = 0, b = 0, c = 0, d = 0;
                    bool ok = false;

                    auto check = [&](long long p, int e, long long &rem) -> bool {
                        for (int i = 0; i < e; i++) {
                            if (rem % p != 0) return false;
                            rem /= p;
                        }
                        return true;
                    };

                    i128 root = 0;

                    auto attempt = [&](long long p) -> bool {
                        if (p < 2) return false;
                        long long rem = N;
                        int e = 0;
                        while (rem % p == 0) {
                            rem /= p;
                            e++;
                            if (e > 4) break;
                        }
                        if (e > 4) return false;
                        if (e == 4) return rem == 1;
                        if (e == 3) {
                            if (rem == 1) return false;
                            if (rem == 1) return false;
                            if (rem >= 2 && isPrime64(rem)) return true;
                            return false;
                        }
                        if (e == 2) {
                            if (rem == 1) return false;
                            long long rem2 = rem;
                            int e2 = 0;
                            for (long long q : {2LL, 3LL, 5LL, 7LL, 11LL, 13LL}) {
                                while (rem2 % q == 0) {
                                    rem2 /= q;
                                    e2++;
                                    if (e2 > 2) break;
                                }
                                if (e2 > 2) break;
                            }
                            if (e2 > 2) return false;
                            if (e2 == 0) {
                                return rem == rem && isPrime64(rem);
                            }
                            if (e2 == 1) {
                                long long last = rem2;
                                if (last >= 2 && isPrime64(last)) return true;
                                return false;
                            }
                            if (e2 == 2) return rem2 == 1;
                            return false;
                        }
                        if (e == 1) {
                            if (rem == 1) return false;
                            long long rem2 = rem;
                            int e2 = 0;
                            for (long long q : {2LL, 3LL, 5LL, 7LL, 11LL, 13LL}) {
                                while (rem2 % q == 0) {
                                    rem2 /= q;
                                    e2++;
                                    if (e2 > 3) break;
                                }
                                if (e2 > 3) break;
                            }
                            if (e2 > 3) return false;
                            if (e2 == 3) return rem2 == 1;
                            if (e2 == 2) {
                                if (rem2 >= 2 && isPrime64(rem2)) return true;
                                return false;
                            }
                            if (e2 == 1) {
                                if (rem2 >= 2) {
                                    if (rem2 == 1) return false;
                                    if (isPrime64(rem2) && isPrime64(rem2)) return true;
                                    return false;
                                }
                                return false;
                            }
                            if (e2 == 0) return isPrime64(rem) && isPrime64(rem);
                            return false;
                        }
                        return false;
                    };

                    vector<long long> smallPrimes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
                    bool done = false;

                    long long rem = N;
                    map<long long,int> fac;
                    for (long long p : smallPrimes) {
                        if (p*p > rem) break;
                        int e=0;
                        while(rem%p==0){ rem/=p; e++; if(e>4) break; }
                        if(e>0) fac[p]=e;
                        if(rem==1) break;
                    }

                    if (rem != 1) {
                        if (fac.empty() || rem != 1) {
                            if (isPrime64(rem)) fac[rem] = fac.count(rem)?fac[rem]:1;
                            else {
                                i128 r = (i128)llround(sqrt((long double)rem));
                                long long rr = (long long)r;
                                for (long long p = rr-2; p<=rr+2 && p>=2; p++){
                                    if(p>=2 && rem%p==0){
                                        long long t=0;
                                        while(rem%p==0){ rem/=p; t++; if(t>4) break; }
                                        fac[p]=t;
                                        break;
                                    }
                                }
                                if (rem!=1 && isPrime64(rem)) fac[rem]=1;
                            }
                        }
                    }

                    long long total = 0;
                    for (auto &kv: fac) total += kv.second;
                    if (total != 4) {
                        ans = "eu nunca duvidei";
                    } else {
                        vector<pair<long long,int>> factors(fac.begin(), fac.end());
                        bool ok=false;

                        auto productFromCounts = [&](vector<long long> &primes) -> long long {
                            i128 prod=1;
                            for(long long p: primes) prod*=p;
                            return (long long)prod;
                        };

                        int distinct = (int)factors.size();
                        vector<long long> primesList;
                        for (auto &kv: factors) for(int i=0;i<kv.second;i++) primesList.push_back(kv.first);
                        if ((int)primesList.size()==4) {
                            i128 prod=1;
                            for(long long p: primesList) prod*=p;
                            ok = (prod == (i128)N);
                        } else ok=false;

                        ans = ok ? "eh um primo de 4" : "eu nunca duvidei";
                    }

                    done = true;
                    (void)a;(void)b;(void)c;(void)d;
                }
            }
        }

        if (ans == "eh um primo de 4") cout << N << " eh um primo de 4\n";
        else cout << N << ", eu nunca duvidei\n";
    }
    return 0;
}