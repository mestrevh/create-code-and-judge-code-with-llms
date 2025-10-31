/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> nums;
    int target, num, operations = 0;

    while (std::cin >> num) {
        nums.push_back(num);
    }

    target = nums[0];
    nums.erase(nums.begin());
    std::sort(nums.begin(), nums.end());

    int left = 0, right = nums.size() - 1, index = -1;

    while (left <= right) {
        operations++;
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            index = mid;
            break;
        }
        if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (index != -1) {
        index = std::find(nums.begin(), nums.end(), target) - nums.begin();
    }

    std::cout << index << std::endl;
    std::cout << operations << std::endl;

    return 0;
}
