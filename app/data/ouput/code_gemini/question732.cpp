/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

void solve(int case_num) {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> counts(1001, 0);
    for (int i = 0; i < n; ++i) {
        int p;
        std::cin >> p;
        counts[p]++;
    }

    long long min_cost = 0;
    int k_needed = k;
    for (int p = 1; p <= 1000; ++p) {
        if (k_needed == 0) {
            break;
        }
        int num_to_take = std::min(k_needed, counts[p]);
        min_cost += static_cast<long long>(num_to_take) * p;
        k_needed -= num_to_take;
    }

    std::vector<int> q(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> q[i];
    }

    int min_length = m + 1;
    long long current_sum = 0;
    int left = 0;

    for (int right = 0; right < m; ++right) {
        current_sum += q[right];
        while (current_sum >= min_cost) {
            min_length = std::min(min_length, right - left + 1);
            current_sum -= q[left];
            left++;
        }
    }

    std::cout << "Caso #" << case_num << ": ";
    if (min_length > m) {
        std::cout << -1 << "\n";
    } else {
        std::cout << min_length << "\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) {
        solve(i);
    }

    return 0;
}
