/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    const int LIMIT = 1100000;
    std::vector<bool> is_prime(LIMIT + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int p = 2; p * p <= LIMIT; ++p) {
        if (is_prime[p]) {
            for (int i = p * p; i <= LIMIT; i += p) {
                is_prime[i] = false;
            }
        }
    }

    int count = 0;
    for (int p = 2; p <= LIMIT && count < n; ++p) {
        if (is_prime[p]) {
            std::cout << p << "\n";
            count++;
        }
    }

    return 0;
}
