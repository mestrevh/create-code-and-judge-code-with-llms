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
    vector<int> L(N), R(N);
    for (int i = 0; i < N; i++) cin >> L[i];
    for (int i = 0; i < N; i++) cin >> R[i];

    const int INF = 1e9;
    vector<int> prefL(N + 1, 0), prefR(N + 1, 0);
    for (int i = 0; i < N; i++) {
        prefL[i + 1] = prefL[i] + (L[i] == 0);
        prefR[i + 1] = prefR[i] + (R[i] == 0);
    }

    int ans = min(prefL[N], prefR[N]);

    int minRafter = INF;
    for (int k = 0; k < N; k++) {
        minRafter = min(minRafter, prefR[N] - prefR[k + 1]);
        int cand = prefL[k] + (N - 1 >= k ? 1 : 0) + (prefR[N] - prefR[k + 1]);
        if (k == N - 1) cand = prefL[N - 1] + 0 + 0;
        ans = min(ans, cand);
    }

    for (int k = 0; k < N; k++) {
        int leftBefore = prefL[k];
        int rightAfter = (k + 1 < N) ? (prefR[N] - prefR[k + 1]) : 0;
        int cand = leftBefore + 1 + rightAfter;
        if (k == N - 1) cand = leftBefore;
        ans = min(ans, cand);
    }

    for (int k = 0; k < N; k++) {
        int rightBefore = prefR[k];
        int leftAfter = (k + 1 < N) ? (prefL[N] - prefL[k + 1]) : 0;
        int cand = rightBefore + 1 + leftAfter;
        if (k == N - 1) cand = rightBefore;
        ans = min(ans, cand);
    }

    cout << ans << "\n";
    return 0;
}