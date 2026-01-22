/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }

    for (int d = 2; d <= n; ++d) {
        if (n % d == 0) {
            std::cout << d << std::endl;
            int k = n / d;
            for (int i = 0; i < n - k; ++i) {
                int p = i / k;
                int j = i % k;
                int neighbor_idx = (p + 1) * k + (k - 1 - j);
                std::cout << nums[i] << " - " << nums[neighbor_idx] << std::endl;
            }
        }
    }

    return 0;
}
