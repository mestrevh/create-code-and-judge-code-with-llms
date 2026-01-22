/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    const std::vector<int> marsenne_primes_exponents = {1, 2, 3, 5, 7, 13, 17, 19, 31, 61, 89, 107, 127};

    int m;
    while (std::cin >> m) {
        if (m < 0) {
            break;
        }

        bool first_output = true;
        for (int n : marsenne_primes_exponents) {
            if (n < m) {
                if (!first_output) {
                    std::cout << " ";
                }
                std::cout << n;
                first_output = false;
            } else {
                break;
            }
        }
        std::cout << '\n';
    }

    return 0;
}
