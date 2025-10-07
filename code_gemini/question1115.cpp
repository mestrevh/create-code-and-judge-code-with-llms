/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

const int K_MAX = 25000;

struct Package {
    int cost;
    long long fun;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;

    std::vector<std::vector<Package>> packages_by_ride(N);

    for (int i = 0; i < N; ++i) {
        int S, B, C;
        std::cin >> S >> B >> C;

        long long current_total_fun = 0;
        int current_total_cost = 0;
        for (int k = 1; ; ++k) {
            long long fun_k = S - (long long)(k - 1) * (k - 1) * B;
            if (fun_k <= 0) {
                break;
            }
            
            current_total_cost += C;
            if (current_total_cost > K_MAX) {
                break;
            }
            
            current_total_fun += fun_k;
            packages_by_ride[i].push_back({current_total_cost, current_total_fun});
        }
    }

    std::vector<long long> dp(K_MAX + 1, 0);

    for (int i = 0; i < N; ++i) {
        std::vector<long long> next_dp = dp;
        for (const auto& p : packages_by_ride[i]) {
            for (int c = p.cost; c <= K_MAX; ++c) {
                next_dp[c] = std::max(next_dp[c], dp[c - p.cost] + p.fun);
            }
        }
        dp = next_dp;
    }

    int V;
    std::cin >> V;
    for (int j = 0; j < V; ++j) {
        int K;
        std::cin >> K;
        std::cout << j << ": " << dp[K] << "\n";
    }

    return 0;
}
