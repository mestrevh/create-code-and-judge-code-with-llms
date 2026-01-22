/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int x;
    std::cin >> x;

    if (x <= 0) {
        std::cout << 0 << "\n";
        return 0;
    }

    std::vector<int> nums(x);
    long long total_sum = 0;
    for (int i = 0; i < x; ++i) {
        std::cin >> nums[i];
        total_sum += nums[i];
    }

    long long max_non_wrap = nums[0];
    long long current_max = nums[0];
    for (int i = 1; i < x; ++i) {
        current_max = std::max((long long)nums[i], current_max + nums[i]);
        max_non_wrap = std::max(max_non_wrap, current_max);
    }

    if (max_non_wrap < 0) {
        std::cout << max_non_wrap << "\n";
        return 0;
    }

    long long min_non_wrap = nums[0];
    long long current_min = nums[0];
    for (int i = 1; i < x; ++i) {
        current_min = std::min((long long)nums[i], current_min + nums[i]);
        min_non_wrap = std::min(min_non_wrap, current_min);
    }

    long long max_wrap = total_sum - min_non_wrap;

    std::cout << std::max(max_non_wrap, max_wrap) << "\n";

    return 0;
}
