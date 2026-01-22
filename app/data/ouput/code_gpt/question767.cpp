/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

int main() {
    std::vector<int> nums;
    int num;
    while (std::cin >> num) {
        nums.push_back(num);
        if (std::cin.peek() == '\n') break;
    }
    
    std::sort(nums.begin(), nums.end());
    size_t n = nums.size();
    double median;

    if (n % 2 == 1) {
        median = nums[n / 2];
    } else {
        median = (nums[n / 2 - 1] + nums[n / 2]) / 2.0;
    }

    std::cout << "Mediana = " << std::fixed << std::setprecision(n % 2 == 0 ? 1 : 0) << median << std::endl;
    return 0;
}
