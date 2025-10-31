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

    int n, k;
    std::cin >> n >> k;

    std::vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> h[i];
    }

    if (k > n) {
        return 1;
    }

    long long current_sum = 0;
    for (int i = 0; i < k; ++i) {
        current_sum += h[i];
    }

    long long min_sum = current_sum;
    int min_index = 0;

    for (int i = 1; i <= n - k; ++i) {
        current_sum = current_sum - h[i - 1] + h[i + k - 1];
        if (current_sum < min_sum) {
            min_sum = current_sum;
            min_index = i;
        }
    }

    std::cout << min_index + 1 << std::endl;

    return 0;
}
