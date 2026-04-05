/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    for (int tc = 1; tc <= T; tc++) {
        int N, M, K;
        cin >> N >> M >> K;

        vector<long long> P(N + 1);
        for (int i = 1; i <= N; i++) cin >> P[i];

        vector<long long> Q(M + 1);
        for (int i = 1; i <= M; i++) cin >> Q[i];

        vector<long long> prefP(N + 1, 0);
        vector<long long> sortedP = P;
        sortedP.erase(sortedP.begin());
        sort(sortedP.begin(), sortedP.end());
        prefP[0] = 0;
        for (int i = 1; i <= N; i++) prefP[i] = prefP[i - 1] + sortedP[i - 1];

        long long need = prefP[K];

        vector<long long> prefQ(M + 1, 0);
        for (int i = 1; i <= M; i++) prefQ[i] = prefQ[i - 1] + Q[i];

        long long ans = -1;

        int lo = 1, hi = M;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            bool ok = false;
            for (int l = 1; l + mid - 1 <= M; l++) {
                int r = l + mid - 1;
                long long sumQ = prefQ[r] - prefQ[l - 1];
                if (sumQ >= need) { ok = true; break; }
            }
            if (ok) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        cout << "Caso #" << tc << ": " << ans << "\n";
    }
    return 0;
}