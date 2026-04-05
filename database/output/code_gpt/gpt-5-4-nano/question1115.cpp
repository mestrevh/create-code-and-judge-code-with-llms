/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    vector<int> S(N), B(N), C(N);
    for (int i = 0; i < N; i++) cin >> S[i] >> B[i] >> C[i];

    int V;
    cin >> V;
    vector<int> K(V);
    int Kmax = 0;
    for (int j = 0; j < V; j++) {
        cin >> K[j];
        Kmax = max(Kmax, K[j]);
    }

    vector<long long> dp(Kmax + 1, 0);

    for (int i = 0; i < N; i++) {
        int maxk = 1;
        int limitK = (int)dp.size() - 1;
        while (true) {
            long long val = (long long)S[i] - 1LL * (maxk - 1) * (maxk - 1) * B[i];
            if (val <= 0) break;
            if (1LL * maxk * C[i] > limitK) break;
            maxk++;
        }
        int tmax = maxk - 1;
        if (tmax <= 0) continue;

        for (int used = 0; used < tmax; used++) {
            long long w = 1LL * (used + 1) * C[i];
            long long f = (long long)S[i] * (used + 1) - 1LL * B[i] * (long long)used * (long long)(used + 1) * (2LL * used + 1) / 6;
            long long val;
            if (w > Kmax) break;
            val = f;
            for (int cap = (int)Kmax; cap >= (int)w; cap--) {
                dp[cap] = max(dp[cap], dp[cap - (int)w] + val);
            }
        }
    }

    for (int j = 0; j < V; j++) {
        cout << j << ": " << dp[K[j]] << "\n";
    }
    return 0;
}