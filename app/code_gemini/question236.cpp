/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<long long> calculate_counts_up_to(long long n) {
    if (n < 0) {
        return std::vector<long long>(10, 0);
    }

    std::string s = std::to_string(n);
    int len = s.length();
    std::vector<long long> ans(10, 0);

    long long p10 = 1;
    for (int i = len - 1; i >= 0; --i) {
        long long prefix = n / (p10 * 10);
        long long suffix = n % p10;
        int current_digit = s[i] - '0';

        for (int d = 0; d <= 9; ++d) {
            long long contribution = prefix * p10;
            if (d < current_digit) {
                contribution += p10;
            } else if (d == current_digit) {
                contribution += suffix + 1;
            }
            ans[d] += contribution;
        }
        p10 *= 10;
    }

    p10 = 1;
    for (int i = 1; i < len; ++i) {
        p10 *= 10;
        ans[0] -= p10;
    }
    
    return ans;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long a, b;
    while (std::cin >> a >> b && (a != 0 || b != 0)) {
        std::vector<long long> counts_b = calculate_counts_up_to(b);
        std::vector<long long> counts_a_minus_1 = calculate_counts_up_to(a - 1);

        for (int i = 0; i < 10; ++i) {
            std::cout << counts_b[i] - counts_a_minus_1[i] << (i == 9 ? "" : " ");
        }
        std::cout << "\n";
    }

    return 0;
}
