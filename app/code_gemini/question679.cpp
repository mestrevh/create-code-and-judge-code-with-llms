/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

void solve() {
    long long k, c, d;
    int a, b;
    std::cin >> k >> a >> b >> c >> d;

    long long total_count = 0;

    for (int x = a; x <= b; ++x) {
        long long lower_bound_y_from_k = k - x + 1;
        long long effective_lower_bound_y = std::max(c, lower_bound_y_from_k);

        if (effective_lower_bound_y <= d) {
            long long count_y = d - effective_lower_bound_y + 1;
            total_count += count_y;
        }
    }

    std::cout << total_count << std::endl;
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
