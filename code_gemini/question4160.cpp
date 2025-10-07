/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<long long> factorials;
    factorials.push_back(1);
    long long current_fact = 1;
    for (int i = 1; i <= 20; ++i) {
        if (__builtin_mul_overflow(current_fact, i, &current_fact)) {
            break;
        }
        factorials.push_back(current_fact);
    }

    int x;
    std::cin >> x;

    long long total_sum = 0;
    for (int i = 0; i < x; ++i) {
        int value;
        std::cin >> value;
        total_sum += value;
    }

    int best_n = 0;
    long long min_diff = std::numeric_limits<long long>::max();

    for (size_t n = 0; n < factorials.size(); ++n) {
        long long diff = std::abs(total_sum - factorials[n]);
        if (diff < min_diff) {
            min_diff = diff;
            best_n = n;
        }
    }

    std::cout << "Bia arrecadou " << best_n << "! dinheiros e pode jogar tenis!" << std::endl;

    return 0;
}
