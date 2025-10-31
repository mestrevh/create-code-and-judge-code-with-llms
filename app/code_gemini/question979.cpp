/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::vector<int> nums(4);
    for (int i = 0; i < 4; ++i) {
        std::cin >> nums[i];
    }
    std::sort(nums.begin(), nums.end(), std::greater<int>());
    std::cout << nums[0] << " " << nums[1] << " " << nums[2] << " " << nums[3] << std::endl;
    return 0;
}
