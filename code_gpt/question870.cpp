/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int X;
    std::cin >> X;
    std::vector<int> nums(X);
    
    for (int i = 0; i < X; ++i) {
        std::cin >> nums[i];
    }

    int max_sum = 0;

    for (int i = 0; i < X; ++i) {
        int current_sum = 0;
        for (int j = 0; j < X; ++j) {
            current_sum += nums[(i + j) % X];
            max_sum = std::max(max_sum, current_sum);
        }
    }

    std::cout << max_sum << std::endl;
    return 0;
}
