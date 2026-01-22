/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

bool temPropriedade(int n) {
    if (n <= 1) {
        return false;
    }
    long long soma_divisores = 1;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            soma_divisores += i;
            if (i * i != n) {
                soma_divisores += n / i;
            }
        }
    }
    if (n > 1) {
        soma_divisores += n;
    }
    
    return soma_divisores == (long long)n + 1;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int i, j;
    std::cin >> i >> j;
    for (int k = i; k <= j; ++k) {
        if (temPropriedade(k)) {
            std::cout << k << "\n";
        }
    }
    return 0;
}
