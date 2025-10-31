/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    std::vector<int> nums = {a, b, c};
    std::sort(nums.begin(), nums.end());
    for (int num : nums) {
        std::cout << num << std::endl;
    }
    return 0;
}
