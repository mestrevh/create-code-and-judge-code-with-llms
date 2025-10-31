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

    std::vector<bool> is_prime(2001, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= 2000; ++p) {
        if (is_prime[p]) {
            for (int i = p * p; i <= 2000; i += p) {
                is_prime[i] = false;
            }
        }
    }

    int a, b;
    std::cin >> a >> b;

    int max_len = 0;

    for (int i = a; i < b; ++i) {
        int current_len = 0;
        int current_num = i;
        while (current_num < b && is_prime[current_num]) {
            current_len++;
            current_num += 6;
        }
        max_len = std::max(max_len, current_len);
    }

    std::cout << max_len << std::endl;

    return 0;
}
