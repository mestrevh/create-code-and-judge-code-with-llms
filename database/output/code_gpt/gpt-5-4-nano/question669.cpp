/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;

    while (T--) {
        long long N, R;
        cin >> N >> R;
        long long L = 2 * N + 1;

        vector<long long> rowCount(L, 0), colCount(L, 0);
        for (long long i = 0; i < R; i++) {
            int Ti;
            long long Pi;
            cin >> Ti >> Pi;
            if (Ti == 0) rowCount[Pi - 1] = 1;
            else colCount[Pi - 1] = 1;
        }

        long long removed = 0;
        long long k = N; 
        for (long long i = 0; i < L; i++) {
            if (!rowCount[i]) continue;
            long long t = min(i + 1, L - i);
            if (t <= k) removed += (2 * t - 1);
        }

        for (long long j = 0; j < L; j++) {
            if (!colCount[j]) continue;
            long long t = min(j + 1, L - j);
            if (t <= k) removed += (2 * t - 1);
        }

        long long totalPins = (N == 1 ? 1 : 0);
        {
            long long sum = 0;
            for (long long t = 1; t <= N; t++) sum += (2 * t - 1);
            totalPins = 2 * sum + (2 * (N + 0) - 1);
        }

        long long rowActive = 0, colActive = 0;
        {
            for (long long i = 0; i < L; i++) rowActive += rowCount[i];
            for (long long j = 0; j < L; j++) colActive += colCount[j];
        }

        long long overlap = 0;
        {
            for (long long i = 0; i < L; i++) if (rowCount[i]) {
                for (long long j = 0; j < L; j++) if (colCount[j]) {
                    long long t = min({i + 1, j + 1, L - i, L - j});
                    if (t >= 1 && t <= N) overlap++;
                }
            }
        }

        long long ans = totalPins - removed;
        ans -= overlap;
        if (ans < 0) ans = 0;

        cout << ans << "\n";
    }

    return 0;
}