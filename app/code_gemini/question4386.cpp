/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, k;
    std::cin >> n >> k;

    std::vector<int> m(k);
    for (int i = 0; i < k; ++i) {
        std::cin >> m[i];
    }

    long long low = 1;
    long long high = 10001;
    long long ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (mid == 0) {
            break;
        }

        long long current_slices = 0;
        for (int len : m) {
            current_slices += len / mid;
        }

        if (current_slices >= n) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
