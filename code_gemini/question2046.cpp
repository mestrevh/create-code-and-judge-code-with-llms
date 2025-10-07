/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

bool eh_primo(int x) {
    if (x <= 1) {
        return false;
    }
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int proximo_primo(int y) {
    int num = y;
    while (true) {
        if (eh_primo(num)) {
            return num;
        }
        num++;
    }
}

long long fatorial(int z) {
    long long res = 1;
    for (int i = 1; i <= z; ++i) {
        res *= i;
    }
    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    if (n == 0) {
        std::cout << std::fixed << std::setprecision(2) << 0.0 << std::endl;
        return 0;
    }

    double soma = 0.0;
    int current_prime_den = 0;

    for (int i = 1; i <= n; ++i) {
        long long num = fatorial(i);
        int den;

        if (i == 1) {
            den = 1;
        } else {
            if (i > current_prime_den) {
                current_prime_den = proximo_primo(i);
            }
            den = current_prime_den;
        }

        soma += static_cast<double>(num) / den;

        std::cout << i << "!/" << den;
        if (i < n) {
            std::cout << " + ";
        }
    }
    
    std::cout << std::endl;
    std::cout << std::fixed << std::setprecision(2) << soma << std::endl;

    return 0;
}
