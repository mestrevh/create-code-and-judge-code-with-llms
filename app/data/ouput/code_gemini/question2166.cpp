/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>

void solve() {
    int T;
    std::cin >> T;
    std::vector<int> heights(T);
    std::vector<int> costs(T);
    for (int i = 0; i < T; ++i) {
        std::cin >> heights[i];
    }
    for (int i = 0; i < T; ++i) {
        std::cin >> costs[i];
    }

    long long min_total_cost = std::numeric_limits<long long>::max();

    for (int h_target = 1; h_target <= 100; ++h_target) {
        long long current_total_cost = 0;
        for (int i = 0; i < T; ++i) {
            current_total_cost += static_cast<long long>(std::abs(heights[i] - h_target)) * costs[i];
        }
        if (current_total_cost < min_total_cost) {
            min_total_cost = current_total_cost;
        }
    }
    
    std::cout << min_total_cost << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N;
    std::cin >> N;
    while (N--) {
        solve();
    }
    return 0;
}
