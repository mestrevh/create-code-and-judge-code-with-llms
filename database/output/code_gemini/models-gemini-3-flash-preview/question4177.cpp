/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    for (int i = 0; i < 3; ++i) {
        std::vector<int> nums;
        int val;
        while (std::cin >> val) {
            nums.push_back(val);
            if (val == 420) {
                break;
            }
        }

        if (nums.empty()) {
            break;
        }

        std::sort(nums.begin(), nums.end());

        std::cout << nums.size() << "\n";
        for (size_t j = 0; j < nums.size(); ++j) {
            std::cout << nums[j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}