/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>

bool isPrime(int n) {
    if (n < 2) {
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
    
    while (true) {
        std::cin >> n;
        if (n >= 2 && n <= 12) {
            break;
        }
        std::cout << "Informe um valor entre 2 e 12!\n";
    }

    std::vector<int> found_primes;
    
    while (found_primes.size() < n) {
        int current_number;
        std::cin >> current_number;
        if (isPrime(current_number)) {
            found_primes.push_back(current_number);
        }
    }

    for (size_t i = 0; i < found_primes.size(); ++i) {
        std::cout << found_primes[i];
        if (i < found_primes.size() - 1) {
            std::cout << " ";
        }
    }
    std::cout << "\n";

    return 0;
}
