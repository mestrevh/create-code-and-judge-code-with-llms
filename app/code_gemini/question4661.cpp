/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

long long power(long long base, long long exp) {
    long long res = 1;
    base %= 998244353;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % 998244353;
        base = (base * base) % 998244353;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, 998244353 - 2);
}

const int MAX_VAL = 200005;
long long fact[MAX_VAL];
long long invFact[MAX_VAL];

void precompute_factorials() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < MAX_VAL; i++) {
        fact[i] = (fact[i - 1] * i) % 998244353;
        invFact[i] = modInverse(fact[i]);
    }
}

long long combinations(int n, int k) {
    if (k < 0 || k > n) {
        return 0;
    }
    return (((fact[n] * invFact[k]) % 998244353) * invFact[n - k]) % 998244353;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute_factorials();

    long long L, N;
    cin >> L >> N;

    if (N == 1) {
        cout << 0 << endl;
        return 0;
    }

    long long L_div_2 = L / 2;

    long long C_total_0 = combinations(L - 1, N - 1);
    long long term1 = (L_div_2 * C_total_0) % 998244353;

    long long sum_a0 = 0;
    
    long long start_k = (N + 1) / 2;
    if (start_k == 0) {
        start_k = 1;
    }

    for (long long k = start_k; k <= L_div_2; ++k) {
        sum_a0 = (sum_a0 + combinations(2 * k - 2, N - 1)) % 998244353;
    }
    
    long long s0 = (term1 - sum_a0 + 998244353) % 998244353;
    long long n_inv = modInverse(N);
    
    long long ans = (L * s0) % 998244353;
    ans = (ans * n_inv) % 998244353;

    cout << ans << endl;

    return 0;
}
