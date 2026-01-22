/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string comp_str;
    std::cin >> comp_str;

    int n = comp_str.length() + 1;
    
    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }

    std::sort(nums.begin(), nums.end());

    std::vector<int> result(n);
    int low = 0;
    int high = n - 1;

    for (int i = 0; i < n - 1; ++i) {
        if (comp_str[i] == '<') {
            result[i] = nums[low++];
        } else { // comp_str[i] == '>'
            result[i] = nums[high--];
        }
    }

    result[n - 1] = nums[low];

    std::cout << result[0];
    for (int i = 0; i < n - 1; ++i) {
        std::cout << " " << comp_str[i] << " " << result[i + 1];
    }
    std::cout << std::endl;

    return 0;
}
