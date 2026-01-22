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
    std::vector<int> nums(3);
    std::cin >> nums[0];
    std::cin >> nums[1];
    std::cin >> nums[2];
    std::sort(nums.begin(), nums.end());
    std::cout << nums[0] << "\n";
    std::cout << nums[1] << "\n";
    std::cout << nums[2] << "\n";
    return 0;
}
