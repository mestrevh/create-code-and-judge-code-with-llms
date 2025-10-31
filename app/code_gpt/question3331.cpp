/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int main() {
    std::vector<int> nums;
    int num;
    while (std::cin >> num) {
        nums.push_back(num);
    }

    std::sort(nums.begin(), nums.end());
    std::map<int, int> count;
    
    for (int n : nums) {
        count[n]++;
    }

    int odd_count_number = 0;
    for (const auto& pair : count) {
        if (pair.second % 2 != 0) {
            odd_count_number = pair.first;
            break;
        }
    }

    for (int i = 0; i < nums.size(); i++) {
        std::cout << nums[i];
        if (i < nums.size() - 1) std::cout << " ";
    }
    std::cout << " \n" << odd_count_number << "\n";

    return 0;
}
