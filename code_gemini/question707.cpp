/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>

void solve() {
    int n;
    long long x;
    std::cin >> n >> x;
    std::vector<long long> costs(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> costs[i];
    }

    long long current_sum = 0;
    int start_index = 0;
    bool found = false;

    for (int end_index = 0; end_index < n; ++end_index) {
        current_sum += costs[end_index];
        while (current_sum > x && start_index <= end_index) {
            current_sum -= costs[start_index];
            start_index++;
        }
        if (current_sum == x) {
            found = true;
            break;
        }
    }

    if (found) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
