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

    std::vector<int> nums;
    int n;
    int result = 0;

    while (std::cin >> n) {
        nums.push_back(n);
        result ^= n;
    }

    if (!nums.empty()) {
        std::sort(nums.begin(), nums.end());

        for (int val : nums) {
            std::cout << val << " ";
        }
        std::cout << "\n";

        std::cout << result << "\n";
    }

    return 0;
}
