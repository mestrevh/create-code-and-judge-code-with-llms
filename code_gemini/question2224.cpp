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
    std::cin >> nums[0] >> nums[1] >> nums[2];
    std::sort(nums.rbegin(), nums.rend());
    std::cout << nums[0] << " " << nums[1] << " " << nums[2] << "\n";
    return 0;
}
