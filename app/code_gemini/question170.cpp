/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    if (is_prime(a) && is_prime(b) && is_prime(c) && is_prime(d)) {
        long long product = 1LL * a * b * c * d;
        std::cout << product << std::endl;
    } else {
        std::cout << "SEM PRODUTO" << std::endl;
    }

    return 0;
}
