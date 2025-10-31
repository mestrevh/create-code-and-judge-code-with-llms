/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <set>

bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

int main() {
    int count;
    while (true) {
        std::cin >> count;
        if (count >= 2 && count <= 12) break;
        std::cout << "Informe um valor entre 2 e 12!" << std::endl;
    }

    std::set<int> primes;
    int number;
    while (primes.size() < count) {
        std::cin >> number;
        if (is_prime(number)) {
            primes.insert(number);
        }
    }

    for (auto it = primes.begin(); it != primes.end(); ++it) {
        if (it != primes.begin()) std::cout << " ";
        std::cout << *it;
    }
    std::cout << std::endl;
    return 0;
}
