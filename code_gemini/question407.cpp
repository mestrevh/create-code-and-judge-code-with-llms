/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

const int MAX_N = 1000001;
int cache[MAX_N] = {0};

int calculate_cycle_length(long long n) {
    if (n == 1) {
        return 1;
    }
    if (n < MAX_N && cache[n] != 0) {
        return cache[n];
    }

    long long next_n;
    if (n % 2 == 0) {
        next_n = n / 2;
    } else {
        next_n = 3 * n + 1;
    }

    int length = 1 + calculate_cycle_length(next_n);

    if (n < MAX_N) {
        cache[n] = length;
    }

    return length;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int i, j;
    while (std::cin >> i >> j) {
        int orig_i = i;
        int orig_j = j;

        if (i > j) {
            std::swap(i, j);
        }

        int max_cycle = 0;
        for (int k = i; k <= j; ++k) {
            int current_cycle = calculate_cycle_length(k);
            if (current_cycle > max_cycle) {
                max_cycle = current_cycle;
            }
        }

        std::cout << orig_i << " " << orig_j << " " << max_cycle << "\n";
    }

    return 0;
}
