/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>

void print_vector(const std::vector<int>& vec) {
    if (vec.empty()) {
        return;
    }
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << (i == vec.size() - 1 ? "" : " ");
    }
    std::cout << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string line;
    std::getline(std::cin, line);
    std::stringstream ss(line);
    std::vector<int> nums;
    int num;
    while (ss >> num) {
        nums.push_back(num);
    }
    
    if (nums.empty()) {
        return 0;
    }

    auto minmax_it = std::minmax_element(nums.begin(), nums.end());
    int min_val = *minmax_it.first;
    int max_val = *minmax_it.second;

    int m = (min_val + max_val) / 2;

    int pivot = nums[0];
    int min_diff = std::abs(nums[0] - m);

    for (size_t i = 1; i < nums.size(); ++i) {
        int current_diff = std::abs(nums[i] - m);
        if (current_diff < min_diff) {
            min_diff = current_diff;
            pivot = nums[i];
        }
    }
    
    std::cout << pivot << std::endl;

    auto it = std::find(nums.begin(), nums.end(), pivot);
    if (it != nums.end()) {
        std::iter_swap(it, nums.end() - 1);
    }
    
    if (nums.size() > 1) {
        int i = -1;
        for (size_t j = 0; j < nums.size() - 1; ++j) {
            if (nums[j] <= pivot) {
                i++;
                std::swap(nums[i], nums[j]);
            }
        }
        std::swap(nums[i + 1], nums.back());
    }

    print_vector(nums);

    return 0;
}
