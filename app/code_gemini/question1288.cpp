/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

long long meeseeks(long long x, long long q, long long n) {
    if (x >= n) {
        return (x - n) + (x * q);
    } else {
        return meeseeks(x * q, q, n - x);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long x, q, n;
    std::cin >> x >> q >> n;
    std::cout << meeseeks(x, q, n) << std::endl;
    return 0;
}
