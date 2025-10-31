/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

long long calculate_power(const std::vector<int>& strengths, int start, int end) {
    if (start > end) {
        return 0;
    }
    if (start == end) {
        if (strengths[start] > 10) {
            return strengths[start];
        } else {
            return 0;
        }
    }

    int mid = start + (end - start) / 2;
    
    long long left_power = calculate_power(strengths, start, mid);
    long long right_power = calculate_power(strengths, mid + 1, end);
    
    return left_power + right_power;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    if (n <= 0) {
        std::cout << 0 << std::endl;
        return 0;
    }

    std::vector<int> strengths(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> strengths[i];
    }

    std::cout << calculate_power(strengths, 0, n - 1) << std::endl;

    return 0;
}
