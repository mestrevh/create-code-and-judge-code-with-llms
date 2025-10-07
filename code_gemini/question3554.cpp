/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <vector>

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

    int n;
    std::cin >> n;

    int a = 0;
    int b = 1;
    int last_fib = 0;

    if (n >= 1) {
        last_fib = 1;
    }

    while (true) {
        int next_fib = a + b;
        if (next_fib > n) {
            break;
        }
        last_fib = next_fib;
        a = b;
        b = next_fib;
    }

    for (int i = last_fib; i >= 2; --i) {
        if (is_prime(i)) {
            std::cout << i << std::endl;
            break;
        }
    }

    return 0;
}
