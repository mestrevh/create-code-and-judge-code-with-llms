/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

const int MAX_DAYS = 3650;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    int case_num = 1;
    while (std::cin >> n) {
        std::vector<std::vector<std::pair<int, int>>> jobs_by_end(MAX_DAYS + 1);
        for (int i = 0; i < n; ++i) {
            int s, e, v;
            std::cin >> s >> e >> v;
            jobs_by_end[e].push_back({s, v});
        }

        std::vector<long long> dp(MAX_DAYS + 1, 0);

        for (int d = 1; d <= MAX_DAYS; ++d) {
            dp[d] = dp[d - 1];

            if (!jobs_by_end[d].empty()) {
                for (const auto& job : jobs_by_end[d]) {
                    int start = job.first;
                    int value = job.second;
                    dp[d] = std::max(dp[d], static_cast<long long>(value) + dp[start - 1]);
                }
            }
        }

        std::cout << "caso " << case_num << ": " << dp[MAX_DAYS] << std::endl;
        std::cout << std::endl;
        case_num++;
    }

    return 0;
}
