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
    int max_m = 0;
    for (int i = 0; i < k; ++i) {
        std::cin >> m[i];
        if (m[i] > max_m) {
            max_m = m[i];
        }
    }

    int low = 1;
    int high = max_m;
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (mid == 0) {
            break;
        }

        long long count = 0;
        for (int i = 0; i < k; ++i) {
            count += m[i] / mid;
        }

        if (count >= n) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
