/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <ios>

void solve() {
    int n;
    std::cin >> n;
    std::vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    if (n <= 2) {
        std::cout << 1 << " " << n << "\n";
        return;
    }

    int best_start_idx = 0;
    int max_len = 2;
    
    int current_start_idx = 0;
    int current_len = 2;
    long long current_reason = a[1] - a[0];

    for (int i = 2; i < n; ++i) {
        if (a[i] - a[i - 1] == current_reason) {
            current_len++;
        } else {
            if (current_len > max_len) {
                max_len = current_len;
                best_start_idx = current_start_idx;
            }
            current_start_idx = i - 1;
            current_len = 2;
            current_reason = a[i] - a[i - 1];
        }
    }

    if (current_len > max_len) {
        max_len = current_len;
        best_start_idx = current_start_idx;
    }
    
    std::cout << best_start_idx + 1 << " " << best_start_idx + max_len << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
