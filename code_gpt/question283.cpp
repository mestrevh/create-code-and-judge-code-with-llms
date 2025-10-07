/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int L, U;
    std::cin >> L >> U;
    std::vector<int> primes;
    
    for (int i = L; i <= U; ++i) {
        if (isPrime(i)) {
            primes.push_back(i);
        }
    }

    std::map<int, int> diffCount;
    for (size_t i = 1; i < primes.size(); ++i) {
        int diff = primes[i] - primes[i - 1];
        diffCount[diff]++;
    }

    int championJump = -1;
    int maxCount = 0;
    for (const auto& pair : diffCount) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            championJump = pair.first;
        }
    }

    std::cout << championJump << std::endl;
    return 0;
}
