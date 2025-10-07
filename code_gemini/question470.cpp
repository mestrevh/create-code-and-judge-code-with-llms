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

    int num;
    int largest_prime = -1;

    while (std::cin >> num && num != 404) {
        if (is_prime(num)) {
            if (num > largest_prime) {
                largest_prime = num;
            }
        }
    }

    if (largest_prime == -1) {
        std::cout << "SEM PRIMOS\n";
    } else {
        std::cout << largest_prime << "\n";
    }

    return 0;
}
