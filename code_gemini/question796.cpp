/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

long long power(long long base, long long exp) {
    long long res = 1;
    long long mod = 100;
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

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n1, n2;
    while (std::cin >> n1 >> n2) {
        long long res1 = power(n1, n1);
        long long res2 = power(n2, n2);
        if (res1 > res2) {
            std::cout << n1 << "\n";
        } else if (res2 > res1) {
            std::cout << n2 << "\n";
        } else {
            std::cout << 0 << "\n";
        }
    }
    return 0;
}
