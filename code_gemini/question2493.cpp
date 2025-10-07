/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    std::cin >> n;
    
    if (n < 2) {
        return 0;
    }
    
    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }
    
    long long max_product = LLONG_MIN;
    
    for (int i = 0; i < n - 1; ++i) {
        long long current_product = static_cast<long long>(nums[i]) * nums[i + 1];
        if (current_product > max_product) {
            max_product = current_product;
        }
    }
    
    std::cout << max_product << std::endl;
    
    return 0;
}
