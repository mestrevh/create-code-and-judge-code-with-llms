/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

bool is_prime(long long n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long nums[4];
    bool all_prime = true;
    
    for (int i = 0; i < 4; ++i) {
        if (!(std::cin >> nums[i])) {
            all_prime = false;
            break;
        }
        if (!is_prime(nums[i])) {
            all_prime = false;
        }
    }

    if (all_prime) {
        long long product = 1;
        for (int i = 0; i < 4; ++i) {
            product *= nums[i];
        }
        std::cout << product << std::endl;
    } else {
        std::cout << "SEM PRODUTO" << std::endl;
    }

    return 0;
}