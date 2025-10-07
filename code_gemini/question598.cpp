/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

const int MOD = 100000007;
const int MAXN = 10001;

long long fact[MAXN];

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

long long modInverse(long long n) {
    return power(n, MOD - 2);
}

void precompute_factorials() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    precompute_factorials();

    std::string s;
    while (std::cin >> s && s != "0") {
        int n = s.length();
        std::vector<int> counts(26, 0);
        for (char c : s) {
            counts[c - 'a']++;
        }

        long long numerator = fact[n];
        long long denominator_inv = 1;

        for (int count : counts) {
            if (count > 1) {
                denominator_inv = (denominator_inv * modInverse(fact[count])) % MOD;
            }
        }

        long long result = (numerator * denominator_inv) % MOD;
        std::cout << result << std::endl;
    }

    return 0;
}
