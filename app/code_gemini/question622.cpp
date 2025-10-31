/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>

long long power(long long base, long long exp) {
    long long res = 1;
    long long mod = 1000000007;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<long long> a(n);
    long long fx = 1;
    long long mod = 1000000007;

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        fx = (fx * a[i]) % mod;
    }

    long long gx = a[0];
    for (int i = 1; i < n; ++i) {
        gx = gcd(gx, a[i]);
    }

    long long result = power(fx, gx);
    std::cout << result << std::endl;

    return 0;
}
