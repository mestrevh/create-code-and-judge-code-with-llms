/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;

    if (a < 0 || b < 0 || c < 0) {
        std::cout << "Ordenacao cancelada." << std::endl;
        return 0;
    }

    std::vector<int> nums = {a, b, c};

    if (a % 2 == 1) {
        std::sort(nums.begin(), nums.end());
    } else {
        std::sort(nums.begin(), nums.end(), std::greater<int>());
    }

    for (int num : nums) {
        std::cout << num << std::endl;
    }

    return 0;
}
