/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <vector>

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

int count_divisors(int n) {
    if (n <= 3) {
        return 0;
    }
    int count = 0;
    for (int i = 2; i <= n / 2; ++i) {
        if (n % i == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;

    while (N--) {
        int M;
        std::cin >> M;
        double total_reliability = 0.0;

        for (int k = 0; k < M; ++k) {
            int i;
            std::cin >> i;
            int abs_i = std::abs(i);

            if (is_prime(abs_i)) {
                total_reliability += 2.0 * abs_i;
            } else {
                total_reliability += (static_cast<double>(abs_i) / 2.0) * count_divisors(abs_i);
            }
        }

        if (total_reliability > 2048) {
            std::cout << "Anão Paulo. babado.\n";
        } else if (total_reliability > 512) {
            std::cout << "Para pow.\n";
        } else if (total_reliability > 0) {
            std::cout << "Se isso não é mentira eu sou uma brastemp 4 portas\n";
        } else {
            std::cout << "que mentirada\n";
        }
    }

    return 0;
}
