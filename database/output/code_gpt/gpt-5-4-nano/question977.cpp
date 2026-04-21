/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    if (!(cin >> N >> K)) return 0;

    vector<int> t(N), m(N);
    for (int i = 0; i < N; i++) cin >> t[i] >> m[i];

    const int INF = 1e9;
    vector<int> dp(K + 1, INF);
    vector<int> prevIdx(K + 1, -1);
    vector<int> prevCap(K + 1, -1);

    dp[0] = 0;

    for (int i = 0; i < N; i++) {
        int ti = t[i], mi = m[i];
        for (int cap = K; cap >= mi; cap--) {
            if (dp[cap - mi] == INF) continue;
            int cand = dp[cap - mi] + ti;
            if (cand < dp[cap]) {
                dp[cap] = cand;
                prevIdx[cap] = i;
                prevCap[cap] = cap - mi;
            }
        }
    }

    int bestF = -1;
    int bestS = INF;

    for (int cap = 0; cap <= K; cap++) {
        if (dp[cap] < bestS) {
            bestS = dp[cap];
            bestF = cap;
        }
    }

    vector<int> chosen;
    int cap = bestF;
    while (cap != 0 && cap >= 0) {
        int idx = prevIdx[cap];
        if (idx == -1) break;
        chosen.push_back(idx);
        cap = prevCap[cap];
    }
    sort(chosen.begin(), chosen.end());

    cout << bestS << ' ' << bestF << "\n";
    for (int i = 0; i < (int)chosen.size(); i++) {
        if (i) cout << ' ';
        cout << chosen[i];
    }
    cout << "\n";
    return 0;
}