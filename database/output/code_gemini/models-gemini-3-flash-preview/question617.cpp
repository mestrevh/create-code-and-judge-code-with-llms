/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 5005;
const int MOD = 1000000007;

long long fact[MAXN], invFact[MAXN];

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

void precompute() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[MAXN - 1] = power(fact[MAXN - 1], MOD - 2);
    for (int i = MAXN - 2; i >= 0; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

long long combinations(int n, int k) {
    if (k < 0 || k > n) return 0;
    long long res = (fact[n] * invFact[k]) % MOD;
    res = (res * invFact[n - k]) % MOD;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int N, Q;
    while (cin >> N >> Q) {
        vector<long long> powers(N + 1);
        for (int k = 1; k <= N; k++) {
            powers[k] = power(k, N);
        }
        vector<long long> memo(N + 1, -1);
        for (int q = 0; q < Q; q++) {
            long long Ki;
            cin >> Ki;
            int K = (Ki > (long long)N) ? N : (int)Ki;
            if (memo[K] == -1) {
                long long res = 0;
                for (int k = 1; k <= K; k++) {
                    long long term = (powers[k] * combinations(N, K - k)) % MOD;
                    if ((K - k) % 2 == 1) {
                        res = (res - term + MOD) % MOD;
                    } else {
                        res = (res + term) % MOD;
                    }
                }
                memo[K] = res;
            }
            cout << memo[K] << (q == Q - 1 ? "" : " ");
        }
        cout << "\n";
    }
    return 0;
}