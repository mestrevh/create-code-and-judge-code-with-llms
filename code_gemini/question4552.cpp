/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, i;
    std::cin >> n >> i;
    std::vector<int> nums(n);
    for (int j = 0; j < n; ++j) {
        std::cin >> nums[j];
    }
    std::sort(nums.begin(), nums.end(), std::greater<int>());
    std::cout << nums[i - 1] << std::endl;
    return 0;
}

