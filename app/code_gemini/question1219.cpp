/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <numeric>

int solve(const std::vector<int>& nums, int index, char op) {
    if (index == nums.size() - 1) {
        return nums[index];
    }

    if (op == '+') {
        return nums[index] + solve(nums, index + 1, op);
    } else {
        return nums[index] - solve(nums, index + 1, op);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::string x, y;
    char op;
    std::cin >> x >> op >> y;

    std::cout << solve(a, 0, op) << std::endl;

    return 0;
}
