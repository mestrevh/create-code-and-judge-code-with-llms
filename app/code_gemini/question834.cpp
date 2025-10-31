/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::vector<int> nums(4);
    for (int i = 0; i < 4; ++i) {
        std::cin >> nums[i];
    }
    
    std::sort(nums.begin(), nums.end());
    
    int part1 = nums[0] + nums[1];
    int part2 = nums[0] + nums[2];
    
    std::cout << part1 << part2 << '\n';
    
    return 0;
}
