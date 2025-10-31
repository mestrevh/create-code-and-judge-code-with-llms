/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, K;
    std::cin >> N >> K;

    std::vector<int> t(N);
    std::vector<int> m(N);
    long long total_sadness_all = 0;

    for (int i = 0; i < N; ++i) {
        std::cin >> t[i] >> m[i];
        total_sadness_all += t[i];
    }

    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(K + 1, 0));

    for (int i = N - 1; i >= 0; --i) {
        for (int j = 0; j <= K; ++j) {
            int val_attend = dp[i + 1][j];
            dp[i][j] = val_attend;

            if (j >= m[i]) {
                int val_skip = t[i] + dp[i + 1][j - m[i]];
                if (val_skip >= val_attend) {
                    dp[i][j] = val_skip;
                }
            }
        }
    }

    int max_avoided_sadness = dp[0][K];
    long long min_sadness = total_sadness_all - max_avoided_sadness;

    int final_fear = 0;
    for (int j = 0; j <= K; ++j) {
        if (dp[0][j] == max_avoided_sadness) {
            final_fear = j;
            break;
        }
    }
    
    std::cout << min_sadness << " " << final_fear << "\n";

    std::vector<int> attended_events;
    int current_fear = final_fear;

    for (int i = 0; i < N; ++i) {
        bool skipped = false;
        if (current_fear >= m[i]) {
            int val_if_skipped = t[i] + dp[i + 1][current_fear - m[i]];
            if (dp[i][current_fear] == val_if_skipped) {
                 skipped = true;
            }
        }
        
        if (skipped) {
            current_fear -= m[i];
        } else {
            attended_events.push_back(i);
        }
    }

    bool first = true;
    for (int event_id : attended_events) {
        if (!first) {
            std::cout << " ";
        }
        std::cout << event_id;
        first = false;
    }
    std::cout << "\n";

    return 0;
}
