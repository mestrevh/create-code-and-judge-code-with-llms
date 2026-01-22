/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

void solve(int case_num) {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> c(N + 1);
    std::vector<int> t(N + 1);
    for (int i = 1; i <= N; ++i) std::cin >> c[i];
    for (int i = 1; i <= N; ++i) std::cin >> t[i];

    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(K + 1, 0));
    std::vector<std::vector<bool>> parent(N + 1, std::vector<bool>(K + 1, false));

    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= K; ++j) {
            dp[i][j] = dp[i - 1][j];
            parent[i][j] = false;

            if (j >= c[i]) {
                int time_with_i = t[i] + dp[i - 1][j - c[i]];
                if (time_with_i >= dp[i][j]) {
                    dp[i][j] = time_with_i;
                    parent[i][j] = true;
                }
            }
        }
    }

    int max_time = 0;
    for (int j = 0; j <= K; ++j) {
        if (dp[N][j] > max_time) {
            max_time = dp[N][j];
        }
    }

    if (max_time == 0) {
        std::cout << "caso " << case_num << ": saldo insuficiente\n";
        return;
    }

    std::vector<int> best_set_desc;

    for (int j = 0; j <= K; ++j) {
        if (dp[N][j] == max_time) {
            std::vector<int> current_set_desc;
            int current_k = j;
            for (int i = N; i >= 1; --i) {
                if (parent[i][current_k]) {
                    current_set_desc.push_back(i);
                    current_k -= c[i];
                }
            }
            if (best_set_desc.empty() || current_set_desc > best_set_desc) {
                best_set_desc = current_set_desc;
            }
        }
    }

    std::vector<int> final_set = best_set_desc;
    std::reverse(final_set.begin(), final_set.end());

    int total_cost = 0;
    for (int item_idx : final_set) {
        total_cost += c[item_idx];
    }

    std::cout << "brinquedos caso " << case_num << ":";
    for (size_t i = 0; i < final_set.size(); ++i) {
        std::cout << " " << final_set[i];
    }
    std::cout << "\n";
    std::cout << "custo total caso " << case_num << ": " << total_cost << "\n";
    std::cout << "tempo total caso " << case_num << ": " << max_time << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int M;
    std::cin >> M;
    
    for (int i = 1; i <= M; ++i) {
        solve(i);
        if (i < M) {
            std::cout << "\n";
        }
    }

    return 0;
}
