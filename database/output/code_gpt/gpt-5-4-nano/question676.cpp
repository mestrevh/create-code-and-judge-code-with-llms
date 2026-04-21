/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static const long long INFLL = (1LL<<60);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if(!(cin >> T)) return 0;
    while (T--) {
        int N, M, L;
        cin >> N >> M >> L;
        vector<int> V(N);
        for (int i = 0; i < N; i++) cin >> V[i];

        vector<vector<long long>> dist(N, vector<long long>(N, INFLL));
        for (int i = 0; i < N; i++) dist[i][i] = 0;

        for (int i = 0; i < M; i++) {
            int A, B;
            long long C;
            cin >> A >> B >> C;
            if (C < dist[A][B]) {
                dist[A][B] = C;
                dist[B][A] = C;
            }
        }

        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                long long dik = dist[i][k];
                if (dik >= INFLL) continue;
                for (int j = 0; j < N; j++) {
                    long long nd = dik + dist[k][j];
                    if (nd < dist[i][j]) dist[i][j] = nd;
                }
            }
        }

        vector<long long> d0(N);
        for (int i = 0; i < N; i++) d0[i] = dist[0][i];

        vector<int> groups;
        groups.reserve(N);
        for (int i = 0; i < N; i++) {
            if (V[i] > 0) groups.push_back(i);
        }

        int G = (int)groups.size();
        vector<vector<long long>> costPerCount(G, vector<long long>(L + 1, INFLL));
        vector<long long> totalCost(L + 1, INFLL);
        totalCost[0] = 0;

        for (int gi = 0; gi < G; gi++) {
            int node = groups[gi];
            long long c = d0[node];
            int cap = V[node];

            vector<long long> newCost(L + 1, INFLL);
            for (int have = 0; have <= L; have++) {
                if (totalCost[have] >= INFLL) continue;
                for (int take = 0; take <= cap && have + take <= L; take++) {
                    long long add = c * take;
                    long long val = totalCost[have] + add;
                    if (val < newCost[have + take]) newCost[have + take] = val;
                }
            }
            totalCost.swap(newCost);
        }

        long long ans = totalCost[L];
        cout << ans << "\n";
    }
    return 0;
}