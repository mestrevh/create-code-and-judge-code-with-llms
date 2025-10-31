/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

bool can_climb(int k, int n, const std::vector<int>& rungs) {
    int current_k = k;
    int prev_height = 0;
    for (int i = 0; i < n; ++i) {
        int jump = rungs[i] - prev_height;
        if (jump > current_k) {
            return false;
        }
        if (jump == current_k) {
            current_k--;
        }
        prev_height = rungs[i];
    }
    return true;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> rungs(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> rungs[i];
    }

    int low = 1;
    int high = 10000001;
    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (can_climb(mid, n, rungs)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    std::cout << ans << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) {
        std::cout << "Case " << i << ": ";
        solve();
    }

    return 0;
}
