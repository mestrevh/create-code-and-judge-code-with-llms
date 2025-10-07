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

    std::vector<int> nums(3);
    
    if (!(std::cin >> nums[0] >> nums[1] >> nums[2])) {
        return 1;
    }

    int first_num = nums[0];

    if (nums[0] < 0 || nums[1] < 0 || nums[2] < 0) {
        std::cout << "Ordenacao cancelada.\n";
        return 0;
    }

    if (first_num % 2 != 0) {
        std::sort(nums.begin(), nums.end());
    } else {
        std::sort(nums.begin(), nums.end(), std::greater<int>());
    }

    for (int i = 0; i < 3; ++i) {
        std::cout << nums[i] << "\n";
    }

    return 0;
}
