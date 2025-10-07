/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> nums(4);
    for (int i = 0; i < 4; i++) {
        std::cin >> nums[i];
    }
    std::sort(nums.begin(), nums.end());
    std::cout << nums[0] + nums[1] << nums[2] + nums[3] << std::endl;
    return 0;
}
