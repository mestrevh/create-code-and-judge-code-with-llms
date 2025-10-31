/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }
    int d;
    std::cin >> d;
    for (int i = 0; i < n; ++i) {
        int new_val = (nums[i] + d) % 10;
        if (new_val < 0) {
            new_val += 10;
        }
        std::cout << new_val << (i == n - 1 ? "" : " ");
    }
    std::cout << '\n';
    return 0;
}
