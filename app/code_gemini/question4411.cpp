/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    std::unordered_map<int, int> num_map;
    
    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        if (num_map.count(complement)) {
            std::cout << "[" << num_map[complement] << ", " << i << "]\n";
            return 0;
        }
        num_map[nums[i]] = i;
    }

    return 0;
}
