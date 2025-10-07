/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <unordered_set>

int main() {
    int n;
    std::cin >> n;
    std::vector<double> nums(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }
    double s;
    std::cin >> s;
    std::unordered_set<double> seen;
    for (double num : nums) {
        if (seen.count(s - num)) {
            std::cout << "SIM" << std::endl;
            return 0;
        }
        seen.insert(num);
    }
    std::cout << "NAO" << std::endl;
    return 0;
}

