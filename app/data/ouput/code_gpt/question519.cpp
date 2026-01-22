/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct Toy {
    int cost;
    int time;
    int index;
};

bool compare(const Toy &a, const Toy &b) {
    return a.cost < b.cost;
}

int main() {
    int M;
    cin >> M;
    cin.ignore();

    for (int case_num = 1; case_num <= M; ++case_num) {
        if (case_num > 1) cout << endl;

        int N, K;
        cin >> N >> K;

        vector<Toy> toys(N);
        for (int i = 0; i < N; ++i) {
            cin >> toys[i].cost;
            toys[i].index = i + 1;
        }

        for (int i = 0; i < N; ++i) {
            cin >> toys[i].time;
        }

        vector<vector<int>> dp(K + 1, vector<int>(N + 1, 0));
        vector<vector<bool>> used(K + 1, vector<bool>(N + 1, false));

        for (int i = 0; i < N; ++i) {
            for (int j = K; j >= toys[i].cost; --j) {
                if (dp[j - toys[i].cost][N] + toys[i].time > dp[j][N]) {
                    dp[j][N] = dp[j - toys[i].cost][N] + toys[i].time;
                    used[j][i + 1] = true;
                }
            }
        }

        int max_time = 0, best_cost = 0;
        vector<int> chosen;
        for (int j = K; j >= 0; --j) {
            if (dp[j][N] > max_time) {
                max_time = dp[j][N];
                best_cost = j;
            }
        }

        if (max_time == 0) {
            cout << "caso " << case_num << ": saldo insuficiente";
        } else {
            for (int i = N-1, j = best_cost; i >= 0 && j >= 0; --i) {
                if (used[j][i + 1]) {
                    chosen.push_back(toys[i].index);
                    j -= toys[i].cost;
                }
            }
            sort(chosen.begin(), chosen.end());

            int total_cost = 0, total_time = 0;
            for (int index : chosen) {
                total_cost += toys[index - 1].cost;
                total_time += toys[index - 1].time;
            }

            cout << "brinquedos caso " << case_num << ":";
            for (int index : chosen) {
                cout << " " << index;
            }
            cout << endl;
            cout << "custo total caso " << case_num << ": " << total_cost << endl;
            cout << "tempo total caso " << case_num << ": " << total_time;
        }
    }
    return 0;
}
