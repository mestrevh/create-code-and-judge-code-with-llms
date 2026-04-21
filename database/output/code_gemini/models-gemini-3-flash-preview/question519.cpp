/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cost[105];
int time_val[105];
int dp[101][100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M;
    if (!(cin >> M)) return 0;

    for (int m = 1; m <= M; ++m) {
        int N, K;
        if (!(cin >> N >> K)) break;

        for (int i = 1; i <= N; ++i) cin >> cost[i];
        for (int i = 1; i <= N; ++i) cin >> time_val[i];

        for (int j = 0; j <= K; ++j) dp[0][j] = 0;

        for (int i = 1; i <= N; ++i) {
            int ci = cost[i];
            int ti = time_val[i];
            int* curr = dp[i];
            int* prev = dp[i - 1];
            for (int j = 0; j < ci; ++j) {
                curr[j] = prev[j];
            }
            for (int j = ci; j <= K; ++j) {
                int val = ti + prev[j - ci];
                int no_val = prev[j];
                if (val >= no_val) {
                    curr[j] = val;
                } else {
                    curr[j] = no_val;
                }
            }
        }

        if (dp[N][K] == 0) {
            cout << "caso " << m << ": saldo insuficiente" << "\n\n";
        } else {
            int curr_T = dp[N][K];
            int curr_W = K;
            vector<int> best_set;
            for (int i = N; i >= 1; --i) {
                if (curr_W >= cost[i] && time_val[i] + dp[i - 1][curr_W - cost[i]] == curr_T) {
                    best_set.push_back(i);
                    curr_W -= cost[i];
                    curr_T -= time_val[i];
                }
            }

            sort(best_set.begin(), best_set.end());

            int total_cost = 0;
            int total_time = 0;
            cout << "brinquedos caso " << m << ":";
            for (int i = 0; i < (int)best_set.size(); ++i) {
                cout << " " << best_set[i];
                total_cost += cost[best_set[i]];
                total_time += time_val[best_set[i]];
            }
            cout << "\n";
            cout << "custo total caso " << m << ": " << total_cost << "\n";
            cout << "tempo total caso " << m << ": " << total_time << "\n";
            cout << "\n";
        }
    }

    return 0;
}