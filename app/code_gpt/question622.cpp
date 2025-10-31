/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

const int MOD = 1e9 + 7;

long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    int N;
    std::cin >> N;
    std::vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> a[i];
    }
    
    long long f = 1;
    for (int num : a) {
        f = (f * num) % MOD;
    }
    
    int g = std::gcd(a[0], a[1]);
    for (int i = 2; i < N; ++i) {
        g = std::gcd(g, a[i]);
    }
    
    long long result = modExp(f, g, MOD);
    std::cout << result << std::endl;
    
    return 0;
}
