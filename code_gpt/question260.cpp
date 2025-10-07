/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int number;
    while (std::cin >> number && number != -1) {
        std::cout << (is_prime(number) ? 1 : 0) << std::endl;
    }
    return 0;
}
