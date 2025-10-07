/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    const int MOD = 1000000007;
    const int MAXN = 1001;

    std::vector<long long> fact(MAXN);
    fact[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        if (n == 2) {
            std::cout << 1 << "\n";
        } else {
            long long inv2 = 500000004LL;
            long long result = (fact[n - 1] * inv2) % MOD;
            std::cout << result << "\n";
        }
    }

    return 0;
}
