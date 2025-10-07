/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M, L;
        cin >> N >> M >> L;

        vector<int> V(N);
        for (int i = 0; i < N; ++i) {
            cin >> V[i];
        }

        vector<vector<int>> cost(N, vector<int>(N, INF));

        for (int i = 0; i < N; ++i) {
            cost[i][i] = 0;
        }

        for (int i = 0; i < M; ++i) {
            int A, B, C;
            cin >> A >> B >> C;
            cost[A][B] = min(cost[A][B], C);
            cost[B][A] = min(cost[B][A], C);
        }

        for (int k = 0; k < N; ++k) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    if (cost[i][k] < INF && cost[k][j] < INF) {
                        cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
                    }
                }
            }
        }

        vector<int> chosen;
        for (int i = 0; i < N; ++i) {
            if (V[i] > 0) {
                chosen.push_back(i);
            }
        }

        int minCost = INF;

        int totalV = 0;
        for (int v : V) totalV += v;

        for (int mask = 0; mask < (1 << chosen.size()); ++mask) {
            int count = 0;
            int costSum = 0;

            for (int i = 0; i < chosen.size(); ++i) {
                if (mask & (1 << i)) {
                    count += V[chosen[i]];
                    for (int j = 0; j < chosen.size(); ++j) {
                        if (i != j && (mask & (1 << j))) {
                            costSum += cost[chosen[i]][chosen[j]];
                        }
                    }
                }
            }

            if (count >= L) {
                minCost = min(minCost, costSum);
            }
        }

        cout << minCost << endl;
    }

    return 0;
}
