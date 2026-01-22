/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    if (n < 2) {
        std::cout << 0 << "\n";
        return;
    }

    int max_len = 0;
    int max_start_idx = -1;

    int current_len = 1;
    int current_start_idx = 0;

    for (int i = 1; i < n; ++i) {
        if (a[i] < a[i - 1]) {
            current_len++;
        } else {
            if (current_len > 1 && current_len > max_len) {
                max_len = current_len;
                max_start_idx = current_start_idx;
            }
            current_len = 1;
            current_start_idx = i;
        }
    }

    if (current_len > 1 && current_len > max_len) {
        max_len = current_len;
        max_start_idx = current_start_idx;
    }

    if (max_len == 0) {
        std::cout << 0 << "\n";
    } else {
        std::cout << max_len << "\n";
        for (int i = 0; i < max_len; ++i) {
            std::cout << a[max_start_idx + i] << (i == max_len - 1 ? "" : " ");
        }
        std::cout << "\n";
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
